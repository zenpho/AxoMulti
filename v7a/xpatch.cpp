/*
   AxoMulti v7a by zenpho ::: see github.com/zenpho/AxoMulti
   Multitimbral polyphonic engine for Axoloti v1.0.12
 
   We (ab)use the ParameterExchange mechanism a fair bit, and rework
   much of the (also courtesy of Axo editor) polyphonic voice handling
   to get close to 1990s style behaviour like MT32 EVS-1 FB01 etc
 
   We also (ab)use section(".sdram") stuff to cram everything into the
   STM32F427 256kb of cortex SRAM and prefer using Axoloti Core SDRAM
 
   I'm not too proud of the vtype switching code but this is a first
   (very shitty, very embarrasing) attempt and it works - Yay! I guess?
 
   Horrend-o-whitespace layout courtesy of Axo editor
   Suggest prettyprint for more joyous happy readable funtime yeah?
*/
#include "~/Documents/axoloti/axoloti-factory/objects/osc/brds/brds_digital.h"

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#define MIDICHANNEL 0 // DEPRECATED!
void xpatch_init2(int fwid);
extern "C" __attribute__ ((section(".boot"))) void xpatch_init(int fwid){
  xpatch_init2(fwid);
}

void PatchMidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2);

     int32buffer AudioInputLeft;
     int32buffer AudioInputRight;
     int32buffer AudioOutputLeft;
     int32buffer AudioOutputRight;
     typedef enum { A_STEREO, A_MONO, A_BALANCED } AudioModeType;
     AudioModeType AudioOutputMode = A_STEREO;
     AudioModeType AudioInputMode = A_STEREO;
static void PropagateToSub(ParameterExchange_t *origin) {
      ParameterExchange_t *pex = (ParameterExchange_t *)origin->finalvalue;
      PExParameterChange(pex,origin->modvalue,0xFFFFFFEE);
}
class rootc{
   public:
    static const uint32_t NPEXCH = 6;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[5];
    static const uint32_t NPRESETS = 0;
    static const uint32_t NPRESET_ENTRIES = 0;
    static const uint32_t NMODULATIONSOURCES = 0;
    static const uint32_t NMODULATIONTARGETS = 0;
    int32_t PExModulationPrevVal[1][NMODULATIONSOURCES];
/* modsource defines */
/* parameter instance indices */
static const int PARAM_INDEX_patcher__1_vtype = 0;
static const int PARAM_INDEX_patcher__2_vtype = 1;
static const int PARAM_INDEX_patcher__3_vtype = 2;
static const int PARAM_INDEX_patcher__4_vtype = 3;
static const int PARAM_INDEX_patcher__5_vtype = 4;
static const int PARAM_INDEX_patcher__6_vtype = 5;
/* controller classes */
/* object classes */
class instancelogger__1{
  public: // v1
  rootc *parent;
int logTimer;
  public: void Init(rootc * _parent) {
parent = _parent;
logTimer = 0;
}
  public: void Dispose() {
}
  public: void dsp (  ){
if( ++logTimer == 60000 )
{
	logTimer = 0;
	LogTextMessage( "axoMulti-7a.axp (2025apr17)" );
}
}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if( (status == MIDI_PROGRAM_CHANGE + MIDICHANNEL ) ){
	LogTextMessage( "axoMulti-7a.axp (2025apr17)" );
}}
}
}
;class instancealgo__1{
  public: // v1
  rootc *parent;
   static int32_t * GetInitParams(void){
      static const int32_t p[11]= {
      0,
      126877696,
      67108864,
      -134217728,
      0,
      0,
      0,
      0,
      0,
      0,
      0
      };
      return (int32_t *)&p[0];
   }    static const uint32_t NPEXCH = 11;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 0;
    static const uint32_t NPRESET_ENTRIES = 0;
    static const uint32_t NMODULATIONSOURCES = 0;
    static const uint32_t NMODULATIONTARGETS = 0;
    int32_t PExModulationPrevVal[1][NMODULATIONSOURCES];
/* parameter instance indices */
static const int PARAM_INDEX_cnoise__1_pitch = 0;
static const int PARAM_INDEX_cnoise__1_timbre = 1;
static const int PARAM_INDEX_cnoise__1_color = 2;
static const int PARAM_INDEX_a__time_a = 3;
static const int PARAM_INDEX_a__vel_amp = 4;
static const int PARAM_INDEX_env__t_time = 5;
static const int PARAM_INDEX_env__t_vt = 6;
static const int PARAM_INDEX_env__t_env = 7;
static const int PARAM_INDEX_env__c_time = 8;
static const int PARAM_INDEX_env__c_vt = 9;
static const int PARAM_INDEX_env__c_env = 10;
   static const int32_t * GetPresets(void){
      static const int32_t p[NPRESETS][NPRESET_ENTRIES][2] = {
      };
   return &p[0][0][0];
   };
void ApplyPreset(int index){
   if (!index) {
     int i;
     int32_t *p = GetInitParams();
     for(i=0;i<NPEXCH;i++){
        PExParameterChange(&PExch[i],p[i],0xFFEF);
     }
   }
   index--;
   if (index < NPRESETS) {
     PresetParamChange_t *pa = (PresetParamChange_t *)(GetPresets());
     PresetParamChange_t *p = &pa[index*NPRESET_ENTRIES];
       int i;
       for(i=0;i<NPRESET_ENTRIES;i++){
         PresetParamChange_t *pp = &p[i];
         if ((pp->pexIndex>=0)&&(pp->pexIndex<NPEXCH)) {
           PExParameterChange(&PExch[pp->pexIndex],pp->value,0xFFEF);         }
         else break;
       }
   }
}
   static PExModulationTarget_t * GetModulationTable(void){
    static const PExModulationTarget_t PExModulationSources[NMODULATIONSOURCES][NMODULATIONTARGETS] = 
{};
   return (PExModulationTarget_t *)&PExModulationSources[0][0];
   };
class voice {
   public:
   int polyIndex;
    static const uint32_t NPEXCH = 11;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 0;
    static const uint32_t NPRESET_ENTRIES = 0;
    static const uint32_t NMODULATIONSOURCES = 0;
    static const uint32_t NMODULATIONTARGETS = 0;
/* modsource defines */
/* parameter instance indices */
static const int PARAM_INDEX_cnoise__1_pitch = 0;
static const int PARAM_INDEX_cnoise__1_timbre = 1;
static const int PARAM_INDEX_cnoise__1_color = 2;
static const int PARAM_INDEX_a__time_a = 3;
static const int PARAM_INDEX_a__vel_amp = 4;
static const int PARAM_INDEX_env__t_time = 5;
static const int PARAM_INDEX_env__t_vt = 6;
static const int PARAM_INDEX_env__t_env = 7;
static const int PARAM_INDEX_env__c_time = 8;
static const int PARAM_INDEX_env__c_vt = 9;
static const int PARAM_INDEX_env__c_env = 10;
/* controller classes */
/* object classes */
class instancecnoise__1{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instancecnoise__1_pitch;
//KeyValuePair KVP_instancecnoise__1_timbre;
//KeyValuePair KVP_instancecnoise__1_color;
braids_digital_deriv::ClockedNoise osc;
bool pstrike;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_cnoise__1_pitch].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instancecnoise__1_pitch,ObjectKvpRoot, "cnoise_1:pitch" ,&parent->PExch[PARAM_INDEX_cnoise__1_pitch], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instancecnoise__1_pitch);
parent->PExch[PARAM_INDEX_cnoise__1_timbre].pfunction = pfun_unsigned_clamp;
  //SetKVP_IPVP(&KVP_instancecnoise__1_timbre,ObjectKvpRoot, "cnoise_1:timbre" ,&parent->PExch[PARAM_INDEX_cnoise__1_timbre], 0, 1<<27);
  //KVP_RegisterObject(&KVP_instancecnoise__1_timbre);
parent->PExch[PARAM_INDEX_cnoise__1_color].pfunction = pfun_unsigned_clamp;
  //SetKVP_IPVP(&KVP_instancecnoise__1_color,ObjectKvpRoot, "cnoise_1:color" ,&parent->PExch[PARAM_INDEX_cnoise__1_color], 0, 1<<27);
  //KVP_RegisterObject(&KVP_instancecnoise__1_color);
osc.Init();
pstrike = 0;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_pitch,
const int32_t  inlet_timbre,
const int32_t  inlet_color,
const bool  inlet_strike,
int32buffer  & outlet_wave,
int param_pitch,
int param_timbre,
int param_color  ){
osc.set_parameters(__USAT((inlet_timbre+param_timbre)>>12,15),__USAT((inlet_color+param_color)>>12,15));
osc.set_pitch((64<<7)+((param_pitch + inlet_pitch)>>14));
bool strike = 0;
if (inlet_strike && !pstrike){
	pstrike = 1;
	strike = 1;
} else if (!inlet_strike) {
	pstrike = 0;	
}

osc.Render(0,&outlet_wave[0],BUFSIZE,strike);
}
}
;class instancea__time{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instancea__time_a;
int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a__time_a].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instancea__time_a,ObjectKvpRoot, "a_time" ,&parent->PExch[PARAM_INDEX_a__time_a], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instancea__time_a);
val = 0;
}
  public: void Dispose() {
}
  public: void dsp (const bool  inlet_trig,
const int32_t  inlet_a,
int32_t  & outlet_env,
int param_a  ){
if (inlet_trig > 0) {
  int32_t t;
  int32_t at = param_a + inlet_a;
  MTOF(-at,t);
  val += t>>6;
}
else {
  val = 0;
}
val = __USAT(val,27);
outlet_env = val;
}
}
;class instancekeyb__1{
  public: // v1
  voice *parent;
int8_t _note;
int32_t _gate;
int32_t _gate2;
uint8_t _velo;
uint8_t _rvelo;

  public: void Init(voice * _parent) {
parent = _parent;
_gate = 0;
_note = 0;

}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_note,
bool  & outlet_gate,
bool  & outlet_gate2,
int32_t  & outlet_velocity,
int32_t  & outlet_releaseVelocity  ){
outlet_note= _note<<21;
outlet_gate= _gate;
outlet_gate2= _gate2;
_gate2 = _gate;
outlet_velocity= _velo<<20;
outlet_releaseVelocity= _rvelo<<20;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ((status == MIDI_NOTE_ON + 0) && (data2)) {
  _velo = data2;
  _note = data1-64;
  _gate = 1<<27;
  _gate2 = 0;
} else if (((status == MIDI_NOTE_ON + 0) && (!data2))||
          (status == MIDI_NOTE_OFF + 0)) {
  if (_note == data1-64) {
    _rvelo = data2;
    _gate = 0;
  }
} else if ((status == 0 + MIDI_CONTROL_CHANGE)&&(data1 == MIDI_C_ALL_NOTES_OFF)) {
  _gate = 0;
}
}
}
}
;class instancea__vel{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instancea__vel_amp;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a__vel_amp].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instancea__vel_amp,ObjectKvpRoot, "a_vel" ,&parent->PExch[PARAM_INDEX_a__vel_amp], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instancea__vel_amp);
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out,
int param_amp  ){
outlet_out= ___SMMUL(param_amp, inlet_in)<<5;

}
}
;class instancevca__1{
  public: // v1
  voice *parent;
   int32_t prev;
    int32_t step;

  public: void Init(voice * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_v,
const int32buffer  inlet_a,
int32buffer  & outlet_o  ){
   step = (inlet_v - prev)>>4;
   int32_t i = prev;
   prev = inlet_v;

int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   outlet_o[buffer_index] =  ___SMMUL(inlet_a[buffer_index],i)<<5;
   i += step;

}
}
}
;class instancecc__1{
  public: // v1
  voice *parent;
int32_t ccv;
int32_t ntrig;

  public: void Init(voice * _parent) {
parent = _parent;
ccv = 100 << 20;

}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_midiCC,
bool  & outlet_trig  ){
outlet_midiCC= ccv;
outlet_trig = ntrig;
ntrig = 0;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ((status == 0 + MIDI_CONTROL_CHANGE)&&(data1 == 7)) { ccv = data2<<20; ntrig = 1;}
}
}
}
;class instancevca__2{
  public: // v1
  voice *parent;
   int32_t prev;
    int32_t step;

  public: void Init(voice * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_v,
const int32buffer  inlet_a,
int32buffer  & outlet_o  ){
   step = (inlet_v - prev)>>4;
   int32_t i = prev;
   prev = inlet_v;

int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   outlet_o[buffer_index] =  ___SMMUL(inlet_a[buffer_index],i)<<5;
   i += step;

}
}
}
;class instanceoutlet__1{
  public: // v1
  voice *parent;
int32buffer _outlet;

  public: void Init(voice * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_outlet  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   _outlet[buffer_index] = inlet_outlet[buffer_index];

}
}
}
;class instanceenv__t{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instanceenv__t_time;
//KeyValuePair KVP_instanceenv__t_vt;
//KeyValuePair KVP_instanceenv__t_env;
int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_env__t_time].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__t_time,ObjectKvpRoot, "env_t:time" ,&parent->PExch[PARAM_INDEX_env__t_time], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__t_time);
parent->PExch[PARAM_INDEX_env__t_vt].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__t_vt,ObjectKvpRoot, "env_t:vt" ,&parent->PExch[PARAM_INDEX_env__t_vt], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__t_vt);
parent->PExch[PARAM_INDEX_env__t_env].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__t_env,ObjectKvpRoot, "env_t:env" ,&parent->PExch[PARAM_INDEX_env__t_env], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__t_env);
val = 0;
}
  public: void Dispose() {
}
  public: void dsp (const bool  inlet_trig,
const int32_t  inlet_vel,
int32_t  & outlet_env,
int param_time,
int param_vt,
int param_env  ){
int32_t vel_vt = ___SMMUL(param_vt, inlet_vel)<<5; // shorten or lengthen time by velo
if (inlet_trig > 0) {
  int32_t t;
  int32_t at = param_time + vel_vt;
  MTOF(-at,t);
  val += t>>6;
}
else {
  val = 0;
}
val = __USAT(val,27);

outlet_env = ___SMMUL(param_env, val)<<5;
}
}
;class instanceenv__c{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instanceenv__c_time;
//KeyValuePair KVP_instanceenv__c_vt;
//KeyValuePair KVP_instanceenv__c_env;
int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_env__c_time].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__c_time,ObjectKvpRoot, "env_c:time" ,&parent->PExch[PARAM_INDEX_env__c_time], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__c_time);
parent->PExch[PARAM_INDEX_env__c_vt].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__c_vt,ObjectKvpRoot, "env_c:vt" ,&parent->PExch[PARAM_INDEX_env__c_vt], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__c_vt);
parent->PExch[PARAM_INDEX_env__c_env].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__c_env,ObjectKvpRoot, "env_c:env" ,&parent->PExch[PARAM_INDEX_env__c_env], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__c_env);
val = 0;
}
  public: void Dispose() {
}
  public: void dsp (const bool  inlet_trig,
const int32_t  inlet_vel,
int32_t  & outlet_env,
int param_time,
int param_vt,
int param_env  ){
int32_t vel_vt = ___SMMUL(param_vt, inlet_vel)<<5; // shorten or lengthen time by velo
if (inlet_trig > 0) {
  int32_t t;
  int32_t at = param_time + vel_vt;
  MTOF(-at,t);
  val += t>>6;
}
else {
  val = 0;
}
val = __USAT(val,27);

outlet_env = ___SMMUL(param_env, val)<<5;
}
}
;/* controller instances */
/* object instances */
     instancecnoise__1 instancecnoise__1_i;
     instancea__time instancea__time_i;
     instancekeyb__1 instancekeyb__1_i;
     instancea__vel instancea__vel_i;
     instancevca__1 instancevca__1_i;
     instancecc__1 instancecc__1_i;
     instancevca__2 instancevca__2_i;
     instanceoutlet__1 instanceoutlet__1_i;
     instanceenv__t instanceenv__t_i;
     instanceenv__c instanceenv__c_i;
/* net latches */
    bool  net2Latch;
    int32_t  net3Latch;
    int32_t  net7Latch;
    int32_t  net9Latch;
    int32_t  net10Latch;
instancealgo__1 *common;
void Init(voice *parent) {
        int i;
        for(i=0;i<NPEXCH;i++){
          PExch[i].pfunction = 0;
        }
   instancecnoise__1_i.Init(parent );
   instancea__time_i.Init(parent );
   instancekeyb__1_i.Init(parent );
   instancea__vel_i.Init(parent );
   instancevca__1_i.Init(parent );
   instancecc__1_i.Init(parent );
   instancevca__2_i.Init(parent );
   instanceoutlet__1_i.Init(parent );
   instanceenv__t_i.Init(parent );
   instanceenv__c_i.Init(parent );
      int k;
      for (k = 0; k < NPEXCH; k++) {
        if (PExch[k].pfunction){
          (PExch[k].pfunction)(&PExch[k]);
        } else {
          PExch[k].finalvalue = PExch[k].value;
        }
      }
}

void dsp(void) {
 int i;
//--------- <nets> -----------//
    int32_t  net0;
    int32_t  net1;
    bool  net2;
    int32_t  net3;
    int32_t  net4;
    int32buffer  net5;
    int32buffer  net6;
    int32_t  net7;
    int32buffer  net8;
    int32_t  net9;
    int32_t  net10;
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instancecnoise__1_i.dsp(net7Latch, net9Latch, net10Latch, net2Latch, net8, PExch[PARAM_INDEX_cnoise__1_pitch].finalvalue, PExch[PARAM_INDEX_cnoise__1_timbre].finalvalue, PExch[PARAM_INDEX_cnoise__1_color].finalvalue);
  instancea__time_i.dsp(net2Latch, net3Latch, net1, PExch[PARAM_INDEX_a__time_a].finalvalue);
  instancekeyb__1_i.dsp(net7, (bool &)UNCONNECTED_OUTPUT, net2, net0, UNCONNECTED_OUTPUT);
  instancea__vel_i.dsp(net0, net3, PExch[PARAM_INDEX_a__vel_amp].finalvalue);
  instancevca__1_i.dsp(net1, net8, net6);
  instancecc__1_i.dsp(net4, (bool &)UNCONNECTED_OUTPUT);
  instancevca__2_i.dsp(net4, net6, net5);
  instanceoutlet__1_i.dsp(net5);
  instanceenv__t_i.dsp(net2, net0, net9, PExch[PARAM_INDEX_env__t_time].finalvalue, PExch[PARAM_INDEX_env__t_vt].finalvalue, PExch[PARAM_INDEX_env__t_env].finalvalue);
  instanceenv__c_i.dsp(net2, net0, net10, PExch[PARAM_INDEX_env__c_time].finalvalue, PExch[PARAM_INDEX_env__c_vt].finalvalue, PExch[PARAM_INDEX_env__c_env].finalvalue);
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
net2Latch = net2;
net3Latch = net3;
net7Latch = net7;
net9Latch = net9;
net10Latch = net10;
//--------- </net latch copy> ----------//
}
void dispose(void) {
 int i;
   instanceenv__c_i.Dispose();
   instanceenv__t_i.Dispose();
   instanceoutlet__1_i.Dispose();
   instancevca__2_i.Dispose();
   instancecc__1_i.Dispose();
   instancevca__1_i.Dispose();
   instancea__vel_i.Dispose();
   instancekeyb__1_i.Dispose();
   instancea__time_i.Dispose();
   instancecnoise__1_i.Dispose();
}
void MidiInHandler(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2){
instancekeyb__1_i.MidiInHandler(dev, port, status, data1, data2);
instancecc__1_i.MidiInHandler(dev, port, status, data1, data2);
}

};
static voice * getVoices(void){
     static voice v[1];
    return v;
}
static void PropagateToVoices(ParameterExchange_t *origin) {
      ParameterExchange_t *pex = (ParameterExchange_t *)origin->finalvalue;
      int vi;
      for (vi = 0; vi < 1; vi++) {
        PExParameterChange(pex,origin->modvalue,0xFFFFFFEE);
          pex = (ParameterExchange_t *)((int)pex + sizeof(voice)); // dirty trick...
      }}
int8_t notePlaying[1];
int32_t voicePriority[1];
int32_t priority;
int32_t sustain;
int8_t pressed[1];

  public: void Init(rootc * _parent) {
parent = _parent;
   int i;
   int j;
   const int32_t *p;
   p = GetInitParams();
   for(j=0;j<11;j++){
      PExch[j].value = p[j];
      PExch[j].modvalue = p[j];
      PExch[j].signals = 0;
      PExch[j].pfunction = 0;
   }
   int32_t *pp = &PExModulationPrevVal[0][0];
   for(j=0;j<1*NMODULATIONSOURCES;j++){
      *pp = 0; pp++;
   }
     displayVector[0] = 0x446F7841;
     displayVector[1] = 0;
     displayVector[2] = 0;
int k;
   for(k=0;k<NPEXCH;k++){
      PExch[k].pfunction = PropagateToVoices;
      PExch[k].finalvalue = (int32_t) (&(getVoices()[0].PExch[k]));
   }
int vi; for(vi=0;vi<1;vi++) {
   voice *v = &getVoices()[vi];
   v->polyIndex = vi;
   v->common = this;
   v->Init(&getVoices()[vi]);
   notePlaying[vi]=0;
   voicePriority[vi]=0;
   for (j = 0; j < v->NPEXCH; j++) {
      v->PExch[j].value = 0;
      v->PExch[j].modvalue = 0;
   }
}
      for (k = 0; k < NPEXCH; k++) {
        if (PExch[k].pfunction){
          (PExch[k].pfunction)(&PExch[k]);
        } else {
          PExch[k].finalvalue = PExch[k].value;
        }
      }
priority=0;
sustain=0;

}
  public: void Dispose() {
int vi; for(vi=0;vi<1;vi++) {
  voice *v = &getVoices()[vi];
  v->dispose();
}

}
  public: void dsp (int32buffer  & outlet_outlet__1  ){
{
      int j;
      for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] = 0;
}
int vi; for(vi=0;vi<1;vi++) {if(!pressed[vi]) continue; getVoices()[vi].dsp();
{
      int j;
      for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += getVoices()[vi].instanceoutlet__1_i._outlet[j];
}
}

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ( 15 > 0 && dev > 0 && 15 != dev) return;
if ( 16 > 0 && port > 0 && 16 != port) return;
if ((status == MIDI_NOTE_ON + 0) && (data2)) {
  int min = 1<<30;
  int mini = 0;
  int i;
  for(i=0;i<1;i++){
    if (voicePriority[i] < min){
      min = voicePriority[i];
      mini = i;
    }
  }
  voicePriority[mini] = 100000+priority++;
  notePlaying[mini] = data1;
  pressed[mini] = 1;
  getVoices()[mini].MidiInHandler(dev, port, status, data1, data2);
} else if (((status == MIDI_NOTE_ON + 0) && (!data2))||
          (status == MIDI_NOTE_OFF + 0)) {
  int i;
  for(i=0;i<1;i++){
    if ((notePlaying[i] == data1) && pressed[i]){
      voicePriority[i] = priority++;
      pressed[i] = 0;
      if (!sustain)
        getVoices()[i].MidiInHandler(dev, port, status, data1, data2);
      }
  }
} else if (status == 0 + MIDI_CONTROL_CHANGE) {
  int i;
  for(i=0;i<1;i++) getVoices()[i].MidiInHandler(dev, port, status, data1, data2);
  if (data1 == 64) {
    if (data2>0) {
      sustain = 1;
    } else if (sustain == 1) {
      sustain = 0;
      for(i=0;i<1;i++){
        if (pressed[i] == 0) {
          getVoices()[i].MidiInHandler(dev, port, MIDI_NOTE_ON + 0, notePlaying[i], 0);
        }
      }
    }
  }
} else {  int i;   for(i=0;i<1;i++) getVoices()[i].MidiInHandler(dev, port, status, data1, data2);
}
}
}
}
;class instancealgo__2{
  public: // v1
  rootc *parent;
   static int32_t * GetInitParams(void){
      static const int32_t p[11]= {
      0,
      67108864,
      67108864,
      -134217728,
      0,
      0,
      0,
      0,
      0,
      0,
      0
      };
      return (int32_t *)&p[0];
   }    static const uint32_t NPEXCH = 11;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 0;
    static const uint32_t NPRESET_ENTRIES = 0;
    static const uint32_t NMODULATIONSOURCES = 0;
    static const uint32_t NMODULATIONTARGETS = 0;
    int32_t PExModulationPrevVal[1][NMODULATIONSOURCES];
/* parameter instance indices */
static const int PARAM_INDEX_fbfm__1_pitch = 0;
static const int PARAM_INDEX_fbfm__1_timbre = 1;
static const int PARAM_INDEX_fbfm__1_color = 2;
static const int PARAM_INDEX_a__time_a = 3;
static const int PARAM_INDEX_a__vel_amp = 4;
static const int PARAM_INDEX_env__t_time = 5;
static const int PARAM_INDEX_env__t_vt = 6;
static const int PARAM_INDEX_env__t_env = 7;
static const int PARAM_INDEX_env__c_time = 8;
static const int PARAM_INDEX_env__c_vt = 9;
static const int PARAM_INDEX_env__c_env = 10;
   static const int32_t * GetPresets(void){
      static const int32_t p[NPRESETS][NPRESET_ENTRIES][2] = {
      };
   return &p[0][0][0];
   };
void ApplyPreset(int index){
   if (!index) {
     int i;
     int32_t *p = GetInitParams();
     for(i=0;i<NPEXCH;i++){
        PExParameterChange(&PExch[i],p[i],0xFFEF);
     }
   }
   index--;
   if (index < NPRESETS) {
     PresetParamChange_t *pa = (PresetParamChange_t *)(GetPresets());
     PresetParamChange_t *p = &pa[index*NPRESET_ENTRIES];
       int i;
       for(i=0;i<NPRESET_ENTRIES;i++){
         PresetParamChange_t *pp = &p[i];
         if ((pp->pexIndex>=0)&&(pp->pexIndex<NPEXCH)) {
           PExParameterChange(&PExch[pp->pexIndex],pp->value,0xFFEF);         }
         else break;
       }
   }
}
   static PExModulationTarget_t * GetModulationTable(void){
    static const PExModulationTarget_t PExModulationSources[NMODULATIONSOURCES][NMODULATIONTARGETS] = 
{};
   return (PExModulationTarget_t *)&PExModulationSources[0][0];
   };
class voice {
   public:
   int polyIndex;
    static const uint32_t NPEXCH = 11;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 0;
    static const uint32_t NPRESET_ENTRIES = 0;
    static const uint32_t NMODULATIONSOURCES = 0;
    static const uint32_t NMODULATIONTARGETS = 0;
/* modsource defines */
/* parameter instance indices */
static const int PARAM_INDEX_fbfm__1_pitch = 0;
static const int PARAM_INDEX_fbfm__1_timbre = 1;
static const int PARAM_INDEX_fbfm__1_color = 2;
static const int PARAM_INDEX_a__time_a = 3;
static const int PARAM_INDEX_a__vel_amp = 4;
static const int PARAM_INDEX_env__t_time = 5;
static const int PARAM_INDEX_env__t_vt = 6;
static const int PARAM_INDEX_env__t_env = 7;
static const int PARAM_INDEX_env__c_time = 8;
static const int PARAM_INDEX_env__c_vt = 9;
static const int PARAM_INDEX_env__c_env = 10;
/* controller classes */
/* object classes */
class instancefbfm__1{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instancefbfm__1_pitch;
//KeyValuePair KVP_instancefbfm__1_timbre;
//KeyValuePair KVP_instancefbfm__1_color;
braids_digital_deriv::FeedbackFm osc;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_fbfm__1_pitch].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instancefbfm__1_pitch,ObjectKvpRoot, "fbfm_1:pitch" ,&parent->PExch[PARAM_INDEX_fbfm__1_pitch], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instancefbfm__1_pitch);
parent->PExch[PARAM_INDEX_fbfm__1_timbre].pfunction = pfun_unsigned_clamp;
  //SetKVP_IPVP(&KVP_instancefbfm__1_timbre,ObjectKvpRoot, "fbfm_1:timbre" ,&parent->PExch[PARAM_INDEX_fbfm__1_timbre], 0, 1<<27);
  //KVP_RegisterObject(&KVP_instancefbfm__1_timbre);
parent->PExch[PARAM_INDEX_fbfm__1_color].pfunction = pfun_unsigned_clamp;
  //SetKVP_IPVP(&KVP_instancefbfm__1_color,ObjectKvpRoot, "fbfm_1:color" ,&parent->PExch[PARAM_INDEX_fbfm__1_color], 0, 1<<27);
  //KVP_RegisterObject(&KVP_instancefbfm__1_color);
osc.Init();
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_pitch,
const int32_t  inlet_timbre,
const int32_t  inlet_color,
int32buffer  & outlet_wave,
int param_pitch,
int param_timbre,
int param_color  ){
osc.set_parameters(__USAT((inlet_timbre+param_timbre)>>12,15),__USAT((inlet_color+param_color)>>12,15));
osc.set_pitch((64<<7)+((param_pitch + inlet_pitch)>>14));
osc.Render(0,&outlet_wave[0],BUFSIZE);
}
}
;class instancea__time{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instancea__time_a;
int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a__time_a].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instancea__time_a,ObjectKvpRoot, "a_time" ,&parent->PExch[PARAM_INDEX_a__time_a], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instancea__time_a);
val = 0;
}
  public: void Dispose() {
}
  public: void dsp (const bool  inlet_trig,
const int32_t  inlet_a,
int32_t  & outlet_env,
int param_a  ){
if (inlet_trig > 0) {
  int32_t t;
  int32_t at = param_a + inlet_a;
  MTOF(-at,t);
  val += t>>6;
}
else {
  val = 0;
}
val = __USAT(val,27);
outlet_env = val;
}
}
;class instancekeyb__1{
  public: // v1
  voice *parent;
int8_t _note;
int32_t _gate;
int32_t _gate2;
uint8_t _velo;
uint8_t _rvelo;

  public: void Init(voice * _parent) {
parent = _parent;
_gate = 0;
_note = 0;

}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_note,
bool  & outlet_gate,
bool  & outlet_gate2,
int32_t  & outlet_velocity,
int32_t  & outlet_releaseVelocity  ){
outlet_note= _note<<21;
outlet_gate= _gate;
outlet_gate2= _gate2;
_gate2 = _gate;
outlet_velocity= _velo<<20;
outlet_releaseVelocity= _rvelo<<20;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ((status == MIDI_NOTE_ON + 0) && (data2)) {
  _velo = data2;
  _note = data1-64;
  _gate = 1<<27;
  _gate2 = 0;
} else if (((status == MIDI_NOTE_ON + 0) && (!data2))||
          (status == MIDI_NOTE_OFF + 0)) {
  if (_note == data1-64) {
    _rvelo = data2;
    _gate = 0;
  }
} else if ((status == 0 + MIDI_CONTROL_CHANGE)&&(data1 == MIDI_C_ALL_NOTES_OFF)) {
  _gate = 0;
}
}
}
}
;class instancea__vel{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instancea__vel_amp;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a__vel_amp].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instancea__vel_amp,ObjectKvpRoot, "a_vel" ,&parent->PExch[PARAM_INDEX_a__vel_amp], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instancea__vel_amp);
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out,
int param_amp  ){
outlet_out= ___SMMUL(param_amp, inlet_in)<<5;

}
}
;class instancevca__1{
  public: // v1
  voice *parent;
   int32_t prev;
    int32_t step;

  public: void Init(voice * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_v,
const int32buffer  inlet_a,
int32buffer  & outlet_o  ){
   step = (inlet_v - prev)>>4;
   int32_t i = prev;
   prev = inlet_v;

int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   outlet_o[buffer_index] =  ___SMMUL(inlet_a[buffer_index],i)<<5;
   i += step;

}
}
}
;class instancecc__1{
  public: // v1
  voice *parent;
int32_t ccv;
int32_t ntrig;

  public: void Init(voice * _parent) {
parent = _parent;
ccv = 100 << 20;

}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_midiCC,
bool  & outlet_trig  ){
outlet_midiCC= ccv;
outlet_trig = ntrig;
ntrig = 0;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ((status == 0 + MIDI_CONTROL_CHANGE)&&(data1 == 7)) { ccv = data2<<20; ntrig = 1;}
}
}
}
;class instancevca__2{
  public: // v1
  voice *parent;
   int32_t prev;
    int32_t step;

  public: void Init(voice * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_v,
const int32buffer  inlet_a,
int32buffer  & outlet_o  ){
   step = (inlet_v - prev)>>4;
   int32_t i = prev;
   prev = inlet_v;

int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   outlet_o[buffer_index] =  ___SMMUL(inlet_a[buffer_index],i)<<5;
   i += step;

}
}
}
;class instanceoutlet__1{
  public: // v1
  voice *parent;
int32buffer _outlet;

  public: void Init(voice * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_outlet  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   _outlet[buffer_index] = inlet_outlet[buffer_index];

}
}
}
;class instanceenv__t{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instanceenv__t_time;
//KeyValuePair KVP_instanceenv__t_vt;
//KeyValuePair KVP_instanceenv__t_env;
int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_env__t_time].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__t_time,ObjectKvpRoot, "env_t:time" ,&parent->PExch[PARAM_INDEX_env__t_time], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__t_time);
parent->PExch[PARAM_INDEX_env__t_vt].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__t_vt,ObjectKvpRoot, "env_t:vt" ,&parent->PExch[PARAM_INDEX_env__t_vt], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__t_vt);
parent->PExch[PARAM_INDEX_env__t_env].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__t_env,ObjectKvpRoot, "env_t:env" ,&parent->PExch[PARAM_INDEX_env__t_env], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__t_env);
val = 0;
}
  public: void Dispose() {
}
  public: void dsp (const bool  inlet_trig,
const int32_t  inlet_vel,
int32_t  & outlet_env,
int param_time,
int param_vt,
int param_env  ){
int32_t vel_vt = ___SMMUL(param_vt, inlet_vel)<<5; // shorten or lengthen time by velo
if (inlet_trig > 0) {
  int32_t t;
  int32_t at = param_time + vel_vt;
  MTOF(-at,t);
  val += t>>6;
}
else {
  val = 0;
}
val = __USAT(val,27);

outlet_env = ___SMMUL(param_env, val)<<5;
}
}
;class instanceenv__c{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instanceenv__c_time;
//KeyValuePair KVP_instanceenv__c_vt;
//KeyValuePair KVP_instanceenv__c_env;
int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_env__c_time].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__c_time,ObjectKvpRoot, "env_c:time" ,&parent->PExch[PARAM_INDEX_env__c_time], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__c_time);
parent->PExch[PARAM_INDEX_env__c_vt].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__c_vt,ObjectKvpRoot, "env_c:vt" ,&parent->PExch[PARAM_INDEX_env__c_vt], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__c_vt);
parent->PExch[PARAM_INDEX_env__c_env].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__c_env,ObjectKvpRoot, "env_c:env" ,&parent->PExch[PARAM_INDEX_env__c_env], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__c_env);
val = 0;
}
  public: void Dispose() {
}
  public: void dsp (const bool  inlet_trig,
const int32_t  inlet_vel,
int32_t  & outlet_env,
int param_time,
int param_vt,
int param_env  ){
int32_t vel_vt = ___SMMUL(param_vt, inlet_vel)<<5; // shorten or lengthen time by velo
if (inlet_trig > 0) {
  int32_t t;
  int32_t at = param_time + vel_vt;
  MTOF(-at,t);
  val += t>>6;
}
else {
  val = 0;
}
val = __USAT(val,27);

outlet_env = ___SMMUL(param_env, val)<<5;
}
}
;/* controller instances */
/* object instances */
     instancefbfm__1 instancefbfm__1_i;
     instancea__time instancea__time_i;
     instancekeyb__1 instancekeyb__1_i;
     instancea__vel instancea__vel_i;
     instancevca__1 instancevca__1_i;
     instancecc__1 instancecc__1_i;
     instancevca__2 instancevca__2_i;
     instanceoutlet__1 instanceoutlet__1_i;
     instanceenv__t instanceenv__t_i;
     instanceenv__c instanceenv__c_i;
