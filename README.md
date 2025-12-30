# AxoMulti
Multitimbral polyphonic synth for axoloti and ksoloti 1.0.12

Reminiscent of oldschool hardware synths like EVS-1, FB01, MT32 etc this is a multitimbral polysynth 'expander module' built with the [Axoloti platform by Johannes Taelman](https://github.com/axoloti/axoloti) and compatible with [Ksoloti platform](https://github.com/ksoloti).

![detail of the patch](images/xpatch.png)

Synth _'Engines'_ are algorithms assigned to MIDI channels with eight polyphonic voices per channel. An additional set of drum voices bring the total polyphonic voices to at least 50 in the default configuration.

Synth engines include FM, PM, Waveshaping, Wavetable, Physical mudelling, and drum ROMpler types.

![one of the engines](images/engine.png)

Realtime patch editing uses MIDI CONTROL CHANGE messages. A complete MULTI setup can be stored in a sequencer, as can expressive changes to patch parameters during realtime performance, or using CC automation. See [Midi Implementation](#midi-implementation) section below for more info.

# Installation and usage

No editor, no problem. Copy the files to a microSD card (including `start.bin`), insert into hardware, switch on and enjoy the sounds. 😎

# Help!

I'm working on developing this to work with multiple boards as 'voice cards' with a central device receiving MIDI channel messages and despatching to the voice cards, bussing audio outputs together. That'll be fun, but I'm not there yet. Can you help?

Most synth engines here do not use CHANNEL or POLY AFTER TOUCH, PITCH BEND, nor MOD WHEEL yet. Can you help?

# Compatibility and requirements

Development and extensive testing has been carried out with both axoloti and ksoloti firmware hardware and editor. This release 1.2 focuses on Ksoloti v1.0.12 firmware hardware and editor. You need a microSD card at least 1MByte in size for the drumkit wave ROM. 

# MIDI implementation

* Channels 1..6 may be configured as pitched voices, select engine with MIDI PROGRAM CHANGE.
* Channel 10 is always drumkit (if you have an SD card with wav files, silence otherwise).
* Channel 11 is an optional second drum kit (see note above).

* MIDI CONTROL CHANGE 7 sets volume on any supported channel
* MIDI CONTROL CHANGE 10 sets routing (only left, left+right, right only)
* MIDI CONTROL CHANGE 72 sets envelope type (snap, gentle fade-out only, in-and-out)

* MIDI PROGRAM CHANGE 0,1,2 etc selects the pitched voice engine
* MIDI PROGRAM CHANGE 127 invokes a response for all values for the selected voice engine

There are two implementations, each with different sets of voice engines.

|Version 28a     |Description                    |
|---------------|-------------------------------|
|Voice engine 0 | idle, no DSP                  |
|Voice engine 1 | noisy shift register (MI)     |
|Voice engine 2 | feedback fm (MI)              |
|Voice engine 3 | sine waveshaper (SSS)         |
|Voice engine 4 | sine wavefolder (SSS)         |
|Voice engine 5 | asymmetrical sinefolder (SSS) |

|Version 28b     |Description                    |
|---------------|-------------------------------|
|Voice engine 0 | idle, no DSP                  |
|Voice engine 1 | fm (MI)                       |
|Voice engine 2 | sinefolder (MI)               |
|Voice engine 3 | wavetables (MI)               |
|Voice engine 4 | buzz (MI)                     |
|Voice engine 5 | noisy shift register (MI)     |
|Voice engine 6 | feedback fm (MI)              |

A consistent map of MIDI CONTROL CHANGE 16..31 is used for all pitched voice channels to configure parameters.

|CC#|Description               |
|---|--------------------------|
|07	|volume                    |
|16	|voice timbre              |
|17	|voice colour(if available)|
|18	|a time                    |
|19	|a vel-time                |
|20	|t time                    |
|21	|t vel+-                   |
|22	|t env                     |
|23	|c time     (if available) |
|24	|c vel-time (if available) |
|25	|c env      (if available) |
|26	|s time     (if available) |
|27	|s vel-time	(if available) |
|28	|s env      (if available) |
|29 |t set      (if available) |
|30 |c set      (if available) |
|31 |s set      (if available) |

# To build from source

The `xpatch.cpp` and `patch.bin` files exported from editor v1.0.12 are provided.
The editor project `.axp` file(s) are also provided which require valid installation of the `axoloti-factory` and `axoloti-community` repositories as well as my very necessary modifications to the build configuration file `Makefile.patch`.

* ZPO-POLYFIX perl 's/find/replace/g' to optimise idle polyphonic voices
* ZPO-KVPLOMEM perl 's/find/replace/g' to omit KVP IPVP etc registration, saving SRAM
* gcc -O1 preferred optimisation, again saving SRAM

# Anything else I should know?

Yeah, unlike EVOLUTION EVS-1 behaviour, switching engine with a PROGRAM CHANGE initialises voice params. I would love to preserve parameter values across switching to easily answer the question _"I wonder what these parameter values would sound like on a different engine?"_... You can kinda work around this to capture a state dump in your sequencer and retransmit CONTROL CHANGE param values with a different PROGRAM CHANGE, but it's a bit of a faff.

See my other axo/kso projects
 * [AxoPanelControls github repo](https://github.com/zenpho/AxoPanelControls) hastily constructed control panel for axoloti and ksoloti
 * [ks1.0.12 firmware](https://github.com/zenpho/ks1.0.12/tree/midi-patch) my modified ksoloti firmware with midi 'improvements'
 * [kz editor](https://github.com/zenpho/kzeditor) modified OG Axoloti editor compatible with older intel macs and older MacOS

# Quick sketching with ks-multi30c

The consistent MIDI CONTROL CHANGE [mapping](#midi-implementation) across all synth _'engine'_ algorithms is beneficial but such a hastle when designing new engines.

When inconsistent mapping is acceptable. Using `ks-multi30c` is effective to quickly sketch music with multiple polyphonic parts on multiple simulateneous timbres (BAS, PNO, KIT, TPT, TBN etc). 

I often:

 1. pick and paste-replace engines from `bank30` into a unique copy of the `30c` template then send to ksoloti hardware
 2. send MIDI PROGRAM CHANGE and MIDI CONTROL CHANGE to design multiple sounds (PNO, BRS, STR, etc) _being forced to guess which control affects which parameter and being guided by ear alone_
 3. save the complete MULTI setup (including all voice engine state variables) in my MIDI sequencer project with perfect recall

![detail of ks-multi30 patch](images/multi30.png)

To build from source this requires `ZP-OMITALGO` (part of my `Makefile.patch`) which will optimise SRAM usage.