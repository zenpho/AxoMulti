# AxoMulti
Multitimbral polyphonic synth for Axoloti 1.0.12

Reminiscent of oldschool hardware synths like MT32, EVS-1, FB01 etc this is a multitimbral polysynth 'expander module' built with the [Axoloti platform by Johannes Taelman](https://github.com/axoloti/axoloti).

---picture---

One of five 'engines' can be assigned to MIDI channels 1..6 with 8 polyphonic voices per channel. An additional set of drum voices on MIDI channel 10 bring the total polyphonic voices to at least 32 (in the default configuration).

Synth engines include FM, PM, Waveshaping, Wavetable, Physical mdelling, and drum ROMpler types.

Realtime patch editing is possible via MIDI CC messages and front panel controls. A complete MULTI setup can be stored in a sequencer, as can expressive changes to patch parameters during realtime performance, or using CC automation. See [Midi Implementation](#midi-implementation) section below for more info.

# Installation and usage

Copy `startup.bin` and `zp-kit1.wav` to a microSD card, insert into hardware, switch on and enjoy the sounds. 😎
You can use Axoloti editor `upload to internal flash` menu option for synthesis-only (drum channel 10 will simply be silent).

# Compatibility and requirements

Extensive testing and development with Axoloti v1.0.12 firmware hardware and editor. You need a microSD card at least 1MByte in size for the drumkit wave ROM. 

# MIDI implementation

Channels 1..6 may be configured as pitched voices, select engine with MIDI PROGRAM CHANGE.
Channel 10 is always drumkit (if you have an SD card with wav files, silence otherwise).

MIDI CONTROL CHANGE #7 sets channel volume on any supported channel
MIDI PROGRAM CHANGE 0,1,2 etc selects the pitched voice engine
MIDI PROGRAM CHANGE 127 invokes a response for all values for the selected voice engine

Voice engine 1: noisy shift register (MI)
Voice engine 2: feedback fm (MI)
Voice engine 3: sine waveshaper (SSS)
Voice engine 4: sine wavefolder (SSS)
Voice engine 5: asymmetrical sinefolder (SSS)

---table---

# To build from source

The `xpatch.cpp` exported from Axoloti 1.0.12 editor is provided.
The editor project `AxoMulti.axp` file(s) are also provided which require valid installation of the `axoloti-factory` and `axoloti-community` repositories as well as my very necessary modifications to the build configuration file `Makefile.patch`.

* ZPO-POLYFIX perl 's/find/replace/g' to optimise idle polyphonic voices
* ZPO-KVPLOMEM perl 's/find/replace/g' to omit KVP IPVP etc registration, saving SRAM
* gcc -O1 preferred optimisation, again saving SRAM