/* net latches */
    bool  net2Latch;
    int32_t  net3Latch;
    int32_t  net7Latch;
    int32_t  net9Latch;
    int32_t  net10Latch;
instancealgo__2 *common;
void Init(voice *parent) {
        int i;
        for(i=0;i<NPEXCH;i++){
          PExch[i].pfunction = 0;
        }
   instancefbfm__1_i.Init(parent );
   instancea__time_i.Init(parent );
   instancekeyb__1_i.Init(parent );
   instancea__vel_i.Init(parent );
   instancevca__1_i.Init(parent );
   instancecc__1_i.Init(parent );
   instancevca__2_i.Init(parent );
   instanceoutlet__1_i.Init(parent );
   instanceenv__t_i.Init(parent );
   instanceenv__c_i.Init(parent );
      int k;
      for (k = 0; k < NPEXCH; k++) {
        if (PExch[k].pfunction){
          (PExch[k].pfunction)(&PExch[k]);
        } else {
          PExch[k].finalvalue = PExch[k].value;
        }
      }
}

void dsp(void) {
 int i;
//--------- <nets> -----------//
    int32_t  net0;
    int32_t  net1;
    bool  net2;
    int32_t  net3;
    int32_t  net4;
    int32buffer  net5;
    int32buffer  net6;
    int32_t  net7;
    int32buffer  net8;
    int32_t  net9;
    int32_t  net10;
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instancefbfm__1_i.dsp(net7Latch, net9Latch, net10Latch, net8, PExch[PARAM_INDEX_fbfm__1_pitch].finalvalue, PExch[PARAM_INDEX_fbfm__1_timbre].finalvalue, PExch[PARAM_INDEX_fbfm__1_color].finalvalue);
  instancea__time_i.dsp(net2Latch, net3Latch, net1, PExch[PARAM_INDEX_a__time_a].finalvalue);
  instancekeyb__1_i.dsp(net7, (bool &)UNCONNECTED_OUTPUT, net2, net0, UNCONNECTED_OUTPUT);
  instancea__vel_i.dsp(net0, net3, PExch[PARAM_INDEX_a__vel_amp].finalvalue);
  instancevca__1_i.dsp(net1, net8, net6);
  instancecc__1_i.dsp(net4, (bool &)UNCONNECTED_OUTPUT);
  instancevca__2_i.dsp(net4, net6, net5);
  instanceoutlet__1_i.dsp(net5);
  instanceenv__t_i.dsp(net2, net0, net9, PExch[PARAM_INDEX_env__t_time].finalvalue, PExch[PARAM_INDEX_env__t_vt].finalvalue, PExch[PARAM_INDEX_env__t_env].finalvalue);
  instanceenv__c_i.dsp(net2, net0, net10, PExch[PARAM_INDEX_env__c_time].finalvalue, PExch[PARAM_INDEX_env__c_vt].finalvalue, PExch[PARAM_INDEX_env__c_env].finalvalue);
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
net2Latch = net2;
net3Latch = net3;
net7Latch = net7;
net9Latch = net9;
net10Latch = net10;
//--------- </net latch copy> ----------//
}
void dispose(void) {
 int i;
   instanceenv__c_i.Dispose();
   instanceenv__t_i.Dispose();
   instanceoutlet__1_i.Dispose();
   instancevca__2_i.Dispose();
   instancecc__1_i.Dispose();
   instancevca__1_i.Dispose();
   instancea__vel_i.Dispose();
   instancekeyb__1_i.Dispose();
   instancea__time_i.Dispose();
   instancefbfm__1_i.Dispose();
}
void MidiInHandler(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2){
instancekeyb__1_i.MidiInHandler(dev, port, status, data1, data2);
instancecc__1_i.MidiInHandler(dev, port, status, data1, data2);
}

};
static voice * getVoices(void){
     static voice v[1];
    return v;
}
static void PropagateToVoices(ParameterExchange_t *origin) {
      ParameterExchange_t *pex = (ParameterExchange_t *)origin->finalvalue;
      int vi;
      for (vi = 0; vi < 1; vi++) {
        PExParameterChange(pex,origin->modvalue,0xFFFFFFEE);
          pex = (ParameterExchange_t *)((int)pex + sizeof(voice)); // dirty trick...
      }}
int8_t notePlaying[1];
int32_t voicePriority[1];
int32_t priority;
int32_t sustain;
int8_t pressed[1];

  public: void Init(rootc * _parent) {
parent = _parent;
   int i;
   int j;
   const int32_t *p;
   p = GetInitParams();
   for(j=0;j<11;j++){
      PExch[j].value = p[j];
      PExch[j].modvalue = p[j];
      PExch[j].signals = 0;
      PExch[j].pfunction = 0;
   }
   int32_t *pp = &PExModulationPrevVal[0][0];
   for(j=0;j<1*NMODULATIONSOURCES;j++){
      *pp = 0; pp++;
   }
     displayVector[0] = 0x446F7841;
     displayVector[1] = 0;
     displayVector[2] = 0;
int k;
   for(k=0;k<NPEXCH;k++){
      PExch[k].pfunction = PropagateToVoices;
      PExch[k].finalvalue = (int32_t) (&(getVoices()[0].PExch[k]));
   }
int vi; for(vi=0;vi<1;vi++) {
   voice *v = &getVoices()[vi];
   v->polyIndex = vi;
   v->common = this;
   v->Init(&getVoices()[vi]);
   notePlaying[vi]=0;
   voicePriority[vi]=0;
   for (j = 0; j < v->NPEXCH; j++) {
      v->PExch[j].value = 0;
      v->PExch[j].modvalue = 0;
   }
}
      for (k = 0; k < NPEXCH; k++) {
        if (PExch[k].pfunction){
          (PExch[k].pfunction)(&PExch[k]);
        } else {
          PExch[k].finalvalue = PExch[k].value;
        }
      }
priority=0;
sustain=0;

}
  public: void Dispose() {
int vi; for(vi=0;vi<1;vi++) {
  voice *v = &getVoices()[vi];
  v->dispose();
}

}
  public: void dsp (int32buffer  & outlet_outlet__1  ){
{
      int j;
      for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] = 0;
}
int vi; for(vi=0;vi<1;vi++) {if(!pressed[vi]) continue; getVoices()[vi].dsp();
{
      int j;
      for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += getVoices()[vi].instanceoutlet__1_i._outlet[j];
}
}

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ( 15 > 0 && dev > 0 && 15 != dev) return;
if ( 16 > 0 && port > 0 && 16 != port) return;
if ((status == MIDI_NOTE_ON + 0) && (data2)) {
  int min = 1<<30;
  int mini = 0;
  int i;
  for(i=0;i<1;i++){
    if (voicePriority[i] < min){
      min = voicePriority[i];
      mini = i;
    }
  }
  voicePriority[mini] = 100000+priority++;
  notePlaying[mini] = data1;
  pressed[mini] = 1;
  getVoices()[mini].MidiInHandler(dev, port, status, data1, data2);
} else if (((status == MIDI_NOTE_ON + 0) && (!data2))||
          (status == MIDI_NOTE_OFF + 0)) {
  int i;
  for(i=0;i<1;i++){
    if ((notePlaying[i] == data1) && pressed[i]){
      voicePriority[i] = priority++;
      pressed[i] = 0;
      if (!sustain)
        getVoices()[i].MidiInHandler(dev, port, status, data1, data2);
      }
  }
} else if (status == 0 + MIDI_CONTROL_CHANGE) {
  int i;
  for(i=0;i<1;i++) getVoices()[i].MidiInHandler(dev, port, status, data1, data2);
  if (data1 == 64) {
    if (data2>0) {
      sustain = 1;
    } else if (sustain == 1) {
      sustain = 0;
      for(i=0;i<1;i++){
        if (pressed[i] == 0) {
          getVoices()[i].MidiInHandler(dev, port, MIDI_NOTE_ON + 0, notePlaying[i], 0);
        }
      }
    }
  }
} else {  int i;   for(i=0;i<1;i++) getVoices()[i].MidiInHandler(dev, port, status, data1, data2);
}
}
}
}
;class instancealgo__3{
  public: // v1
  rootc *parent;
   static int32_t * GetInitParams(void){
      static const int32_t p[13]= {
      0,
      0,
      0,
      69206016,
      -132120576,
      -134217728,
      0,
      0,
      0,
      0,
      0,
      0,
      0
      };
      return (int32_t *)&p[0];
   }    static const uint32_t NPEXCH = 13;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 0;
    static const uint32_t NPRESET_ENTRIES = 0;
    static const uint32_t NMODULATIONSOURCES = 0;
    static const uint32_t NMODULATIONTARGETS = 0;
    int32_t PExModulationPrevVal[1][NMODULATIONSOURCES];
/* parameter instance indices */
static const int PARAM_INDEX_mds__1_pitch = 0;
static const int PARAM_INDEX_mds__1_detune = 1;
static const int PARAM_INDEX_mds__1_fade = 2;
static const int PARAM_INDEX_mds__1_saw = 3;
static const int PARAM_INDEX_mds__1_dip = 4;
static const int PARAM_INDEX_a__time_a = 5;
static const int PARAM_INDEX_a__vel_amp = 6;
static const int PARAM_INDEX_env__s_time = 7;
static const int PARAM_INDEX_env__s_vt = 8;
static const int PARAM_INDEX_env__s_env = 9;
static const int PARAM_INDEX_env__d_time = 10;
static const int PARAM_INDEX_env__d_vt = 11;
static const int PARAM_INDEX_env__d_env = 12;
   static const int32_t * GetPresets(void){
      static const int32_t p[NPRESETS][NPRESET_ENTRIES][2] = {
      };
   return &p[0][0][0];
   };
void ApplyPreset(int index){
   if (!index) {
     int i;
     int32_t *p = GetInitParams();
     for(i=0;i<NPEXCH;i++){
        PExParameterChange(&PExch[i],p[i],0xFFEF);
     }
   }
   index--;
   if (index < NPRESETS) {
     PresetParamChange_t *pa = (PresetParamChange_t *)(GetPresets());
     PresetParamChange_t *p = &pa[index*NPRESET_ENTRIES];
       int i;
       for(i=0;i<NPRESET_ENTRIES;i++){
         PresetParamChange_t *pp = &p[i];
         if ((pp->pexIndex>=0)&&(pp->pexIndex<NPEXCH)) {
           PExParameterChange(&PExch[pp->pexIndex],pp->value,0xFFEF);         }
         else break;
       }
   }
}
   static PExModulationTarget_t * GetModulationTable(void){
    static const PExModulationTarget_t PExModulationSources[NMODULATIONSOURCES][NMODULATIONTARGETS] = 
{};
   return (PExModulationTarget_t *)&PExModulationSources[0][0];
   };
class voice {
   public:
   int polyIndex;
    static const uint32_t NPEXCH = 13;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 0;
    static const uint32_t NPRESET_ENTRIES = 0;
    static const uint32_t NMODULATIONSOURCES = 0;
    static const uint32_t NMODULATIONTARGETS = 0;
/* modsource defines */
/* parameter instance indices */
static const int PARAM_INDEX_mds__1_pitch = 0;
static const int PARAM_INDEX_mds__1_detune = 1;
static const int PARAM_INDEX_mds__1_fade = 2;
static const int PARAM_INDEX_mds__1_saw = 3;
static const int PARAM_INDEX_mds__1_dip = 4;
static const int PARAM_INDEX_a__time_a = 5;
static const int PARAM_INDEX_a__vel_amp = 6;
static const int PARAM_INDEX_env__s_time = 7;
static const int PARAM_INDEX_env__s_vt = 8;
static const int PARAM_INDEX_env__s_env = 9;
static const int PARAM_INDEX_env__d_time = 10;
static const int PARAM_INDEX_env__d_vt = 11;
static const int PARAM_INDEX_env__d_env = 12;
/* controller classes */
/* object classes */
class instancemds__1{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instancemds__1_pitch;
//KeyValuePair KVP_instancemds__1_detune;
//KeyValuePair KVP_instancemds__1_fade;
//KeyValuePair KVP_instancemds__1_saw;
//KeyValuePair KVP_instancemds__1_dip;
uint32_t Phs1;
uint32_t Phs2;
bool sel;
bool trg;
int32_t frq1;
int32_t frq2;
int32_t mix;
int32_t v30=1<<30;
int32_t v19=1<<19;
int32_t v27=1<<27;
int32_t wave;
int32_t hp;
int32_t prv;
int32_t lp;
int32_t HP;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_mds__1_pitch].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instancemds__1_pitch,ObjectKvpRoot, "mds_1:pitch" ,&parent->PExch[PARAM_INDEX_mds__1_pitch], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instancemds__1_pitch);
parent->PExch[PARAM_INDEX_mds__1_detune].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instancemds__1_detune,ObjectKvpRoot, "mds_1:detune" ,&parent->PExch[PARAM_INDEX_mds__1_detune], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instancemds__1_detune);
parent->PExch[PARAM_INDEX_mds__1_fade].pfunction = pfun_unsigned_clamp;
  //SetKVP_IPVP(&KVP_instancemds__1_fade,ObjectKvpRoot, "mds_1:fade" ,&parent->PExch[PARAM_INDEX_mds__1_fade], 0, 1<<27);
  //KVP_RegisterObject(&KVP_instancemds__1_fade);
parent->PExch[PARAM_INDEX_mds__1_saw].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instancemds__1_saw,ObjectKvpRoot, "mds_1:saw" ,&parent->PExch[PARAM_INDEX_mds__1_saw], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instancemds__1_saw);
parent->PExch[PARAM_INDEX_mds__1_dip].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instancemds__1_dip,ObjectKvpRoot, "mds_1:dip" ,&parent->PExch[PARAM_INDEX_mds__1_dip], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instancemds__1_dip);
Phs1 = 0;
Phs2 = 0;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_pitch,
const int32buffer  inlet_saw,
const int32buffer  inlet_dip,
const bool  inlet_gate,
int32buffer  & outlet_wave,
int32buffer  & outlet_mix,
int param_pitch,
int param_detune,
int param_fade,
int param_saw,
int param_dip  ){
int32_t detune=param_detune>>7;
if((inlet_gate>0)&&!trg){
	trg=1;
	sel=(int)((int)sel+1)&1;
	if(sel==1){
	Phs2=Phs1;
	//MTOFEXTENDED(param_pitch + inlet_pitch,frq2);
	}
	else{
	Phs1=Phs2;
	//MTOFEXTENDED(param_pitch + inlet_pitch,frq1);
	}
}
else if(inlet_gate==0){trg=0;}

if(sel==1)
{	
	MTOFEXTENDED(param_pitch + inlet_pitch+detune,frq2);
}
else
{
	MTOFEXTENDED(param_pitch + inlet_pitch,frq1);
}

int32_t rate=v19+(v27-param_fade>>4);
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
int32_t dip=param_dip+inlet_dip[buffer_index];
int32_t FM1=___SMMUL(dip,frq1)<<4;
int32_t FM2=___SMMUL(dip,frq2)<<4;

Phs1 += frq1+(___SMMUL(wave,FM1)<<5);
Phs2 += frq2+(___SMMUL(wave,FM2)<<5);
int32_t r1;
int32_t r2;
int32_t saw=inlet_saw[buffer_index]+param_saw;
SINE2TINTERP(Phs1+(___SMMUL(lp,saw)<<6),r1)
SINE2TINTERP(Phs2+(___SMMUL(lp,saw)<<6),r2)
r1=r1>>4;
r2=r2>>4;
mix=__USAT(mix+(sel>0?rate:-rate),30);
wave= r1+___SMMUL(r2-r1<<2,mix);
int32_t ring=-___SMMUL(wave<<3,(wave>0?wave:-wave)<<2);
HP+=ring-HP>>9;
ring-=HP;
outlet_wave[buffer_index]=wave;
wave=wave+ring<<3;

hp+=wave-hp>>9;
wave-=hp;
lp+=(wave-lp)>>2;
wave=lp;
outlet_mix[buffer_index]=mix>>4;
}
}
}
;class instancekeyb__1{
  public: // v1
  voice *parent;
int8_t _note;
int32_t _gate;
int32_t _gate2;
uint8_t _velo;
uint8_t _rvelo;

  public: void Init(voice * _parent) {
parent = _parent;
_gate = 0;
_note = 0;

}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_note,
bool  & outlet_gate,
bool  & outlet_gate2,
int32_t  & outlet_velocity,
int32_t  & outlet_releaseVelocity  ){
outlet_note= _note<<21;
outlet_gate= _gate;
outlet_gate2= _gate2;
_gate2 = _gate;
outlet_velocity= _velo<<20;
outlet_releaseVelocity= _rvelo<<20;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ((status == MIDI_NOTE_ON + 0) && (data2)) {
  _velo = data2;
  _note = data1-64;
  _gate = 1<<27;
  _gate2 = 0;
} else if (((status == MIDI_NOTE_ON + 0) && (!data2))||
          (status == MIDI_NOTE_OFF + 0)) {
  if (_note == data1-64) {
    _rvelo = data2;
    _gate = 0;
  }
} else if ((status == 0 + MIDI_CONTROL_CHANGE)&&(data1 == MIDI_C_ALL_NOTES_OFF)) {
  _gate = 0;
}
}
}
}
;class instancea__time{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instancea__time_a;
int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a__time_a].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instancea__time_a,ObjectKvpRoot, "a_time" ,&parent->PExch[PARAM_INDEX_a__time_a], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instancea__time_a);
val = 0;
}
  public: void Dispose() {
}
  public: void dsp (const bool  inlet_trig,
const int32_t  inlet_a,
int32_t  & outlet_env,
int param_a  ){
if (inlet_trig > 0) {
  int32_t t;
  int32_t at = param_a + inlet_a;
  MTOF(-at,t);
  val += t>>6;
}
else {
  val = 0;
}
val = __USAT(val,27);
outlet_env = val;
}
}
;class instancea__vel{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instancea__vel_amp;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a__vel_amp].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instancea__vel_amp,ObjectKvpRoot, "a_vel" ,&parent->PExch[PARAM_INDEX_a__vel_amp], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instancea__vel_amp);
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out,
int param_amp  ){
outlet_out= ___SMMUL(param_amp, inlet_in)<<5;

}
}
;class instancevca__1{
  public: // v1
  voice *parent;
   int32_t prev;
    int32_t step;

  public: void Init(voice * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_v,
const int32buffer  inlet_a,
int32buffer  & outlet_o  ){
   step = (inlet_v - prev)>>4;
   int32_t i = prev;
   prev = inlet_v;

int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   outlet_o[buffer_index] =  ___SMMUL(inlet_a[buffer_index],i)<<5;
   i += step;

}
}
}
;class instancecc__1{
  public: // v1
  voice *parent;
int32_t ccv;
int32_t ntrig;

  public: void Init(voice * _parent) {
parent = _parent;
ccv = 100 << 20;

}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_midiCC,
bool  & outlet_trig  ){
outlet_midiCC= ccv;
outlet_trig = ntrig;
ntrig = 0;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ((status == 0 + MIDI_CONTROL_CHANGE)&&(data1 == 7)) { ccv = data2<<20; ntrig = 1;}
}
}
}
;class instancevca__2{
  public: // v1
  voice *parent;
   int32_t prev;
    int32_t step;

  public: void Init(voice * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_v,
const int32buffer  inlet_a,
int32buffer  & outlet_o  ){
   step = (inlet_v - prev)>>4;
   int32_t i = prev;
   prev = inlet_v;

int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   outlet_o[buffer_index] =  ___SMMUL(inlet_a[buffer_index],i)<<5;
   i += step;

}
}
}
;class instanceoutlet__1{
  public: // v1
  voice *parent;
int32buffer _outlet;

  public: void Init(voice * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_outlet  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   _outlet[buffer_index] = inlet_outlet[buffer_index];

}
}
}
;class instanceenv__s{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instanceenv__s_time;
//KeyValuePair KVP_instanceenv__s_vt;
//KeyValuePair KVP_instanceenv__s_env;
int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_env__s_time].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__s_time,ObjectKvpRoot, "env_s:time" ,&parent->PExch[PARAM_INDEX_env__s_time], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__s_time);
parent->PExch[PARAM_INDEX_env__s_vt].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__s_vt,ObjectKvpRoot, "env_s:vt" ,&parent->PExch[PARAM_INDEX_env__s_vt], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__s_vt);
parent->PExch[PARAM_INDEX_env__s_env].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__s_env,ObjectKvpRoot, "env_s:env" ,&parent->PExch[PARAM_INDEX_env__s_env], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__s_env);
val = 0;
}
  public: void Dispose() {
}
  public: void dsp (const bool  inlet_trig,
const int32_t  inlet_vel,
int32_t  & outlet_env,
int param_time,
int param_vt,
int param_env  ){
int32_t vel_vt = ___SMMUL(param_vt, inlet_vel)<<5; // shorten or lengthen time by velo
if (inlet_trig > 0) {
  int32_t t;
  int32_t at = param_time + vel_vt;
  MTOF(-at,t);
  val += t>>6;
}
else {
  val = 0;
}
val = __USAT(val,27);

outlet_env = ___SMMUL(param_env, val)<<5;
}
}
;class instancenointerp__2{
  public: // v1
  voice *parent;
  public: void Init(voice * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_i,
int32buffer  & outlet_o  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   outlet_o[buffer_index] = inlet_i;

}
}
}
;class instanceenv__d{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instanceenv__d_time;
//KeyValuePair KVP_instanceenv__d_vt;
//KeyValuePair KVP_instanceenv__d_env;
int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_env__d_time].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__d_time,ObjectKvpRoot, "env_d:time" ,&parent->PExch[PARAM_INDEX_env__d_time], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__d_time);
parent->PExch[PARAM_INDEX_env__d_vt].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__d_vt,ObjectKvpRoot, "env_d:vt" ,&parent->PExch[PARAM_INDEX_env__d_vt], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__d_vt);
parent->PExch[PARAM_INDEX_env__d_env].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__d_env,ObjectKvpRoot, "env_d:env" ,&parent->PExch[PARAM_INDEX_env__d_env], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__d_env);
val = 0;
}
  public: void Dispose() {
}
  public: void dsp (const bool  inlet_trig,
const int32_t  inlet_vel,
int32_t  & outlet_env,
int param_time,
int param_vt,
int param_env  ){
int32_t vel_vt = ___SMMUL(param_vt, inlet_vel)<<5; // shorten or lengthen time by velo
if (inlet_trig > 0) {
  int32_t t;
  int32_t at = param_time + vel_vt;
  MTOF(-at,t);
  val += t>>6;
}
else {
  val = 0;
}
val = __USAT(val,27);

outlet_env = ___SMMUL(param_env, val)<<5;
}
}
;class instancenointerp__1{
  public: // v1
  voice *parent;
  public: void Init(voice * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_i,
int32buffer  & outlet_o  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   outlet_o[buffer_index] = inlet_i;

}
}
}
;/* controller instances */
/* object instances */
     instancemds__1 instancemds__1_i;
     instancekeyb__1 instancekeyb__1_i;
     instancea__time instancea__time_i;
     instancea__vel instancea__vel_i;
     instancevca__1 instancevca__1_i;
     instancecc__1 instancecc__1_i;
     instancevca__2 instancevca__2_i;
     instanceoutlet__1 instanceoutlet__1_i;
     instanceenv__s instanceenv__s_i;
     instancenointerp__2 instancenointerp__2_i;
     instanceenv__d instanceenv__d_i;
     instancenointerp__1 instancenointerp__1_i;
/* net latches */
    bool  net2Latch;
    int32_t  net3Latch;
    int32buffer  net7Latch;
    int32buffer  net8Latch;
    int32_t  net9Latch;
instancealgo__3 *common;
void Init(voice *parent) {
        int i;
        for(i=0;i<NPEXCH;i++){
          PExch[i].pfunction = 0;
        }
   instancemds__1_i.Init(parent );
   instancekeyb__1_i.Init(parent );
   instancea__time_i.Init(parent );
   instancea__vel_i.Init(parent );
   instancevca__1_i.Init(parent );
   instancecc__1_i.Init(parent );
   instancevca__2_i.Init(parent );
   instanceoutlet__1_i.Init(parent );
   instanceenv__s_i.Init(parent );
   instancenointerp__2_i.Init(parent );
   instanceenv__d_i.Init(parent );
   instancenointerp__1_i.Init(parent );
      int k;
      for (k = 0; k < NPEXCH; k++) {
        if (PExch[k].pfunction){
          (PExch[k].pfunction)(&PExch[k]);
        } else {
          PExch[k].finalvalue = PExch[k].value;
        }
      }
}

void dsp(void) {
 int i;
//--------- <nets> -----------//
    int32_t  net0;
    int32_t  net1;
    bool  net2;
    int32_t  net3;
    int32_t  net4;
    int32buffer  net5;
    int32buffer  net6;
    int32buffer  net7;
    int32buffer  net8;
    int32_t  net9;
    int32buffer  net10;
    int32_t  net11;
    int32_t  net12;
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instancemds__1_i.dsp(net9Latch, net8Latch, net7Latch, net2Latch, net10, UNCONNECTED_OUTPUT_BUFFER, PExch[PARAM_INDEX_mds__1_pitch].finalvalue, PExch[PARAM_INDEX_mds__1_detune].finalvalue, PExch[PARAM_INDEX_mds__1_fade].finalvalue, PExch[PARAM_INDEX_mds__1_saw].finalvalue, PExch[PARAM_INDEX_mds__1_dip].finalvalue);
  instancekeyb__1_i.dsp(net9, (bool &)UNCONNECTED_OUTPUT, net2, net0, UNCONNECTED_OUTPUT);
  instancea__time_i.dsp(net2, net3Latch, net1, PExch[PARAM_INDEX_a__time_a].finalvalue);
  instancea__vel_i.dsp(net0, net3, PExch[PARAM_INDEX_a__vel_amp].finalvalue);
  instancevca__1_i.dsp(net1, net10, net6);
  instancecc__1_i.dsp(net4, (bool &)UNCONNECTED_OUTPUT);
  instancevca__2_i.dsp(net4, net6, net5);
  instanceoutlet__1_i.dsp(net5);
  instanceenv__s_i.dsp(net2, net0, net11, PExch[PARAM_INDEX_env__s_time].finalvalue, PExch[PARAM_INDEX_env__s_vt].finalvalue, PExch[PARAM_INDEX_env__s_env].finalvalue);
  instancenointerp__2_i.dsp(net11, net8);
  instanceenv__d_i.dsp(net2, net0, net12, PExch[PARAM_INDEX_env__d_time].finalvalue, PExch[PARAM_INDEX_env__d_vt].finalvalue, PExch[PARAM_INDEX_env__d_env].finalvalue);
  instancenointerp__1_i.dsp(net12, net7);
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
net2Latch = net2;
net3Latch = net3;
   for(i=0;i<BUFSIZE;i++)
      net7Latch[i]=net7[i];
   for(i=0;i<BUFSIZE;i++)
      net8Latch[i]=net8[i];
net9Latch = net9;
//--------- </net latch copy> ----------//
}
void dispose(void) {
 int i;
   instancenointerp__1_i.Dispose();
   instanceenv__d_i.Dispose();
   instancenointerp__2_i.Dispose();
   instanceenv__s_i.Dispose();
   instanceoutlet__1_i.Dispose();
   instancevca__2_i.Dispose();
   instancecc__1_i.Dispose();
   instancevca__1_i.Dispose();
   instancea__vel_i.Dispose();
   instancea__time_i.Dispose();
   instancekeyb__1_i.Dispose();
   instancemds__1_i.Dispose();
}
void MidiInHandler(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2){
instancekeyb__1_i.MidiInHandler(dev, port, status, data1, data2);
instancecc__1_i.MidiInHandler(dev, port, status, data1, data2);
}

};
static voice * getVoices(void){
     static voice v[1];
    return v;
}
static void PropagateToVoices(ParameterExchange_t *origin) {
      ParameterExchange_t *pex = (ParameterExchange_t *)origin->finalvalue;
      int vi;
      for (vi = 0; vi < 1; vi++) {
        PExParameterChange(pex,origin->modvalue,0xFFFFFFEE);
          pex = (ParameterExchange_t *)((int)pex + sizeof(voice)); // dirty trick...
      }}
int8_t notePlaying[1];
int32_t voicePriority[1];
int32_t priority;
int32_t sustain;
int8_t pressed[1];

  public: void Init(rootc * _parent) {
parent = _parent;
   int i;
   int j;
   const int32_t *p;
   p = GetInitParams();
   for(j=0;j<13;j++){
      PExch[j].value = p[j];
      PExch[j].modvalue = p[j];
      PExch[j].signals = 0;
      PExch[j].pfunction = 0;
   }
   int32_t *pp = &PExModulationPrevVal[0][0];
   for(j=0;j<1*NMODULATIONSOURCES;j++){
      *pp = 0; pp++;
   }
     displayVector[0] = 0x446F7841;
     displayVector[1] = 0;
     displayVector[2] = 0;
int k;
   for(k=0;k<NPEXCH;k++){
      PExch[k].pfunction = PropagateToVoices;
      PExch[k].finalvalue = (int32_t) (&(getVoices()[0].PExch[k]));
   }
int vi; for(vi=0;vi<1;vi++) {
   voice *v = &getVoices()[vi];
   v->polyIndex = vi;
   v->common = this;
   v->Init(&getVoices()[vi]);
   notePlaying[vi]=0;
   voicePriority[vi]=0;
   for (j = 0; j < v->NPEXCH; j++) {
      v->PExch[j].value = 0;
      v->PExch[j].modvalue = 0;
   }
}
      for (k = 0; k < NPEXCH; k++) {
        if (PExch[k].pfunction){
          (PExch[k].pfunction)(&PExch[k]);
        } else {
          PExch[k].finalvalue = PExch[k].value;
        }
      }
priority=0;
sustain=0;

}
  public: void Dispose() {
int vi; for(vi=0;vi<1;vi++) {
  voice *v = &getVoices()[vi];
  v->dispose();
}

}
  public: void dsp (int32buffer  & outlet_outlet__1  ){
{
      int j;
      for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] = 0;
}
int vi; for(vi=0;vi<1;vi++) {if(!pressed[vi]) continue; getVoices()[vi].dsp();
{
      int j;
      for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += getVoices()[vi].instanceoutlet__1_i._outlet[j];
}
}

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ( 15 > 0 && dev > 0 && 15 != dev) return;
if ( 16 > 0 && port > 0 && 16 != port) return;
if ((status == MIDI_NOTE_ON + 0) && (data2)) {
  int min = 1<<30;
  int mini = 0;
  int i;
  for(i=0;i<1;i++){
    if (voicePriority[i] < min){
      min = voicePriority[i];
      mini = i;
    }
  }
  voicePriority[mini] = 100000+priority++;
  notePlaying[mini] = data1;
  pressed[mini] = 1;
  getVoices()[mini].MidiInHandler(dev, port, status, data1, data2);
} else if (((status == MIDI_NOTE_ON + 0) && (!data2))||
          (status == MIDI_NOTE_OFF + 0)) {
  int i;
  for(i=0;i<1;i++){
    if ((notePlaying[i] == data1) && pressed[i]){
      voicePriority[i] = priority++;
      pressed[i] = 0;
      if (!sustain)
        getVoices()[i].MidiInHandler(dev, port, status, data1, data2);
      }
  }
} else if (status == 0 + MIDI_CONTROL_CHANGE) {
  int i;
  for(i=0;i<1;i++) getVoices()[i].MidiInHandler(dev, port, status, data1, data2);
  if (data1 == 64) {
    if (data2>0) {
      sustain = 1;
    } else if (sustain == 1) {
      sustain = 0;
      for(i=0;i<1;i++){
        if (pressed[i] == 0) {
          getVoices()[i].MidiInHandler(dev, port, MIDI_NOTE_ON + 0, notePlaying[i], 0);
        }
      }
    }
  }
} else {  int i;   for(i=0;i<1;i++) getVoices()[i].MidiInHandler(dev, port, status, data1, data2);
}
}
}
}
;class instancealgo__4{
  public: // v1
  rootc *parent;
   static int32_t * GetInitParams(void){
      static const int32_t p[20]= {
      134217728,
      0,
      0,
      71303168,
      134217728,
      0,
      0,
      0,
      -134217728,
      0,
      0,
      75497472,
      0,
      -111149056,
      44040192,
      0,
      109051904,
      -6291456,
      0,
      69206016
      };
      return (int32_t *)&p[0];
   }    static const uint32_t NPEXCH = 20;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 0;
    static const uint32_t NPRESET_ENTRIES = 0;
    static const uint32_t NMODULATIONSOURCES = 0;
    static const uint32_t NMODULATIONTARGETS = 0;
    int32_t PExModulationPrevVal[1][NMODULATIONSOURCES];
/* parameter instance indices */
static const int PARAM_INDEX_wavemix_sin = 0;
static const int PARAM_INDEX_wavemix_saw = 1;
static const int PARAM_INDEX_sine__1_pitch = 2;
static const int PARAM_INDEX_sineslope__1_gain = 3;
static const int PARAM_INDEX_sineslope__1_clipH = 4;
static const int PARAM_INDEX_sineslope__1_clipL = 5;
static const int PARAM_INDEX_sineslope__1_strength = 6;
static const int PARAM_INDEX_sineslope__1_halfout = 7;
static const int PARAM_INDEX_a__time_a = 8;
static const int PARAM_INDEX_a__vel_amp = 9;
static const int PARAM_INDEX_saw__1_pitch = 10;
static const int PARAM_INDEX_env__g_time = 11;
static const int PARAM_INDEX_env__g_vt = 12;
static const int PARAM_INDEX_env__g_env = 13;
static const int PARAM_INDEX_env__c_time = 14;
static const int PARAM_INDEX_env__c_vt = 15;
static const int PARAM_INDEX_env__c_env = 16;
static const int PARAM_INDEX_env__s_time = 17;
static const int PARAM_INDEX_env__s_vt = 18;
static const int PARAM_INDEX_env__s_env = 19;
   static const int32_t * GetPresets(void){
      static const int32_t p[NPRESETS][NPRESET_ENTRIES][2] = {
      };
   return &p[0][0][0];
   };
void ApplyPreset(int index){
   if (!index) {
     int i;
     int32_t *p = GetInitParams();
     for(i=0;i<NPEXCH;i++){
        PExParameterChange(&PExch[i],p[i],0xFFEF);
     }
   }
   index--;
   if (index < NPRESETS) {
     PresetParamChange_t *pa = (PresetParamChange_t *)(GetPresets());
     PresetParamChange_t *p = &pa[index*NPRESET_ENTRIES];
       int i;
       for(i=0;i<NPRESET_ENTRIES;i++){
         PresetParamChange_t *pp = &p[i];
         if ((pp->pexIndex>=0)&&(pp->pexIndex<NPEXCH)) {
           PExParameterChange(&PExch[pp->pexIndex],pp->value,0xFFEF);         }
         else break;
       }
   }
}
   static PExModulationTarget_t * GetModulationTable(void){
    static const PExModulationTarget_t PExModulationSources[NMODULATIONSOURCES][NMODULATIONTARGETS] = 
{};
   return (PExModulationTarget_t *)&PExModulationSources[0][0];
   };
class voice {
   public:
   int polyIndex;
    static const uint32_t NPEXCH = 20;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 0;
    static const uint32_t NPRESET_ENTRIES = 0;
    static const uint32_t NMODULATIONSOURCES = 0;
    static const uint32_t NMODULATIONTARGETS = 0;
/* modsource defines */
/* parameter instance indices */
static const int PARAM_INDEX_wavemix_sin = 0;
static const int PARAM_INDEX_wavemix_saw = 1;
static const int PARAM_INDEX_sine__1_pitch = 2;
static const int PARAM_INDEX_sineslope__1_gain = 3;
static const int PARAM_INDEX_sineslope__1_clipH = 4;
static const int PARAM_INDEX_sineslope__1_clipL = 5;
static const int PARAM_INDEX_sineslope__1_strength = 6;
static const int PARAM_INDEX_sineslope__1_halfout = 7;
static const int PARAM_INDEX_a__time_a = 8;
static const int PARAM_INDEX_a__vel_amp = 9;
static const int PARAM_INDEX_saw__1_pitch = 10;
static const int PARAM_INDEX_env__g_time = 11;
static const int PARAM_INDEX_env__g_vt = 12;
static const int PARAM_INDEX_env__g_env = 13;
static const int PARAM_INDEX_env__c_time = 14;
static const int PARAM_INDEX_env__c_vt = 15;
static const int PARAM_INDEX_env__c_env = 16;
static const int PARAM_INDEX_env__s_time = 17;
static const int PARAM_INDEX_env__s_vt = 18;
static const int PARAM_INDEX_env__s_env = 19;
/* controller classes */
/* object classes */
class instancewavemix{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instancewavemix_sin;
//KeyValuePair KVP_instancewavemix_saw;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_wavemix_sin].pfunction = pfun_unsigned_clamp_fullrange;
  //SetKVP_IPVP(&KVP_instancewavemix_sin,ObjectKvpRoot, "wavemix:sin" ,&parent->PExch[PARAM_INDEX_wavemix_sin], 0, 1<<27);
  //KVP_RegisterObject(&KVP_instancewavemix_sin);
parent->PExch[PARAM_INDEX_wavemix_saw].pfunction = pfun_unsigned_clamp_fullrange;
  //SetKVP_IPVP(&KVP_instancewavemix_saw,ObjectKvpRoot, "wavemix:saw" ,&parent->PExch[PARAM_INDEX_wavemix_saw], 0, 1<<27);
  //KVP_RegisterObject(&KVP_instancewavemix_saw);
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_in1,
const int32buffer  inlet_in2,
int32buffer  & outlet_out,
int param_sin,
int param_saw  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
int32_t accum = ___SMMUL(inlet_in1[buffer_index],param_sin);
accum = ___SMMLA(inlet_in2[buffer_index],param_saw,accum);
outlet_out[buffer_index]= __SSAT((accum<<1),28);
}
}
}
;class instancesine__1{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instancesine__1_pitch;
uint32_t Phase;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_sine__1_pitch].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instancesine__1_pitch,ObjectKvpRoot, "sine_1" ,&parent->PExch[PARAM_INDEX_sine__1_pitch], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instancesine__1_pitch);
Phase = 0;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_pitch,
const int32buffer  inlet_freq,
const int32buffer  inlet_phase,
int32buffer  & outlet_wave,
int param_pitch  ){
   int32_t freq;
   MTOFEXTENDED(param_pitch + inlet_pitch,freq);

int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
Phase += freq + inlet_freq[buffer_index];
int32_t r;
int32_t p2 = Phase + (inlet_phase[buffer_index]<<4);
SINE2TINTERP(p2,r)
outlet_wave[buffer_index]= (r>>4);

}
}
}
;class instancesineslope__1{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instancesineslope__1_gain;
//KeyValuePair KVP_instancesineslope__1_clipH;
//KeyValuePair KVP_instancesineslope__1_clipL;
//KeyValuePair KVP_instancesineslope__1_strength;
//KeyValuePair KVP_instancesineslope__1_halfout;
int32_t pv1;
int32_t pv2;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_sineslope__1_gain].pfunction = pfun_unsigned_clamp;
  //SetKVP_IPVP(&KVP_instancesineslope__1_gain,ObjectKvpRoot, "sineslope_1:gain" ,&parent->PExch[PARAM_INDEX_sineslope__1_gain], 0, 1<<27);
  //KVP_RegisterObject(&KVP_instancesineslope__1_gain);
parent->PExch[PARAM_INDEX_sineslope__1_clipH].pfunction = pfun_unsigned_clamp;
  //SetKVP_IPVP(&KVP_instancesineslope__1_clipH,ObjectKvpRoot, "sineslope_1:clipH" ,&parent->PExch[PARAM_INDEX_sineslope__1_clipH], 0, 1<<27);
  //KVP_RegisterObject(&KVP_instancesineslope__1_clipH);
parent->PExch[PARAM_INDEX_sineslope__1_clipL].pfunction = pfun_unsigned_clamp;
  //SetKVP_IPVP(&KVP_instancesineslope__1_clipL,ObjectKvpRoot, "sineslope_1:clipL" ,&parent->PExch[PARAM_INDEX_sineslope__1_clipL], 0, 1<<27);
  //KVP_RegisterObject(&KVP_instancesineslope__1_clipL);
parent->PExch[PARAM_INDEX_sineslope__1_strength].pfunction = pfun_unsigned_clamp;
  //SetKVP_IPVP(&KVP_instancesineslope__1_strength,ObjectKvpRoot, "sineslope_1:strength" ,&parent->PExch[PARAM_INDEX_sineslope__1_strength], 0, 1<<27);
  //KVP_RegisterObject(&KVP_instancesineslope__1_strength);
    parent->PExch[PARAM_INDEX_sineslope__1_halfout].signals = 0;
    //SetKVP_IPVP(&KVP_instancesineslope__1_halfout,ObjectKvpRoot, "KVP_instancesineslope__1_halfout" ,&parent->PExch[PARAM_INDEX_sineslope__1_halfout],0,65535);
  //KVP_RegisterObject(&KVP_instancesineslope__1_halfout);
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_in,
const int32_t  inlet_gain,
const int32_t  inlet_clip,
const int32_t  inlet_strength,
int32buffer  & outlet_out,
int param_gain,
int param_clipH,
int param_clipL,
int param_strength,
int param_halfout  ){
float32_t STR=param_strength+inlet_strength>>3;
STR=3+STR/(1<<16);
int32_t gain=__USAT(param_gain+inlet_gain,27);
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
int32_t in=inlet_in[buffer_index];
in+=___SMMUL(in<<3,gain<<4);
int32_t A=in;
int32_t clipH=param_clipH+inlet_clip-(gain>>2);
clipH=___SMMUL(clipH<<3,clipH<<2);
int32_t clipL=param_clipL+inlet_clip-(gain>>2);
clipL=___SMMUL(clipL<<3,clipL<<2);
A=A>clipH?clipH:A;
A=A<-clipL?-clipL:A;
int32_t B=in-A;
int32_t r1;
if(B>0){
SINE2TINTERP(((int32_t)((B>>5)*STR)<<5)+(1<<31),r1)}
else{SINE2TINTERP(((int32_t)((B>>5)*STR)<<5)-(1<<31),r1)}
r1=(r1>>2)/STR;
//r1=___SMMUL(r1>>1,(1<<27)-(param_gain>>2)<<2);
outlet_out[buffer_index]=A-r1>>param_halfout;
}
}
}
;class instancea__time{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instancea__time_a;
int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a__time_a].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instancea__time_a,ObjectKvpRoot, "a_time" ,&parent->PExch[PARAM_INDEX_a__time_a], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instancea__time_a);
val = 0;
}
  public: void Dispose() {
}
  public: void dsp (const bool  inlet_trig,
const int32_t  inlet_a,
int32_t  & outlet_env,
int param_a  ){
if (inlet_trig > 0) {
  int32_t t;
  int32_t at = param_a + inlet_a;
  MTOF(-at,t);
  val += t>>6;
}
else {
  val = 0;
}
val = __USAT(val,27);
outlet_env = val;
}
}
;class instancea__vel{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instancea__vel_amp;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a__vel_amp].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instancea__vel_amp,ObjectKvpRoot, "a_vel" ,&parent->PExch[PARAM_INDEX_a__vel_amp], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instancea__vel_amp);
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out,
int param_amp  ){
outlet_out= ___SMMUL(param_amp, inlet_in)<<5;

}
}
;class instancevca__1{
  public: // v1
  voice *parent;
   int32_t prev;
    int32_t step;

  public: void Init(voice * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_v,
const int32buffer  inlet_a,
int32buffer  & outlet_o  ){
   step = (inlet_v - prev)>>4;
   int32_t i = prev;
   prev = inlet_v;

int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   outlet_o[buffer_index] =  ___SMMUL(inlet_a[buffer_index],i)<<5;
   i += step;

}
}
}
;class instancecc__1{
  public: // v1
  voice *parent;
int32_t ccv;
int32_t ntrig;

  public: void Init(voice * _parent) {
parent = _parent;
ccv = 100 << 20;

}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_midiCC,
bool  & outlet_trig  ){
outlet_midiCC= ccv;
outlet_trig = ntrig;
ntrig = 0;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ((status == 0 + MIDI_CONTROL_CHANGE)&&(data1 == 7)) { ccv = data2<<20; ntrig = 1;}
}
}
}
;class instancevca__2{
  public: // v1
  voice *parent;
   int32_t prev;
    int32_t step;

  public: void Init(voice * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_v,
const int32buffer  inlet_a,
int32buffer  & outlet_o  ){
   step = (inlet_v - prev)>>4;
   int32_t i = prev;
   prev = inlet_v;

int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   outlet_o[buffer_index] =  ___SMMUL(inlet_a[buffer_index],i)<<5;
   i += step;

}
}
}
;class instanceoutlet__1{
  public: // v1
  voice *parent;
int32buffer _outlet;

  public: void Init(voice * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_outlet  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   _outlet[buffer_index] = inlet_outlet[buffer_index];

}
}
}
;class instancekeyb__1{
  public: // v1
  voice *parent;
int8_t _note;
int32_t _gate;
int32_t _gate2;
uint8_t _velo;
uint8_t _rvelo;

  public: void Init(voice * _parent) {
parent = _parent;
_gate = 0;
_note = 0;

}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_note,
bool  & outlet_gate,
bool  & outlet_gate2,
int32_t  & outlet_velocity,
int32_t  & outlet_releaseVelocity  ){
outlet_note= _note<<21;
outlet_gate= _gate;
outlet_gate2= _gate2;
_gate2 = _gate;
outlet_velocity= _velo<<20;
outlet_releaseVelocity= _rvelo<<20;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ((status == MIDI_NOTE_ON + 0) && (data2)) {
  _velo = data2;
  _note = data1-64;
  _gate = 1<<27;
  _gate2 = 0;
} else if (((status == MIDI_NOTE_ON + 0) && (!data2))||
          (status == MIDI_NOTE_OFF + 0)) {
  if (_note == data1-64) {
    _rvelo = data2;
    _gate = 0;
  }
} else if ((status == 0 + MIDI_CONTROL_CHANGE)&&(data1 == MIDI_C_ALL_NOTES_OFF)) {
  _gate = 0;
}
}
}
}
;class instancesaw__1{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instancesaw__1_pitch;
  int32_t osc_p;

  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_saw__1_pitch].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instancesaw__1_pitch,ObjectKvpRoot, "saw_1" ,&parent->PExch[PARAM_INDEX_saw__1_pitch], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instancesaw__1_pitch);
    osc_p=0;

}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_pitch,
int32buffer  & outlet_wave,
int param_pitch  ){
  uint32_t freq;
  MTOFEXTENDED(param_pitch + inlet_pitch,freq);
  int j;
  for(j=0;j<BUFSIZE;j++){
    osc_p+=freq;
    outlet_wave[j] = (osc_p)>>5;
  }

}
}
;class instanceenv__g{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instanceenv__g_time;
//KeyValuePair KVP_instanceenv__g_vt;
//KeyValuePair KVP_instanceenv__g_env;
int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_env__g_time].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__g_time,ObjectKvpRoot, "env_g:time" ,&parent->PExch[PARAM_INDEX_env__g_time], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__g_time);
parent->PExch[PARAM_INDEX_env__g_vt].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__g_vt,ObjectKvpRoot, "env_g:vt" ,&parent->PExch[PARAM_INDEX_env__g_vt], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__g_vt);
parent->PExch[PARAM_INDEX_env__g_env].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__g_env,ObjectKvpRoot, "env_g:env" ,&parent->PExch[PARAM_INDEX_env__g_env], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__g_env);
val = 0;
}
  public: void Dispose() {
}
  public: void dsp (const bool  inlet_trig,
const int32_t  inlet_vel,
int32_t  & outlet_env,
int param_time,
int param_vt,
int param_env  ){
int32_t vel_vt = ___SMMUL(param_vt, inlet_vel)<<5; // shorten or lengthen time by velo
if (inlet_trig > 0) {
  int32_t t;
  int32_t at = param_time + vel_vt;
  MTOF(-at,t);
  val += t>>6;
}
else {
  val = 0;
}
val = __USAT(val,27);

outlet_env = ___SMMUL(param_env, val)<<5;
}
}
;class instanceenv__c{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instanceenv__c_time;
//KeyValuePair KVP_instanceenv__c_vt;
//KeyValuePair KVP_instanceenv__c_env;
int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_env__c_time].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__c_time,ObjectKvpRoot, "env_c:time" ,&parent->PExch[PARAM_INDEX_env__c_time], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__c_time);
parent->PExch[PARAM_INDEX_env__c_vt].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__c_vt,ObjectKvpRoot, "env_c:vt" ,&parent->PExch[PARAM_INDEX_env__c_vt], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__c_vt);
parent->PExch[PARAM_INDEX_env__c_env].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__c_env,ObjectKvpRoot, "env_c:env" ,&parent->PExch[PARAM_INDEX_env__c_env], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__c_env);
val = 0;
}
  public: void Dispose() {
}
  public: void dsp (const bool  inlet_trig,
const int32_t  inlet_vel,
int32_t  & outlet_env,
int param_time,
int param_vt,
int param_env  ){
int32_t vel_vt = ___SMMUL(param_vt, inlet_vel)<<5; // shorten or lengthen time by velo
if (inlet_trig > 0) {
  int32_t t;
  int32_t at = param_time + vel_vt;
  MTOF(-at,t);
  val += t>>6;
}
else {
  val = 0;
}
val = __USAT(val,27);

outlet_env = ___SMMUL(param_env, val)<<5;
}
}
;class instanceenv__s{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instanceenv__s_time;
//KeyValuePair KVP_instanceenv__s_vt;
//KeyValuePair KVP_instanceenv__s_env;
int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_env__s_time].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__s_time,ObjectKvpRoot, "env_s:time" ,&parent->PExch[PARAM_INDEX_env__s_time], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__s_time);
parent->PExch[PARAM_INDEX_env__s_vt].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__s_vt,ObjectKvpRoot, "env_s:vt" ,&parent->PExch[PARAM_INDEX_env__s_vt], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__s_vt);
parent->PExch[PARAM_INDEX_env__s_env].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__s_env,ObjectKvpRoot, "env_s:env" ,&parent->PExch[PARAM_INDEX_env__s_env], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__s_env);
val = 0;
}
  public: void Dispose() {
}
  public: void dsp (const bool  inlet_trig,
const int32_t  inlet_vel,
int32_t  & outlet_env,
int param_time,
int param_vt,
int param_env  ){
int32_t vel_vt = ___SMMUL(param_vt, inlet_vel)<<5; // shorten or lengthen time by velo
if (inlet_trig > 0) {
  int32_t t;
  int32_t at = param_time + vel_vt;
  MTOF(-at,t);
  val += t>>6;
}
else {
  val = 0;
}
val = __USAT(val,27);

outlet_env = ___SMMUL(param_env, val)<<5;
}
}
;/* controller instances */
/* object instances */
     instancewavemix instancewavemix_i;
     instancesine__1 instancesine__1_i;
     instancesineslope__1 instancesineslope__1_i;
     instancea__time instancea__time_i;
     instancea__vel instancea__vel_i;
     instancevca__1 instancevca__1_i;
     instancecc__1 instancecc__1_i;
     instancevca__2 instancevca__2_i;
     instanceoutlet__1 instanceoutlet__1_i;
     instancekeyb__1 instancekeyb__1_i;
     instancesaw__1 instancesaw__1_i;
     instanceenv__g instanceenv__g_i;
     instanceenv__c instanceenv__c_i;
     instanceenv__s instanceenv__s_i;
/* net latches */
    int32_t  net0Latch;
    int32_t  net2Latch;
    int32buffer  net6Latch;
    int32_t  net7Latch;
    int32buffer  net8Latch;
    bool  net11Latch;
    int32_t  net12Latch;
    int32_t  net13Latch;
    int32_t  net14Latch;
instancealgo__4 *common;
void Init(voice *parent) {
        int i;
        for(i=0;i<NPEXCH;i++){
          PExch[i].pfunction = 0;
        }
   instancewavemix_i.Init(parent );
   instancesine__1_i.Init(parent );
   instancesineslope__1_i.Init(parent );
   instancea__time_i.Init(parent );
   instancea__vel_i.Init(parent );
   instancevca__1_i.Init(parent );
   instancecc__1_i.Init(parent );
   instancevca__2_i.Init(parent );
   instanceoutlet__1_i.Init(parent );
   instancekeyb__1_i.Init(parent );
   instancesaw__1_i.Init(parent );
   instanceenv__g_i.Init(parent );
   instanceenv__c_i.Init(parent );
   instanceenv__s_i.Init(parent );
      int k;
      for (k = 0; k < NPEXCH; k++) {
        if (PExch[k].pfunction){
          (PExch[k].pfunction)(&PExch[k]);
        } else {
          PExch[k].finalvalue = PExch[k].value;
        }
      }
}

void dsp(void) {
 int i;
//--------- <nets> -----------//
    int32_t  net0;
    int32_t  net1;
    int32_t  net2;
    int32_t  net3;
    int32buffer  net4;
    int32buffer  net5;
    int32buffer  net6;
    int32_t  net7;
    int32buffer  net8;
    int32buffer  net9;
    int32buffer  net10;
    bool  net11;
    int32_t  net12;
    int32_t  net13;
    int32_t  net14;
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instancewavemix_i.dsp(net8Latch, net6Latch, net9, PExch[PARAM_INDEX_wavemix_sin].finalvalue, PExch[PARAM_INDEX_wavemix_saw].finalvalue);
  instancesine__1_i.dsp(net7Latch, zerobuffer, zerobuffer, net8, PExch[PARAM_INDEX_sine__1_pitch].finalvalue);
  instancesineslope__1_i.dsp(net9, net12Latch, net13Latch, net14Latch, net10, PExch[PARAM_INDEX_sineslope__1_gain].finalvalue, PExch[PARAM_INDEX_sineslope__1_clipH].finalvalue, PExch[PARAM_INDEX_sineslope__1_clipL].finalvalue, PExch[PARAM_INDEX_sineslope__1_strength].finalvalue, PExch[PARAM_INDEX_sineslope__1_halfout].finalvalue);
  instancea__time_i.dsp(net11Latch, net2Latch, net1, PExch[PARAM_INDEX_a__time_a].finalvalue);
  instancea__vel_i.dsp(net0Latch, net2, PExch[PARAM_INDEX_a__vel_amp].finalvalue);
  instancevca__1_i.dsp(net1, net10, net5);
  instancecc__1_i.dsp(net3, (bool &)UNCONNECTED_OUTPUT);
  instancevca__2_i.dsp(net3, net5, net4);
  instanceoutlet__1_i.dsp(net4);
  instancekeyb__1_i.dsp(net7, (bool &)UNCONNECTED_OUTPUT, net11, net0, UNCONNECTED_OUTPUT);
  instancesaw__1_i.dsp(net7, net6, PExch[PARAM_INDEX_saw__1_pitch].finalvalue);
  instanceenv__g_i.dsp(net11, net0, net12, PExch[PARAM_INDEX_env__g_time].finalvalue, PExch[PARAM_INDEX_env__g_vt].finalvalue, PExch[PARAM_INDEX_env__g_env].finalvalue);
  instanceenv__c_i.dsp(net11, net0, net13, PExch[PARAM_INDEX_env__c_time].finalvalue, PExch[PARAM_INDEX_env__c_vt].finalvalue, PExch[PARAM_INDEX_env__c_env].finalvalue);
  instanceenv__s_i.dsp(net11, net0, net14, PExch[PARAM_INDEX_env__s_time].finalvalue, PExch[PARAM_INDEX_env__s_vt].finalvalue, PExch[PARAM_INDEX_env__s_env].finalvalue);
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
net0Latch = net0;
net2Latch = net2;
   for(i=0;i<BUFSIZE;i++)
      net6Latch[i]=net6[i];
net7Latch = net7;
   for(i=0;i<BUFSIZE;i++)
      net8Latch[i]=net8[i];
net11Latch = net11;
net12Latch = net12;
net13Latch = net13;
net14Latch = net14;
//--------- </net latch copy> ----------//
}
void dispose(void) {
 int i;
   instanceenv__s_i.Dispose();
   instanceenv__c_i.Dispose();
   instanceenv__g_i.Dispose();
   instancesaw__1_i.Dispose();
   instancekeyb__1_i.Dispose();
   instanceoutlet__1_i.Dispose();
   instancevca__2_i.Dispose();
   instancecc__1_i.Dispose();
   instancevca__1_i.Dispose();
   instancea__vel_i.Dispose();
   instancea__time_i.Dispose();
   instancesineslope__1_i.Dispose();
   instancesine__1_i.Dispose();
   instancewavemix_i.Dispose();
}
void MidiInHandler(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2){
instancecc__1_i.MidiInHandler(dev, port, status, data1, data2);
instancekeyb__1_i.MidiInHandler(dev, port, status, data1, data2);
}

};
static voice * getVoices(void){
     static voice v[1];
    return v;
}
static void PropagateToVoices(ParameterExchange_t *origin) {
      ParameterExchange_t *pex = (ParameterExchange_t *)origin->finalvalue;
      int vi;
      for (vi = 0; vi < 1; vi++) {
        PExParameterChange(pex,origin->modvalue,0xFFFFFFEE);
          pex = (ParameterExchange_t *)((int)pex + sizeof(voice)); // dirty trick...
      }}
int8_t notePlaying[1];
int32_t voicePriority[1];
int32_t priority;
int32_t sustain;
int8_t pressed[1];

  public: void Init(rootc * _parent) {
parent = _parent;
   int i;
   int j;
   const int32_t *p;
   p = GetInitParams();
   for(j=0;j<20;j++){
      PExch[j].value = p[j];
      PExch[j].modvalue = p[j];
      PExch[j].signals = 0;
      PExch[j].pfunction = 0;
   }
   int32_t *pp = &PExModulationPrevVal[0][0];
   for(j=0;j<1*NMODULATIONSOURCES;j++){
      *pp = 0; pp++;
   }
     displayVector[0] = 0x446F7841;
     displayVector[1] = 0;
     displayVector[2] = 0;
int k;
   for(k=0;k<NPEXCH;k++){
      PExch[k].pfunction = PropagateToVoices;
      PExch[k].finalvalue = (int32_t) (&(getVoices()[0].PExch[k]));
   }
int vi; for(vi=0;vi<1;vi++) {
   voice *v = &getVoices()[vi];
   v->polyIndex = vi;
   v->common = this;
   v->Init(&getVoices()[vi]);
   notePlaying[vi]=0;
   voicePriority[vi]=0;
   for (j = 0; j < v->NPEXCH; j++) {
      v->PExch[j].value = 0;
      v->PExch[j].modvalue = 0;
   }
}
      for (k = 0; k < NPEXCH; k++) {
        if (PExch[k].pfunction){
          (PExch[k].pfunction)(&PExch[k]);
        } else {
          PExch[k].finalvalue = PExch[k].value;
        }
      }
priority=0;
sustain=0;

}
  public: void Dispose() {
int vi; for(vi=0;vi<1;vi++) {
  voice *v = &getVoices()[vi];
  v->dispose();
}

}
  public: void dsp (int32buffer  & outlet_outlet__1  ){
{
      int j;
      for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] = 0;
}
int vi; for(vi=0;vi<1;vi++) {if(!pressed[vi]) continue; getVoices()[vi].dsp();
{
      int j;
      for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += getVoices()[vi].instanceoutlet__1_i._outlet[j];
}
}

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ( 15 > 0 && dev > 0 && 15 != dev) return;
if ( 16 > 0 && port > 0 && 16 != port) return;
if ((status == MIDI_NOTE_ON + 0) && (data2)) {
  int min = 1<<30;
  int mini = 0;
  int i;
  for(i=0;i<1;i++){
    if (voicePriority[i] < min){
      min = voicePriority[i];
      mini = i;
    }
  }
  voicePriority[mini] = 100000+priority++;
  notePlaying[mini] = data1;
  pressed[mini] = 1;
  getVoices()[mini].MidiInHandler(dev, port, status, data1, data2);
} else if (((status == MIDI_NOTE_ON + 0) && (!data2))||
          (status == MIDI_NOTE_OFF + 0)) {
  int i;
  for(i=0;i<1;i++){
    if ((notePlaying[i] == data1) && pressed[i]){
      voicePriority[i] = priority++;
      pressed[i] = 0;
      if (!sustain)
        getVoices()[i].MidiInHandler(dev, port, status, data1, data2);
      }
  }
} else if (status == 0 + MIDI_CONTROL_CHANGE) {
  int i;
  for(i=0;i<1;i++) getVoices()[i].MidiInHandler(dev, port, status, data1, data2);
  if (data1 == 64) {
    if (data2>0) {
      sustain = 1;
    } else if (sustain == 1) {
      sustain = 0;
      for(i=0;i<1;i++){
        if (pressed[i] == 0) {
          getVoices()[i].MidiInHandler(dev, port, MIDI_NOTE_ON + 0, notePlaying[i], 0);
        }
      }
    }
  }
} else {  int i;   for(i=0;i<1;i++) getVoices()[i].MidiInHandler(dev, port, status, data1, data2);
}
}
}
}
;class instancealgo__5{
  public: // v1
  rootc *parent;
   static int32_t * GetInitParams(void){
      static const int32_t p[14]= {
      134217728,
      0,
      0,
      -125829120,
      -77594624,
      -134217728,
      0,
      0,
      48234496,
      0,
      0,
      -20971520,
      0,
      104857600
      };
      return (int32_t *)&p[0];
   }    static const uint32_t NPEXCH = 14;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 0;
    static const uint32_t NPRESET_ENTRIES = 0;
    static const uint32_t NMODULATIONSOURCES = 0;
    static const uint32_t NMODULATIONTARGETS = 0;
    int32_t PExModulationPrevVal[1][NMODULATIONSOURCES];
/* parameter instance indices */
static const int PARAM_INDEX_wavemix_sin = 0;
static const int PARAM_INDEX_wavemix_saw = 1;
static const int PARAM_INDEX_sine__1_pitch = 2;
static const int PARAM_INDEX_asymSin__1_mod1 = 3;
static const int PARAM_INDEX_asymSin__1_mod2 = 4;
static const int PARAM_INDEX_a__time_a = 5;
static const int PARAM_INDEX_a__vel_amp = 6;
static const int PARAM_INDEX_saw__1_pitch = 7;
static const int PARAM_INDEX_env__m1_time = 8;
static const int PARAM_INDEX_env__m1_vt = 9;
static const int PARAM_INDEX_env__m1_env = 10;
static const int PARAM_INDEX_env__m2_time = 11;
static const int PARAM_INDEX_env__m2_vt = 12;
static const int PARAM_INDEX_env__m2_env = 13;
   static const int32_t * GetPresets(void){
      static const int32_t p[NPRESETS][NPRESET_ENTRIES][2] = {
      };
   return &p[0][0][0];
   };
void ApplyPreset(int index){
   if (!index) {
     int i;
     int32_t *p = GetInitParams();
     for(i=0;i<NPEXCH;i++){
        PExParameterChange(&PExch[i],p[i],0xFFEF);
     }
   }
   index--;
   if (index < NPRESETS) {
     PresetParamChange_t *pa = (PresetParamChange_t *)(GetPresets());
     PresetParamChange_t *p = &pa[index*NPRESET_ENTRIES];
       int i;
       for(i=0;i<NPRESET_ENTRIES;i++){
         PresetParamChange_t *pp = &p[i];
         if ((pp->pexIndex>=0)&&(pp->pexIndex<NPEXCH)) {
           PExParameterChange(&PExch[pp->pexIndex],pp->value,0xFFEF);         }
         else break;
       }
   }
}
   static PExModulationTarget_t * GetModulationTable(void){
    static const PExModulationTarget_t PExModulationSources[NMODULATIONSOURCES][NMODULATIONTARGETS] = 
{};
   return (PExModulationTarget_t *)&PExModulationSources[0][0];
   };
class voice {
   public:
   int polyIndex;
    static const uint32_t NPEXCH = 14;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 0;
    static const uint32_t NPRESET_ENTRIES = 0;
    static const uint32_t NMODULATIONSOURCES = 0;
    static const uint32_t NMODULATIONTARGETS = 0;
/* modsource defines */
/* parameter instance indices */
static const int PARAM_INDEX_wavemix_sin = 0;
static const int PARAM_INDEX_wavemix_saw = 1;
static const int PARAM_INDEX_sine__1_pitch = 2;
static const int PARAM_INDEX_asymSin__1_mod1 = 3;
static const int PARAM_INDEX_asymSin__1_mod2 = 4;
static const int PARAM_INDEX_a__time_a = 5;
static const int PARAM_INDEX_a__vel_amp = 6;
static const int PARAM_INDEX_saw__1_pitch = 7;
static const int PARAM_INDEX_env__m1_time = 8;
static const int PARAM_INDEX_env__m1_vt = 9;
static const int PARAM_INDEX_env__m1_env = 10;
static const int PARAM_INDEX_env__m2_time = 11;
static const int PARAM_INDEX_env__m2_vt = 12;
static const int PARAM_INDEX_env__m2_env = 13;
/* controller classes */
/* object classes */
class instancewavemix{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instancewavemix_sin;
//KeyValuePair KVP_instancewavemix_saw;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_wavemix_sin].pfunction = pfun_unsigned_clamp_fullrange;
  //SetKVP_IPVP(&KVP_instancewavemix_sin,ObjectKvpRoot, "wavemix:sin" ,&parent->PExch[PARAM_INDEX_wavemix_sin], 0, 1<<27);
  //KVP_RegisterObject(&KVP_instancewavemix_sin);
parent->PExch[PARAM_INDEX_wavemix_saw].pfunction = pfun_unsigned_clamp_fullrange;
  //SetKVP_IPVP(&KVP_instancewavemix_saw,ObjectKvpRoot, "wavemix:saw" ,&parent->PExch[PARAM_INDEX_wavemix_saw], 0, 1<<27);
  //KVP_RegisterObject(&KVP_instancewavemix_saw);
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_in1,
const int32buffer  inlet_in2,
int32buffer  & outlet_out,
int param_sin,
int param_saw  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
int32_t accum = ___SMMUL(inlet_in1[buffer_index],param_sin);
accum = ___SMMLA(inlet_in2[buffer_index],param_saw,accum);
outlet_out[buffer_index]= __SSAT((accum<<1),28);
}
}
}
;class instancesine__1{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instancesine__1_pitch;
uint32_t Phase;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_sine__1_pitch].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instancesine__1_pitch,ObjectKvpRoot, "sine_1" ,&parent->PExch[PARAM_INDEX_sine__1_pitch], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instancesine__1_pitch);
Phase = 0;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_pitch,
const int32buffer  inlet_freq,
const int32buffer  inlet_phase,
int32buffer  & outlet_wave,
int param_pitch  ){
   int32_t freq;
   MTOFEXTENDED(param_pitch + inlet_pitch,freq);

int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
Phase += freq + inlet_freq[buffer_index];
int32_t r;
int32_t p2 = Phase + (inlet_phase[buffer_index]<<4);
SINE2TINTERP(p2,r)
outlet_wave[buffer_index]= (r>>4);

}
}
}
;class instanceasymSin__1{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instanceasymSin__1_mod1;
//KeyValuePair KVP_instanceasymSin__1_mod2;
int32_t O1;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_asymSin__1_mod1].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceasymSin__1_mod1,ObjectKvpRoot, "asymSin_1:mod1" ,&parent->PExch[PARAM_INDEX_asymSin__1_mod1], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceasymSin__1_mod1);
parent->PExch[PARAM_INDEX_asymSin__1_mod2].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceasymSin__1_mod2,ObjectKvpRoot, "asymSin_1:mod2" ,&parent->PExch[PARAM_INDEX_asymSin__1_mod2], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceasymSin__1_mod2);
SINE2TINTERP(1<<30,O1)
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_in,
const int32_t  inlet_mod1,
const int32_t  inlet_mod2,
int32buffer  & outlet_out,
int param_mod1,
int param_mod2  ){
int32_t mod1=param_mod1+inlet_mod1;
int32_t mod2=mod1<0?-mod1:0;
mod1=mod1>0?mod1:0;
int32_t mod3=param_mod2+inlet_mod2;
int32_t mod4=mod3<0?-mod3:0;
mod3=mod3>0?mod3:0;
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
int32_t in=inlet_in[buffer_index];
if(in>0){
in+=___SMMUL(mod2<<4,in<<4);}
else{
in+=___SMMUL(mod4<<4,in<<4);}
int32_t clip=in>mod1?mod1:in;
clip=clip<-mod3?-mod3:clip;
int32_t over=in-clip;
if(over>0){
SINE2TINTERP((-over<<4)+(1<<30),over)
over=over>>5;
over-=(O1>>5);
}
else{SINE2TINTERP((-over<<4)-(1<<30),over)
over=over>>5;
over+=(O1>>5);
}
outlet_out[buffer_index]=clip+(over);
}
}
}
;class instancea__time{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instancea__time_a;
int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a__time_a].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instancea__time_a,ObjectKvpRoot, "a_time" ,&parent->PExch[PARAM_INDEX_a__time_a], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instancea__time_a);
val = 0;
}
  public: void Dispose() {
}
  public: void dsp (const bool  inlet_trig,
const int32_t  inlet_a,
int32_t  & outlet_env,
int param_a  ){
if (inlet_trig > 0) {
  int32_t t;
  int32_t at = param_a + inlet_a;
  MTOF(-at,t);
  val += t>>6;
}
else {
  val = 0;
}
val = __USAT(val,27);
outlet_env = val;
}
}
;class instancea__vel{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instancea__vel_amp;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a__vel_amp].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instancea__vel_amp,ObjectKvpRoot, "a_vel" ,&parent->PExch[PARAM_INDEX_a__vel_amp], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instancea__vel_amp);
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out,
int param_amp  ){
outlet_out= ___SMMUL(param_amp, inlet_in)<<5;

}
}
;class instancevca__1{
  public: // v1
  voice *parent;
   int32_t prev;
    int32_t step;

  public: void Init(voice * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_v,
const int32buffer  inlet_a,
int32buffer  & outlet_o  ){
   step = (inlet_v - prev)>>4;
   int32_t i = prev;
   prev = inlet_v;

int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   outlet_o[buffer_index] =  ___SMMUL(inlet_a[buffer_index],i)<<5;
   i += step;

}
}
}
;class instancecc__1{
  public: // v1
  voice *parent;
int32_t ccv;
int32_t ntrig;

  public: void Init(voice * _parent) {
parent = _parent;
ccv = 100 << 20;

}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_midiCC,
bool  & outlet_trig  ){
outlet_midiCC= ccv;
outlet_trig = ntrig;
ntrig = 0;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ((status == 0 + MIDI_CONTROL_CHANGE)&&(data1 == 7)) { ccv = data2<<20; ntrig = 1;}
}
}
}
;class instancevca__2{
  public: // v1
  voice *parent;
   int32_t prev;
    int32_t step;

  public: void Init(voice * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_v,
const int32buffer  inlet_a,
int32buffer  & outlet_o  ){
   step = (inlet_v - prev)>>4;
   int32_t i = prev;
   prev = inlet_v;

int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   outlet_o[buffer_index] =  ___SMMUL(inlet_a[buffer_index],i)<<5;
   i += step;

}
}
}
;class instanceoutlet__1{
  public: // v1
  voice *parent;
int32buffer _outlet;

  public: void Init(voice * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_outlet  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   _outlet[buffer_index] = inlet_outlet[buffer_index];

}
}
}
;class instancekeyb__1{
  public: // v1
  voice *parent;
int8_t _note;
int32_t _gate;
int32_t _gate2;
uint8_t _velo;
uint8_t _rvelo;

  public: void Init(voice * _parent) {
parent = _parent;
_gate = 0;
_note = 0;

}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_note,
bool  & outlet_gate,
bool  & outlet_gate2,
int32_t  & outlet_velocity,
int32_t  & outlet_releaseVelocity  ){
outlet_note= _note<<21;
outlet_gate= _gate;
outlet_gate2= _gate2;
_gate2 = _gate;
outlet_velocity= _velo<<20;
outlet_releaseVelocity= _rvelo<<20;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ((status == MIDI_NOTE_ON + 0) && (data2)) {
  _velo = data2;
  _note = data1-64;
  _gate = 1<<27;
  _gate2 = 0;
} else if (((status == MIDI_NOTE_ON + 0) && (!data2))||
          (status == MIDI_NOTE_OFF + 0)) {
  if (_note == data1-64) {
    _rvelo = data2;
    _gate = 0;
  }
} else if ((status == 0 + MIDI_CONTROL_CHANGE)&&(data1 == MIDI_C_ALL_NOTES_OFF)) {
  _gate = 0;
}
}
}
}
;class instancesaw__1{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instancesaw__1_pitch;
  int32_t osc_p;

  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_saw__1_pitch].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instancesaw__1_pitch,ObjectKvpRoot, "saw_1" ,&parent->PExch[PARAM_INDEX_saw__1_pitch], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instancesaw__1_pitch);
    osc_p=0;

}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_pitch,
int32buffer  & outlet_wave,
int param_pitch  ){
  uint32_t freq;
  MTOFEXTENDED(param_pitch + inlet_pitch,freq);
  int j;
  for(j=0;j<BUFSIZE;j++){
    osc_p+=freq;
    outlet_wave[j] = (osc_p)>>5;
  }

}
}
;class instanceenv__m1{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instanceenv__m1_time;
//KeyValuePair KVP_instanceenv__m1_vt;
//KeyValuePair KVP_instanceenv__m1_env;
int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_env__m1_time].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__m1_time,ObjectKvpRoot, "env_m1:time" ,&parent->PExch[PARAM_INDEX_env__m1_time], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__m1_time);
parent->PExch[PARAM_INDEX_env__m1_vt].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__m1_vt,ObjectKvpRoot, "env_m1:vt" ,&parent->PExch[PARAM_INDEX_env__m1_vt], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__m1_vt);
parent->PExch[PARAM_INDEX_env__m1_env].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__m1_env,ObjectKvpRoot, "env_m1:env" ,&parent->PExch[PARAM_INDEX_env__m1_env], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__m1_env);
val = 0;
}
  public: void Dispose() {
}
  public: void dsp (const bool  inlet_trig,
const int32_t  inlet_vel,
int32_t  & outlet_env,
int param_time,
int param_vt,
int param_env  ){
int32_t vel_vt = ___SMMUL(param_vt, inlet_vel)<<5; // shorten or lengthen time by velo
if (inlet_trig > 0) {
  int32_t t;
  int32_t at = param_time + vel_vt;
  MTOF(-at,t);
  val += t>>6;
}
else {
  val = 0;
}
val = __USAT(val,27);

outlet_env = ___SMMUL(param_env, val)<<5;
}
}
;class instanceenv__m2{
  public: // v1
  voice *parent;
//KeyValuePair KVP_instanceenv__m2_time;
//KeyValuePair KVP_instanceenv__m2_vt;
//KeyValuePair KVP_instanceenv__m2_env;
int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_env__m2_time].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__m2_time,ObjectKvpRoot, "env_m2:time" ,&parent->PExch[PARAM_INDEX_env__m2_time], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__m2_time);
parent->PExch[PARAM_INDEX_env__m2_vt].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__m2_vt,ObjectKvpRoot, "env_m2:vt" ,&parent->PExch[PARAM_INDEX_env__m2_vt], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__m2_vt);
parent->PExch[PARAM_INDEX_env__m2_env].pfunction = pfun_signed_clamp;
  //SetKVP_IPVP(&KVP_instanceenv__m2_env,ObjectKvpRoot, "env_m2:env" ,&parent->PExch[PARAM_INDEX_env__m2_env], -1<<27, 1<<27);
  //KVP_RegisterObject(&KVP_instanceenv__m2_env);
val = 0;
}
  public: void Dispose() {
}
  public: void dsp (const bool  inlet_trig,
const int32_t  inlet_vel,
int32_t  & outlet_env,
int param_time,
int param_vt,
int param_env  ){
int32_t vel_vt = ___SMMUL(param_vt, inlet_vel)<<5; // shorten or lengthen time by velo
if (inlet_trig > 0) {
  int32_t t;
  int32_t at = param_time + vel_vt;
  MTOF(-at,t);
  val += t>>6;
}
else {
  val = 0;
}
val = __USAT(val,27);

outlet_env = ___SMMUL(param_env, val)<<5;
}
}
;/* controller instances */
/* object instances */
     instancewavemix instancewavemix_i;
     instancesine__1 instancesine__1_i;
     instanceasymSin__1 instanceasymSin__1_i;
     instancea__time instancea__time_i;
     instancea__vel instancea__vel_i;
     instancevca__1 instancevca__1_i;
     instancecc__1 instancecc__1_i;
     instancevca__2 instancevca__2_i;
     instanceoutlet__1 instanceoutlet__1_i;
     instancekeyb__1 instancekeyb__1_i;
     instancesaw__1 instancesaw__1_i;
     instanceenv__m1 instanceenv__m1_i;
     instanceenv__m2 instanceenv__m2_i;
/* net latches */
    int32_t  net0Latch;
    bool  net2Latch;
    int32_t  net3Latch;
    int32buffer  net7Latch;
    int32_t  net8Latch;
    int32buffer  net9Latch;
    int32_t  net12Latch;
    int32_t  net13Latch;
instancealgo__5 *common;
void Init(voice *parent) {
        int i;
        for(i=0;i<NPEXCH;i++){
          PExch[i].pfunction = 0;
        }
   instancewavemix_i.Init(parent );
   instancesine__1_i.Init(parent );
   instanceasymSin__1_i.Init(parent );
   instancea__time_i.Init(parent );
   instancea__vel_i.Init(parent );
   instancevca__1_i.Init(parent );
   instancecc__1_i.Init(parent );
   instancevca__2_i.Init(parent );
   instanceoutlet__1_i.Init(parent );
   instancekeyb__1_i.Init(parent );
   instancesaw__1_i.Init(parent );
   instanceenv__m1_i.Init(parent );
   instanceenv__m2_i.Init(parent );
      int k;
      for (k = 0; k < NPEXCH; k++) {
        if (PExch[k].pfunction){
          (PExch[k].pfunction)(&PExch[k]);
        } else {
          PExch[k].finalvalue = PExch[k].value;
        }
      }
}

void dsp(void) {
 int i;
//--------- <nets> -----------//
    int32_t  net0;
    int32_t  net1;
    bool  net2;
    int32_t  net3;
    int32_t  net4;
    int32buffer  net5;
    int32buffer  net6;
    int32buffer  net7;
    int32_t  net8;
    int32buffer  net9;
    int32buffer  net10;
    int32buffer  net11;
    int32_t  net12;
    int32_t  net13;
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instancewavemix_i.dsp(net9Latch, net7Latch, net10, PExch[PARAM_INDEX_wavemix_sin].finalvalue, PExch[PARAM_INDEX_wavemix_saw].finalvalue);
  instancesine__1_i.dsp(net8Latch, zerobuffer, zerobuffer, net9, PExch[PARAM_INDEX_sine__1_pitch].finalvalue);
  instanceasymSin__1_i.dsp(net10, net13Latch, net12Latch, net11, PExch[PARAM_INDEX_asymSin__1_mod1].finalvalue, PExch[PARAM_INDEX_asymSin__1_mod2].finalvalue);
  instancea__time_i.dsp(net2Latch, net3Latch, net1, PExch[PARAM_INDEX_a__time_a].finalvalue);
  instancea__vel_i.dsp(net0Latch, net3, PExch[PARAM_INDEX_a__vel_amp].finalvalue);
  instancevca__1_i.dsp(net1, net11, net6);
  instancecc__1_i.dsp(net4, (bool &)UNCONNECTED_OUTPUT);
  instancevca__2_i.dsp(net4, net6, net5);
  instanceoutlet__1_i.dsp(net5);
  instancekeyb__1_i.dsp(net8, (bool &)UNCONNECTED_OUTPUT, net2, net0, UNCONNECTED_OUTPUT);
  instancesaw__1_i.dsp(net8, net7, PExch[PARAM_INDEX_saw__1_pitch].finalvalue);
  instanceenv__m1_i.dsp(net2, net0, net13, PExch[PARAM_INDEX_env__m1_time].finalvalue, PExch[PARAM_INDEX_env__m1_vt].finalvalue, PExch[PARAM_INDEX_env__m1_env].finalvalue);
  instanceenv__m2_i.dsp(net2, net0, net12, PExch[PARAM_INDEX_env__m2_time].finalvalue, PExch[PARAM_INDEX_env__m2_vt].finalvalue, PExch[PARAM_INDEX_env__m2_env].finalvalue);
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
net0Latch = net0;
net2Latch = net2;
net3Latch = net3;
   for(i=0;i<BUFSIZE;i++)
      net7Latch[i]=net7[i];
net8Latch = net8;
   for(i=0;i<BUFSIZE;i++)
      net9Latch[i]=net9[i];
net12Latch = net12;
net13Latch = net13;
//--------- </net latch copy> ----------//
}
void dispose(void) {
 int i;
   instanceenv__m2_i.Dispose();
   instanceenv__m1_i.Dispose();
   instancesaw__1_i.Dispose();
   instancekeyb__1_i.Dispose();
   instanceoutlet__1_i.Dispose();
   instancevca__2_i.Dispose();
   instancecc__1_i.Dispose();
   instancevca__1_i.Dispose();
   instancea__vel_i.Dispose();
   instancea__time_i.Dispose();
   instanceasymSin__1_i.Dispose();
   instancesine__1_i.Dispose();
   instancewavemix_i.Dispose();
}
void MidiInHandler(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2){
instancecc__1_i.MidiInHandler(dev, port, status, data1, data2);
instancekeyb__1_i.MidiInHandler(dev, port, status, data1, data2);
}

};
static voice * getVoices(void){
     static voice v[1];
    return v;
}
static void PropagateToVoices(ParameterExchange_t *origin) {
      ParameterExchange_t *pex = (ParameterExchange_t *)origin->finalvalue;
      int vi;
      for (vi = 0; vi < 1; vi++) {
        PExParameterChange(pex,origin->modvalue,0xFFFFFFEE);
          pex = (ParameterExchange_t *)((int)pex + sizeof(voice)); // dirty trick...
      }}
int8_t notePlaying[1];
int32_t voicePriority[1];
int32_t priority;
int32_t sustain;
int8_t pressed[1];

  public: void Init(rootc * _parent) {
parent = _parent;
   int i;
   int j;
   const int32_t *p;
   p = GetInitParams();
   for(j=0;j<14;j++){
      PExch[j].value = p[j];
      PExch[j].modvalue = p[j];
      PExch[j].signals = 0;
      PExch[j].pfunction = 0;
   }
   int32_t *pp = &PExModulationPrevVal[0][0];
   for(j=0;j<1*NMODULATIONSOURCES;j++){
      *pp = 0; pp++;
   }
     displayVector[0] = 0x446F7841;
     displayVector[1] = 0;
     displayVector[2] = 0;
int k;
   for(k=0;k<NPEXCH;k++){
      PExch[k].pfunction = PropagateToVoices;
      PExch[k].finalvalue = (int32_t) (&(getVoices()[0].PExch[k]));
   }
int vi; for(vi=0;vi<1;vi++) {
   voice *v = &getVoices()[vi];
   v->polyIndex = vi;
   v->common = this;
   v->Init(&getVoices()[vi]);
   notePlaying[vi]=0;
   voicePriority[vi]=0;
   for (j = 0; j < v->NPEXCH; j++) {
      v->PExch[j].value = 0;
      v->PExch[j].modvalue = 0;
   }
}
      for (k = 0; k < NPEXCH; k++) {
        if (PExch[k].pfunction){
          (PExch[k].pfunction)(&PExch[k]);
        } else {
          PExch[k].finalvalue = PExch[k].value;
        }
      }
priority=0;
sustain=0;

}
  public: void Dispose() {
int vi; for(vi=0;vi<1;vi++) {
  voice *v = &getVoices()[vi];
  v->dispose();
}

}
  public: void dsp (int32buffer  & outlet_outlet__1  ){
{
      int j;
      for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] = 0;
}
int vi; for(vi=0;vi<1;vi++) {if(!pressed[vi]) continue; getVoices()[vi].dsp();
{
      int j;
      for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += getVoices()[vi].instanceoutlet__1_i._outlet[j];
}
}

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ( 15 > 0 && dev > 0 && 15 != dev) return;
if ( 16 > 0 && port > 0 && 16 != port) return;
if ((status == MIDI_NOTE_ON + 0) && (data2)) {
  int min = 1<<30;
  int mini = 0;
  int i;
  for(i=0;i<1;i++){
    if (voicePriority[i] < min){
      min = voicePriority[i];
      mini = i;
    }
  }
  voicePriority[mini] = 100000+priority++;
  notePlaying[mini] = data1;
  pressed[mini] = 1;
  getVoices()[mini].MidiInHandler(dev, port, status, data1, data2);
} else if (((status == MIDI_NOTE_ON + 0) && (!data2))||
          (status == MIDI_NOTE_OFF + 0)) {
  int i;
  for(i=0;i<1;i++){
    if ((notePlaying[i] == data1) && pressed[i]){
      voicePriority[i] = priority++;
      pressed[i] = 0;
      if (!sustain)
        getVoices()[i].MidiInHandler(dev, port, status, data1, data2);
      }
  }
} else if (status == 0 + MIDI_CONTROL_CHANGE) {
  int i;
  for(i=0;i<1;i++) getVoices()[i].MidiInHandler(dev, port, status, data1, data2);
  if (data1 == 64) {
    if (data2>0) {
      sustain = 1;
    } else if (sustain == 1) {
      sustain = 0;
      for(i=0;i<1;i++){
        if (pressed[i] == 0) {
          getVoices()[i].MidiInHandler(dev, port, MIDI_NOTE_ON + 0, notePlaying[i], 0);
        }
      }
    }
  }
} else {  int i;   for(i=0;i<1;i++) getVoices()[i].MidiInHandler(dev, port, status, data1, data2);
}
}
}
}
;class instancepatcher__1{
  public: // v1
  rootc *parent;
//KeyValuePair KVP_instancepatcher__1_vtype;
int32_t vtype = 0; // zp
class voice {
   public:
   int polyIndex;
      
instancepatcher__1 *common;
void Init(voice *parent) {
	if( common->vtype == 1 )
	{
      instancealgo__1::voice* av = &common->get200Algo1()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 2 )
	{
      instancealgo__2::voice* av = &common->get200Algo2()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 3 )
	{
      instancealgo__3::voice* av = &common->get200Algo3()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 4 )
	{
      instancealgo__4::voice* av = &common->get200Algo4()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 5 )
	{
      instancealgo__5::voice* av = &common->get200Algo5()[polyIndex]; //zp
      av->Init( av ); //zp
	}
}
void dsp(void) { } //zp
void dispose(void) {
   if( common->vtype == 1 ) common->get200Algo1()[polyIndex].dispose(); //zp
   if( common->vtype == 2 ) common->get200Algo2()[polyIndex].dispose(); //zp
   if( common->vtype == 3 ) common->get200Algo3()[polyIndex].dispose(); //zp
   if( common->vtype == 4 ) common->get200Algo4()[polyIndex].dispose(); //zp
   if( common->vtype == 5 ) common->get200Algo5()[polyIndex].dispose(); //zp
}
void MidiInHandler(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2) {
  // passthru cc to voice
  if( common->vtype == 1 ) common->get200Algo1()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 2 ) common->get200Algo2()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 3 ) common->get200Algo3()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 4 ) common->get200Algo4()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 5 ) common->get200Algo5()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp

  // ccMGR paramexchange
  if( common->vtype == 1 ) instanceccMGR::setPEx( 1, &common->get200Algo1()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 2 ) instanceccMGR::setPEx( 2, &common->get200Algo2()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 3 ) instanceccMGR::setPEx( 3, &common->get200Algo3()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 4 ) instanceccMGR::setPEx( 4, &common->get200Algo4()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 5 ) instanceccMGR::setPEx( 5, &common->get200Algo5()[polyIndex], data1, data2 ); //zp
}

};

static voice * getVoices(void){
    static voice v[8];
    return v;
}


static instancealgo__1::voice * get200Algo1(){    //zp
	static instancealgo__1::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__2::voice * get200Algo2(){    //zp
	static instancealgo__2::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__3::voice * get200Algo3(){    //zp
	static instancealgo__3::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__4::voice * get200Algo4(){    //zp
	static instancealgo__4::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__5::voice * get200Algo5(){    //zp
	static instancealgo__5::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}

void setParamBatch( const int32_t *srcV, uint8_t NV, ParameterExchange_t *targetPE ) {
  for(int j=0;j<NV;j++) {
	targetPE[j].value = srcV[j];
	targetPE[j].modvalue = srcV[j];
	targetPE[j].signals = 0;
	targetPE[j].pfunction = 0;
  }
}

int8_t notePlaying[8];
int32_t voicePriority[8];
int32_t priority;
int32_t sustain;
int8_t pressed[8];
  public: void Init(rootc * _parent) {
parent = _parent;
for(int vi=0;vi<8;vi++){ //zp
   if( vtype == 1 ) setParamBatch( instancealgo__1::GetInitParams(), instancealgo__1::NPEXCH, &get200Algo1()[vi].PExch[0] );
   if( vtype == 2 ) setParamBatch( instancealgo__2::GetInitParams(), instancealgo__2::NPEXCH, &get200Algo2()[vi].PExch[0] );
   if( vtype == 3 ) setParamBatch( instancealgo__3::GetInitParams(), instancealgo__3::NPEXCH, &get200Algo3()[vi].PExch[0] );
   if( vtype == 4 ) setParamBatch( instancealgo__4::GetInitParams(), instancealgo__4::NPEXCH, &get200Algo4()[vi].PExch[0] );
   if( vtype == 5 ) setParamBatch( instancealgo__5::GetInitParams(), instancealgo__5::NPEXCH, &get200Algo5()[vi].PExch[0] );
} //zp

int vi; for(vi=0;vi<8;vi++) {
   voice *v = &getVoices()[vi];
   v->polyIndex = vi;
   v->common = this;
   v->Init(&getVoices()[vi]); 
   notePlaying[vi]=0;
   voicePriority[vi]=0;
}

priority=0;
sustain=0;
}
  public: void Dispose() {
int vi; for(vi=0;vi<8;vi++) {
  voice *v = &getVoices()[vi];
  v->dispose();
}
}
  public: void dsp (int32buffer  & outlet_outlet__1,
int param_vtype  ){
bool reset = ( param_vtype != vtype ); // zp
if( reset ){ //zp 
 Dispose(); //zp
 vtype = param_vtype; //zp
 Init(parent); //zp
} //zp

int j; for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] = 0;

int vi; for(vi=0;vi<8;vi++) {
	 if(!pressed[vi]) continue; 

	 // our voices are silent without dsp
	 // getVoices()[vi].dsp(); //zp
	 // for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += getVoices()[vi].dsp_out[j]; // zp

	 // our vtype determines algo dsp
	 if( vtype == 1 ){
	  get200Algo1()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo1()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 2 ){
	  get200Algo2()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo2()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 3 ){
	  get200Algo3()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo3()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 4 ){
	  get200Algo4()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo4()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 5 ){
	  get200Algo5()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo5()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
}
}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ( 0 > 0 && dev > 0 && 0 != dev) return;
if ( 0 > 0 && port > 0 && 0 != port) return;

if( status == MIDI_PROGRAM_CHANGE + 0 && (data1<127) ){ //zp
  uint8_t PExVal = (data1 < 5) ? data1 : 5; // NUM_VTYPES //zp
  int     PExIdx = rootc::PARAM_INDEX_patcher__1_vtype + 0; //zp KLUDGE HERE
  PExParameterChange( &parent->PExch[ PExIdx ], PExVal, 0xFFEF);
}
else if( status == MIDI_PROGRAM_CHANGE + 0 && (data1==127) ){ //zp
  uint8_t txChan = 0;
  
  MidiSend2((midi_device_t) MIDI_DEVICE_DIN, 1, txChan + MIDI_PROGRAM_CHANGE, vtype&0x7F ); //2byte
  chThdSleepMilliseconds(400);
 
  if( vtype == 1 ){ instanceccMGR::txState( 1, &get200Algo1()[0].PExch[0], txChan ); }
  if( vtype == 2 ){ instanceccMGR::txState( 2, &get200Algo2()[0].PExch[0], txChan ); }
  if( vtype == 3 ){ instanceccMGR::txState( 3, &get200Algo3()[0].PExch[0], txChan ); }
  if( vtype == 4 ){ instanceccMGR::txState( 4, &get200Algo4()[0].PExch[0], txChan ); }
  if( vtype == 5 ){ instanceccMGR::txState( 5, &get200Algo5()[0].PExch[0], txChan ); }
  
  
} else if ((status == MIDI_NOTE_ON + 0) && (data2)) {
  int min = 1<<30;
  int mini = 0;
  int i;
  for(i=0;i<8;i++){
    if (voicePriority[i] < min){
      min = voicePriority[i];
      mini = i;
    }
  }
  voicePriority[mini] = 100000+priority++;
  notePlaying[mini] = data1;
  pressed[mini] = 1;

  if( vtype == 1 ) get200Algo1()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 2 ) get200Algo2()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 3 ) get200Algo3()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 4 ) get200Algo4()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 5 ) get200Algo5()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  
  
} else if (((status == MIDI_NOTE_ON + 0) && (!data2))||
          (status == MIDI_NOTE_OFF + 0)) {
          	
  int i; for(i=0;i<8;i++){
    if ((notePlaying[i] == data1) && pressed[i]){
      voicePriority[i] = priority++;
      pressed[i] = 0;
    }
  }
} else if (status == 0 + MIDI_CONTROL_CHANGE) {
  int i; for(i=0;i<8;i++) getVoices()[i].MidiInHandler(dev, port, status, data1, data2); //zp
}}
}
}
;class instancepatcher__2{
  public: // v1
  rootc *parent;
//KeyValuePair KVP_instancepatcher__2_vtype;
int32_t vtype = 0; // zp
class voice {
   public:
   int polyIndex;
      
instancepatcher__2 *common;
void Init(voice *parent) {
	if( common->vtype == 1 )
	{
      instancealgo__1::voice* av = &common->get200Algo1()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 2 )
	{
      instancealgo__2::voice* av = &common->get200Algo2()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 3 )
	{
      instancealgo__3::voice* av = &common->get200Algo3()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 4 )
	{
      instancealgo__4::voice* av = &common->get200Algo4()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 5 )
	{
      instancealgo__5::voice* av = &common->get200Algo5()[polyIndex]; //zp
      av->Init( av ); //zp
	}
}
void dsp(void) { } //zp
void dispose(void) {
   if( common->vtype == 1 ) common->get200Algo1()[polyIndex].dispose(); //zp
   if( common->vtype == 2 ) common->get200Algo2()[polyIndex].dispose(); //zp
   if( common->vtype == 3 ) common->get200Algo3()[polyIndex].dispose(); //zp
   if( common->vtype == 4 ) common->get200Algo4()[polyIndex].dispose(); //zp
   if( common->vtype == 5 ) common->get200Algo5()[polyIndex].dispose(); //zp
}
void MidiInHandler(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2) {
  // passthru cc to voice
  if( common->vtype == 1 ) common->get200Algo1()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 2 ) common->get200Algo2()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 3 ) common->get200Algo3()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 4 ) common->get200Algo4()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 5 ) common->get200Algo5()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp

  // ccMGR paramexchange
  if( common->vtype == 1 ) instanceccMGR::setPEx( 1, &common->get200Algo1()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 2 ) instanceccMGR::setPEx( 2, &common->get200Algo2()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 3 ) instanceccMGR::setPEx( 3, &common->get200Algo3()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 4 ) instanceccMGR::setPEx( 4, &common->get200Algo4()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 5 ) instanceccMGR::setPEx( 5, &common->get200Algo5()[polyIndex], data1, data2 ); //zp
}

};

static voice * getVoices(void){
    static voice v[8];
    return v;
}


static instancealgo__1::voice * get200Algo1(){    //zp
	static instancealgo__1::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__2::voice * get200Algo2(){    //zp
	static instancealgo__2::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__3::voice * get200Algo3(){    //zp
	static instancealgo__3::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__4::voice * get200Algo4(){    //zp
	static instancealgo__4::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__5::voice * get200Algo5(){    //zp
	static instancealgo__5::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}

void setParamBatch( const int32_t *srcV, uint8_t NV, ParameterExchange_t *targetPE ) {
  for(int j=0;j<NV;j++) {
	targetPE[j].value = srcV[j];
	targetPE[j].modvalue = srcV[j];
	targetPE[j].signals = 0;
	targetPE[j].pfunction = 0;
  }
}

int8_t notePlaying[8];
int32_t voicePriority[8];
int32_t priority;
int32_t sustain;
int8_t pressed[8];
  public: void Init(rootc * _parent) {
parent = _parent;
for(int vi=0;vi<8;vi++){ //zp
   if( vtype == 1 ) setParamBatch( instancealgo__1::GetInitParams(), instancealgo__1::NPEXCH, &get200Algo1()[vi].PExch[0] );
   if( vtype == 2 ) setParamBatch( instancealgo__2::GetInitParams(), instancealgo__2::NPEXCH, &get200Algo2()[vi].PExch[0] );
   if( vtype == 3 ) setParamBatch( instancealgo__3::GetInitParams(), instancealgo__3::NPEXCH, &get200Algo3()[vi].PExch[0] );
   if( vtype == 4 ) setParamBatch( instancealgo__4::GetInitParams(), instancealgo__4::NPEXCH, &get200Algo4()[vi].PExch[0] );
   if( vtype == 5 ) setParamBatch( instancealgo__5::GetInitParams(), instancealgo__5::NPEXCH, &get200Algo5()[vi].PExch[0] );
} //zp

int vi; for(vi=0;vi<8;vi++) {
   voice *v = &getVoices()[vi];
   v->polyIndex = vi;
   v->common = this;
   v->Init(&getVoices()[vi]); 
   notePlaying[vi]=0;
   voicePriority[vi]=0;
}

priority=0;
sustain=0;
}
  public: void Dispose() {
int vi; for(vi=0;vi<8;vi++) {
  voice *v = &getVoices()[vi];
  v->dispose();
}
}
  public: void dsp (int32buffer  & outlet_outlet__1,
int param_vtype  ){
bool reset = ( param_vtype != vtype ); // zp
if( reset ){ //zp 
 Dispose(); //zp
 vtype = param_vtype; //zp
 Init(parent); //zp
} //zp

int j; for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] = 0;

int vi; for(vi=0;vi<8;vi++) {
	 if(!pressed[vi]) continue; 

	 // our voices are silent without dsp
	 // getVoices()[vi].dsp(); //zp
	 // for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += getVoices()[vi].dsp_out[j]; // zp

	 // our vtype determines algo dsp
	 if( vtype == 1 ){
	  get200Algo1()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo1()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 2 ){
	  get200Algo2()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo2()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 3 ){
	  get200Algo3()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo3()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 4 ){
	  get200Algo4()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo4()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 5 ){
	  get200Algo5()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo5()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
}
}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ( 0 > 0 && dev > 0 && 0 != dev) return;
if ( 0 > 0 && port > 0 && 0 != port) return;

if( status == MIDI_PROGRAM_CHANGE + 1 && (data1<127) ){ //zp
  uint8_t PExVal = (data1 < 5) ? data1 : 5; // NUM_VTYPES //zp
  int     PExIdx = rootc::PARAM_INDEX_patcher__1_vtype + 1; //zp KLUDGE HERE
  PExParameterChange( &parent->PExch[ PExIdx ], PExVal, 0xFFEF);
}
else if( status == MIDI_PROGRAM_CHANGE + 1 && (data1==127) ){ //zp
  uint8_t txChan = 1;
  
  MidiSend2((midi_device_t) MIDI_DEVICE_DIN, 1, txChan + MIDI_PROGRAM_CHANGE, vtype&0x7F ); //2byte
  chThdSleepMilliseconds(400);
 
  if( vtype == 1 ){ instanceccMGR::txState( 1, &get200Algo1()[0].PExch[0], txChan ); }
  if( vtype == 2 ){ instanceccMGR::txState( 2, &get200Algo2()[0].PExch[0], txChan ); }
  if( vtype == 3 ){ instanceccMGR::txState( 3, &get200Algo3()[0].PExch[0], txChan ); }
  if( vtype == 4 ){ instanceccMGR::txState( 4, &get200Algo4()[0].PExch[0], txChan ); }
  if( vtype == 5 ){ instanceccMGR::txState( 5, &get200Algo5()[0].PExch[0], txChan ); }
  
  
} else if ((status == MIDI_NOTE_ON + 1) && (data2)) {
  int min = 1<<30;
  int mini = 0;
  int i;
  for(i=0;i<8;i++){
    if (voicePriority[i] < min){
      min = voicePriority[i];
      mini = i;
    }
  }
  voicePriority[mini] = 100000+priority++;
  notePlaying[mini] = data1;
  pressed[mini] = 1;

  if( vtype == 1 ) get200Algo1()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 2 ) get200Algo2()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 3 ) get200Algo3()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 4 ) get200Algo4()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 5 ) get200Algo5()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  
  
} else if (((status == MIDI_NOTE_ON + 1) && (!data2))||
          (status == MIDI_NOTE_OFF + 1)) {
          	
  int i; for(i=0;i<8;i++){
    if ((notePlaying[i] == data1) && pressed[i]){
      voicePriority[i] = priority++;
      pressed[i] = 0;
    }
  }
} else if (status == 1 + MIDI_CONTROL_CHANGE) {
  int i; for(i=0;i<8;i++) getVoices()[i].MidiInHandler(dev, port, status, data1, data2); //zp
}}
}
}
;class instancepatcher__3{
  public: // v1
  rootc *parent;
//KeyValuePair KVP_instancepatcher__3_vtype;
int32_t vtype = 0; // zp
class voice {
   public:
   int polyIndex;
      
instancepatcher__3 *common;
void Init(voice *parent) {
	if( common->vtype == 1 )
	{
      instancealgo__1::voice* av = &common->get200Algo1()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 2 )
	{
      instancealgo__2::voice* av = &common->get200Algo2()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 3 )
	{
      instancealgo__3::voice* av = &common->get200Algo3()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 4 )
	{
      instancealgo__4::voice* av = &common->get200Algo4()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 5 )
	{
      instancealgo__5::voice* av = &common->get200Algo5()[polyIndex]; //zp
      av->Init( av ); //zp
	}
}
void dsp(void) { } //zp
void dispose(void) {
   if( common->vtype == 1 ) common->get200Algo1()[polyIndex].dispose(); //zp
   if( common->vtype == 2 ) common->get200Algo2()[polyIndex].dispose(); //zp
   if( common->vtype == 3 ) common->get200Algo3()[polyIndex].dispose(); //zp
   if( common->vtype == 4 ) common->get200Algo4()[polyIndex].dispose(); //zp
   if( common->vtype == 5 ) common->get200Algo5()[polyIndex].dispose(); //zp
}
void MidiInHandler(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2) {
  // passthru cc to voice
  if( common->vtype == 1 ) common->get200Algo1()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 2 ) common->get200Algo2()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 3 ) common->get200Algo3()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 4 ) common->get200Algo4()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 5 ) common->get200Algo5()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp

  // ccMGR paramexchange
  if( common->vtype == 1 ) instanceccMGR::setPEx( 1, &common->get200Algo1()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 2 ) instanceccMGR::setPEx( 2, &common->get200Algo2()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 3 ) instanceccMGR::setPEx( 3, &common->get200Algo3()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 4 ) instanceccMGR::setPEx( 4, &common->get200Algo4()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 5 ) instanceccMGR::setPEx( 5, &common->get200Algo5()[polyIndex], data1, data2 ); //zp
}

};

static voice * getVoices(void){
    static voice v[8];
    return v;
}


static instancealgo__1::voice * get200Algo1(){    //zp
	static instancealgo__1::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__2::voice * get200Algo2(){    //zp
	static instancealgo__2::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__3::voice * get200Algo3(){    //zp
	static instancealgo__3::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__4::voice * get200Algo4(){    //zp
	static instancealgo__4::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__5::voice * get200Algo5(){    //zp
	static instancealgo__5::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}

void setParamBatch( const int32_t *srcV, uint8_t NV, ParameterExchange_t *targetPE ) {
  for(int j=0;j<NV;j++) {
	targetPE[j].value = srcV[j];
	targetPE[j].modvalue = srcV[j];
	targetPE[j].signals = 0;
	targetPE[j].pfunction = 0;
  }
}

int8_t notePlaying[8];
int32_t voicePriority[8];
int32_t priority;
int32_t sustain;
int8_t pressed[8];
  public: void Init(rootc * _parent) {
parent = _parent;
for(int vi=0;vi<8;vi++){ //zp
   if( vtype == 1 ) setParamBatch( instancealgo__1::GetInitParams(), instancealgo__1::NPEXCH, &get200Algo1()[vi].PExch[0] );
   if( vtype == 2 ) setParamBatch( instancealgo__2::GetInitParams(), instancealgo__2::NPEXCH, &get200Algo2()[vi].PExch[0] );
   if( vtype == 3 ) setParamBatch( instancealgo__3::GetInitParams(), instancealgo__3::NPEXCH, &get200Algo3()[vi].PExch[0] );
   if( vtype == 4 ) setParamBatch( instancealgo__4::GetInitParams(), instancealgo__4::NPEXCH, &get200Algo4()[vi].PExch[0] );
   if( vtype == 5 ) setParamBatch( instancealgo__5::GetInitParams(), instancealgo__5::NPEXCH, &get200Algo5()[vi].PExch[0] );
} //zp

int vi; for(vi=0;vi<8;vi++) {
   voice *v = &getVoices()[vi];
   v->polyIndex = vi;
   v->common = this;
   v->Init(&getVoices()[vi]); 
   notePlaying[vi]=0;
   voicePriority[vi]=0;
}

priority=0;
sustain=0;
}
  public: void Dispose() {
int vi; for(vi=0;vi<8;vi++) {
  voice *v = &getVoices()[vi];
  v->dispose();
}
}
  public: void dsp (int32buffer  & outlet_outlet__1,
int param_vtype  ){
bool reset = ( param_vtype != vtype ); // zp
if( reset ){ //zp 
 Dispose(); //zp
 vtype = param_vtype; //zp
 Init(parent); //zp
} //zp

int j; for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] = 0;

int vi; for(vi=0;vi<8;vi++) {
	 if(!pressed[vi]) continue; 

	 // our voices are silent without dsp
	 // getVoices()[vi].dsp(); //zp
	 // for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += getVoices()[vi].dsp_out[j]; // zp

	 // our vtype determines algo dsp
	 if( vtype == 1 ){
	  get200Algo1()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo1()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 2 ){
	  get200Algo2()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo2()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 3 ){
	  get200Algo3()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo3()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 4 ){
	  get200Algo4()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo4()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 5 ){
	  get200Algo5()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo5()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
}
}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ( 0 > 0 && dev > 0 && 0 != dev) return;
if ( 0 > 0 && port > 0 && 0 != port) return;

if( status == MIDI_PROGRAM_CHANGE + 2 && (data1<127) ){ //zp
  uint8_t PExVal = (data1 < 5) ? data1 : 5; // NUM_VTYPES //zp
  int     PExIdx = rootc::PARAM_INDEX_patcher__1_vtype + 2; //zp KLUDGE HERE
  PExParameterChange( &parent->PExch[ PExIdx ], PExVal, 0xFFEF);
}
else if( status == MIDI_PROGRAM_CHANGE + 2 && (data1==127) ){ //zp
  uint8_t txChan = 2;
  
  MidiSend2((midi_device_t) MIDI_DEVICE_DIN, 1, txChan + MIDI_PROGRAM_CHANGE, vtype&0x7F ); //2byte
  chThdSleepMilliseconds(400);
 
  if( vtype == 1 ){ instanceccMGR::txState( 1, &get200Algo1()[0].PExch[0], txChan ); }
  if( vtype == 2 ){ instanceccMGR::txState( 2, &get200Algo2()[0].PExch[0], txChan ); }
  if( vtype == 3 ){ instanceccMGR::txState( 3, &get200Algo3()[0].PExch[0], txChan ); }
  if( vtype == 4 ){ instanceccMGR::txState( 4, &get200Algo4()[0].PExch[0], txChan ); }
  if( vtype == 5 ){ instanceccMGR::txState( 5, &get200Algo5()[0].PExch[0], txChan ); }
  
  
} else if ((status == MIDI_NOTE_ON + 2) && (data2)) {
  int min = 1<<30;
  int mini = 0;
  int i;
  for(i=0;i<8;i++){
    if (voicePriority[i] < min){
      min = voicePriority[i];
      mini = i;
    }
  }
  voicePriority[mini] = 100000+priority++;
  notePlaying[mini] = data1;
  pressed[mini] = 1;

  if( vtype == 1 ) get200Algo1()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 2 ) get200Algo2()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 3 ) get200Algo3()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 4 ) get200Algo4()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 5 ) get200Algo5()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  
  
} else if (((status == MIDI_NOTE_ON + 2) && (!data2))||
          (status == MIDI_NOTE_OFF + 2)) {
          	
  int i; for(i=0;i<8;i++){
    if ((notePlaying[i] == data1) && pressed[i]){
      voicePriority[i] = priority++;
      pressed[i] = 0;
    }
  }
} else if (status == 2 + MIDI_CONTROL_CHANGE) {
  int i; for(i=0;i<8;i++) getVoices()[i].MidiInHandler(dev, port, status, data1, data2); //zp
}}
}
}
;class instancepatcher__4{
  public: // v1
  rootc *parent;
//KeyValuePair KVP_instancepatcher__4_vtype;
int32_t vtype = 0; // zp
class voice {
   public:
   int polyIndex;
      
instancepatcher__4 *common;
void Init(voice *parent) {
	if( common->vtype == 1 )
	{
      instancealgo__1::voice* av = &common->get200Algo1()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 2 )
	{
      instancealgo__2::voice* av = &common->get200Algo2()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 3 )
	{
      instancealgo__3::voice* av = &common->get200Algo3()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 4 )
	{
      instancealgo__4::voice* av = &common->get200Algo4()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 5 )
	{
      instancealgo__5::voice* av = &common->get200Algo5()[polyIndex]; //zp
      av->Init( av ); //zp
	}
}
void dsp(void) { } //zp
void dispose(void) {
   if( common->vtype == 1 ) common->get200Algo1()[polyIndex].dispose(); //zp
   if( common->vtype == 2 ) common->get200Algo2()[polyIndex].dispose(); //zp
   if( common->vtype == 3 ) common->get200Algo3()[polyIndex].dispose(); //zp
   if( common->vtype == 4 ) common->get200Algo4()[polyIndex].dispose(); //zp
   if( common->vtype == 5 ) common->get200Algo5()[polyIndex].dispose(); //zp
}
void MidiInHandler(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2) {
  // passthru cc to voice
  if( common->vtype == 1 ) common->get200Algo1()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 2 ) common->get200Algo2()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 3 ) common->get200Algo3()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 4 ) common->get200Algo4()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 5 ) common->get200Algo5()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp

  // ccMGR paramexchange
  if( common->vtype == 1 ) instanceccMGR::setPEx( 1, &common->get200Algo1()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 2 ) instanceccMGR::setPEx( 2, &common->get200Algo2()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 3 ) instanceccMGR::setPEx( 3, &common->get200Algo3()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 4 ) instanceccMGR::setPEx( 4, &common->get200Algo4()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 5 ) instanceccMGR::setPEx( 5, &common->get200Algo5()[polyIndex], data1, data2 ); //zp
}

};

static voice * getVoices(void){
    static voice v[8];
    return v;
}


static instancealgo__1::voice * get200Algo1(){    //zp
	static instancealgo__1::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__2::voice * get200Algo2(){    //zp
	static instancealgo__2::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__3::voice * get200Algo3(){    //zp
	static instancealgo__3::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__4::voice * get200Algo4(){    //zp
	static instancealgo__4::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__5::voice * get200Algo5(){    //zp
	static instancealgo__5::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}

void setParamBatch( const int32_t *srcV, uint8_t NV, ParameterExchange_t *targetPE ) {
  for(int j=0;j<NV;j++) {
	targetPE[j].value = srcV[j];
	targetPE[j].modvalue = srcV[j];
	targetPE[j].signals = 0;
	targetPE[j].pfunction = 0;
  }
}

int8_t notePlaying[8];
int32_t voicePriority[8];
int32_t priority;
int32_t sustain;
int8_t pressed[8];
  public: void Init(rootc * _parent) {
parent = _parent;
for(int vi=0;vi<8;vi++){ //zp
   if( vtype == 1 ) setParamBatch( instancealgo__1::GetInitParams(), instancealgo__1::NPEXCH, &get200Algo1()[vi].PExch[0] );
   if( vtype == 2 ) setParamBatch( instancealgo__2::GetInitParams(), instancealgo__2::NPEXCH, &get200Algo2()[vi].PExch[0] );
   if( vtype == 3 ) setParamBatch( instancealgo__3::GetInitParams(), instancealgo__3::NPEXCH, &get200Algo3()[vi].PExch[0] );
   if( vtype == 4 ) setParamBatch( instancealgo__4::GetInitParams(), instancealgo__4::NPEXCH, &get200Algo4()[vi].PExch[0] );
   if( vtype == 5 ) setParamBatch( instancealgo__5::GetInitParams(), instancealgo__5::NPEXCH, &get200Algo5()[vi].PExch[0] );
} //zp

int vi; for(vi=0;vi<8;vi++) {
   voice *v = &getVoices()[vi];
   v->polyIndex = vi;
   v->common = this;
   v->Init(&getVoices()[vi]); 
   notePlaying[vi]=0;
   voicePriority[vi]=0;
}

priority=0;
sustain=0;
}
  public: void Dispose() {
int vi; for(vi=0;vi<8;vi++) {
  voice *v = &getVoices()[vi];
  v->dispose();
}
}
  public: void dsp (int32buffer  & outlet_outlet__1,
int param_vtype  ){
bool reset = ( param_vtype != vtype ); // zp
if( reset ){ //zp 
 Dispose(); //zp
 vtype = param_vtype; //zp
 Init(parent); //zp
} //zp

int j; for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] = 0;

int vi; for(vi=0;vi<8;vi++) {
	 if(!pressed[vi]) continue; 

	 // our voices are silent without dsp
	 // getVoices()[vi].dsp(); //zp
	 // for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += getVoices()[vi].dsp_out[j]; // zp

	 // our vtype determines algo dsp
	 if( vtype == 1 ){
	  get200Algo1()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo1()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 2 ){
	  get200Algo2()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo2()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 3 ){
	  get200Algo3()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo3()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 4 ){
	  get200Algo4()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo4()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 5 ){
	  get200Algo5()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo5()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
}
}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ( 0 > 0 && dev > 0 && 0 != dev) return;
if ( 0 > 0 && port > 0 && 0 != port) return;

if( status == MIDI_PROGRAM_CHANGE + 3 && (data1<127) ){ //zp
  uint8_t PExVal = (data1 < 5) ? data1 : 5; // NUM_VTYPES //zp
  int     PExIdx = rootc::PARAM_INDEX_patcher__1_vtype + 3; //zp KLUDGE HERE
  PExParameterChange( &parent->PExch[ PExIdx ], PExVal, 0xFFEF);
}
else if( status == MIDI_PROGRAM_CHANGE + 3 && (data1==127) ){ //zp
  uint8_t txChan = 3;
  
  MidiSend2((midi_device_t) MIDI_DEVICE_DIN, 1, txChan + MIDI_PROGRAM_CHANGE, vtype&0x7F ); //2byte
  chThdSleepMilliseconds(400);
 
  if( vtype == 1 ){ instanceccMGR::txState( 1, &get200Algo1()[0].PExch[0], txChan ); }
  if( vtype == 2 ){ instanceccMGR::txState( 2, &get200Algo2()[0].PExch[0], txChan ); }
  if( vtype == 3 ){ instanceccMGR::txState( 3, &get200Algo3()[0].PExch[0], txChan ); }
  if( vtype == 4 ){ instanceccMGR::txState( 4, &get200Algo4()[0].PExch[0], txChan ); }
  if( vtype == 5 ){ instanceccMGR::txState( 5, &get200Algo5()[0].PExch[0], txChan ); }
  
  
} else if ((status == MIDI_NOTE_ON + 3) && (data2)) {
  int min = 1<<30;
  int mini = 0;
  int i;
  for(i=0;i<8;i++){
    if (voicePriority[i] < min){
      min = voicePriority[i];
      mini = i;
    }
  }
  voicePriority[mini] = 100000+priority++;
  notePlaying[mini] = data1;
  pressed[mini] = 1;

  if( vtype == 1 ) get200Algo1()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 2 ) get200Algo2()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 3 ) get200Algo3()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 4 ) get200Algo4()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 5 ) get200Algo5()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  
  
} else if (((status == MIDI_NOTE_ON + 3) && (!data2))||
          (status == MIDI_NOTE_OFF + 3)) {
          	
  int i; for(i=0;i<8;i++){
    if ((notePlaying[i] == data1) && pressed[i]){
      voicePriority[i] = priority++;
      pressed[i] = 0;
    }
  }
} else if (status == 3 + MIDI_CONTROL_CHANGE) {
  int i; for(i=0;i<8;i++) getVoices()[i].MidiInHandler(dev, port, status, data1, data2); //zp
}}
}
}
;class instancepatcher__5{
  public: // v1
  rootc *parent;
//KeyValuePair KVP_instancepatcher__5_vtype;
int32_t vtype = 0; // zp
class voice {
   public:
   int polyIndex;
      
instancepatcher__5 *common;
void Init(voice *parent) {
	if( common->vtype == 1 )
	{
      instancealgo__1::voice* av = &common->get200Algo1()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 2 )
	{
      instancealgo__2::voice* av = &common->get200Algo2()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 3 )
	{
      instancealgo__3::voice* av = &common->get200Algo3()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 4 )
	{
      instancealgo__4::voice* av = &common->get200Algo4()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 5 )
	{
      instancealgo__5::voice* av = &common->get200Algo5()[polyIndex]; //zp
      av->Init( av ); //zp
	}
}
void dsp(void) { } //zp
void dispose(void) {
   if( common->vtype == 1 ) common->get200Algo1()[polyIndex].dispose(); //zp
   if( common->vtype == 2 ) common->get200Algo2()[polyIndex].dispose(); //zp
   if( common->vtype == 3 ) common->get200Algo3()[polyIndex].dispose(); //zp
   if( common->vtype == 4 ) common->get200Algo4()[polyIndex].dispose(); //zp
   if( common->vtype == 5 ) common->get200Algo5()[polyIndex].dispose(); //zp
}
void MidiInHandler(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2) {
  // passthru cc to voice
  if( common->vtype == 1 ) common->get200Algo1()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 2 ) common->get200Algo2()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 3 ) common->get200Algo3()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 4 ) common->get200Algo4()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 5 ) common->get200Algo5()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp

  // ccMGR paramexchange
  if( common->vtype == 1 ) instanceccMGR::setPEx( 1, &common->get200Algo1()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 2 ) instanceccMGR::setPEx( 2, &common->get200Algo2()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 3 ) instanceccMGR::setPEx( 3, &common->get200Algo3()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 4 ) instanceccMGR::setPEx( 4, &common->get200Algo4()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 5 ) instanceccMGR::setPEx( 5, &common->get200Algo5()[polyIndex], data1, data2 ); //zp
}

};

static voice * getVoices(void){
    static voice v[8];
    return v;
}


static instancealgo__1::voice * get200Algo1(){    //zp
	static instancealgo__1::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__2::voice * get200Algo2(){    //zp
	static instancealgo__2::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__3::voice * get200Algo3(){    //zp
	static instancealgo__3::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__4::voice * get200Algo4(){    //zp
	static instancealgo__4::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__5::voice * get200Algo5(){    //zp
	static instancealgo__5::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}

void setParamBatch( const int32_t *srcV, uint8_t NV, ParameterExchange_t *targetPE ) {
  for(int j=0;j<NV;j++) {
	targetPE[j].value = srcV[j];
	targetPE[j].modvalue = srcV[j];
	targetPE[j].signals = 0;
	targetPE[j].pfunction = 0;
  }
}

int8_t notePlaying[8];
int32_t voicePriority[8];
int32_t priority;
int32_t sustain;
int8_t pressed[8];
  public: void Init(rootc * _parent) {
parent = _parent;
for(int vi=0;vi<8;vi++){ //zp
   if( vtype == 1 ) setParamBatch( instancealgo__1::GetInitParams(), instancealgo__1::NPEXCH, &get200Algo1()[vi].PExch[0] );
   if( vtype == 2 ) setParamBatch( instancealgo__2::GetInitParams(), instancealgo__2::NPEXCH, &get200Algo2()[vi].PExch[0] );
   if( vtype == 3 ) setParamBatch( instancealgo__3::GetInitParams(), instancealgo__3::NPEXCH, &get200Algo3()[vi].PExch[0] );
   if( vtype == 4 ) setParamBatch( instancealgo__4::GetInitParams(), instancealgo__4::NPEXCH, &get200Algo4()[vi].PExch[0] );
   if( vtype == 5 ) setParamBatch( instancealgo__5::GetInitParams(), instancealgo__5::NPEXCH, &get200Algo5()[vi].PExch[0] );
} //zp

int vi; for(vi=0;vi<8;vi++) {
   voice *v = &getVoices()[vi];
   v->polyIndex = vi;
   v->common = this;
   v->Init(&getVoices()[vi]); 
   notePlaying[vi]=0;
   voicePriority[vi]=0;
}

priority=0;
sustain=0;
}
  public: void Dispose() {
int vi; for(vi=0;vi<8;vi++) {
  voice *v = &getVoices()[vi];
  v->dispose();
}
}
  public: void dsp (int32buffer  & outlet_outlet__1,
int param_vtype  ){
bool reset = ( param_vtype != vtype ); // zp
if( reset ){ //zp 
 Dispose(); //zp
 vtype = param_vtype; //zp
 Init(parent); //zp
} //zp

int j; for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] = 0;

int vi; for(vi=0;vi<8;vi++) {
	 if(!pressed[vi]) continue; 

	 // our voices are silent without dsp
	 // getVoices()[vi].dsp(); //zp
	 // for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += getVoices()[vi].dsp_out[j]; // zp

	 // our vtype determines algo dsp
	 if( vtype == 1 ){
	  get200Algo1()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo1()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 2 ){
	  get200Algo2()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo2()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 3 ){
	  get200Algo3()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo3()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 4 ){
	  get200Algo4()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo4()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 5 ){
	  get200Algo5()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo5()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
}
}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ( 0 > 0 && dev > 0 && 0 != dev) return;
if ( 0 > 0 && port > 0 && 0 != port) return;

if( status == MIDI_PROGRAM_CHANGE + 4 && (data1<127) ){ //zp
  uint8_t PExVal = (data1 < 5) ? data1 : 5; // NUM_VTYPES //zp
  int     PExIdx = rootc::PARAM_INDEX_patcher__1_vtype + 4; //zp KLUDGE HERE
  PExParameterChange( &parent->PExch[ PExIdx ], PExVal, 0xFFEF);
}
else if( status == MIDI_PROGRAM_CHANGE + 4 && (data1==127) ){ //zp
  uint8_t txChan = 4;
  
  MidiSend2((midi_device_t) MIDI_DEVICE_DIN, 1, txChan + MIDI_PROGRAM_CHANGE, vtype&0x7F ); //2byte
  chThdSleepMilliseconds(400);
 
  if( vtype == 1 ){ instanceccMGR::txState( 1, &get200Algo1()[0].PExch[0], txChan ); }
  if( vtype == 2 ){ instanceccMGR::txState( 2, &get200Algo2()[0].PExch[0], txChan ); }
  if( vtype == 3 ){ instanceccMGR::txState( 3, &get200Algo3()[0].PExch[0], txChan ); }
  if( vtype == 4 ){ instanceccMGR::txState( 4, &get200Algo4()[0].PExch[0], txChan ); }
  if( vtype == 5 ){ instanceccMGR::txState( 5, &get200Algo5()[0].PExch[0], txChan ); }
  
  
} else if ((status == MIDI_NOTE_ON + 4) && (data2)) {
  int min = 1<<30;
  int mini = 0;
  int i;
  for(i=0;i<8;i++){
    if (voicePriority[i] < min){
      min = voicePriority[i];
      mini = i;
    }
  }
  voicePriority[mini] = 100000+priority++;
  notePlaying[mini] = data1;
  pressed[mini] = 1;

  if( vtype == 1 ) get200Algo1()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 2 ) get200Algo2()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 3 ) get200Algo3()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 4 ) get200Algo4()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 5 ) get200Algo5()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  
  
} else if (((status == MIDI_NOTE_ON + 4) && (!data2))||
          (status == MIDI_NOTE_OFF + 4)) {
          	
  int i; for(i=0;i<8;i++){
    if ((notePlaying[i] == data1) && pressed[i]){
      voicePriority[i] = priority++;
      pressed[i] = 0;
    }
  }
} else if (status == 4 + MIDI_CONTROL_CHANGE) {
  int i; for(i=0;i<8;i++) getVoices()[i].MidiInHandler(dev, port, status, data1, data2); //zp
}}
}
}
;class instancepatcher__6{
  public: // v1
  rootc *parent;
//KeyValuePair KVP_instancepatcher__6_vtype;
int32_t vtype = 0; // zp
class voice {
   public:
   int polyIndex;
      
instancepatcher__6 *common;
void Init(voice *parent) {
	if( common->vtype == 1 )
	{
      instancealgo__1::voice* av = &common->get200Algo1()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 2 )
	{
      instancealgo__2::voice* av = &common->get200Algo2()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 3 )
	{
      instancealgo__3::voice* av = &common->get200Algo3()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 4 )
	{
      instancealgo__4::voice* av = &common->get200Algo4()[polyIndex]; //zp
      av->Init( av ); //zp
	}
	if( common->vtype == 5 )
	{
      instancealgo__5::voice* av = &common->get200Algo5()[polyIndex]; //zp
      av->Init( av ); //zp
	}
}
void dsp(void) { } //zp
void dispose(void) {
   if( common->vtype == 1 ) common->get200Algo1()[polyIndex].dispose(); //zp
   if( common->vtype == 2 ) common->get200Algo2()[polyIndex].dispose(); //zp
   if( common->vtype == 3 ) common->get200Algo3()[polyIndex].dispose(); //zp
   if( common->vtype == 4 ) common->get200Algo4()[polyIndex].dispose(); //zp
   if( common->vtype == 5 ) common->get200Algo5()[polyIndex].dispose(); //zp
}
void MidiInHandler(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2) {
  // passthru cc to voice
  if( common->vtype == 1 ) common->get200Algo1()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 2 ) common->get200Algo2()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 3 ) common->get200Algo3()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 4 ) common->get200Algo4()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( common->vtype == 5 ) common->get200Algo5()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp

  // ccMGR paramexchange
  if( common->vtype == 1 ) instanceccMGR::setPEx( 1, &common->get200Algo1()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 2 ) instanceccMGR::setPEx( 2, &common->get200Algo2()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 3 ) instanceccMGR::setPEx( 3, &common->get200Algo3()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 4 ) instanceccMGR::setPEx( 4, &common->get200Algo4()[polyIndex], data1, data2 ); //zp
  if( common->vtype == 5 ) instanceccMGR::setPEx( 5, &common->get200Algo5()[polyIndex], data1, data2 ); //zp
}

};

static voice * getVoices(void){
    static voice v[8];
    return v;
}


static instancealgo__1::voice * get200Algo1(){    //zp
	static instancealgo__1::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__2::voice * get200Algo2(){    //zp
	static instancealgo__2::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__3::voice * get200Algo3(){    //zp
	static instancealgo__3::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__4::voice * get200Algo4(){    //zp
	static instancealgo__4::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__5::voice * get200Algo5(){    //zp
	static instancealgo__5::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}

void setParamBatch( const int32_t *srcV, uint8_t NV, ParameterExchange_t *targetPE ) {
  for(int j=0;j<NV;j++) {
	targetPE[j].value = srcV[j];
	targetPE[j].modvalue = srcV[j];
	targetPE[j].signals = 0;
	targetPE[j].pfunction = 0;
  }
}

int8_t notePlaying[8];
int32_t voicePriority[8];
int32_t priority;
int32_t sustain;
int8_t pressed[8];
  public: void Init(rootc * _parent) {
parent = _parent;
for(int vi=0;vi<8;vi++){ //zp
   if( vtype == 1 ) setParamBatch( instancealgo__1::GetInitParams(), instancealgo__1::NPEXCH, &get200Algo1()[vi].PExch[0] );
   if( vtype == 2 ) setParamBatch( instancealgo__2::GetInitParams(), instancealgo__2::NPEXCH, &get200Algo2()[vi].PExch[0] );
   if( vtype == 3 ) setParamBatch( instancealgo__3::GetInitParams(), instancealgo__3::NPEXCH, &get200Algo3()[vi].PExch[0] );
   if( vtype == 4 ) setParamBatch( instancealgo__4::GetInitParams(), instancealgo__4::NPEXCH, &get200Algo4()[vi].PExch[0] );
   if( vtype == 5 ) setParamBatch( instancealgo__5::GetInitParams(), instancealgo__5::NPEXCH, &get200Algo5()[vi].PExch[0] );
} //zp

int vi; for(vi=0;vi<8;vi++) {
   voice *v = &getVoices()[vi];
   v->polyIndex = vi;
   v->common = this;
   v->Init(&getVoices()[vi]); 
   notePlaying[vi]=0;
   voicePriority[vi]=0;
}

priority=0;
sustain=0;
}
  public: void Dispose() {
int vi; for(vi=0;vi<8;vi++) {
  voice *v = &getVoices()[vi];
  v->dispose();
}
}
  public: void dsp (int32buffer  & outlet_outlet__1,
int param_vtype  ){
bool reset = ( param_vtype != vtype ); // zp
if( reset ){ //zp 
 Dispose(); //zp
 vtype = param_vtype; //zp
 Init(parent); //zp
} //zp

int j; for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] = 0;

int vi; for(vi=0;vi<8;vi++) {
	 if(!pressed[vi]) continue; 

	 // our voices are silent without dsp
	 // getVoices()[vi].dsp(); //zp
	 // for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += getVoices()[vi].dsp_out[j]; // zp

	 // our vtype determines algo dsp
	 if( vtype == 1 ){
	  get200Algo1()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo1()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 2 ){
	  get200Algo2()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo2()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 3 ){
	  get200Algo3()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo3()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 4 ){
	  get200Algo4()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo4()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
	 if( vtype == 5 ){
	  get200Algo5()[vi].dsp(); //zp
       for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] += get200Algo5()[vi].instanceoutlet__1_i._outlet[j]; //zp
	 }
}
}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ( 0 > 0 && dev > 0 && 0 != dev) return;
if ( 0 > 0 && port > 0 && 0 != port) return;

if( status == MIDI_PROGRAM_CHANGE + 5 && (data1<127) ){ //zp
  uint8_t PExVal = (data1 < 5) ? data1 : 5; // NUM_VTYPES //zp
  int     PExIdx = rootc::PARAM_INDEX_patcher__1_vtype + 5; //zp KLUDGE HERE
  PExParameterChange( &parent->PExch[ PExIdx ], PExVal, 0xFFEF);
}
else if( status == MIDI_PROGRAM_CHANGE + 5 && (data1==127) ){ //zp
  uint8_t txChan = 5;
  
  MidiSend2((midi_device_t) MIDI_DEVICE_DIN, 1, txChan + MIDI_PROGRAM_CHANGE, vtype&0x7F ); //2byte
  chThdSleepMilliseconds(400);
 
  if( vtype == 1 ){ instanceccMGR::txState( 1, &get200Algo1()[0].PExch[0], txChan ); }
  if( vtype == 2 ){ instanceccMGR::txState( 2, &get200Algo2()[0].PExch[0], txChan ); }
  if( vtype == 3 ){ instanceccMGR::txState( 3, &get200Algo3()[0].PExch[0], txChan ); }
  if( vtype == 4 ){ instanceccMGR::txState( 4, &get200Algo4()[0].PExch[0], txChan ); }
  if( vtype == 5 ){ instanceccMGR::txState( 5, &get200Algo5()[0].PExch[0], txChan ); }
  
  
} else if ((status == MIDI_NOTE_ON + 5) && (data2)) {
  int min = 1<<30;
  int mini = 0;
  int i;
  for(i=0;i<8;i++){
    if (voicePriority[i] < min){
      min = voicePriority[i];
      mini = i;
    }
  }
  voicePriority[mini] = 100000+priority++;
  notePlaying[mini] = data1;
  pressed[mini] = 1;

  if( vtype == 1 ) get200Algo1()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 2 ) get200Algo2()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 3 ) get200Algo3()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 4 ) get200Algo4()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  if( vtype == 5 ) get200Algo5()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2); //zp
  
  
} else if (((status == MIDI_NOTE_ON + 5) && (!data2))||
          (status == MIDI_NOTE_OFF + 5)) {
          	
  int i; for(i=0;i<8;i++){
    if ((notePlaying[i] == data1) && pressed[i]){
      voicePriority[i] = priority++;
      pressed[i] = 0;
    }
  }
} else if (status == 5 + MIDI_CONTROL_CHANGE) {
  int i; for(i=0;i<8;i++) getVoices()[i].MidiInHandler(dev, port, status, data1, data2); //zp
}}
}
}
;class instancesum8__1{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_in1,
const int32buffer  inlet_in2,
const int32buffer  inlet_in3,
const int32buffer  inlet_in4,
const int32buffer  inlet_in5,
const int32buffer  inlet_in6,
const int32buffer  inlet_in7,
const int32buffer  inlet_in8,
int32buffer  & outlet_out  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {

      outlet_out[buffer_index] = inlet_in1[buffer_index] + inlet_in2[buffer_index] + inlet_in3[buffer_index] + inlet_in4[buffer_index] + inlet_in5[buffer_index] + inlet_in6[buffer_index] + inlet_in7[buffer_index] + inlet_in8[buffer_index];
    
}
}
}
;class instanceout__1{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent,
int32_t & disp_vuLeft,
int32_t & disp_vuRight) {
parent = _parent;
disp_vuLeft = 0;
disp_vuRight = 0;
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_left,
const int32buffer  inlet_right,
int32_t & disp_vuLeft,
int32_t & disp_vuRight  ){
int j;
for(j=0;j<BUFSIZE;j++){
   AudioOutputLeft[j] += __SSAT(inlet_left[j],28);
   AudioOutputRight[j] += __SSAT(inlet_right[j],28);
}
disp_vuLeft=inlet_left[0];
disp_vuRight=inlet_right[0];

}
}
;class instanceoutconfig__1{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent) {
parent = _parent;
ADAU1961_WriteRegister(0x4023,(33<<2)+3);
ADAU1961_WriteRegister(0x4024,(33<<2)+3);
AudioOutputMode = A_STEREO;

}
  public: void Dispose() {
}
  public: void dsp (  ){
}
}
;class instancefourkit__10{
  public: // v1
  rootc *parent;
    static const uint32_t NPEXCH = 3;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 0;
    static const uint32_t NPRESET_ENTRIES = 0;
    static const uint32_t NMODULATIONSOURCES = 0;
    static const uint32_t NMODULATIONTARGETS = 0;
    int32_t PExModulationPrevVal[1][NMODULATIONSOURCES];
/* modsource defines */
/* parameter instance indices */
static const int PARAM_INDEX__dash_c__1_c = 0;
static const int PARAM_INDEX__dash_c__2_c = 1;
static const int PARAM_INDEX__dash_c__3_c = 2;
/* controller classes */
/* object classes */
class instancekeyb__1{
  public: // v1
  instancefourkit__10 *parent;
int8_t _note;
int32_t _gate;
int32_t _gate2;
uint8_t _velo;
uint8_t _rvelo;
uint32_t np[51-36+1];
uint32_t p;

  public: void Init(instancefourkit__10 * _parent) {
parent = _parent;
_gate = 0;
_gate2 = 0;
_note = 0;
p = 1;
int j;
for(j=0;j<51-36+1;j++) np[j]=0;

}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_note,
bool  & outlet_gate,
bool  & outlet_gate2,
int32_t  & outlet_velocity,
int32_t  & outlet_releaseVelocity  ){
outlet_note= _note<<21;
outlet_gate= _gate;
outlet_gate2= _gate2;
_gate2 = _gate;
outlet_velocity= _velo<<20;
outlet_releaseVelocity= _rvelo<<20;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ((status == MIDI_NOTE_ON + 9) && (data2)) {
  if ((data1 >= 36)&&(data1 <= 51)) {
    _velo = data2;
    _note = data1-64;
    _gate = 1<<27;
    _gate2 = 0;
    np[data1-36]=p++;
  }
} else if (((status == MIDI_NOTE_ON + 9) && (!data2))||
          (status == MIDI_NOTE_OFF + 9)) {
if ((data1 >= 36)&&(data1 <= 51)) {
   _rvelo = data2;
np[data1-36]=0;
int j;
int np2 = 0;
int n2 = 0;
for(j=0;j<51-36+1;j++){
   if (np[j]>np2) {
      np2=np[j];
      n2 = j;
   }
}
if (n2>0) {
  int nn = n2+36-64;
  if (nn != _note) {
    _gate2 = 0;
    _note = nn;
  }
}
else _gate = 0;
}
} else if ((status == 9 + MIDI_CONTROL_CHANGE)&&(data1 == MIDI_C_ALL_NOTES_OFF)) {
  _gate = 0;
}
}
}
}
;class instancebipolar2unipolar__1{
  public: // v1
  instancefourkit__10 *parent;
  public: void Init(instancefourkit__10 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_i,
int32_t  & outlet_o  ){
   outlet_o= (inlet_i>>1)+(1<<26);

}
}
;class instance_dash_c__1{
  public: // v1
  instancefourkit__10 *parent;
//KeyValuePair KVP_instance_dash_c__1_c;
  public: void Init(instancefourkit__10 * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX__dash_c__1_c].pfunction = pfun_unsigned_clamp;
  //SetKVP_IPVP(&KVP_instance_dash_c__1_c,ObjectKvpRoot, "-c_1" ,&parent->PExch[PARAM_INDEX__dash_c__1_c], 0, 1<<27);
  //KVP_RegisterObject(&KVP_instance_dash_c__1_c);
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out,
int param_c  ){
outlet_out= inlet_in- param_c;
}
}
;class instanceflashplay__1{
  public: // v1
  instancefourkit__10 *parent;
const static int max_length = 16*16384;
int16_t *sample;
uint32_t _pos = max_length;
int ntrig=0;
  public: void Init(instancefourkit__10 * _parent) {
parent = _parent;
static int16_t _sample[max_length] __attribute__ ((section (".sdram")));
sample = &_sample[0];
FIL FileObject;
FRESULT err;
UINT bytes_read;
const char fn[] = "/zp-kit1.wav";
err = f_open(&FileObject, fn, FA_READ | FA_OPEN_EXISTING);
if (err != FR_OK) {
	LogTextMessage("Open failed: %s",fn); 
	// clear from file end to array end
	int i;
	for(i=0;i<max_length;i++){
		sample[i]=0;
	}
	return;
}
err = f_read(&FileObject, (char *)sample, sizeof(_sample),&bytes_read);
if (err != FR_OK) {LogTextMessage("Read failed\n"); return;}
err = f_close(&FileObject);
if (err != FR_OK) {LogTextMessage("Close failed\n"); return;}

int i=bytes_read/2; // 16 bit per sample
// clear from file end to array end
for(;i<max_length;i++){
	sample[i]=0;
}
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_index,
const bool  inlet_trig,
int32buffer  & outlet_out  ){
if ((inlet_trig>0) && !ntrig){ _pos=(inlet_index>>6); ntrig=1; }
if (!(inlet_trig>0)) ntrig=0;

int32_t i;
if (_pos<max_length && ntrig ) {
    for(i=0;i<BUFSIZE;i++) (outlet_out)[i] = (sample[_pos++])<<12;
} else {
    for(i=0;i<BUFSIZE;i++) (outlet_out)[i] = 0;
}
}
}
;class instancesum4__1{
  public: // v1
  instancefourkit__10 *parent;
  public: void Init(instancefourkit__10 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_in1,
const int32buffer  inlet_in2,
const int32buffer  inlet_in3,
const int32buffer  inlet_in4,
int32buffer  & outlet_out  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {

      outlet_out[buffer_index] = inlet_in1[buffer_index] + inlet_in2[buffer_index] + inlet_in3[buffer_index] + inlet_in4[buffer_index];
    
}
}
}
;class instancecc__1{
  public: // v1
  instancefourkit__10 *parent;
int32_t ccv;
int32_t ntrig;

  public: void Init(instancefourkit__10 * _parent) {
parent = _parent;
ccv = 100 << 20;

}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_midiCC,
bool  & outlet_trig  ){
outlet_midiCC= ccv;
outlet_trig = ntrig;
ntrig = 0;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ((status == 9 + MIDI_CONTROL_CHANGE)&&(data1 == 7)) { ccv = data2<<20; ntrig = 1;}
}
}
}
;class instancevca__2{
  public: // v1
  instancefourkit__10 *parent;
   int32_t prev;
    int32_t step;

  public: void Init(instancefourkit__10 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_v,
const int32buffer  inlet_a,
int32buffer  & outlet_o  ){
   step = (inlet_v - prev)>>4;
   int32_t i = prev;
   prev = inlet_v;

int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   outlet_o[buffer_index] =  ___SMMUL(inlet_a[buffer_index],i)<<5;
   i += step;

}
}
}
;class instanceoutlet__1{
  public: // v1
  instancefourkit__10 *parent;
int32buffer _outlet;

  public: void Init(instancefourkit__10 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_outlet  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
   _outlet[buffer_index] = inlet_outlet[buffer_index];

}
}
}
;class instancekeyb__2{
  public: // v1
  instancefourkit__10 *parent;
int8_t _note;
int32_t _gate;
int32_t _gate2;
uint8_t _velo;
uint8_t _rvelo;
uint32_t np[67-52+1];
uint32_t p;

  public: void Init(instancefourkit__10 * _parent) {
parent = _parent;
_gate = 0;
_gate2 = 0;
_note = 0;
p = 1;
int j;
for(j=0;j<67-52+1;j++) np[j]=0;

}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_note,
bool  & outlet_gate,
bool  & outlet_gate2,
int32_t  & outlet_velocity,
int32_t  & outlet_releaseVelocity  ){
outlet_note= _note<<21;
outlet_gate= _gate;
outlet_gate2= _gate2;
_gate2 = _gate;
outlet_velocity= _velo<<20;
outlet_releaseVelocity= _rvelo<<20;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ((status == MIDI_NOTE_ON + 9) && (data2)) {
  if ((data1 >= 52)&&(data1 <= 67)) {
    _velo = data2;
    _note = data1-64;
    _gate = 1<<27;
    _gate2 = 0;
    np[data1-52]=p++;
  }
} else if (((status == MIDI_NOTE_ON + 9) && (!data2))||
          (status == MIDI_NOTE_OFF + 9)) {
if ((data1 >= 52)&&(data1 <= 67)) {
   _rvelo = data2;
np[data1-52]=0;
int j;
int np2 = 0;
int n2 = 0;
for(j=0;j<67-52+1;j++){
   if (np[j]>np2) {
      np2=np[j];
      n2 = j;
   }
}
if (n2>0) {
  int nn = n2+52-64;
  if (nn != _note) {
    _gate2 = 0;
    _note = nn;
  }
}
else _gate = 0;
}
} else if ((status == 9 + MIDI_CONTROL_CHANGE)&&(data1 == MIDI_C_ALL_NOTES_OFF)) {
  _gate = 0;
}
}
}
}
;class instancebipolar2unipolar__2{
  public: // v1
  instancefourkit__10 *parent;
  public: void Init(instancefourkit__10 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_i,
int32_t  & outlet_o  ){
   outlet_o= (inlet_i>>1)+(1<<26);

}
}
;class instance_dash_c__2{
  public: // v1
  instancefourkit__10 *parent;
//KeyValuePair KVP_instance_dash_c__2_c;
  public: void Init(instancefourkit__10 * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX__dash_c__2_c].pfunction = pfun_unsigned_clamp;
  //SetKVP_IPVP(&KVP_instance_dash_c__2_c,ObjectKvpRoot, "-c_2" ,&parent->PExch[PARAM_INDEX__dash_c__2_c], 0, 1<<27);
  //KVP_RegisterObject(&KVP_instance_dash_c__2_c);
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out,
int param_c  ){
outlet_out= inlet_in- param_c;
}
}
;class instanceflashplay__2{
  public: // v1
  instancefourkit__10 *parent;
const static int max_length = 16*16384;
int16_t *sample;
uint32_t _pos = max_length;
int ntrig=0;
  public: void Init(instancefourkit__10 * _parent) {
parent = _parent;
static int16_t _sample[max_length] __attribute__ ((section (".sdram")));
sample = &_sample[0];
FIL FileObject;
FRESULT err;
UINT bytes_read;
const char fn[] = "/zp-kit1.wav";
err = f_open(&FileObject, fn, FA_READ | FA_OPEN_EXISTING);
if (err != FR_OK) {
	LogTextMessage("Open failed: %s",fn); 
	// clear from file end to array end
	int i;
	for(i=0;i<max_length;i++){
		sample[i]=0;
	}
	return;
}
err = f_read(&FileObject, (char *)sample, sizeof(_sample),&bytes_read);
if (err != FR_OK) {LogTextMessage("Read failed\n"); return;}
err = f_close(&FileObject);
if (err != FR_OK) {LogTextMessage("Close failed\n"); return;}

int i=bytes_read/2; // 16 bit per sample
// clear from file end to array end
for(;i<max_length;i++){
	sample[i]=0;
}
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_index,
const bool  inlet_trig,
int32buffer  & outlet_out  ){
if ((inlet_trig>0) && !ntrig){ _pos=(inlet_index>>6); ntrig=1; }
if (!(inlet_trig>0)) ntrig=0;

int32_t i;
if (_pos<max_length && ntrig ) {
    for(i=0;i<BUFSIZE;i++) (outlet_out)[i] = (sample[_pos++])<<12;
} else {
    for(i=0;i<BUFSIZE;i++) (outlet_out)[i] = 0;
}
}
}
;class instancekeyb__3{
  public: // v1
  instancefourkit__10 *parent;
int8_t _note;
int32_t _gate;
int32_t _gate2;
uint8_t _velo;
uint8_t _rvelo;
uint32_t np[84-68+1];
uint32_t p;

  public: void Init(instancefourkit__10 * _parent) {
parent = _parent;
_gate = 0;
_gate2 = 0;
_note = 0;
p = 1;
int j;
for(j=0;j<84-68+1;j++) np[j]=0;

}
  public: void Dispose() {
}
  public: void dsp (int32_t  & outlet_note,
bool  & outlet_gate,
bool  & outlet_gate2,
int32_t  & outlet_velocity,
int32_t  & outlet_releaseVelocity  ){
outlet_note= _note<<21;
outlet_gate= _gate;
outlet_gate2= _gate2;
_gate2 = _gate;
outlet_velocity= _velo<<20;
outlet_releaseVelocity= _rvelo<<20;

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ((status == MIDI_NOTE_ON + 9) && (data2)) {
  if ((data1 >= 68)&&(data1 <= 84)) {
    _velo = data2;
    _note = data1-64;
    _gate = 1<<27;
    _gate2 = 0;
    np[data1-68]=p++;
  }
} else if (((status == MIDI_NOTE_ON + 9) && (!data2))||
          (status == MIDI_NOTE_OFF + 9)) {
if ((data1 >= 68)&&(data1 <= 84)) {
   _rvelo = data2;
np[data1-68]=0;
int j;
int np2 = 0;
int n2 = 0;
for(j=0;j<84-68+1;j++){
   if (np[j]>np2) {
      np2=np[j];
      n2 = j;
   }
}
if (n2>0) {
  int nn = n2+68-64;
  if (nn != _note) {
    _gate2 = 0;
    _note = nn;
  }
}
else _gate = 0;
}
} else if ((status == 9 + MIDI_CONTROL_CHANGE)&&(data1 == MIDI_C_ALL_NOTES_OFF)) {
  _gate = 0;
}
}
}
}
;class instancebipolar2unipolar__3{
  public: // v1
  instancefourkit__10 *parent;
  public: void Init(instancefourkit__10 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_i,
int32_t  & outlet_o  ){
   outlet_o= (inlet_i>>1)+(1<<26);

}
}
;class instance_dash_c__3{
  public: // v1
  instancefourkit__10 *parent;
//KeyValuePair KVP_instance_dash_c__3_c;
  public: void Init(instancefourkit__10 * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX__dash_c__3_c].pfunction = pfun_unsigned_clamp;
  //SetKVP_IPVP(&KVP_instance_dash_c__3_c,ObjectKvpRoot, "-c_3" ,&parent->PExch[PARAM_INDEX__dash_c__3_c], 0, 1<<27);
  //KVP_RegisterObject(&KVP_instance_dash_c__3_c);
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out,
int param_c  ){
outlet_out= inlet_in- param_c;
}
}
;class instanceflashplay__3{
  public: // v1
  instancefourkit__10 *parent;
const static int max_length = 16*16384;
int16_t *sample;
uint32_t _pos = max_length;
int ntrig=0;
  public: void Init(instancefourkit__10 * _parent) {
parent = _parent;
static int16_t _sample[max_length] __attribute__ ((section (".sdram")));
sample = &_sample[0];
FIL FileObject;
FRESULT err;
UINT bytes_read;
const char fn[] = "/zp-kit1.wav";
err = f_open(&FileObject, fn, FA_READ | FA_OPEN_EXISTING);
if (err != FR_OK) {
	LogTextMessage("Open failed: %s",fn); 
	// clear from file end to array end
	int i;
	for(i=0;i<max_length;i++){
		sample[i]=0;
	}
	return;
}
err = f_read(&FileObject, (char *)sample, sizeof(_sample),&bytes_read);
if (err != FR_OK) {LogTextMessage("Read failed\n"); return;}
err = f_close(&FileObject);
if (err != FR_OK) {LogTextMessage("Close failed\n"); return;}

int i=bytes_read/2; // 16 bit per sample
// clear from file end to array end
for(;i<max_length;i++){
	sample[i]=0;
}
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_index,
const bool  inlet_trig,
int32buffer  & outlet_out  ){
if ((inlet_trig>0) && !ntrig){ _pos=(inlet_index>>6); ntrig=1; }
if (!(inlet_trig>0)) ntrig=0;

int32_t i;
if (_pos<max_length && ntrig ) {
    for(i=0;i<BUFSIZE;i++) (outlet_out)[i] = (sample[_pos++])<<12;
} else {
    for(i=0;i<BUFSIZE;i++) (outlet_out)[i] = 0;
}
}
}
;/* controller instances */
/* object instances */
     instancekeyb__1 instancekeyb__1_i;
     instancebipolar2unipolar__1 instancebipolar2unipolar__1_i;
     instance_dash_c__1 instance_dash_c__1_i;
     instanceflashplay__1 instanceflashplay__1_i;
     instancesum4__1 instancesum4__1_i;
     instancecc__1 instancecc__1_i;
     instancevca__2 instancevca__2_i;
     instanceoutlet__1 instanceoutlet__1_i;
     instancekeyb__2 instancekeyb__2_i;
     instancebipolar2unipolar__2 instancebipolar2unipolar__2_i;
     instance_dash_c__2 instance_dash_c__2_i;
     instanceflashplay__2 instanceflashplay__2_i;
     instancekeyb__3 instancekeyb__3_i;
     instancebipolar2unipolar__3 instancebipolar2unipolar__3_i;
     instance_dash_c__3 instance_dash_c__3_i;
     instanceflashplay__3 instanceflashplay__3_i;
/* net latches */
    int32buffer  net12Latch;
    int32buffer  net17Latch;
static const int polyIndex = 0;
   static int32_t * GetInitParams(void){
      static const int32_t p[3]= {
      37748736,
      54525952,
      71303168
      };
      return (int32_t *)&p[0];
   }   static const int32_t * GetPresets(void){
      static const int32_t p[NPRESETS][NPRESET_ENTRIES][2] = {
      };
   return &p[0][0][0];
   };
void ApplyPreset(int index){
   if (!index) {
     int i;
     int32_t *p = GetInitParams();
     for(i=0;i<NPEXCH;i++){
        PExParameterChange(&PExch[i],p[i],0xFFEF);
     }
   }
   index--;
   if (index < NPRESETS) {
     PresetParamChange_t *pa = (PresetParamChange_t *)(GetPresets());
     PresetParamChange_t *p = &pa[index*NPRESET_ENTRIES];
       int i;
       for(i=0;i<NPRESET_ENTRIES;i++){
         PresetParamChange_t *pp = &p[i];
         if ((pp->pexIndex>=0)&&(pp->pexIndex<NPEXCH)) {
           PExParameterChange(&PExch[pp->pexIndex],pp->value,0xFFEF);         }
         else break;
       }
   }
}
   static PExModulationTarget_t * GetModulationTable(void){
    static const PExModulationTarget_t PExModulationSources[NMODULATIONSOURCES][NMODULATIONTARGETS] = 
{};
   return (PExModulationTarget_t *)&PExModulationSources[0][0];
   };

  public: void Init(rootc * _parent) {
parent = _parent;
   int i;
   int j;
   const int32_t *p;
   p = GetInitParams();
   for(j=0;j<3;j++){
      PExch[j].value = p[j];
      PExch[j].modvalue = p[j];
      PExch[j].signals = 0;
      PExch[j].pfunction = 0;
   }
   int32_t *pp = &PExModulationPrevVal[0][0];
   for(j=0;j<1*NMODULATIONSOURCES;j++){
      *pp = 0; pp++;
   }
     displayVector[0] = 0x446F7841;
     displayVector[1] = 0;
     displayVector[2] = 0;
   instancekeyb__1_i.Init(this );
   instancebipolar2unipolar__1_i.Init(this );
   instance_dash_c__1_i.Init(this );
   instanceflashplay__1_i.Init(this );
   instancesum4__1_i.Init(this );
   instancecc__1_i.Init(this );
   instancevca__2_i.Init(this );
   instanceoutlet__1_i.Init(this );
   instancekeyb__2_i.Init(this );
   instancebipolar2unipolar__2_i.Init(this );
   instance_dash_c__2_i.Init(this );
   instanceflashplay__2_i.Init(this );
   instancekeyb__3_i.Init(this );
   instancebipolar2unipolar__3_i.Init(this );
   instance_dash_c__3_i.Init(this );
   instanceflashplay__3_i.Init(this );
      int k;
      for (k = 0; k < NPEXCH; k++) {
        if (PExch[k].pfunction){
          (PExch[k].pfunction)(&PExch[k]);
        } else {
          PExch[k].finalvalue = PExch[k].value;
        }
      }

}
  public: void Dispose() {
   instanceflashplay__3_i.Dispose();
   instance_dash_c__3_i.Dispose();
   instancebipolar2unipolar__3_i.Dispose();
   instancekeyb__3_i.Dispose();
   instanceflashplay__2_i.Dispose();
   instance_dash_c__2_i.Dispose();
   instancebipolar2unipolar__2_i.Dispose();
   instancekeyb__2_i.Dispose();
   instanceoutlet__1_i.Dispose();
   instancevca__2_i.Dispose();
   instancecc__1_i.Dispose();
   instancesum4__1_i.Dispose();
   instanceflashplay__1_i.Dispose();
   instance_dash_c__1_i.Dispose();
   instancebipolar2unipolar__1_i.Dispose();
   instancekeyb__1_i.Dispose();

}
  public: void dsp (int32buffer  & outlet_outlet__1  ){
int i; /*...*/
//--------- <nets> -----------//
    int32_t  net0;
    int32_t  net1;
    int32_t  net2;
    int32_t  net3;
    int32_t  net4;
    bool  net5;
    int32_t  net6;
    int32buffer  net7;
    int32_t  net8;
    bool  net9;
    int32buffer  net10;
    int32buffer  net11;
    int32buffer  net12;
    int32_t  net13;
    int32_t  net14;
    int32_t  net15;
    bool  net16;
    int32buffer  net17;
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instancekeyb__1_i.dsp(net0, (bool &)UNCONNECTED_OUTPUT, net5, UNCONNECTED_OUTPUT, UNCONNECTED_OUTPUT);
  instancebipolar2unipolar__1_i.dsp(net0, net1);
  instance_dash_c__1_i.dsp(net1, net4, PExch[PARAM_INDEX__dash_c__1_c].finalvalue);
  instanceflashplay__1_i.dsp(net4, net5, net10);
  instancesum4__1_i.dsp(net10, net12Latch, net17Latch, zerobuffer, net11);
  instancecc__1_i.dsp(net6, (bool &)UNCONNECTED_OUTPUT);
  instancevca__2_i.dsp(net6, net11, net7);
  instanceoutlet__1_i.dsp(net7);
  instancekeyb__2_i.dsp(net2, (bool &)UNCONNECTED_OUTPUT, net9, UNCONNECTED_OUTPUT, UNCONNECTED_OUTPUT);
  instancebipolar2unipolar__2_i.dsp(net2, net3);
  instance_dash_c__2_i.dsp(net3, net8, PExch[PARAM_INDEX__dash_c__2_c].finalvalue);
  instanceflashplay__2_i.dsp(net8, net9, net12);
  instancekeyb__3_i.dsp(net13, (bool &)UNCONNECTED_OUTPUT, net16, UNCONNECTED_OUTPUT, UNCONNECTED_OUTPUT);
  instancebipolar2unipolar__3_i.dsp(net13, net14);
  instance_dash_c__3_i.dsp(net14, net15, PExch[PARAM_INDEX__dash_c__3_c].finalvalue);
  instanceflashplay__3_i.dsp(net15, net16, net17);
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
   for(i=0;i<BUFSIZE;i++)
      net12Latch[i]=net12[i];
   for(i=0;i<BUFSIZE;i++)
      net17Latch[i]=net17[i];
//--------- </net latch copy> ----------//
      for(i=0;i<BUFSIZE;i++) outlet_outlet__1[i] = instanceoutlet__1_i._outlet[i];

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ( 0 > 0 && dev > 0 && 0 != dev) return;
if ( 0 > 0 && port > 0 && 0 != port) return;
instancekeyb__1_i.MidiInHandler(dev, port, status, data1, data2);
instancecc__1_i.MidiInHandler(dev, port, status, data1, data2);
instancekeyb__2_i.MidiInHandler(dev, port, status, data1, data2);
instancekeyb__3_i.MidiInHandler(dev, port, status, data1, data2);
}
}
}
;class instancecc7__100{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent) {
parent = _parent;
for(int ch=0; ch<16; ch++) // all 16 channels
{
  MidiSend3((midi_device_t) MIDI_DEVICE_INTERNAL, 1, MIDI_CONTROL_CHANGE + ch, 7, 100);
}
}
  public: void Dispose() {
}
  public: void dsp (  ){
}
}
;class instanceccMGR{
  public: // v1
  rootc *parent;
static void setPEx( uint8_t vtype, void* parent, uint8_t data1, uint8_t data2 ){
  int PExIdx = -1;
  if( vtype==1 ) PExIdx = ccToPExAlgo1( data1 );
  if( vtype==2 ) PExIdx = ccToPExAlgo2( data1 );
  if( vtype==3 ) PExIdx = ccToPExAlgo3( data1 );
  if( vtype==4 ) PExIdx = ccToPExAlgo4( data1 );
  if( vtype==5 ) PExIdx = ccToPExAlgo5( data1 );
  

  if( PExIdx==-1 ) return; // abort

  int PExVal = data2<<20;
  if( vtype==1 && PExBipAlgo1(PExIdx) ){ PExVal = (PExVal-(1<<26))<<1; }
  if( vtype==2 && PExBipAlgo2(PExIdx) ){ PExVal = (PExVal-(1<<26))<<1; }
  if( vtype==3 && PExBipAlgo3(PExIdx) ){ PExVal = (PExVal-(1<<26))<<1; }
  if( vtype==4 && PExBipAlgo4(PExIdx) ){ PExVal = (PExVal-(1<<26))<<1; }
  if( vtype==5 && PExBipAlgo5(PExIdx) ){ PExVal = (PExVal-(1<<26))<<1; }
  

  if( vtype==1 ) PExParameterChange( &((instancealgo__1::voice*)parent)->PExch[ PExIdx ], PExVal, 0xFFEF );
  if( vtype==2 ) PExParameterChange( &((instancealgo__2::voice*)parent)->PExch[ PExIdx ], PExVal, 0xFFEF );
  if( vtype==3 ) PExParameterChange( &((instancealgo__3::voice*)parent)->PExch[ PExIdx ], PExVal, 0xFFEF );
  if( vtype==4 ) PExParameterChange( &((instancealgo__4::voice*)parent)->PExch[ PExIdx ], PExVal, 0xFFEF );
  if( vtype==5 ) PExParameterChange( &((instancealgo__5::voice*)parent)->PExch[ PExIdx ], PExVal, 0xFFEF );
  
}

static void txState( int vtype, ParameterExchange_t *PE, uint8_t txChan ){
  uint8_t MIN_CC = 16;         // cc16..25 with vtype 1..3
  uint8_t MAX_CC = 25;

  if( vtype == 4) MAX_CC = 31; // cc16..31 with vtype 4
  if( vtype == 5) MAX_CC = 27; // cc16..27 with vtype 5
  
  for(int txCCdat1=MIN_CC; txCCdat1<=MAX_CC; txCCdat1++){ txStateCC( vtype, PE, txCCdat1, txChan ); }
}

static void txStateCC( int vtype, ParameterExchange_t *PE, uint8_t txCCdat1, uint8_t txChan ){
	int PExIdx = -1;
	if( vtype == 1 ) PExIdx = ccToPExAlgo1( txCCdat1 );
	if( vtype == 2 ) PExIdx = ccToPExAlgo2( txCCdat1 );
	if( vtype == 3 ) PExIdx = ccToPExAlgo3( txCCdat1 );	
	if( vtype == 4 ) PExIdx = ccToPExAlgo4( txCCdat1 );	
	if( vtype == 5 ) PExIdx = ccToPExAlgo5( txCCdat1 );

	if( PExIdx != -1 ){
  		int txDat2 = PE[ PExIdx ].modvalue; // range 32bit
  		
  	  	if( vtype==1 && PExBipAlgo1( PExIdx ) ){ txDat2 = (txDat2>>1) + (1<<26); }
  	  	if( vtype==2 && PExBipAlgo2( PExIdx ) ){ txDat2 = (txDat2>>1) + (1<<26); }
  	  	if( vtype==3 && PExBipAlgo3( PExIdx ) ){ txDat2 = (txDat2>>1) + (1<<26); }
  	  	if( vtype==4 && PExBipAlgo4( PExIdx ) ){ txDat2 = (txDat2>>1) + (1<<26); }
  	  	if( vtype==5 && PExBipAlgo5( PExIdx ) ){ txDat2 = (txDat2>>1) + (1<<26); }
  	  	
  	  	txDat2 = txDat2 >> 20;              // range 0..128
	     txDat2 = (txDat2!=128)?txDat2:127;  // range 0..127
	     MidiSend3((midi_device_t) MIDI_DEVICE_DIN, 1, txChan + MIDI_CONTROL_CHANGE, txCCdat1&0x7F, txDat2&0x7F);
  	}
}

static int ccToPExAlgo1( uint8_t cc ) __attribute__ ((section (".sdram"))) {
 if( 16==cc ){ return instancealgo__1::voice::PARAM_INDEX_cnoise__1_timbre; }
 if( 17==cc ){ return instancealgo__1::voice::PARAM_INDEX_cnoise__1_color; }
 if( 18==cc ){ return instancealgo__1::voice::PARAM_INDEX_a__time_a; }
 if( 19==cc ){ return instancealgo__1::voice::PARAM_INDEX_a__vel_amp; }
 if( 20==cc ){ return instancealgo__1::voice::PARAM_INDEX_env__t_time; }
 if( 21==cc ){ return instancealgo__1::voice::PARAM_INDEX_env__t_vt; }
 if( 22==cc ){ return instancealgo__1::voice::PARAM_INDEX_env__t_env; }
 if( 23==cc ){ return instancealgo__1::voice::PARAM_INDEX_env__c_time; }
 if( 24==cc ){ return instancealgo__1::voice::PARAM_INDEX_env__c_vt; }
 if( 25==cc ){ return instancealgo__1::voice::PARAM_INDEX_env__c_env; }
 return -1;
}
static int PExBipAlgo1( int idx ) __attribute__ ((section (".sdram"))){
 if( instancealgo__1::voice::PARAM_INDEX_a__time_a  ==idx ){ return 1; }
 if( instancealgo__1::voice::PARAM_INDEX_a__vel_amp ==idx ){ return 1; }
 if( instancealgo__1::voice::PARAM_INDEX_env__t_time==idx ){ return 1; }
 if( instancealgo__1::voice::PARAM_INDEX_env__t_vt  ==idx ){ return 1; }
 if( instancealgo__1::voice::PARAM_INDEX_env__t_env ==idx ){ return 1; }
 if( instancealgo__1::voice::PARAM_INDEX_env__c_time==idx ){ return 1; }
 if( instancealgo__1::voice::PARAM_INDEX_env__c_vt  ==idx ){ return 1; }
 if( instancealgo__1::voice::PARAM_INDEX_env__c_env ==idx ){ return 1; }
 return 0;
}

static int ccToPExAlgo2( uint8_t cc ) __attribute__ ((section (".sdram"))) {
 if( 16==cc ){ return instancealgo__2::voice::PARAM_INDEX_fbfm__1_timbre; }
 if( 17==cc ){ return instancealgo__2::voice::PARAM_INDEX_fbfm__1_color; }
 if( 18==cc ){ return instancealgo__2::voice::PARAM_INDEX_a__time_a; }
 if( 19==cc ){ return instancealgo__2::voice::PARAM_INDEX_a__vel_amp; }
 if( 20==cc ){ return instancealgo__2::voice::PARAM_INDEX_env__t_time; }
 if( 21==cc ){ return instancealgo__2::voice::PARAM_INDEX_env__t_vt; }
 if( 22==cc ){ return instancealgo__2::voice::PARAM_INDEX_env__t_env; }
 if( 23==cc ){ return instancealgo__2::voice::PARAM_INDEX_env__c_time; }
 if( 24==cc ){ return instancealgo__2::voice::PARAM_INDEX_env__c_vt; }
 if( 25==cc ){ return instancealgo__2::voice::PARAM_INDEX_env__c_env; }
 return -1;
}
static int PExBipAlgo2( int idx ) __attribute__ ((section (".sdram"))){
 if( instancealgo__2::voice::PARAM_INDEX_a__time_a  ==idx ){ return 1; }
 if( instancealgo__2::voice::PARAM_INDEX_a__vel_amp ==idx ){ return 1; }
 if( instancealgo__2::voice::PARAM_INDEX_env__t_time==idx ){ return 1; }
 if( instancealgo__2::voice::PARAM_INDEX_env__t_vt  ==idx ){ return 1; }
 if( instancealgo__2::voice::PARAM_INDEX_env__t_env ==idx ){ return 1; }
 if( instancealgo__2::voice::PARAM_INDEX_env__c_time==idx ){ return 1; }
 if( instancealgo__2::voice::PARAM_INDEX_env__c_vt  ==idx ){ return 1; }
 if( instancealgo__2::voice::PARAM_INDEX_env__c_env ==idx ){ return 1; }
 return 0;
}

static int ccToPExAlgo3( uint8_t cc ) __attribute__ ((section (".sdram"))) {
 if( 16==cc ){ return instancealgo__3::voice::PARAM_INDEX_mds__1_saw; }
 if( 17==cc ){ return instancealgo__3::voice::PARAM_INDEX_mds__1_dip; }
 if( 18==cc ){ return instancealgo__3::voice::PARAM_INDEX_a__time_a; }
 if( 19==cc ){ return instancealgo__3::voice::PARAM_INDEX_a__vel_amp; }
 if( 20==cc ){ return instancealgo__3::voice::PARAM_INDEX_env__s_time; }
 if( 21==cc ){ return instancealgo__3::voice::PARAM_INDEX_env__s_vt; }
 if( 22==cc ){ return instancealgo__3::voice::PARAM_INDEX_env__s_env; }
 if( 23==cc ){ return instancealgo__3::voice::PARAM_INDEX_env__d_time; }
 if( 24==cc ){ return instancealgo__3::voice::PARAM_INDEX_env__d_vt; }
 if( 25==cc ){ return instancealgo__3::voice::PARAM_INDEX_env__d_env; }
 return -1;
}
static int PExBipAlgo3( int idx ) __attribute__ ((section (".sdram"))){
 if( instancealgo__3::voice::PARAM_INDEX_a__time_a  ==idx ){ return 1; }
 if( instancealgo__3::voice::PARAM_INDEX_a__vel_amp ==idx ){ return 1; }
 if( instancealgo__3::voice::PARAM_INDEX_env__s_time==idx ){ return 1; }
 if( instancealgo__3::voice::PARAM_INDEX_env__s_vt  ==idx ){ return 1; }
 if( instancealgo__3::voice::PARAM_INDEX_env__s_env ==idx ){ return 1; }
 if( instancealgo__3::voice::PARAM_INDEX_env__d_time==idx ){ return 1; }
 if( instancealgo__3::voice::PARAM_INDEX_env__d_vt  ==idx ){ return 1; }
 if( instancealgo__3::voice::PARAM_INDEX_env__d_env ==idx ){ return 1; }
 return 0;
}

static int ccToPExAlgo4( uint8_t cc ) __attribute__ ((section (".sdram"))) {
 if( 16==cc ){ return instancealgo__4::voice::PARAM_INDEX_wavemix_sin; }
 if( 17==cc ){ return instancealgo__4::voice::PARAM_INDEX_wavemix_saw; }
 if( 18==cc ){ return instancealgo__4::voice::PARAM_INDEX_a__time_a; }
 if( 19==cc ){ return instancealgo__4::voice::PARAM_INDEX_a__vel_amp; }
 if( 20==cc ){ return instancealgo__4::voice::PARAM_INDEX_env__g_time; }
 if( 21==cc ){ return instancealgo__4::voice::PARAM_INDEX_env__g_vt; }
 if( 22==cc ){ return instancealgo__4::voice::PARAM_INDEX_env__g_env; }
 if( 23==cc ){ return instancealgo__4::voice::PARAM_INDEX_env__c_time; }
 if( 24==cc ){ return instancealgo__4::voice::PARAM_INDEX_env__c_vt; }
 if( 25==cc ){ return instancealgo__4::voice::PARAM_INDEX_env__c_env; }
 if( 26==cc ){ return instancealgo__4::voice::PARAM_INDEX_env__s_time; }
 if( 27==cc ){ return instancealgo__4::voice::PARAM_INDEX_env__s_vt; }
 if( 28==cc ){ return instancealgo__4::voice::PARAM_INDEX_env__s_env; }
 if( 29==cc ){ return instancealgo__4::voice::PARAM_INDEX_sineslope__1_gain; }
 if( 30==cc ){ return instancealgo__4::voice::PARAM_INDEX_sineslope__1_clipH; }
 if( 31==cc ){ return instancealgo__4::voice::PARAM_INDEX_sineslope__1_strength; }
 return -1;
}
static int PExBipAlgo4( int idx ) __attribute__ ((section (".sdram"))){
 if( instancealgo__4::voice::PARAM_INDEX_a__time_a  ==idx ){ return 1; }
 if( instancealgo__4::voice::PARAM_INDEX_a__vel_amp ==idx ){ return 1; }
 if( instancealgo__4::voice::PARAM_INDEX_env__g_time==idx ){ return 1; }
 if( instancealgo__4::voice::PARAM_INDEX_env__g_vt  ==idx ){ return 1; }
 if( instancealgo__4::voice::PARAM_INDEX_env__g_env ==idx ){ return 1; }
 if( instancealgo__4::voice::PARAM_INDEX_env__c_time==idx ){ return 1; }
 if( instancealgo__4::voice::PARAM_INDEX_env__c_vt  ==idx ){ return 1; }
 if( instancealgo__4::voice::PARAM_INDEX_env__c_env ==idx ){ return 1; }
 if( instancealgo__4::voice::PARAM_INDEX_env__s_time==idx ){ return 1; }
 if( instancealgo__4::voice::PARAM_INDEX_env__s_vt  ==idx ){ return 1; }
 if( instancealgo__4::voice::PARAM_INDEX_env__s_env ==idx ){ return 1; }
 
 return 0;
}

static int ccToPExAlgo5( uint8_t cc ) __attribute__ ((section (".sdram"))) {
 if( 16==cc ){ return instancealgo__5::voice::PARAM_INDEX_wavemix_sin; }
 if( 17==cc ){ return instancealgo__5::voice::PARAM_INDEX_wavemix_saw; }
 if( 18==cc ){ return instancealgo__5::voice::PARAM_INDEX_a__time_a; }
 if( 19==cc ){ return instancealgo__5::voice::PARAM_INDEX_a__vel_amp; }
 if( 20==cc ){ return instancealgo__5::voice::PARAM_INDEX_env__m1_time; }
 if( 21==cc ){ return instancealgo__5::voice::PARAM_INDEX_env__m1_vt; }
 if( 22==cc ){ return instancealgo__5::voice::PARAM_INDEX_env__m1_env; }
 if( 23==cc ){ return instancealgo__5::voice::PARAM_INDEX_env__m2_time; }
 if( 24==cc ){ return instancealgo__5::voice::PARAM_INDEX_env__m2_vt; }
 if( 25==cc ){ return instancealgo__5::voice::PARAM_INDEX_env__m2_env; }
 if( 26==cc ){ return instancealgo__5::voice::PARAM_INDEX_asymSin__1_mod1; }
 if( 27==cc ){ return instancealgo__5::voice::PARAM_INDEX_asymSin__1_mod2; }
 return -1;
}
static int PExBipAlgo5( int idx ) __attribute__ ((section (".sdram"))){
 if( instancealgo__5::voice::PARAM_INDEX_a__time_a   ==idx ){ return 1; }
 if( instancealgo__5::voice::PARAM_INDEX_a__vel_amp  ==idx ){ return 1; }
 if( instancealgo__5::voice::PARAM_INDEX_env__m1_time==idx ){ return 1; }
 if( instancealgo__5::voice::PARAM_INDEX_env__m1_vt  ==idx ){ return 1; }
 if( instancealgo__5::voice::PARAM_INDEX_env__m1_env ==idx ){ return 1; }
 if( instancealgo__5::voice::PARAM_INDEX_env__m2_time==idx ){ return 1; }
 if( instancealgo__5::voice::PARAM_INDEX_env__m2_vt  ==idx ){ return 1; }
 if( instancealgo__5::voice::PARAM_INDEX_env__m2_env ==idx ){ return 1; }
 return 0;
}
  public: void Init(rootc * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (  ){
}
}
;class instancedumpMGR{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (  ){
// ADC switches invoke patch statedump
static uint8_t isRunning = false;
uint8_t        currADC   = adcvalues[12]>>6; // deliberate precision loss

if( !isRunning && currADC >= 45 ) isRunning = true; // tx patch statedump

static uint8_t  txChan = 0;
static uint16_t kCount = 0; // slow down processing
if( isRunning && ++kCount > 1500 && txChan <= 5 ) //ch0..5
{
 kCount = 0;

 MidiSend2((midi_device_t) MIDI_DEVICE_INTERNAL, 1, txChan + MIDI_PROGRAM_CHANGE, 127 ); // 2byte
 txChan++;

 if( txChan > 5 ){ txChan = 0; isRunning = false; }
}
  

/* 
// TOG switches invoke patch statedump
static uint8_t latch   = false;
uint8_t        currKEY = parent->instancepanelTOG_i.key;

if( !latch && currKEY <= 215 ) { // 215 means two TOGs enabled
	latch = true;
	for(uint8_t txChan=0; txChan<15; txChan++){ // ch0..15
	MidiSend3((midi_device_t) MIDI_DEVICE_INTERNAL, 1, txChan + MIDI_PROGRAM_CHANGE, 127, 0 );
  }
}
if( latch && currKEY == 247 ) latch = false; // 247 means idle
*/
}
}
;/* controller instances */
/* object instances */
     instancelogger__1 instancelogger__1_i;
     instancealgo__1 instancealgo__1_i;
     instancealgo__2 instancealgo__2_i;
     instancealgo__3 instancealgo__3_i;
     instancealgo__4 instancealgo__4_i;
     instancealgo__5 instancealgo__5_i;
     instancepatcher__1 instancepatcher__1_i;
     instancepatcher__2 instancepatcher__2_i;
     instancepatcher__3 instancepatcher__3_i;
     instancepatcher__4 instancepatcher__4_i;
     instancepatcher__5 instancepatcher__5_i;
     instancepatcher__6 instancepatcher__6_i;
     instancesum8__1 instancesum8__1_i;
     instanceout__1 instanceout__1_i;
     instanceoutconfig__1 instanceoutconfig__1_i;
     instancefourkit__10 instancefourkit__10_i;
     instancecc7__100 instancecc7__100_i;
     instanceccMGR instanceccMGR_i;
     instancedumpMGR instancedumpMGR_i;
/* net latches */
    int32buffer  net2Latch;
static const int polyIndex = 0;
   static int32_t * GetInitParams(void){
      static const int32_t p[6]= {
      1,
      1,
      1,
      1,
      1,
      1
      };
      return (int32_t *)&p[0];
   }   static const int32_t * GetPresets(void){
      static const int32_t p[NPRESETS][NPRESET_ENTRIES][2] = {
      };
   return &p[0][0][0];
   };
void ApplyPreset(int index){
   if (!index) {
     int i;
     int32_t *p = GetInitParams();
     for(i=0;i<NPEXCH;i++){
        PExParameterChange(&PExch[i],p[i],0xFFEF);
     }
   }
   index--;
   if (index < NPRESETS) {
     PresetParamChange_t *pa = (PresetParamChange_t *)(GetPresets());
     PresetParamChange_t *p = &pa[index*NPRESET_ENTRIES];
       int i;
       for(i=0;i<NPRESET_ENTRIES;i++){
         PresetParamChange_t *pp = &p[i];
         if ((pp->pexIndex>=0)&&(pp->pexIndex<NPEXCH)) {
           PExParameterChange(&PExch[pp->pexIndex],pp->value,0xFFEF);         }
         else break;
       }
   }
}
   static PExModulationTarget_t * GetModulationTable(void){
    static const PExModulationTarget_t PExModulationSources[NMODULATIONSOURCES][NMODULATIONTARGETS] = 
{};
   return (PExModulationTarget_t *)&PExModulationSources[0][0];
   };
/* init */
void Init() {
   int i;
   int j;
   const int32_t *p;
   p = GetInitParams();
   for(j=0;j<6;j++){
      PExch[j].value = p[j];
      PExch[j].modvalue = p[j];
      PExch[j].signals = 0;
      PExch[j].pfunction = 0;
   }
   int32_t *pp = &PExModulationPrevVal[0][0];
   for(j=0;j<1*NMODULATIONSOURCES;j++){
      *pp = 0; pp++;
   }
     displayVector[0] = 0x446F7841;
     displayVector[1] = 0;
     displayVector[2] = 2;
   instancelogger__1_i.Init(this );
   instancealgo__1_i.Init(this );
   instancealgo__2_i.Init(this );
   instancealgo__3_i.Init(this );
   instancealgo__4_i.Init(this );
   instancealgo__5_i.Init(this );
   instancepatcher__1_i.Init(this );
   instancepatcher__2_i.Init(this );
   instancepatcher__3_i.Init(this );
   instancepatcher__4_i.Init(this );
   instancepatcher__5_i.Init(this );
   instancepatcher__6_i.Init(this );
   instancesum8__1_i.Init(this );
   instanceout__1_i.Init(this, displayVector[3], displayVector[4] );
   instanceoutconfig__1_i.Init(this );
   instancefourkit__10_i.Init(this );
   instancecc7__100_i.Init(this );
   instanceccMGR_i.Init(this );
   instancedumpMGR_i.Init(this );
      int k;
      for (k = 0; k < NPEXCH; k++) {
        if (PExch[k].pfunction){
          (PExch[k].pfunction)(&PExch[k]);
        } else {
          PExch[k].finalvalue = PExch[k].value;
        }
      }
}

/* dispose */
void Dispose() {
   instancedumpMGR_i.Dispose();
   instanceccMGR_i.Dispose();
   instancecc7__100_i.Dispose();
   instancefourkit__10_i.Dispose();
   instanceoutconfig__1_i.Dispose();
   instanceout__1_i.Dispose();
   instancesum8__1_i.Dispose();
   instancepatcher__6_i.Dispose();
   instancepatcher__5_i.Dispose();
   instancepatcher__4_i.Dispose();
   instancepatcher__3_i.Dispose();
   instancepatcher__2_i.Dispose();
   instancepatcher__1_i.Dispose();
   instancealgo__5_i.Dispose();
   instancealgo__4_i.Dispose();
   instancealgo__3_i.Dispose();
   instancealgo__2_i.Dispose();
   instancealgo__1_i.Dispose();
   instancelogger__1_i.Dispose();
}

/* krate */
void dsp (void) {
  int i;
  for(i=0;i<BUFSIZE;i++) AudioOutputLeft[i]=0;
  for(i=0;i<BUFSIZE;i++) AudioOutputRight[i]=0;
//--------- <nets> -----------//
    int32buffer  net0;
    int32buffer  net1;
    int32buffer  net2;
    int32buffer  net3;
    int32buffer  net4;
    int32buffer  net5;
    int32buffer  net6;
    int32buffer  net7;
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instancelogger__1_i.dsp();
  instancealgo__1_i.dsp(UNCONNECTED_OUTPUT_BUFFER);
  instancealgo__2_i.dsp(UNCONNECTED_OUTPUT_BUFFER);
  instancealgo__3_i.dsp(UNCONNECTED_OUTPUT_BUFFER);
  instancealgo__4_i.dsp(UNCONNECTED_OUTPUT_BUFFER);
  instancealgo__5_i.dsp(UNCONNECTED_OUTPUT_BUFFER);
  instancepatcher__1_i.dsp(net0, PExch[PARAM_INDEX_patcher__1_vtype].finalvalue);
  instancepatcher__2_i.dsp(net3, PExch[PARAM_INDEX_patcher__2_vtype].finalvalue);
  instancepatcher__3_i.dsp(net4, PExch[PARAM_INDEX_patcher__3_vtype].finalvalue);
  instancepatcher__4_i.dsp(net5, PExch[PARAM_INDEX_patcher__4_vtype].finalvalue);
  instancepatcher__5_i.dsp(net6, PExch[PARAM_INDEX_patcher__5_vtype].finalvalue);
  instancepatcher__6_i.dsp(net7, PExch[PARAM_INDEX_patcher__6_vtype].finalvalue);
  instancesum8__1_i.dsp(net0, net3, net4, net5, net6, net7, zerobuffer, net2Latch, net1);
  instanceout__1_i.dsp(net1, net1, displayVector[3], displayVector[4]);
  instanceoutconfig__1_i.dsp();
  instancefourkit__10_i.dsp(net2);
  instancecc7__100_i.dsp();
  instanceccMGR_i.dsp();
  instancedumpMGR_i.dsp();
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
   for(i=0;i<BUFSIZE;i++)
      net2Latch[i]=net2[i];
//--------- </net latch copy> ----------//
}

void MidiInHandler(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2){
instancelogger__1_i.MidiInHandler(dev, port, status, data1, data2);
instancealgo__1_i.MidiInHandler(dev, port, status, data1, data2);
instancealgo__2_i.MidiInHandler(dev, port, status, data1, data2);
instancealgo__3_i.MidiInHandler(dev, port, status, data1, data2);
instancealgo__4_i.MidiInHandler(dev, port, status, data1, data2);
instancealgo__5_i.MidiInHandler(dev, port, status, data1, data2);
instancepatcher__1_i.MidiInHandler(dev, port, status, data1, data2);
instancepatcher__2_i.MidiInHandler(dev, port, status, data1, data2);
instancepatcher__3_i.MidiInHandler(dev, port, status, data1, data2);
instancepatcher__4_i.MidiInHandler(dev, port, status, data1, data2);
instancepatcher__5_i.MidiInHandler(dev, port, status, data1, data2);
instancepatcher__6_i.MidiInHandler(dev, port, status, data1, data2);
instancefourkit__10_i.MidiInHandler(dev, port, status, data1, data2);
}

};

static rootc root;
void PatchProcess( int32_t * inbuf, int32_t * outbuf) {
  int i;
  for(i=0;i<BUFSIZE;i++){
    AudioInputLeft[i] = inbuf[i*2]>>4;
    switch(AudioInputMode) {
       case A_MONO:
             AudioInputRight[i] = AudioInputLeft[i];break;
       case A_BALANCED:
             AudioInputLeft[i] = (AudioInputLeft[i] - (inbuf[i*2+1]>>4) ) >> 1;
             AudioInputRight[i] = AudioInputLeft[i];             break;
       case A_STEREO:
       default:
             AudioInputRight[i] = inbuf[i*2+1]>>4;
     }
  }
  root.dsp();
  for(i=0;i<BUFSIZE;i++){
    outbuf[i*2] = __SSAT(AudioOutputLeft[i],28)<<4;
    switch(AudioOutputMode) {
       case A_MONO:
             outbuf[i*2+1] = 0;break;
       case A_BALANCED:
             outbuf[i*2+1] = ~ outbuf[i*2];break;
       case A_STEREO:
       default:
             outbuf[i*2+1] = __SSAT(AudioOutputRight[i],28)<<4;
     }
  }
}

void ApplyPreset(int32_t i) {
   root.ApplyPreset(i);
}

void PatchMidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2){
  root.MidiInHandler(dev, port, status, data1, data2);
}

typedef void (*funcp_t)(void);
typedef funcp_t * funcpp_t;
extern funcp_t __ctor_array_start;
extern funcp_t __ctor_array_end;extern funcp_t __dtor_array_start;
extern funcp_t __dtor_array_end;void PatchDispose( ) {
  root.Dispose();
  {
    funcpp_t fpp = &__dtor_array_start;
    while (fpp < &__dtor_array_end) {
      (*fpp)();
      fpp++;
    }
  }
}

void xpatch_init2(int fwid)
{
  if (fwid != 0xE95BAC96) {
    return;  }
  extern uint32_t _pbss_start;
  extern uint32_t _pbss_end;
  volatile uint32_t *p;
  for(p=&_pbss_start;p<&_pbss_end;p++) *p=0;
  {
    funcpp_t fpp = &__ctor_array_start;
    while (fpp < &__ctor_array_end) {
      (*fpp)();
      fpp++;
    }
  }
  patchMeta.npresets = 0;
  patchMeta.npreset_entries = 0;
  patchMeta.pPresets = (PresetParamChange_t*) root.GetPresets();
  patchMeta.pPExch = &root.PExch[0];
  patchMeta.pDisplayVector = &root.displayVector[0];
  patchMeta.numPEx = 6;
  patchMeta.patchID = -2066148404;
  extern char _sdram_dyn_start;
  extern char _sdram_dyn_end;
  sdram_init(&_sdram_dyn_start,&_sdram_dyn_end);
  root.Init();
  patchMeta.fptr_applyPreset = ApplyPreset;
  patchMeta.fptr_patch_dispose = PatchDispose;
  patchMeta.fptr_MidiInHandler = PatchMidiInHandler;
  patchMeta.fptr_dsp_process = PatchProcess;
}
