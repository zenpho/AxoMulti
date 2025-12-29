#include "~/Documents/ksoloti/1.0.12/axoloti-factory/objects/osc/brds/brds_digital.h"
#include "~/Documents/ksoloti/1.0.12/axoloti-factory/objects/osc/brds/brds_analog.h"

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
    static const uint32_t NPEXCH = 12;
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
static const int PARAM_INDEX_patcher__1_etype = 1;
static const int PARAM_INDEX_patcher__2_vtype = 2;
static const int PARAM_INDEX_patcher__2_etype = 3;
static const int PARAM_INDEX_patcher__3_vtype = 4;
static const int PARAM_INDEX_patcher__3_etype = 5;
static const int PARAM_INDEX_patcher__4_vtype = 6;
static const int PARAM_INDEX_patcher__4_etype = 7;
static const int PARAM_INDEX_patcher__5_vtype = 8;
static const int PARAM_INDEX_patcher__5_etype = 9;
static const int PARAM_INDEX_patcher__6_vtype = 10;
static const int PARAM_INDEX_patcher__6_etype = 11;
/* controller classes */
/* object classes */
class instanceident{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent) {
parent = _parent;
static const char *idPATCH = "ks-multi28b (2025jul24)";
const char              *c = 0;

c = idPATCH;
MidiSend1((midi_device_t) MIDI_DEVICE_DIN, 1, 0xF0 );
while( *c != 0 )
{
 MidiSend1((midi_device_t) MIDI_DEVICE_DIN, 1, *c );
 c++;
}
MidiSend1((midi_device_t) MIDI_DEVICE_DIN, 1, 0xF7 );
}
  public: void Dispose() {
}
  public: void dsp (  ){
}
}
;class instancealgo__1{
  public: // v1
  rootc *parent;
   static int32_t * GetInitParams(void){
      static const int32_t p[11]= {
      0,
      29360128,
      47185920,
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
static const int PARAM_INDEX_fm__1_pitch = 0;
static const int PARAM_INDEX_fm__1_timbre = 1;
static const int PARAM_INDEX_fm__1_color = 2;
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
static const int PARAM_INDEX_fm__1_pitch = 0;
static const int PARAM_INDEX_fm__1_timbre = 1;
static const int PARAM_INDEX_fm__1_color = 2;
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
class instancekeyb__1{
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
;class instancefm__1{
  public: // v1
  voice *parent;



braids_digital_deriv::Fm osc;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_fm__1_pitch].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_fm__1_timbre].pfunction = pfun_unsigned_clamp;
  
  
parent->PExch[PARAM_INDEX_fm__1_color].pfunction = pfun_unsigned_clamp;
  
  
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

int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a__time_a].pfunction = pfun_signed_clamp;
  
  
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

  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a__vel_amp].pfunction = pfun_signed_clamp;
  
  
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



int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_env__t_time].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__t_vt].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__t_env].pfunction = pfun_signed_clamp;
  
  
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



int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_env__c_time].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__c_vt].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__c_env].pfunction = pfun_signed_clamp;
  
  
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
     instancekeyb__1 instancekeyb__1_i;
     instancefm__1 instancefm__1_i;
     instancea__time instancea__time_i;
     instancea__vel instancea__vel_i;
     instancevca__1 instancevca__1_i;
     instanceoutlet__1 instanceoutlet__1_i;
     instanceenv__t instanceenv__t_i;
     instanceenv__c instanceenv__c_i;
/* net latches */
    int32_t  net3Latch;
    int32_t  net6Latch;
    int32_t  net7Latch;
instancealgo__1 *common;
void Init(voice *parent) {
        int i;
        for(i=0;i<NPEXCH;i++){
          PExch[i].pfunction = 0;
        }
   instancekeyb__1_i.Init(parent );
   instancefm__1_i.Init(parent );
   instancea__time_i.Init(parent );
   instancea__vel_i.Init(parent );
   instancevca__1_i.Init(parent );
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
    int32buffer  net4;
    int32buffer  net5;
    int32_t  net6;
    int32_t  net7;
    int32_t  net8;
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instancekeyb__1_i.dsp(net8, (bool &)UNCONNECTED_OUTPUT, net2, net0, UNCONNECTED_OUTPUT);
  instancefm__1_i.dsp(net8, net6Latch, net7Latch, net4, PExch[PARAM_INDEX_fm__1_pitch].finalvalue, PExch[PARAM_INDEX_fm__1_timbre].finalvalue, PExch[PARAM_INDEX_fm__1_color].finalvalue);
  instancea__time_i.dsp(net2, net3Latch, net1, PExch[PARAM_INDEX_a__time_a].finalvalue);
  instancea__vel_i.dsp(net0, net3, PExch[PARAM_INDEX_a__vel_amp].finalvalue);
  instancevca__1_i.dsp(net1, net4, net5);
  instanceoutlet__1_i.dsp(net5);
  instanceenv__t_i.dsp(net2, net0, net6, PExch[PARAM_INDEX_env__t_time].finalvalue, PExch[PARAM_INDEX_env__t_vt].finalvalue, PExch[PARAM_INDEX_env__t_env].finalvalue);
  instanceenv__c_i.dsp(net2, net0, net7, PExch[PARAM_INDEX_env__c_time].finalvalue, PExch[PARAM_INDEX_env__c_vt].finalvalue, PExch[PARAM_INDEX_env__c_env].finalvalue);
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
net3Latch = net3;
net6Latch = net6;
net7Latch = net7;
//--------- </net latch copy> ----------//
}
void dispose(void) {
 int i;
   instanceenv__c_i.Dispose();
   instanceenv__t_i.Dispose();
   instanceoutlet__1_i.Dispose();
   instancevca__1_i.Dispose();
   instancea__vel_i.Dispose();
   instancea__time_i.Dispose();
   instancefm__1_i.Dispose();
   instancekeyb__1_i.Dispose();
}
void MidiInHandler(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2){
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
      static const int32_t p[7]= {
      0,
      0,
      -134217728,
      0,
      0,
      0,
      0
      };
      return (int32_t *)&p[0];
   }    static const uint32_t NPEXCH = 7;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 0;
    static const uint32_t NPRESET_ENTRIES = 0;
    static const uint32_t NMODULATIONSOURCES = 0;
    static const uint32_t NMODULATIONTARGETS = 0;
    int32_t PExModulationPrevVal[1][NMODULATIONSOURCES];
/* parameter instance indices */
static const int PARAM_INDEX_sinefold__1_pitch = 0;
static const int PARAM_INDEX_sinefold__1_timbre = 1;
static const int PARAM_INDEX_a__time_a = 2;
static const int PARAM_INDEX_a__vel_amp = 3;
static const int PARAM_INDEX_env__t_time = 4;
static const int PARAM_INDEX_env__t_vt = 5;
static const int PARAM_INDEX_env__t_env = 6;
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
    static const uint32_t NPEXCH = 7;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 0;
    static const uint32_t NPRESET_ENTRIES = 0;
    static const uint32_t NMODULATIONSOURCES = 0;
    static const uint32_t NMODULATIONTARGETS = 0;
/* modsource defines */
/* parameter instance indices */
static const int PARAM_INDEX_sinefold__1_pitch = 0;
static const int PARAM_INDEX_sinefold__1_timbre = 1;
static const int PARAM_INDEX_a__time_a = 2;
static const int PARAM_INDEX_a__vel_amp = 3;
static const int PARAM_INDEX_env__t_time = 4;
static const int PARAM_INDEX_env__t_vt = 5;
static const int PARAM_INDEX_env__t_env = 6;
/* controller classes */
/* object classes */
class instancekeyb__1{
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
;class instancesinefold__1{
  public: // v1
  voice *parent;


braids_deriv::SineFold osc;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_sinefold__1_pitch].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_sinefold__1_timbre].pfunction = pfun_unsigned_clamp;
  
  
osc.Init();
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_pitch,
const int32_t  inlet_timbre,
int32buffer  & outlet_wave,
int param_pitch,
int param_timbre  ){
osc.set_parameter(__USAT((inlet_timbre+param_timbre)>>12,15));
osc.set_pitch((64<<7)+((param_pitch + inlet_pitch)>>14));

osc.Render(0,&outlet_wave[0],BUFSIZE);
}
}
;class instancea__time{
  public: // v1
  voice *parent;

int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a__time_a].pfunction = pfun_signed_clamp;
  
  
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

  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a__vel_amp].pfunction = pfun_signed_clamp;
  
  
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



int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_env__t_time].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__t_vt].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__t_env].pfunction = pfun_signed_clamp;
  
  
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
     instancekeyb__1 instancekeyb__1_i;
     instancesinefold__1 instancesinefold__1_i;
     instancea__time instancea__time_i;
     instancea__vel instancea__vel_i;
     instancevca__1 instancevca__1_i;
     instanceoutlet__1 instanceoutlet__1_i;
     instanceenv__t instanceenv__t_i;
/* net latches */
    int32_t  net4Latch;
    int32_t  net7Latch;
instancealgo__2 *common;
void Init(voice *parent) {
        int i;
        for(i=0;i<NPEXCH;i++){
          PExch[i].pfunction = 0;
        }
   instancekeyb__1_i.Init(parent );
   instancesinefold__1_i.Init(parent );
   instancea__time_i.Init(parent );
   instancea__vel_i.Init(parent );
   instancevca__1_i.Init(parent );
   instanceoutlet__1_i.Init(parent );
   instanceenv__t_i.Init(parent );
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
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instancekeyb__1_i.dsp(net0, (bool &)UNCONNECTED_OUTPUT, net2, net1, UNCONNECTED_OUTPUT);
  instancesinefold__1_i.dsp(net0, net7Latch, net5, PExch[PARAM_INDEX_sinefold__1_pitch].finalvalue, PExch[PARAM_INDEX_sinefold__1_timbre].finalvalue);
  instancea__time_i.dsp(net2, net4Latch, net3, PExch[PARAM_INDEX_a__time_a].finalvalue);
  instancea__vel_i.dsp(net1, net4, PExch[PARAM_INDEX_a__vel_amp].finalvalue);
  instancevca__1_i.dsp(net3, net5, net6);
  instanceoutlet__1_i.dsp(net6);
  instanceenv__t_i.dsp(net2, net1, net7, PExch[PARAM_INDEX_env__t_time].finalvalue, PExch[PARAM_INDEX_env__t_vt].finalvalue, PExch[PARAM_INDEX_env__t_env].finalvalue);
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
net4Latch = net4;
net7Latch = net7;
//--------- </net latch copy> ----------//
}
void dispose(void) {
 int i;
   instanceenv__t_i.Dispose();
   instanceoutlet__1_i.Dispose();
   instancevca__1_i.Dispose();
   instancea__vel_i.Dispose();
   instancea__time_i.Dispose();
   instancesinefold__1_i.Dispose();
   instancekeyb__1_i.Dispose();
}
void MidiInHandler(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2){
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
   for(j=0;j<7;j++){
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
      static const int32_t p[11]= {
      0,
      134217728,
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
static const int PARAM_INDEX_wtables__1_pitch = 0;
static const int PARAM_INDEX_wtables__1_timbre = 1;
static const int PARAM_INDEX_wtables__1_color = 2;
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
static const int PARAM_INDEX_wtables__1_pitch = 0;
static const int PARAM_INDEX_wtables__1_timbre = 1;
static const int PARAM_INDEX_wtables__1_color = 2;
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
class instancewtables__1{
  public: // v1
  voice *parent;



braids_digital_deriv::Wavetables osc;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_wtables__1_pitch].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_wtables__1_timbre].pfunction = pfun_unsigned_clamp;
  
  
parent->PExch[PARAM_INDEX_wtables__1_color].pfunction = pfun_unsigned_clamp;
  
  
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

int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a__time_a].pfunction = pfun_signed_clamp;
  
  
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

  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a__vel_amp].pfunction = pfun_signed_clamp;
  
  
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



int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_env__t_time].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__t_vt].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__t_env].pfunction = pfun_signed_clamp;
  
  
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



int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_env__c_time].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__c_vt].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__c_env].pfunction = pfun_signed_clamp;
  
  
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
     instancewtables__1 instancewtables__1_i;
     instancea__time instancea__time_i;
     instancekeyb__1 instancekeyb__1_i;
     instancea__vel instancea__vel_i;
     instancevca__1 instancevca__1_i;
     instanceoutlet__1 instanceoutlet__1_i;
     instanceenv__t instanceenv__t_i;
     instanceenv__c instanceenv__c_i;
/* net latches */
    int32_t  net1Latch;
    bool  net4Latch;
    int32_t  net5Latch;
    int32_t  net7Latch;
    int32_t  net8Latch;
instancealgo__3 *common;
void Init(voice *parent) {
        int i;
        for(i=0;i<NPEXCH;i++){
          PExch[i].pfunction = 0;
        }
   instancewtables__1_i.Init(parent );
   instancea__time_i.Init(parent );
   instancekeyb__1_i.Init(parent );
   instancea__vel_i.Init(parent );
   instancevca__1_i.Init(parent );
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
    int32buffer  net2;
    int32_t  net3;
    bool  net4;
    int32_t  net5;
    int32buffer  net6;
    int32_t  net7;
    int32_t  net8;
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instancewtables__1_i.dsp(net1Latch, net7Latch, net8Latch, net2, PExch[PARAM_INDEX_wtables__1_pitch].finalvalue, PExch[PARAM_INDEX_wtables__1_timbre].finalvalue, PExch[PARAM_INDEX_wtables__1_color].finalvalue);
  instancea__time_i.dsp(net4Latch, net5Latch, net3, PExch[PARAM_INDEX_a__time_a].finalvalue);
  instancekeyb__1_i.dsp(net1, (bool &)UNCONNECTED_OUTPUT, net4, net0, UNCONNECTED_OUTPUT);
  instancea__vel_i.dsp(net0, net5, PExch[PARAM_INDEX_a__vel_amp].finalvalue);
  instancevca__1_i.dsp(net3, net2, net6);
  instanceoutlet__1_i.dsp(net6);
  instanceenv__t_i.dsp(net4, net0, net7, PExch[PARAM_INDEX_env__t_time].finalvalue, PExch[PARAM_INDEX_env__t_vt].finalvalue, PExch[PARAM_INDEX_env__t_env].finalvalue);
  instanceenv__c_i.dsp(net4, net0, net8, PExch[PARAM_INDEX_env__c_time].finalvalue, PExch[PARAM_INDEX_env__c_vt].finalvalue, PExch[PARAM_INDEX_env__c_env].finalvalue);
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
net1Latch = net1;
net4Latch = net4;
net5Latch = net5;
net7Latch = net7;
net8Latch = net8;
//--------- </net latch copy> ----------//
}
void dispose(void) {
 int i;
   instanceenv__c_i.Dispose();
   instanceenv__t_i.Dispose();
   instanceoutlet__1_i.Dispose();
   instancevca__1_i.Dispose();
   instancea__vel_i.Dispose();
   instancekeyb__1_i.Dispose();
   instancea__time_i.Dispose();
   instancewtables__1_i.Dispose();
}
void MidiInHandler(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2){
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
;class instancealgo__4{
  public: // v1
  rootc *parent;
   static int32_t * GetInitParams(void){
      static const int32_t p[7]= {
      0,
      0,
      -134217728,
      0,
      0,
      0,
      0
      };
      return (int32_t *)&p[0];
   }    static const uint32_t NPEXCH = 7;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 0;
    static const uint32_t NPRESET_ENTRIES = 0;
    static const uint32_t NMODULATIONSOURCES = 0;
    static const uint32_t NMODULATIONTARGETS = 0;
    int32_t PExModulationPrevVal[1][NMODULATIONSOURCES];
/* parameter instance indices */
static const int PARAM_INDEX_buzz__1_pitch = 0;
static const int PARAM_INDEX_buzz__1_timbre = 1;
static const int PARAM_INDEX_a__time_a = 2;
static const int PARAM_INDEX_a__vel_amp = 3;
static const int PARAM_INDEX_env__t_time = 4;
static const int PARAM_INDEX_env__t_vt = 5;
static const int PARAM_INDEX_env__t_env = 6;
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
    static const uint32_t NPEXCH = 7;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 0;
    static const uint32_t NPRESET_ENTRIES = 0;
    static const uint32_t NMODULATIONSOURCES = 0;
    static const uint32_t NMODULATIONTARGETS = 0;
/* modsource defines */
/* parameter instance indices */
static const int PARAM_INDEX_buzz__1_pitch = 0;
static const int PARAM_INDEX_buzz__1_timbre = 1;
static const int PARAM_INDEX_a__time_a = 2;
static const int PARAM_INDEX_a__vel_amp = 3;
static const int PARAM_INDEX_env__t_time = 4;
static const int PARAM_INDEX_env__t_vt = 5;
static const int PARAM_INDEX_env__t_env = 6;
/* controller classes */
/* object classes */
class instancebuzz__1{
  public: // v1
  voice *parent;


braids_deriv::Buzz osc;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_buzz__1_pitch].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_buzz__1_timbre].pfunction = pfun_unsigned_clamp;
  
  
osc.Init();
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_pitch,
const int32_t  inlet_timbre,
int32buffer  & outlet_wave,
int param_pitch,
int param_timbre  ){
osc.set_parameter(__USAT((inlet_timbre+param_timbre)>>12,15));
osc.set_pitch((64<<7)+((param_pitch + inlet_pitch)>>14));

osc.Render(0,&outlet_wave[0],BUFSIZE);
}
}
;class instancea__time{
  public: // v1
  voice *parent;

int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a__time_a].pfunction = pfun_signed_clamp;
  
  
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

  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a__vel_amp].pfunction = pfun_signed_clamp;
  
  
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



int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_env__t_time].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__t_vt].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__t_env].pfunction = pfun_signed_clamp;
  
  
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
     instancebuzz__1 instancebuzz__1_i;
     instancea__time instancea__time_i;
     instancekeyb__1 instancekeyb__1_i;
     instancea__vel instancea__vel_i;
     instancevca__1 instancevca__1_i;
     instanceoutlet__1 instanceoutlet__1_i;
     instanceenv__t instanceenv__t_i;
/* net latches */
    bool  net2Latch;
    int32_t  net3Latch;
    int32_t  net5Latch;
    int32_t  net7Latch;
instancealgo__4 *common;
void Init(voice *parent) {
        int i;
        for(i=0;i<NPEXCH;i++){
          PExch[i].pfunction = 0;
        }
   instancebuzz__1_i.Init(parent );
   instancea__time_i.Init(parent );
   instancekeyb__1_i.Init(parent );
   instancea__vel_i.Init(parent );
   instancevca__1_i.Init(parent );
   instanceoutlet__1_i.Init(parent );
   instanceenv__t_i.Init(parent );
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
    int32buffer  net4;
    int32_t  net5;
    int32buffer  net6;
    int32_t  net7;
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instancebuzz__1_i.dsp(net5Latch, net7Latch, net4, PExch[PARAM_INDEX_buzz__1_pitch].finalvalue, PExch[PARAM_INDEX_buzz__1_timbre].finalvalue);
  instancea__time_i.dsp(net2Latch, net3Latch, net1, PExch[PARAM_INDEX_a__time_a].finalvalue);
  instancekeyb__1_i.dsp(net5, (bool &)UNCONNECTED_OUTPUT, net2, net0, UNCONNECTED_OUTPUT);
  instancea__vel_i.dsp(net0, net3, PExch[PARAM_INDEX_a__vel_amp].finalvalue);
  instancevca__1_i.dsp(net1, net4, net6);
  instanceoutlet__1_i.dsp(net6);
  instanceenv__t_i.dsp(net2, net0, net7, PExch[PARAM_INDEX_env__t_time].finalvalue, PExch[PARAM_INDEX_env__t_vt].finalvalue, PExch[PARAM_INDEX_env__t_env].finalvalue);
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
net2Latch = net2;
net3Latch = net3;
net5Latch = net5;
net7Latch = net7;
//--------- </net latch copy> ----------//
}
void dispose(void) {
 int i;
   instanceenv__t_i.Dispose();
   instanceoutlet__1_i.Dispose();
   instancevca__1_i.Dispose();
   instancea__vel_i.Dispose();
   instancekeyb__1_i.Dispose();
   instancea__time_i.Dispose();
   instancebuzz__1_i.Dispose();
}
void MidiInHandler(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2){
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
   for(j=0;j<7;j++){
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
      static const int32_t p[16]= {
      0,
      0,
      0,
      0,
      0,
      -134217728,
      0,
      83886080,
      0,
      62914560,
      0,
      0,
      0,
      0,
      0,
      0
      };
      return (int32_t *)&p[0];
   }    static const uint32_t NPEXCH = 16;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 0;
    static const uint32_t NPRESET_ENTRIES = 0;
    static const uint32_t NMODULATIONSOURCES = 0;
    static const uint32_t NMODULATIONTARGETS = 0;
    int32_t PExModulationPrevVal[1][NMODULATIONSOURCES];
/* parameter instance indices */
static const int PARAM_INDEX_tmo__1_pitch1 = 0;
static const int PARAM_INDEX_tmo__1_Hrm1 = 1;
static const int PARAM_INDEX_tmo__1_Hrm2 = 2;
static const int PARAM_INDEX_tmo__1_Hrm3 = 3;
static const int PARAM_INDEX_tmo__1_lfo = 4;
static const int PARAM_INDEX_a__time_a = 5;
static const int PARAM_INDEX_a__vel_amp = 6;
static const int PARAM_INDEX_env__t_time = 7;
static const int PARAM_INDEX_env__t_vt = 8;
static const int PARAM_INDEX_env__t_env = 9;
static const int PARAM_INDEX_env__c_time = 10;
static const int PARAM_INDEX_env__c_vt = 11;
static const int PARAM_INDEX_env__c_env = 12;
static const int PARAM_INDEX_env__s_time = 13;
static const int PARAM_INDEX_env__s_vt = 14;
static const int PARAM_INDEX_env__s_env = 15;
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
    static const uint32_t NPEXCH = 16;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 0;
    static const uint32_t NPRESET_ENTRIES = 0;
    static const uint32_t NMODULATIONSOURCES = 0;
    static const uint32_t NMODULATIONTARGETS = 0;
/* modsource defines */
/* parameter instance indices */
static const int PARAM_INDEX_tmo__1_pitch1 = 0;
static const int PARAM_INDEX_tmo__1_Hrm1 = 1;
static const int PARAM_INDEX_tmo__1_Hrm2 = 2;
static const int PARAM_INDEX_tmo__1_Hrm3 = 3;
static const int PARAM_INDEX_tmo__1_lfo = 4;
static const int PARAM_INDEX_a__time_a = 5;
static const int PARAM_INDEX_a__vel_amp = 6;
static const int PARAM_INDEX_env__t_time = 7;
static const int PARAM_INDEX_env__t_vt = 8;
static const int PARAM_INDEX_env__t_env = 9;
static const int PARAM_INDEX_env__c_time = 10;
static const int PARAM_INDEX_env__c_vt = 11;
static const int PARAM_INDEX_env__c_env = 12;
static const int PARAM_INDEX_env__s_time = 13;
static const int PARAM_INDEX_env__s_vt = 14;
static const int PARAM_INDEX_env__s_env = 15;
/* controller classes */
/* object classes */
class instancetmo__1{
  public: // v1
  voice *parent;





uint32_t Phase1;
uint32_t Phase2;
uint32_t Phase3;
int32_t a;
int32_t b;
int32_t c;
int32_t ring1;
int32_t ring2;
int32_t ring3;
int32_t ring4;
int32_t MOD1;
int32_t MOD2;
int32_t MOD3;

uint32_t phase;

uint32_t lfo;
int32_t freq;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_tmo__1_pitch1].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_tmo__1_Hrm1].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_tmo__1_Hrm2].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_tmo__1_Hrm3].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_tmo__1_lfo].pfunction = pfun_signed_clamp;
  
  
Phase1 = 0;
Phase2 = 0;
Phase3 = 0;

phase = 0;


}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_pitch,
const int32_t  inlet_FM,
const int32_t  inlet_PM,
const int32_t  inlet_AM,
const bool  inlet_active,
int32buffer  & outlet_phasor,
int param_pitch1,
int param_Hrm1,
int param_Hrm2,
int param_Hrm3,
int param_lfo  ){

if(inlet_active>0){
         MTOFEXTENDED(inlet_pitch + param_lfo,freq);
         lfo += freq>>2;
}
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
if(inlet_active>0){
   uint32_t f;
   MTOFEXTENDED(param_pitch1 + inlet_pitch,f);
   f=f*(param_Hrm1>>20);
   MOD1= ___SMMUL(inlet_FM,c<<3);
Phase1 += (f)+(___SMMUL(f<<3,MOD1<<3)<<1);

SINE2TINTERP((Phase1<<1)+___SMMUL(inlet_AM<<3,(-ring4<<11)),a)

   uint32_t g;
   MTOFEXTENDED(param_pitch1 + inlet_pitch,g);
   g=g*(param_Hrm2>>20);
   MOD2= ___SMMUL(inlet_FM,-a<<3);
Phase2 += (g)+(___SMMUL(g<<3,MOD2<<3)<<1);

SINE2TINTERP((Phase2<<1)+(___SMMUL(inlet_PM<<4,a)<<3)+lfo,b)

   uint32_t h;
   MTOFEXTENDED(param_pitch1 + inlet_pitch,h);
   h=h*(param_Hrm3>>20);
   MOD3= ___SMMUL(inlet_FM,-b<<3);
Phase3 += (h)+(___SMMUL(h<<3,MOD3<<3)<<1);

SINE2TINTERP((Phase3<<1)+(___SMMUL(inlet_PM<<4,b)<<3)-(lfo<<1)+(1<<26),c)


ring1=___SMMUL(a>>2,b>>3)>>3;
ring2=___SMMUL(b>>2,c>>3)>>3;
ring3=___SMMUL(a>>2,c>>3)>>3;
ring4=___SMMUL(ring1,c>>3)>>3;

   outlet_phasor[buffer_index] = (a>>6)+(b>>6)+(c>>6)+___SMMUL(inlet_AM<<3,(ring1+ring2+ring3+ring4)<<4);
}
}
}
}
;class instancea__time{
  public: // v1
  voice *parent;

int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a__time_a].pfunction = pfun_signed_clamp;
  
  
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

  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a__vel_amp].pfunction = pfun_signed_clamp;
  
  
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



int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_env__t_time].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__t_vt].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__t_env].pfunction = pfun_signed_clamp;
  
  
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



int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_env__c_time].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__c_vt].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__c_env].pfunction = pfun_signed_clamp;
  
  
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



int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_env__s_time].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__s_vt].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__s_env].pfunction = pfun_signed_clamp;
  
  
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
     instancetmo__1 instancetmo__1_i;
     instancea__time instancea__time_i;
     instancekeyb__1 instancekeyb__1_i;
     instancea__vel instancea__vel_i;
     instancevca__1 instancevca__1_i;
     instanceoutlet__1 instanceoutlet__1_i;
     instanceenv__t instanceenv__t_i;
     instanceenv__c instanceenv__c_i;
     instanceenv__s instanceenv__s_i;
/* net latches */
    bool  net2Latch;
    int32_t  net3Latch;
    int32_t  net5Latch;
    int32_t  net6Latch;
    int32_t  net7Latch;
    int32_t  net8Latch;
instancealgo__5 *common;
void Init(voice *parent) {
        int i;
        for(i=0;i<NPEXCH;i++){
          PExch[i].pfunction = 0;
        }
   instancetmo__1_i.Init(parent );
   instancea__time_i.Init(parent );
   instancekeyb__1_i.Init(parent );
   instancea__vel_i.Init(parent );
   instancevca__1_i.Init(parent );
   instanceoutlet__1_i.Init(parent );
   instanceenv__t_i.Init(parent );
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
    bool  net2;
    int32_t  net3;
    int32buffer  net4;
    int32_t  net5;
    int32_t  net6;
    int32_t  net7;
    int32_t  net8;
    int32buffer  net9;
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instancetmo__1_i.dsp(net5Latch, net8Latch, net7Latch, net6Latch, net2Latch, net4, PExch[PARAM_INDEX_tmo__1_pitch1].finalvalue, PExch[PARAM_INDEX_tmo__1_Hrm1].finalvalue, PExch[PARAM_INDEX_tmo__1_Hrm2].finalvalue, PExch[PARAM_INDEX_tmo__1_Hrm3].finalvalue, PExch[PARAM_INDEX_tmo__1_lfo].finalvalue);
  instancea__time_i.dsp(net2Latch, net3Latch, net1, PExch[PARAM_INDEX_a__time_a].finalvalue);
  instancekeyb__1_i.dsp(net5, (bool &)UNCONNECTED_OUTPUT, net2, net0, UNCONNECTED_OUTPUT);
  instancea__vel_i.dsp(net0, net3, PExch[PARAM_INDEX_a__vel_amp].finalvalue);
  instancevca__1_i.dsp(net1, net4, net9);
  instanceoutlet__1_i.dsp(net9);
  instanceenv__t_i.dsp(net2, net0, net8, PExch[PARAM_INDEX_env__t_time].finalvalue, PExch[PARAM_INDEX_env__t_vt].finalvalue, PExch[PARAM_INDEX_env__t_env].finalvalue);
  instanceenv__c_i.dsp(net2, net0, net7, PExch[PARAM_INDEX_env__c_time].finalvalue, PExch[PARAM_INDEX_env__c_vt].finalvalue, PExch[PARAM_INDEX_env__c_env].finalvalue);
  instanceenv__s_i.dsp(net2, net0, net6, PExch[PARAM_INDEX_env__s_time].finalvalue, PExch[PARAM_INDEX_env__s_vt].finalvalue, PExch[PARAM_INDEX_env__s_env].finalvalue);
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
net2Latch = net2;
net3Latch = net3;
net5Latch = net5;
net6Latch = net6;
net7Latch = net7;
net8Latch = net8;
//--------- </net latch copy> ----------//
}
void dispose(void) {
 int i;
   instanceenv__s_i.Dispose();
   instanceenv__c_i.Dispose();
   instanceenv__t_i.Dispose();
   instanceoutlet__1_i.Dispose();
   instancevca__1_i.Dispose();
   instancea__vel_i.Dispose();
   instancekeyb__1_i.Dispose();
   instancea__time_i.Dispose();
   instancetmo__1_i.Dispose();
}
void MidiInHandler(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2){
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
   for(j=0;j<16;j++){
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
;class instancealgo__6{
  public: // v1
  rootc *parent;
   static int32_t * GetInitParams(void){
      static const int32_t p[18]= {
      50331648,
      25165824,
      0,
      0,
      0,
      50331648,
      -73400320,
      0,
      -35651584,
      0,
      46137344,
      0,
      -58720256,
      0,
      23068672,
      0,
      50331648,
      0
      };
      return (int32_t *)&p[0];
   }    static const uint32_t NPEXCH = 18;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 0;
    static const uint32_t NPRESET_ENTRIES = 0;
    static const uint32_t NMODULATIONSOURCES = 0;
    static const uint32_t NMODULATIONTARGETS = 0;
    int32_t PExModulationPrevVal[1][NMODULATIONSOURCES];
/* parameter instance indices */
static const int PARAM_INDEX_transp__p_c = 0;
static const int PARAM_INDEX_transp__s_c = 1;
static const int PARAM_INDEX_phasor__pm__pr__b__1_pitch = 2;
static const int PARAM_INDEX_sine__1_pitch = 3;
static const int PARAM_INDEX_a__vel_amp = 4;
static const int PARAM_INDEX_a__time_d = 5;
static const int PARAM_INDEX_env__t_time = 6;
static const int PARAM_INDEX_env__t_vt = 7;
static const int PARAM_INDEX_env__t_env = 8;
static const int PARAM_INDEX_timbre_c = 9;
static const int PARAM_INDEX_env__c_time = 10;
static const int PARAM_INDEX_env__c_vt = 11;
static const int PARAM_INDEX_env__c_env = 12;
static const int PARAM_INDEX_colour_c = 13;
static const int PARAM_INDEX_env__s_time = 14;
static const int PARAM_INDEX_env__s_vt = 15;
static const int PARAM_INDEX_env__s_env = 16;
static const int PARAM_INDEX_shape_c = 17;
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
    static const uint32_t NPEXCH = 18;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 0;
    static const uint32_t NPRESET_ENTRIES = 0;
    static const uint32_t NMODULATIONSOURCES = 0;
    static const uint32_t NMODULATIONTARGETS = 0;
/* modsource defines */
/* parameter instance indices */
static const int PARAM_INDEX_transp__p_c = 0;
static const int PARAM_INDEX_transp__s_c = 1;
static const int PARAM_INDEX_phasor__pm__pr__b__1_pitch = 2;
static const int PARAM_INDEX_sine__1_pitch = 3;
static const int PARAM_INDEX_a__vel_amp = 4;
static const int PARAM_INDEX_a__time_d = 5;
static const int PARAM_INDEX_env__t_time = 6;
static const int PARAM_INDEX_env__t_vt = 7;
static const int PARAM_INDEX_env__t_env = 8;
static const int PARAM_INDEX_timbre_c = 9;
static const int PARAM_INDEX_env__c_time = 10;
static const int PARAM_INDEX_env__c_vt = 11;
static const int PARAM_INDEX_env__c_env = 12;
static const int PARAM_INDEX_colour_c = 13;
static const int PARAM_INDEX_env__s_time = 14;
static const int PARAM_INDEX_env__s_vt = 15;
static const int PARAM_INDEX_env__s_env = 16;
static const int PARAM_INDEX_shape_c = 17;
/* controller classes */
/* object classes */
class instancetransp__p{
  public: // v1
  voice *parent;

  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_transp__p_c].pfunction = pfun_unsigned_clamp;
  
  
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out,
int param_c  ){
outlet_out= inlet_in- param_c;
}
}
;class instancetransp__s{
  public: // v1
  voice *parent;

  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_transp__s_c].pfunction = pfun_unsigned_clamp;
  
  
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out,
int param_c  ){
outlet_out= inlet_in- param_c;
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
;class instancephasor__pm__pr__b__1{
  public: // v1
  voice *parent;



      uint32_t phase;
      int32_t old_reset;
      int32_t freq;

    
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_phasor__pm__pr__b__1_pitch].pfunction = pfun_signed_clamp;
  
  
phase = 0;

      phase = 0;
      old_reset = 0;

    
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_pitch,
const int32buffer  inlet_phase,
const bool  inlet_reset,
int32buffer  & outlet_out,
int param_pitch  ){


      MTOFEXTENDED(param_pitch + inlet_pitch,freq);

    
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {


      if( inlet_reset && !old_reset )
        {
          phase = 0;
        }
      else
        {
          phase += freq;
        }
      old_reset = inlet_reset;

      outlet_out[buffer_index] = ((phase + (inlet_phase[buffer_index]<<4))>>4) - (1<<27);

    
}
}
}
;class instancesine__1{
  public: // v1
  voice *parent;

uint32_t Phase;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_sine__1_pitch].pfunction = pfun_signed_clamp;
  
  
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
;class instancea__vel{
  public: // v1
  voice *parent;

  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a__vel_amp].pfunction = pfun_signed_clamp;
  
  
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out,
int param_amp  ){
outlet_out= ___SMMUL(param_amp, inlet_in)<<5;

}
}
;class instancea__time{
  public: // v1
  voice *parent;

int32_t val;
int ntrig;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_a__time_d].pfunction = pfun_signed_clamp;
  
  
val = 0;
ntrig = 0;
}
  public: void Dispose() {
}
  public: void dsp (const bool  inlet_trig,
const int32_t  inlet_d,
int32_t  & outlet_env,
int param_d  ){
if ((inlet_trig>0) && !ntrig) { val =1<<27; ntrig=1;}
else { 
 if (!(inlet_trig>0)) ntrig=0; 
 int32_t in = - inlet_d - param_d;
 int32_t c;
 MTOFEXTENDED(in, c);
 c = 0x7FFFFFFF - (c >> 2);
 val = ___SMMUL(val, c)<<1;
}

if( inlet_trig ) outlet_env = val;
else             outlet_env = 0;
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
;class instancesum8__1{
  public: // v1
  voice *parent;
  public: void Init(voice * _parent) {
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
;class instancevca__3{
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
;class instancevca__4{
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
;class instance_gt__gt___1{
  public: // v1
  voice *parent;
  public: void Init(voice * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32buffer  inlet_a,
int32buffer  & outlet_result  ){
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
outlet_result[buffer_index]= inlet_a[buffer_index] >> 2;
}
}
}
;class instanceenv__t{
  public: // v1
  voice *parent;



int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_env__t_time].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__t_vt].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__t_env].pfunction = pfun_signed_clamp;
  
  
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

if( param_env < 0 ) outlet_env -= param_env;
}
}
;class instancetimbre{
  public: // v1
  voice *parent;

  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_timbre_c].pfunction = pfun_unsigned_clamp;
  
  
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out,
int param_c  ){
outlet_out= inlet_in+ param_c;
}
}
;class instanceenv__c{
  public: // v1
  voice *parent;



int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_env__c_time].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__c_vt].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__c_env].pfunction = pfun_signed_clamp;
  
  
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

outlet_env = ___SMMUL(param_env, val)<<5;

if( param_env < 0 ) outlet_env -= param_env;
}
}
;class instancecolour{
  public: // v1
  voice *parent;

  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_colour_c].pfunction = pfun_unsigned_clamp;
  
  
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out,
int param_c  ){
outlet_out= inlet_in+ param_c;
}
}
;class instanceenv__s{
  public: // v1
  voice *parent;



int32_t val;
  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_env__s_time].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__s_vt].pfunction = pfun_signed_clamp;
  
  
parent->PExch[PARAM_INDEX_env__s_env].pfunction = pfun_signed_clamp;
  
  
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

outlet_env = ___SMMUL(param_env, val)<<5;

if( param_env < 0 ) outlet_env -= param_env;
}
}
;class instanceshape{
  public: // v1
  voice *parent;

  public: void Init(voice * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX_shape_c].pfunction = pfun_unsigned_clamp;
  
  
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_in,
int32_t  & outlet_out,
int param_c  ){
outlet_out= inlet_in+ param_c;
}
}
;/* controller instances */
/* object instances */
     instancetransp__p instancetransp__p_i;
     instancetransp__s instancetransp__s_i;
     instancekeyb__1 instancekeyb__1_i;
     instancephasor__pm__pr__b__1 instancephasor__pm__pr__b__1_i;
     instancesine__1 instancesine__1_i;
     instancea__vel instancea__vel_i;
     instancea__time instancea__time_i;
     instancevca__1 instancevca__1_i;
     instanceoutlet__1 instanceoutlet__1_i;
     instancevca__2 instancevca__2_i;
     instancesum8__1 instancesum8__1_i;
     instancevca__3 instancevca__3_i;
     instancevca__4 instancevca__4_i;
     instance_gt__gt___1 instance_gt__gt___1_i;
     instanceenv__t instanceenv__t_i;
     instancetimbre instancetimbre_i;
     instanceenv__c instanceenv__c_i;
     instancecolour instancecolour_i;
     instanceenv__s instanceenv__s_i;
     instanceshape instanceshape_i;
/* net latches */
    int32buffer  net4Latch;
    int32buffer  net5Latch;
    int32_t  net7Latch;
    int32buffer  net12Latch;
    int32buffer  net15Latch;
    int32_t  net17Latch;
    int32_t  net18Latch;
    int32_t  net19Latch;
instancealgo__6 *common;
void Init(voice *parent) {
        int i;
        for(i=0;i<NPEXCH;i++){
          PExch[i].pfunction = 0;
        }
   instancetransp__p_i.Init(parent );
   instancetransp__s_i.Init(parent );
   instancekeyb__1_i.Init(parent );
   instancephasor__pm__pr__b__1_i.Init(parent );
   instancesine__1_i.Init(parent );
   instancea__vel_i.Init(parent );
   instancea__time_i.Init(parent );
   instancevca__1_i.Init(parent );
   instanceoutlet__1_i.Init(parent );
   instancevca__2_i.Init(parent );
   instancesum8__1_i.Init(parent );
   instancevca__3_i.Init(parent );
   instancevca__4_i.Init(parent );
   instance_gt__gt___1_i.Init(parent );
   instanceenv__t_i.Init(parent );
   instancetimbre_i.Init(parent );
   instanceenv__c_i.Init(parent );
   instancecolour_i.Init(parent );
   instanceenv__s_i.Init(parent );
   instanceshape_i.Init(parent );
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
    int32buffer  net0;
    int32_t  net1;
    bool  net2;
    int32buffer  net3;
    int32buffer  net4;
    int32buffer  net5;
    int32buffer  net6;
    int32_t  net7;
    int32_t  net8;
    int32_t  net9;
    int32_t  net10;
    int32buffer  net11;
    int32buffer  net12;
    int32_t  net13;
    int32_t  net14;
    int32buffer  net15;
    int32_t  net16;
    int32_t  net17;
    int32_t  net18;
    int32_t  net19;
    int32_t  net20;
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instancetransp__p_i.dsp(net7Latch, net13, PExch[PARAM_INDEX_transp__p_c].finalvalue);
  instancetransp__s_i.dsp(net7Latch, net10, PExch[PARAM_INDEX_transp__s_c].finalvalue);
  instancekeyb__1_i.dsp(net7, (bool &)UNCONNECTED_OUTPUT, net2, net1, UNCONNECTED_OUTPUT);
  instancephasor__pm__pr__b__1_i.dsp(net13, net4Latch, 0, net3, PExch[PARAM_INDEX_phasor__pm__pr__b__1_pitch].finalvalue);
  instancesine__1_i.dsp(net10, net12Latch, net3, net11, PExch[PARAM_INDEX_sine__1_pitch].finalvalue);
  instancea__vel_i.dsp(net1, net16, PExch[PARAM_INDEX_a__vel_amp].finalvalue);
  instancea__time_i.dsp(net2, net16, net20, PExch[PARAM_INDEX_a__time_d].finalvalue);
  instancevca__1_i.dsp(net20, net11, net0);
  instanceoutlet__1_i.dsp(net0);
  instancevca__2_i.dsp(net19Latch, net3, net6);
  instancesum8__1_i.dsp(net6, net5Latch, zerobuffer, zerobuffer, zerobuffer, zerobuffer, zerobuffer, zerobuffer, net4);
  instancevca__3_i.dsp(net17Latch, net15Latch, net12);
  instancevca__4_i.dsp(net18Latch, net11, net5);
  instance_gt__gt___1_i.dsp(net3, net15);
  instanceenv__t_i.dsp(net2, net1, net9, PExch[PARAM_INDEX_env__t_time].finalvalue, PExch[PARAM_INDEX_env__t_vt].finalvalue, PExch[PARAM_INDEX_env__t_env].finalvalue);
  instancetimbre_i.dsp(net9, net19, PExch[PARAM_INDEX_timbre_c].finalvalue);
  instanceenv__c_i.dsp(net2, net1, net8, PExch[PARAM_INDEX_env__c_time].finalvalue, PExch[PARAM_INDEX_env__c_vt].finalvalue, PExch[PARAM_INDEX_env__c_env].finalvalue);
  instancecolour_i.dsp(net8, net18, PExch[PARAM_INDEX_colour_c].finalvalue);
  instanceenv__s_i.dsp(net2, net1, net14, PExch[PARAM_INDEX_env__s_time].finalvalue, PExch[PARAM_INDEX_env__s_vt].finalvalue, PExch[PARAM_INDEX_env__s_env].finalvalue);
  instanceshape_i.dsp(net14, net17, PExch[PARAM_INDEX_shape_c].finalvalue);
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
   for(i=0;i<BUFSIZE;i++)
      net4Latch[i]=net4[i];
   for(i=0;i<BUFSIZE;i++)
      net5Latch[i]=net5[i];
net7Latch = net7;
   for(i=0;i<BUFSIZE;i++)
      net12Latch[i]=net12[i];
   for(i=0;i<BUFSIZE;i++)
      net15Latch[i]=net15[i];
net17Latch = net17;
net18Latch = net18;
net19Latch = net19;
//--------- </net latch copy> ----------//
}
void dispose(void) {
 int i;
   instanceshape_i.Dispose();
   instanceenv__s_i.Dispose();
   instancecolour_i.Dispose();
   instanceenv__c_i.Dispose();
   instancetimbre_i.Dispose();
   instanceenv__t_i.Dispose();
   instance_gt__gt___1_i.Dispose();
   instancevca__4_i.Dispose();
   instancevca__3_i.Dispose();
   instancesum8__1_i.Dispose();
   instancevca__2_i.Dispose();
   instanceoutlet__1_i.Dispose();
   instancevca__1_i.Dispose();
   instancea__time_i.Dispose();
   instancea__vel_i.Dispose();
   instancesine__1_i.Dispose();
   instancephasor__pm__pr__b__1_i.Dispose();
   instancekeyb__1_i.Dispose();
   instancetransp__s_i.Dispose();
   instancetransp__p_i.Dispose();
}
void MidiInHandler(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2){
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
   for(j=0;j<18;j++){
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


int32buffer voiceBuf;        // we render here (enveloped) mixed at our outlet

int      etype;              // etype 'envelope type' (0 off, 1 down, 2 up+down)
uint32_t rampEnv[8];         // range 0..1<<26

int32_t vtype = 0;           // vtype 'voice type' chosen sound generation algorithm 
class voice {
   public:
   int polyIndex;
      
instancepatcher__1 *common;
void Init(voice *parent) {
	if( common->vtype == 1 )
	{
      instancealgo__1::voice* av = &common->get200Algo1()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 2 )
	{
      instancealgo__2::voice* av = &common->get200Algo2()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 3 )
	{
      instancealgo__3::voice* av = &common->get200Algo3()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 4 )
	{
      instancealgo__4::voice* av = &common->get200Algo4()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 5 )
	{
      instancealgo__5::voice* av = &common->get200Algo5()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 6 )
	{
      instancealgo__6::voice* av = &common->get200Algo6()[polyIndex];
      av->Init( av );
	}
}
void dsp(void) { }
void dispose(void) {
   if( common->vtype == 1 ) common->get200Algo1()[polyIndex].dispose();
   else if( common->vtype == 2 ) common->get200Algo2()[polyIndex].dispose();
   else if( common->vtype == 3 ) common->get200Algo3()[polyIndex].dispose();
   else if( common->vtype == 4 ) common->get200Algo4()[polyIndex].dispose();
   else if( common->vtype == 5 ) common->get200Algo5()[polyIndex].dispose();
   else if( common->vtype == 6 ) common->get200Algo6()[polyIndex].dispose();
}
void receiveCC(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2) {
  // passthru cc to voice
  if( common->vtype == 1 ) common->get200Algo1()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 2 ) common->get200Algo2()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 3 ) common->get200Algo3()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 4 ) common->get200Algo4()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 5 ) common->get200Algo5()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 6 ) common->get200Algo6()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);

  // ccMGR paramexchange
  if( common->vtype == 1 ) instanceccMGR::setPEx( 1, &common->get200Algo1()[polyIndex], data1, data2 );
  else if( common->vtype == 2 ) instanceccMGR::setPEx( 2, &common->get200Algo2()[polyIndex], data1, data2 );
  else if( common->vtype == 3 ) instanceccMGR::setPEx( 3, &common->get200Algo3()[polyIndex], data1, data2 );
  else if( common->vtype == 4 ) instanceccMGR::setPEx( 4, &common->get200Algo4()[polyIndex], data1, data2 );
  else if( common->vtype == 5 ) instanceccMGR::setPEx( 5, &common->get200Algo5()[polyIndex], data1, data2 );
  else if( common->vtype == 6 ) instanceccMGR::setPEx( 6, &common->get200Algo6()[polyIndex], data1, data2 );
}

};

static voice * getVoices(void){
    static voice v[8];
    return v;
}

static instancealgo__1::voice * get200Algo1(){
	static instancealgo__1::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__2::voice * get200Algo2(){
	static instancealgo__2::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__3::voice * get200Algo3(){
	static instancealgo__3::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__4::voice * get200Algo4(){
	static instancealgo__4::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__5::voice * get200Algo5(){
	static instancealgo__5::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__6::voice * get200Algo6(){
	static instancealgo__6::voice v[8] __attribute__ ((section (".sdram")));
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
int8_t pressed[8]; // 0 means released, 1 pressed, 3 sustain, 2 releasing
  public: void Init(rootc * _parent) {
parent = _parent;
for(int vi=0;vi<8;vi++){
   if( vtype == 1 ) setParamBatch( instancealgo__1::GetInitParams(), instancealgo__1::NPEXCH, &get200Algo1()[vi].PExch[0] );
   else if( vtype == 2 ) setParamBatch( instancealgo__2::GetInitParams(), instancealgo__2::NPEXCH, &get200Algo2()[vi].PExch[0] );
   else if( vtype == 3 ) setParamBatch( instancealgo__3::GetInitParams(), instancealgo__3::NPEXCH, &get200Algo3()[vi].PExch[0] );
   else if( vtype == 4 ) setParamBatch( instancealgo__4::GetInitParams(), instancealgo__4::NPEXCH, &get200Algo4()[vi].PExch[0] );
   else if( vtype == 5 ) setParamBatch( instancealgo__5::GetInitParams(), instancealgo__5::NPEXCH, &get200Algo5()[vi].PExch[0] );
   else if( vtype == 6 ) setParamBatch( instancealgo__6::GetInitParams(), instancealgo__6::NPEXCH, &get200Algo6()[vi].PExch[0] );
}

int vi; for(vi=0;vi<8;vi++) {
   voice *v = &getVoices()[vi];
   v->polyIndex = vi;
   v->common = this;
   v->Init(&getVoices()[vi]); 
   notePlaying[vi]=0;
   voicePriority[vi]=0;

   rampEnv[vi] = 0; // range 0..1<<27
}

priority=0;
sustain=0;
etype=0;
}
  public: void Dispose() {
int vi; for(vi=0;vi<8;vi++) {
  voice *v = &getVoices()[vi];
  v->dispose();
}
}
  public: void dsp (int32buffer  & outlet_outlet__1,
int param_vtype,
int param_etype  ){
etype = param_etype; // etype 'envelope type' (0 off, 1 down, 2 up+down)

bool reset = ( param_vtype != vtype ); // reset when vtype changes
if( reset ){  
 Dispose(); 
 vtype = param_vtype; 
 Init(parent); 
} 

int j; for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] = 0;

int vi; for(vi=0;vi<8;vi++) {
	
	if( pressed[vi]==0 ) continue; // 0 means released, 1 pressed, 3 sustain, 2 releasing

	// our vtype determines algo dsp
	if( vtype == 1 ){
	  get200Algo1()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo1()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 2 ){
	  get200Algo2()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo2()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 3 ){
	  get200Algo3()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo3()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 4 ){
	  get200Algo4()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo4()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 5 ){
	  get200Algo5()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo5()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 6 ){
	  get200Algo6()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo6()[vi].instanceoutlet__1_i._outlet[j]; 
	}

	// mix voiceBuf to our outlet (and apply envelope if enabled )
	for(j=0;j<BUFSIZE;j++) {
	  outlet_outlet__1[j] += ___SMMUL( voiceBuf[j], rampEnv[vi] )<<5;

	  if( etype==2 && pressed[vi] == 1 ){          // 1 means pressed
	    if( rampEnv[vi] > 1<<27 ) pressed[vi] = 3; // 3 means sustain
	    else rampEnv[vi] = rampEnv[vi]+(1<<20);    // rapid fade up
	  }

	  if( etype>=1 && pressed[vi] == 2 ){          // 2 means releasing
	    if( rampEnv[vi] < 1 ) pressed[vi] = 0;     // 0 means released
	    else rampEnv[vi] = rampEnv[vi]-(1<<17);    // rapid fade down
	  }
	}
}
}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
static int MAX_VTYPE = 6; // 0=silent

if ( 0 > 0 && dev > 0 && 0 != dev) return;
if ( 0 > 0 && port > 0 && 0 != port) return;

if( status == MIDI_PROGRAM_CHANGE + 6 && (data1<127) ){ // pgm sets 'vtype'
  uint8_t PExVal = (data1 <= MAX_VTYPE) ? data1 : 0; // 0=silent when out of range
  int     PExIdx = rootc::PARAM_INDEX_patcher__1_vtype + (2*(6-6)); // KLUDGE
  PExParameterChange( &parent->PExch[ PExIdx ], PExVal, 0xFFEF);

} else if( status == MIDI_PROGRAM_CHANGE + 6 && (data1==127) ){ // request statedump
  uint8_t txChan = 6;

  if( vtype == 0 ){ instanceccMGR::txState( 0, nullptr, txChan ); }
  else if( vtype == 1 ){ instanceccMGR::txState( 1, &get200Algo1()[0].PExch[0], txChan ); }
  else if( vtype == 2 ){ instanceccMGR::txState( 2, &get200Algo2()[0].PExch[0], txChan ); }
  else if( vtype == 3 ){ instanceccMGR::txState( 3, &get200Algo3()[0].PExch[0], txChan ); }
  else if( vtype == 4 ){ instanceccMGR::txState( 4, &get200Algo4()[0].PExch[0], txChan ); }
  else if( vtype == 5 ){ instanceccMGR::txState( 5, &get200Algo5()[0].PExch[0], txChan ); }
  else if( vtype == 6 ){ instanceccMGR::txState( 6, &get200Algo5()[0].PExch[0], txChan ); }

  // KLUDGE report cc72 release time 'etype' state
  int PExIdx   = rootc::PARAM_INDEX_patcher__1_etype + (2*(6-6)); // KLUDGE
  int txDat2   = patchMeta.pPExch[ PExIdx ].modvalue * 46;  // range 0..2 maps to 0..127
  int txCCdat1 = 72;
  MidiSend3((midi_device_t) MIDI_DEVICE_DIN, 1, txChan + MIDI_CONTROL_CHANGE, txCCdat1&0x7F, txDat2&0x7F);

} else if ((status == MIDI_NOTE_ON + 6) && (data2)) {
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
  pressed[mini] = 1; // 2 means releasing, 1 means pressed, 0 means released

  if( etype==2 ) rampEnv[mini] = 0; // etype 0 off, 1 down, 2 up+down
  else rampEnv[mini] = 1<<27;       // rampEnv range 0..1<<27

  if( vtype == 1 ) get200Algo1()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 2 ) get200Algo2()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 3 ) get200Algo3()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 4 ) get200Algo4()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 5 ) get200Algo5()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 6 ) get200Algo6()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  
  
} else if (((status == MIDI_NOTE_ON + 6) && (!data2))||
          (status == MIDI_NOTE_OFF + 6)) {
          	
  // check MIDI_NOTE_OFF or MIDI_NOTE_ON with zero velo - do not passthru to voices
  int i; for(i=0;i<8;i++){
    if ((notePlaying[i] == data1) && pressed[i]){
      voicePriority[i] = priority++;
      pressed[i] = 2; // 2 means releasing, 1 means pressed, 0 means released

      if( etype==0 ) pressed[i] = 0;
    }
  }
} else if (status == 6 + MIDI_CONTROL_CHANGE) {
  int i; for(i=0;i<8;i++) getVoices()[i].receiveCC(dev, port, status, data1, data2);

  if( data1==72 ) {              // cc72 release time sets 'etype'
    uint8_t PExVal = data2 / 46; // range 0..127 maps to 0..2 
    int     PExIdx = rootc::PARAM_INDEX_patcher__1_etype + (2*(6-6));  // KLUDGE
    PExParameterChange( &parent->PExch[ PExIdx ], PExVal, 0xFFEF);
  }
}}
}
}
;class instancepatcher__2{
  public: // v1
  rootc *parent;


int32buffer voiceBuf;        // we render here (enveloped) mixed at our outlet

int      etype;              // etype 'envelope type' (0 off, 1 down, 2 up+down)
uint32_t rampEnv[8];         // range 0..1<<26

int32_t vtype = 0;           // vtype 'voice type' chosen sound generation algorithm 
class voice {
   public:
   int polyIndex;
      
instancepatcher__2 *common;
void Init(voice *parent) {
	if( common->vtype == 1 )
	{
      instancealgo__1::voice* av = &common->get200Algo1()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 2 )
	{
      instancealgo__2::voice* av = &common->get200Algo2()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 3 )
	{
      instancealgo__3::voice* av = &common->get200Algo3()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 4 )
	{
      instancealgo__4::voice* av = &common->get200Algo4()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 5 )
	{
      instancealgo__5::voice* av = &common->get200Algo5()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 6 )
	{
      instancealgo__6::voice* av = &common->get200Algo6()[polyIndex];
      av->Init( av );
	}
}
void dsp(void) { }
void dispose(void) {
   if( common->vtype == 1 ) common->get200Algo1()[polyIndex].dispose();
   else if( common->vtype == 2 ) common->get200Algo2()[polyIndex].dispose();
   else if( common->vtype == 3 ) common->get200Algo3()[polyIndex].dispose();
   else if( common->vtype == 4 ) common->get200Algo4()[polyIndex].dispose();
   else if( common->vtype == 5 ) common->get200Algo5()[polyIndex].dispose();
   else if( common->vtype == 6 ) common->get200Algo6()[polyIndex].dispose();
}
void receiveCC(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2) {
  // passthru cc to voice
  if( common->vtype == 1 ) common->get200Algo1()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 2 ) common->get200Algo2()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 3 ) common->get200Algo3()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 4 ) common->get200Algo4()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 5 ) common->get200Algo5()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 6 ) common->get200Algo6()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);

  // ccMGR paramexchange
  if( common->vtype == 1 ) instanceccMGR::setPEx( 1, &common->get200Algo1()[polyIndex], data1, data2 );
  else if( common->vtype == 2 ) instanceccMGR::setPEx( 2, &common->get200Algo2()[polyIndex], data1, data2 );
  else if( common->vtype == 3 ) instanceccMGR::setPEx( 3, &common->get200Algo3()[polyIndex], data1, data2 );
  else if( common->vtype == 4 ) instanceccMGR::setPEx( 4, &common->get200Algo4()[polyIndex], data1, data2 );
  else if( common->vtype == 5 ) instanceccMGR::setPEx( 5, &common->get200Algo5()[polyIndex], data1, data2 );
  else if( common->vtype == 6 ) instanceccMGR::setPEx( 6, &common->get200Algo6()[polyIndex], data1, data2 );
}

};

static voice * getVoices(void){
    static voice v[8];
    return v;
}

static instancealgo__1::voice * get200Algo1(){
	static instancealgo__1::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__2::voice * get200Algo2(){
	static instancealgo__2::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__3::voice * get200Algo3(){
	static instancealgo__3::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__4::voice * get200Algo4(){
	static instancealgo__4::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__5::voice * get200Algo5(){
	static instancealgo__5::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__6::voice * get200Algo6(){
	static instancealgo__6::voice v[8] __attribute__ ((section (".sdram")));
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
int8_t pressed[8]; // 0 means released, 1 pressed, 3 sustain, 2 releasing
  public: void Init(rootc * _parent) {
parent = _parent;
for(int vi=0;vi<8;vi++){
   if( vtype == 1 ) setParamBatch( instancealgo__1::GetInitParams(), instancealgo__1::NPEXCH, &get200Algo1()[vi].PExch[0] );
   else if( vtype == 2 ) setParamBatch( instancealgo__2::GetInitParams(), instancealgo__2::NPEXCH, &get200Algo2()[vi].PExch[0] );
   else if( vtype == 3 ) setParamBatch( instancealgo__3::GetInitParams(), instancealgo__3::NPEXCH, &get200Algo3()[vi].PExch[0] );
   else if( vtype == 4 ) setParamBatch( instancealgo__4::GetInitParams(), instancealgo__4::NPEXCH, &get200Algo4()[vi].PExch[0] );
   else if( vtype == 5 ) setParamBatch( instancealgo__5::GetInitParams(), instancealgo__5::NPEXCH, &get200Algo5()[vi].PExch[0] );
   else if( vtype == 6 ) setParamBatch( instancealgo__6::GetInitParams(), instancealgo__6::NPEXCH, &get200Algo6()[vi].PExch[0] );
}

int vi; for(vi=0;vi<8;vi++) {
   voice *v = &getVoices()[vi];
   v->polyIndex = vi;
   v->common = this;
   v->Init(&getVoices()[vi]); 
   notePlaying[vi]=0;
   voicePriority[vi]=0;

   rampEnv[vi] = 0; // range 0..1<<27
}

priority=0;
sustain=0;
etype=0;
}
  public: void Dispose() {
int vi; for(vi=0;vi<8;vi++) {
  voice *v = &getVoices()[vi];
  v->dispose();
}
}
  public: void dsp (int32buffer  & outlet_outlet__1,
int param_vtype,
int param_etype  ){
etype = param_etype; // etype 'envelope type' (0 off, 1 down, 2 up+down)

bool reset = ( param_vtype != vtype ); // reset when vtype changes
if( reset ){  
 Dispose(); 
 vtype = param_vtype; 
 Init(parent); 
} 

int j; for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] = 0;

int vi; for(vi=0;vi<8;vi++) {
	
	if( pressed[vi]==0 ) continue; // 0 means released, 1 pressed, 3 sustain, 2 releasing

	// our vtype determines algo dsp
	if( vtype == 1 ){
	  get200Algo1()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo1()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 2 ){
	  get200Algo2()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo2()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 3 ){
	  get200Algo3()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo3()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 4 ){
	  get200Algo4()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo4()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 5 ){
	  get200Algo5()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo5()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 6 ){
	  get200Algo6()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo6()[vi].instanceoutlet__1_i._outlet[j]; 
	}

	// mix voiceBuf to our outlet (and apply envelope if enabled )
	for(j=0;j<BUFSIZE;j++) {
	  outlet_outlet__1[j] += ___SMMUL( voiceBuf[j], rampEnv[vi] )<<5;

	  if( etype==2 && pressed[vi] == 1 ){          // 1 means pressed
	    if( rampEnv[vi] > 1<<27 ) pressed[vi] = 3; // 3 means sustain
	    else rampEnv[vi] = rampEnv[vi]+(1<<20);    // rapid fade up
	  }

	  if( etype>=1 && pressed[vi] == 2 ){          // 2 means releasing
	    if( rampEnv[vi] < 1 ) pressed[vi] = 0;     // 0 means released
	    else rampEnv[vi] = rampEnv[vi]-(1<<17);    // rapid fade down
	  }
	}
}
}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
static int MAX_VTYPE = 6; // 0=silent

if ( 0 > 0 && dev > 0 && 0 != dev) return;
if ( 0 > 0 && port > 0 && 0 != port) return;

if( status == MIDI_PROGRAM_CHANGE + 7 && (data1<127) ){ // pgm sets 'vtype'
  uint8_t PExVal = (data1 <= MAX_VTYPE) ? data1 : 0; // 0=silent when out of range
  int     PExIdx = rootc::PARAM_INDEX_patcher__1_vtype + (2*(7-6)); // KLUDGE
  PExParameterChange( &parent->PExch[ PExIdx ], PExVal, 0xFFEF);

} else if( status == MIDI_PROGRAM_CHANGE + 7 && (data1==127) ){ // request statedump
  uint8_t txChan = 7;

  if( vtype == 0 ){ instanceccMGR::txState( 0, nullptr, txChan ); }
  else if( vtype == 1 ){ instanceccMGR::txState( 1, &get200Algo1()[0].PExch[0], txChan ); }
  else if( vtype == 2 ){ instanceccMGR::txState( 2, &get200Algo2()[0].PExch[0], txChan ); }
  else if( vtype == 3 ){ instanceccMGR::txState( 3, &get200Algo3()[0].PExch[0], txChan ); }
  else if( vtype == 4 ){ instanceccMGR::txState( 4, &get200Algo4()[0].PExch[0], txChan ); }
  else if( vtype == 5 ){ instanceccMGR::txState( 5, &get200Algo5()[0].PExch[0], txChan ); }
  else if( vtype == 6 ){ instanceccMGR::txState( 6, &get200Algo5()[0].PExch[0], txChan ); }

  // KLUDGE report cc72 release time 'etype' state
  int PExIdx   = rootc::PARAM_INDEX_patcher__1_etype + (2*(7-6)); // KLUDGE
  int txDat2   = patchMeta.pPExch[ PExIdx ].modvalue * 46;  // range 0..2 maps to 0..127
  int txCCdat1 = 72;
  MidiSend3((midi_device_t) MIDI_DEVICE_DIN, 1, txChan + MIDI_CONTROL_CHANGE, txCCdat1&0x7F, txDat2&0x7F);

} else if ((status == MIDI_NOTE_ON + 7) && (data2)) {
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
  pressed[mini] = 1; // 2 means releasing, 1 means pressed, 0 means released

  if( etype==2 ) rampEnv[mini] = 0; // etype 0 off, 1 down, 2 up+down
  else rampEnv[mini] = 1<<27;       // rampEnv range 0..1<<27

  if( vtype == 1 ) get200Algo1()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 2 ) get200Algo2()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 3 ) get200Algo3()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 4 ) get200Algo4()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 5 ) get200Algo5()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 6 ) get200Algo6()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  
  
} else if (((status == MIDI_NOTE_ON + 7) && (!data2))||
          (status == MIDI_NOTE_OFF + 7)) {
          	
  // check MIDI_NOTE_OFF or MIDI_NOTE_ON with zero velo - do not passthru to voices
  int i; for(i=0;i<8;i++){
    if ((notePlaying[i] == data1) && pressed[i]){
      voicePriority[i] = priority++;
      pressed[i] = 2; // 2 means releasing, 1 means pressed, 0 means released

      if( etype==0 ) pressed[i] = 0;
    }
  }
} else if (status == 7 + MIDI_CONTROL_CHANGE) {
  int i; for(i=0;i<8;i++) getVoices()[i].receiveCC(dev, port, status, data1, data2);

  if( data1==72 ) {              // cc72 release time sets 'etype'
    uint8_t PExVal = data2 / 46; // range 0..127 maps to 0..2 
    int     PExIdx = rootc::PARAM_INDEX_patcher__1_etype + (2*(7-6));  // KLUDGE
    PExParameterChange( &parent->PExch[ PExIdx ], PExVal, 0xFFEF);
  }
}}
}
}
;class instancepatcher__3{
  public: // v1
  rootc *parent;


int32buffer voiceBuf;        // we render here (enveloped) mixed at our outlet

int      etype;              // etype 'envelope type' (0 off, 1 down, 2 up+down)
uint32_t rampEnv[8];         // range 0..1<<26

int32_t vtype = 0;           // vtype 'voice type' chosen sound generation algorithm 
class voice {
   public:
   int polyIndex;
      
instancepatcher__3 *common;
void Init(voice *parent) {
	if( common->vtype == 1 )
	{
      instancealgo__1::voice* av = &common->get200Algo1()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 2 )
	{
      instancealgo__2::voice* av = &common->get200Algo2()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 3 )
	{
      instancealgo__3::voice* av = &common->get200Algo3()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 4 )
	{
      instancealgo__4::voice* av = &common->get200Algo4()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 5 )
	{
      instancealgo__5::voice* av = &common->get200Algo5()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 6 )
	{
      instancealgo__6::voice* av = &common->get200Algo6()[polyIndex];
      av->Init( av );
	}
}
void dsp(void) { }
void dispose(void) {
   if( common->vtype == 1 ) common->get200Algo1()[polyIndex].dispose();
   else if( common->vtype == 2 ) common->get200Algo2()[polyIndex].dispose();
   else if( common->vtype == 3 ) common->get200Algo3()[polyIndex].dispose();
   else if( common->vtype == 4 ) common->get200Algo4()[polyIndex].dispose();
   else if( common->vtype == 5 ) common->get200Algo5()[polyIndex].dispose();
   else if( common->vtype == 6 ) common->get200Algo6()[polyIndex].dispose();
}
void receiveCC(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2) {
  // passthru cc to voice
  if( common->vtype == 1 ) common->get200Algo1()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 2 ) common->get200Algo2()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 3 ) common->get200Algo3()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 4 ) common->get200Algo4()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 5 ) common->get200Algo5()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 6 ) common->get200Algo6()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);

  // ccMGR paramexchange
  if( common->vtype == 1 ) instanceccMGR::setPEx( 1, &common->get200Algo1()[polyIndex], data1, data2 );
  else if( common->vtype == 2 ) instanceccMGR::setPEx( 2, &common->get200Algo2()[polyIndex], data1, data2 );
  else if( common->vtype == 3 ) instanceccMGR::setPEx( 3, &common->get200Algo3()[polyIndex], data1, data2 );
  else if( common->vtype == 4 ) instanceccMGR::setPEx( 4, &common->get200Algo4()[polyIndex], data1, data2 );
  else if( common->vtype == 5 ) instanceccMGR::setPEx( 5, &common->get200Algo5()[polyIndex], data1, data2 );
  else if( common->vtype == 6 ) instanceccMGR::setPEx( 6, &common->get200Algo6()[polyIndex], data1, data2 );
}

};

static voice * getVoices(void){
    static voice v[8];
    return v;
}

static instancealgo__1::voice * get200Algo1(){
	static instancealgo__1::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__2::voice * get200Algo2(){
	static instancealgo__2::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__3::voice * get200Algo3(){
	static instancealgo__3::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__4::voice * get200Algo4(){
	static instancealgo__4::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__5::voice * get200Algo5(){
	static instancealgo__5::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__6::voice * get200Algo6(){
	static instancealgo__6::voice v[8] __attribute__ ((section (".sdram")));
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
int8_t pressed[8]; // 0 means released, 1 pressed, 3 sustain, 2 releasing
  public: void Init(rootc * _parent) {
parent = _parent;
for(int vi=0;vi<8;vi++){
   if( vtype == 1 ) setParamBatch( instancealgo__1::GetInitParams(), instancealgo__1::NPEXCH, &get200Algo1()[vi].PExch[0] );
   else if( vtype == 2 ) setParamBatch( instancealgo__2::GetInitParams(), instancealgo__2::NPEXCH, &get200Algo2()[vi].PExch[0] );
   else if( vtype == 3 ) setParamBatch( instancealgo__3::GetInitParams(), instancealgo__3::NPEXCH, &get200Algo3()[vi].PExch[0] );
   else if( vtype == 4 ) setParamBatch( instancealgo__4::GetInitParams(), instancealgo__4::NPEXCH, &get200Algo4()[vi].PExch[0] );
   else if( vtype == 5 ) setParamBatch( instancealgo__5::GetInitParams(), instancealgo__5::NPEXCH, &get200Algo5()[vi].PExch[0] );
   else if( vtype == 6 ) setParamBatch( instancealgo__6::GetInitParams(), instancealgo__6::NPEXCH, &get200Algo6()[vi].PExch[0] );
}

int vi; for(vi=0;vi<8;vi++) {
   voice *v = &getVoices()[vi];
   v->polyIndex = vi;
   v->common = this;
   v->Init(&getVoices()[vi]); 
   notePlaying[vi]=0;
   voicePriority[vi]=0;

   rampEnv[vi] = 0; // range 0..1<<27
}

priority=0;
sustain=0;
etype=0;
}
  public: void Dispose() {
int vi; for(vi=0;vi<8;vi++) {
  voice *v = &getVoices()[vi];
  v->dispose();
}
}
  public: void dsp (int32buffer  & outlet_outlet__1,
int param_vtype,
int param_etype  ){
etype = param_etype; // etype 'envelope type' (0 off, 1 down, 2 up+down)

bool reset = ( param_vtype != vtype ); // reset when vtype changes
if( reset ){  
 Dispose(); 
 vtype = param_vtype; 
 Init(parent); 
} 

int j; for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] = 0;

int vi; for(vi=0;vi<8;vi++) {
	
	if( pressed[vi]==0 ) continue; // 0 means released, 1 pressed, 3 sustain, 2 releasing

	// our vtype determines algo dsp
	if( vtype == 1 ){
	  get200Algo1()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo1()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 2 ){
	  get200Algo2()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo2()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 3 ){
	  get200Algo3()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo3()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 4 ){
	  get200Algo4()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo4()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 5 ){
	  get200Algo5()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo5()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 6 ){
	  get200Algo6()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo6()[vi].instanceoutlet__1_i._outlet[j]; 
	}

	// mix voiceBuf to our outlet (and apply envelope if enabled )
	for(j=0;j<BUFSIZE;j++) {
	  outlet_outlet__1[j] += ___SMMUL( voiceBuf[j], rampEnv[vi] )<<5;

	  if( etype==2 && pressed[vi] == 1 ){          // 1 means pressed
	    if( rampEnv[vi] > 1<<27 ) pressed[vi] = 3; // 3 means sustain
	    else rampEnv[vi] = rampEnv[vi]+(1<<20);    // rapid fade up
	  }

	  if( etype>=1 && pressed[vi] == 2 ){          // 2 means releasing
	    if( rampEnv[vi] < 1 ) pressed[vi] = 0;     // 0 means released
	    else rampEnv[vi] = rampEnv[vi]-(1<<17);    // rapid fade down
	  }
	}
}
}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
static int MAX_VTYPE = 6; // 0=silent

if ( 0 > 0 && dev > 0 && 0 != dev) return;
if ( 0 > 0 && port > 0 && 0 != port) return;

if( status == MIDI_PROGRAM_CHANGE + 8 && (data1<127) ){ // pgm sets 'vtype'
  uint8_t PExVal = (data1 <= MAX_VTYPE) ? data1 : 0; // 0=silent when out of range
  int     PExIdx = rootc::PARAM_INDEX_patcher__1_vtype + (2*(8-6)); // KLUDGE
  PExParameterChange( &parent->PExch[ PExIdx ], PExVal, 0xFFEF);

} else if( status == MIDI_PROGRAM_CHANGE + 8 && (data1==127) ){ // request statedump
  uint8_t txChan = 8;

  if( vtype == 0 ){ instanceccMGR::txState( 0, nullptr, txChan ); }
  else if( vtype == 1 ){ instanceccMGR::txState( 1, &get200Algo1()[0].PExch[0], txChan ); }
  else if( vtype == 2 ){ instanceccMGR::txState( 2, &get200Algo2()[0].PExch[0], txChan ); }
  else if( vtype == 3 ){ instanceccMGR::txState( 3, &get200Algo3()[0].PExch[0], txChan ); }
  else if( vtype == 4 ){ instanceccMGR::txState( 4, &get200Algo4()[0].PExch[0], txChan ); }
  else if( vtype == 5 ){ instanceccMGR::txState( 5, &get200Algo5()[0].PExch[0], txChan ); }
  else if( vtype == 6 ){ instanceccMGR::txState( 6, &get200Algo5()[0].PExch[0], txChan ); }

  // KLUDGE report cc72 release time 'etype' state
  int PExIdx   = rootc::PARAM_INDEX_patcher__1_etype + (2*(8-6)); // KLUDGE
  int txDat2   = patchMeta.pPExch[ PExIdx ].modvalue * 46;  // range 0..2 maps to 0..127
  int txCCdat1 = 72;
  MidiSend3((midi_device_t) MIDI_DEVICE_DIN, 1, txChan + MIDI_CONTROL_CHANGE, txCCdat1&0x7F, txDat2&0x7F);

} else if ((status == MIDI_NOTE_ON + 8) && (data2)) {
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
  pressed[mini] = 1; // 2 means releasing, 1 means pressed, 0 means released

  if( etype==2 ) rampEnv[mini] = 0; // etype 0 off, 1 down, 2 up+down
  else rampEnv[mini] = 1<<27;       // rampEnv range 0..1<<27

  if( vtype == 1 ) get200Algo1()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 2 ) get200Algo2()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 3 ) get200Algo3()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 4 ) get200Algo4()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 5 ) get200Algo5()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 6 ) get200Algo6()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  
  
} else if (((status == MIDI_NOTE_ON + 8) && (!data2))||
          (status == MIDI_NOTE_OFF + 8)) {
          	
  // check MIDI_NOTE_OFF or MIDI_NOTE_ON with zero velo - do not passthru to voices
  int i; for(i=0;i<8;i++){
    if ((notePlaying[i] == data1) && pressed[i]){
      voicePriority[i] = priority++;
      pressed[i] = 2; // 2 means releasing, 1 means pressed, 0 means released

      if( etype==0 ) pressed[i] = 0;
    }
  }
} else if (status == 8 + MIDI_CONTROL_CHANGE) {
  int i; for(i=0;i<8;i++) getVoices()[i].receiveCC(dev, port, status, data1, data2);

  if( data1==72 ) {              // cc72 release time sets 'etype'
    uint8_t PExVal = data2 / 46; // range 0..127 maps to 0..2 
    int     PExIdx = rootc::PARAM_INDEX_patcher__1_etype + (2*(8-6));  // KLUDGE
    PExParameterChange( &parent->PExch[ PExIdx ], PExVal, 0xFFEF);
  }
}}
}
}
;class instancepatcher__4{
  public: // v1
  rootc *parent;


int32buffer voiceBuf;        // we render here (enveloped) mixed at our outlet

int      etype;              // etype 'envelope type' (0 off, 1 down, 2 up+down)
uint32_t rampEnv[8];         // range 0..1<<26

int32_t vtype = 0;           // vtype 'voice type' chosen sound generation algorithm 
class voice {
   public:
   int polyIndex;
      
instancepatcher__4 *common;
void Init(voice *parent) {
	if( common->vtype == 1 )
	{
      instancealgo__1::voice* av = &common->get200Algo1()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 2 )
	{
      instancealgo__2::voice* av = &common->get200Algo2()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 3 )
	{
      instancealgo__3::voice* av = &common->get200Algo3()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 4 )
	{
      instancealgo__4::voice* av = &common->get200Algo4()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 5 )
	{
      instancealgo__5::voice* av = &common->get200Algo5()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 6 )
	{
      instancealgo__6::voice* av = &common->get200Algo6()[polyIndex];
      av->Init( av );
	}
}
void dsp(void) { }
void dispose(void) {
   if( common->vtype == 1 ) common->get200Algo1()[polyIndex].dispose();
   else if( common->vtype == 2 ) common->get200Algo2()[polyIndex].dispose();
   else if( common->vtype == 3 ) common->get200Algo3()[polyIndex].dispose();
   else if( common->vtype == 4 ) common->get200Algo4()[polyIndex].dispose();
   else if( common->vtype == 5 ) common->get200Algo5()[polyIndex].dispose();
   else if( common->vtype == 6 ) common->get200Algo6()[polyIndex].dispose();
}
void receiveCC(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2) {
  // passthru cc to voice
  if( common->vtype == 1 ) common->get200Algo1()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 2 ) common->get200Algo2()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 3 ) common->get200Algo3()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 4 ) common->get200Algo4()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 5 ) common->get200Algo5()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 6 ) common->get200Algo6()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);

  // ccMGR paramexchange
  if( common->vtype == 1 ) instanceccMGR::setPEx( 1, &common->get200Algo1()[polyIndex], data1, data2 );
  else if( common->vtype == 2 ) instanceccMGR::setPEx( 2, &common->get200Algo2()[polyIndex], data1, data2 );
  else if( common->vtype == 3 ) instanceccMGR::setPEx( 3, &common->get200Algo3()[polyIndex], data1, data2 );
  else if( common->vtype == 4 ) instanceccMGR::setPEx( 4, &common->get200Algo4()[polyIndex], data1, data2 );
  else if( common->vtype == 5 ) instanceccMGR::setPEx( 5, &common->get200Algo5()[polyIndex], data1, data2 );
  else if( common->vtype == 6 ) instanceccMGR::setPEx( 6, &common->get200Algo6()[polyIndex], data1, data2 );
}

};

static voice * getVoices(void){
    static voice v[8];
    return v;
}

static instancealgo__1::voice * get200Algo1(){
	static instancealgo__1::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__2::voice * get200Algo2(){
	static instancealgo__2::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__3::voice * get200Algo3(){
	static instancealgo__3::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__4::voice * get200Algo4(){
	static instancealgo__4::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__5::voice * get200Algo5(){
	static instancealgo__5::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__6::voice * get200Algo6(){
	static instancealgo__6::voice v[8] __attribute__ ((section (".sdram")));
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
int8_t pressed[8]; // 0 means released, 1 pressed, 3 sustain, 2 releasing
  public: void Init(rootc * _parent) {
parent = _parent;
for(int vi=0;vi<8;vi++){
   if( vtype == 1 ) setParamBatch( instancealgo__1::GetInitParams(), instancealgo__1::NPEXCH, &get200Algo1()[vi].PExch[0] );
   else if( vtype == 2 ) setParamBatch( instancealgo__2::GetInitParams(), instancealgo__2::NPEXCH, &get200Algo2()[vi].PExch[0] );
   else if( vtype == 3 ) setParamBatch( instancealgo__3::GetInitParams(), instancealgo__3::NPEXCH, &get200Algo3()[vi].PExch[0] );
   else if( vtype == 4 ) setParamBatch( instancealgo__4::GetInitParams(), instancealgo__4::NPEXCH, &get200Algo4()[vi].PExch[0] );
   else if( vtype == 5 ) setParamBatch( instancealgo__5::GetInitParams(), instancealgo__5::NPEXCH, &get200Algo5()[vi].PExch[0] );
   else if( vtype == 6 ) setParamBatch( instancealgo__6::GetInitParams(), instancealgo__6::NPEXCH, &get200Algo6()[vi].PExch[0] );
}

int vi; for(vi=0;vi<8;vi++) {
   voice *v = &getVoices()[vi];
   v->polyIndex = vi;
   v->common = this;
   v->Init(&getVoices()[vi]); 
   notePlaying[vi]=0;
   voicePriority[vi]=0;

   rampEnv[vi] = 0; // range 0..1<<27
}

priority=0;
sustain=0;
etype=0;
}
  public: void Dispose() {
int vi; for(vi=0;vi<8;vi++) {
  voice *v = &getVoices()[vi];
  v->dispose();
}
}
  public: void dsp (int32buffer  & outlet_outlet__1,
int param_vtype,
int param_etype  ){
etype = param_etype; // etype 'envelope type' (0 off, 1 down, 2 up+down)

bool reset = ( param_vtype != vtype ); // reset when vtype changes
if( reset ){  
 Dispose(); 
 vtype = param_vtype; 
 Init(parent); 
} 

int j; for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] = 0;

int vi; for(vi=0;vi<8;vi++) {
	
	if( pressed[vi]==0 ) continue; // 0 means released, 1 pressed, 3 sustain, 2 releasing

	// our vtype determines algo dsp
	if( vtype == 1 ){
	  get200Algo1()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo1()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 2 ){
	  get200Algo2()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo2()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 3 ){
	  get200Algo3()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo3()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 4 ){
	  get200Algo4()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo4()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 5 ){
	  get200Algo5()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo5()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 6 ){
	  get200Algo6()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo6()[vi].instanceoutlet__1_i._outlet[j]; 
	}

	// mix voiceBuf to our outlet (and apply envelope if enabled )
	for(j=0;j<BUFSIZE;j++) {
	  outlet_outlet__1[j] += ___SMMUL( voiceBuf[j], rampEnv[vi] )<<5;

	  if( etype==2 && pressed[vi] == 1 ){          // 1 means pressed
	    if( rampEnv[vi] > 1<<27 ) pressed[vi] = 3; // 3 means sustain
	    else rampEnv[vi] = rampEnv[vi]+(1<<20);    // rapid fade up
	  }

	  if( etype>=1 && pressed[vi] == 2 ){          // 2 means releasing
	    if( rampEnv[vi] < 1 ) pressed[vi] = 0;     // 0 means released
	    else rampEnv[vi] = rampEnv[vi]-(1<<17);    // rapid fade down
	  }
	}
}
}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
static int MAX_VTYPE = 6; // 0=silent

if ( 0 > 0 && dev > 0 && 0 != dev) return;
if ( 0 > 0 && port > 0 && 0 != port) return;

if( status == MIDI_PROGRAM_CHANGE + 11 && (data1<127) ){ // pgm sets 'vtype'
  uint8_t PExVal = (data1 <= MAX_VTYPE) ? data1 : 0; // 0=silent when out of range
  int     PExIdx = rootc::PARAM_INDEX_patcher__1_vtype + (2*(11-8)); // KLUDGE
  PExParameterChange( &parent->PExch[ PExIdx ], PExVal, 0xFFEF);

} else if( status == MIDI_PROGRAM_CHANGE + 11 && (data1==127) ){ // request statedump
  uint8_t txChan = 11;

  if( vtype == 0 ){ instanceccMGR::txState( 0, nullptr, txChan ); }
  else if( vtype == 1 ){ instanceccMGR::txState( 1, &get200Algo1()[0].PExch[0], txChan ); }
  else if( vtype == 2 ){ instanceccMGR::txState( 2, &get200Algo2()[0].PExch[0], txChan ); }
  else if( vtype == 3 ){ instanceccMGR::txState( 3, &get200Algo3()[0].PExch[0], txChan ); }
  else if( vtype == 4 ){ instanceccMGR::txState( 4, &get200Algo4()[0].PExch[0], txChan ); }
  else if( vtype == 5 ){ instanceccMGR::txState( 5, &get200Algo5()[0].PExch[0], txChan ); }
  else if( vtype == 6 ){ instanceccMGR::txState( 6, &get200Algo5()[0].PExch[0], txChan ); }

  // KLUDGE report cc72 release time 'etype' state
  int PExIdx   = rootc::PARAM_INDEX_patcher__1_etype + (2*(11-8)); // KLUDGE
  int txDat2   = patchMeta.pPExch[ PExIdx ].modvalue * 46;  // range 0..2 maps to 0..127
  int txCCdat1 = 72;
  MidiSend3((midi_device_t) MIDI_DEVICE_DIN, 1, txChan + MIDI_CONTROL_CHANGE, txCCdat1&0x7F, txDat2&0x7F);

} else if ((status == MIDI_NOTE_ON + 11) && (data2)) {
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
  pressed[mini] = 1; // 2 means releasing, 1 means pressed, 0 means released

  if( etype==2 ) rampEnv[mini] = 0; // etype 0 off, 1 down, 2 up+down
  else rampEnv[mini] = 1<<27;       // rampEnv range 0..1<<27

  if( vtype == 1 ) get200Algo1()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 2 ) get200Algo2()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 3 ) get200Algo3()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 4 ) get200Algo4()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 5 ) get200Algo5()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 6 ) get200Algo6()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  
  
} else if (((status == MIDI_NOTE_ON + 11) && (!data2))||
          (status == MIDI_NOTE_OFF + 11)) {
          	
  // check MIDI_NOTE_OFF or MIDI_NOTE_ON with zero velo - do not passthru to voices
  int i; for(i=0;i<8;i++){
    if ((notePlaying[i] == data1) && pressed[i]){
      voicePriority[i] = priority++;
      pressed[i] = 2; // 2 means releasing, 1 means pressed, 0 means released

      if( etype==0 ) pressed[i] = 0;
    }
  }
} else if (status == 11 + MIDI_CONTROL_CHANGE) {
  int i; for(i=0;i<8;i++) getVoices()[i].receiveCC(dev, port, status, data1, data2);

  if( data1==72 ) {              // cc72 release time sets 'etype'
    uint8_t PExVal = data2 / 46; // range 0..127 maps to 0..2 
    int     PExIdx = rootc::PARAM_INDEX_patcher__1_etype + (2*(11-8));  // KLUDGE
    PExParameterChange( &parent->PExch[ PExIdx ], PExVal, 0xFFEF);
  }
}}
}
}
;class instancepatcher__5{
  public: // v1
  rootc *parent;


int32buffer voiceBuf;        // we render here (enveloped) mixed at our outlet

int      etype;              // etype 'envelope type' (0 off, 1 down, 2 up+down)
uint32_t rampEnv[8];         // range 0..1<<26

int32_t vtype = 0;           // vtype 'voice type' chosen sound generation algorithm 
class voice {
   public:
   int polyIndex;
      
instancepatcher__5 *common;
void Init(voice *parent) {
	if( common->vtype == 1 )
	{
      instancealgo__1::voice* av = &common->get200Algo1()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 2 )
	{
      instancealgo__2::voice* av = &common->get200Algo2()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 3 )
	{
      instancealgo__3::voice* av = &common->get200Algo3()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 4 )
	{
      instancealgo__4::voice* av = &common->get200Algo4()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 5 )
	{
      instancealgo__5::voice* av = &common->get200Algo5()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 6 )
	{
      instancealgo__6::voice* av = &common->get200Algo6()[polyIndex];
      av->Init( av );
	}
}
void dsp(void) { }
void dispose(void) {
   if( common->vtype == 1 ) common->get200Algo1()[polyIndex].dispose();
   else if( common->vtype == 2 ) common->get200Algo2()[polyIndex].dispose();
   else if( common->vtype == 3 ) common->get200Algo3()[polyIndex].dispose();
   else if( common->vtype == 4 ) common->get200Algo4()[polyIndex].dispose();
   else if( common->vtype == 5 ) common->get200Algo5()[polyIndex].dispose();
   else if( common->vtype == 6 ) common->get200Algo6()[polyIndex].dispose();
}
void receiveCC(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2) {
  // passthru cc to voice
  if( common->vtype == 1 ) common->get200Algo1()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 2 ) common->get200Algo2()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 3 ) common->get200Algo3()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 4 ) common->get200Algo4()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 5 ) common->get200Algo5()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 6 ) common->get200Algo6()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);

  // ccMGR paramexchange
  if( common->vtype == 1 ) instanceccMGR::setPEx( 1, &common->get200Algo1()[polyIndex], data1, data2 );
  else if( common->vtype == 2 ) instanceccMGR::setPEx( 2, &common->get200Algo2()[polyIndex], data1, data2 );
  else if( common->vtype == 3 ) instanceccMGR::setPEx( 3, &common->get200Algo3()[polyIndex], data1, data2 );
  else if( common->vtype == 4 ) instanceccMGR::setPEx( 4, &common->get200Algo4()[polyIndex], data1, data2 );
  else if( common->vtype == 5 ) instanceccMGR::setPEx( 5, &common->get200Algo5()[polyIndex], data1, data2 );
  else if( common->vtype == 6 ) instanceccMGR::setPEx( 6, &common->get200Algo6()[polyIndex], data1, data2 );
}

};

static voice * getVoices(void){
    static voice v[8];
    return v;
}

static instancealgo__1::voice * get200Algo1(){
	static instancealgo__1::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__2::voice * get200Algo2(){
	static instancealgo__2::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__3::voice * get200Algo3(){
	static instancealgo__3::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__4::voice * get200Algo4(){
	static instancealgo__4::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__5::voice * get200Algo5(){
	static instancealgo__5::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__6::voice * get200Algo6(){
	static instancealgo__6::voice v[8] __attribute__ ((section (".sdram")));
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
int8_t pressed[8]; // 0 means released, 1 pressed, 3 sustain, 2 releasing
  public: void Init(rootc * _parent) {
parent = _parent;
for(int vi=0;vi<8;vi++){
   if( vtype == 1 ) setParamBatch( instancealgo__1::GetInitParams(), instancealgo__1::NPEXCH, &get200Algo1()[vi].PExch[0] );
   else if( vtype == 2 ) setParamBatch( instancealgo__2::GetInitParams(), instancealgo__2::NPEXCH, &get200Algo2()[vi].PExch[0] );
   else if( vtype == 3 ) setParamBatch( instancealgo__3::GetInitParams(), instancealgo__3::NPEXCH, &get200Algo3()[vi].PExch[0] );
   else if( vtype == 4 ) setParamBatch( instancealgo__4::GetInitParams(), instancealgo__4::NPEXCH, &get200Algo4()[vi].PExch[0] );
   else if( vtype == 5 ) setParamBatch( instancealgo__5::GetInitParams(), instancealgo__5::NPEXCH, &get200Algo5()[vi].PExch[0] );
   else if( vtype == 6 ) setParamBatch( instancealgo__6::GetInitParams(), instancealgo__6::NPEXCH, &get200Algo6()[vi].PExch[0] );
}

int vi; for(vi=0;vi<8;vi++) {
   voice *v = &getVoices()[vi];
   v->polyIndex = vi;
   v->common = this;
   v->Init(&getVoices()[vi]); 
   notePlaying[vi]=0;
   voicePriority[vi]=0;

   rampEnv[vi] = 0; // range 0..1<<27
}

priority=0;
sustain=0;
etype=0;
}
  public: void Dispose() {
int vi; for(vi=0;vi<8;vi++) {
  voice *v = &getVoices()[vi];
  v->dispose();
}
}
  public: void dsp (int32buffer  & outlet_outlet__1,
int param_vtype,
int param_etype  ){
etype = param_etype; // etype 'envelope type' (0 off, 1 down, 2 up+down)

bool reset = ( param_vtype != vtype ); // reset when vtype changes
if( reset ){  
 Dispose(); 
 vtype = param_vtype; 
 Init(parent); 
} 

int j; for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] = 0;

int vi; for(vi=0;vi<8;vi++) {
	
	if( pressed[vi]==0 ) continue; // 0 means released, 1 pressed, 3 sustain, 2 releasing

	// our vtype determines algo dsp
	if( vtype == 1 ){
	  get200Algo1()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo1()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 2 ){
	  get200Algo2()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo2()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 3 ){
	  get200Algo3()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo3()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 4 ){
	  get200Algo4()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo4()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 5 ){
	  get200Algo5()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo5()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 6 ){
	  get200Algo6()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo6()[vi].instanceoutlet__1_i._outlet[j]; 
	}

	// mix voiceBuf to our outlet (and apply envelope if enabled )
	for(j=0;j<BUFSIZE;j++) {
	  outlet_outlet__1[j] += ___SMMUL( voiceBuf[j], rampEnv[vi] )<<5;

	  if( etype==2 && pressed[vi] == 1 ){          // 1 means pressed
	    if( rampEnv[vi] > 1<<27 ) pressed[vi] = 3; // 3 means sustain
	    else rampEnv[vi] = rampEnv[vi]+(1<<20);    // rapid fade up
	  }

	  if( etype>=1 && pressed[vi] == 2 ){          // 2 means releasing
	    if( rampEnv[vi] < 1 ) pressed[vi] = 0;     // 0 means released
	    else rampEnv[vi] = rampEnv[vi]-(1<<17);    // rapid fade down
	  }
	}
}
}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
static int MAX_VTYPE = 6; // 0=silent

if ( 0 > 0 && dev > 0 && 0 != dev) return;
if ( 0 > 0 && port > 0 && 0 != port) return;

if( status == MIDI_PROGRAM_CHANGE + 12 && (data1<127) ){ // pgm sets 'vtype'
  uint8_t PExVal = (data1 <= MAX_VTYPE) ? data1 : 0; // 0=silent when out of range
  int     PExIdx = rootc::PARAM_INDEX_patcher__1_vtype + (2*(12-8)); // KLUDGE
  PExParameterChange( &parent->PExch[ PExIdx ], PExVal, 0xFFEF);

} else if( status == MIDI_PROGRAM_CHANGE + 12 && (data1==127) ){ // request statedump
  uint8_t txChan = 12;

  if( vtype == 0 ){ instanceccMGR::txState( 0, nullptr, txChan ); }
  else if( vtype == 1 ){ instanceccMGR::txState( 1, &get200Algo1()[0].PExch[0], txChan ); }
  else if( vtype == 2 ){ instanceccMGR::txState( 2, &get200Algo2()[0].PExch[0], txChan ); }
  else if( vtype == 3 ){ instanceccMGR::txState( 3, &get200Algo3()[0].PExch[0], txChan ); }
  else if( vtype == 4 ){ instanceccMGR::txState( 4, &get200Algo4()[0].PExch[0], txChan ); }
  else if( vtype == 5 ){ instanceccMGR::txState( 5, &get200Algo5()[0].PExch[0], txChan ); }
  else if( vtype == 6 ){ instanceccMGR::txState( 6, &get200Algo5()[0].PExch[0], txChan ); }

  // KLUDGE report cc72 release time 'etype' state
  int PExIdx   = rootc::PARAM_INDEX_patcher__1_etype + (2*(12-8)); // KLUDGE
  int txDat2   = patchMeta.pPExch[ PExIdx ].modvalue * 46;  // range 0..2 maps to 0..127
  int txCCdat1 = 72;
  MidiSend3((midi_device_t) MIDI_DEVICE_DIN, 1, txChan + MIDI_CONTROL_CHANGE, txCCdat1&0x7F, txDat2&0x7F);

} else if ((status == MIDI_NOTE_ON + 12) && (data2)) {
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
  pressed[mini] = 1; // 2 means releasing, 1 means pressed, 0 means released

  if( etype==2 ) rampEnv[mini] = 0; // etype 0 off, 1 down, 2 up+down
  else rampEnv[mini] = 1<<27;       // rampEnv range 0..1<<27

  if( vtype == 1 ) get200Algo1()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 2 ) get200Algo2()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 3 ) get200Algo3()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 4 ) get200Algo4()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 5 ) get200Algo5()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 6 ) get200Algo6()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  
  
} else if (((status == MIDI_NOTE_ON + 12) && (!data2))||
          (status == MIDI_NOTE_OFF + 12)) {
          	
  // check MIDI_NOTE_OFF or MIDI_NOTE_ON with zero velo - do not passthru to voices
  int i; for(i=0;i<8;i++){
    if ((notePlaying[i] == data1) && pressed[i]){
      voicePriority[i] = priority++;
      pressed[i] = 2; // 2 means releasing, 1 means pressed, 0 means released

      if( etype==0 ) pressed[i] = 0;
    }
  }
} else if (status == 12 + MIDI_CONTROL_CHANGE) {
  int i; for(i=0;i<8;i++) getVoices()[i].receiveCC(dev, port, status, data1, data2);

  if( data1==72 ) {              // cc72 release time sets 'etype'
    uint8_t PExVal = data2 / 46; // range 0..127 maps to 0..2 
    int     PExIdx = rootc::PARAM_INDEX_patcher__1_etype + (2*(12-8));  // KLUDGE
    PExParameterChange( &parent->PExch[ PExIdx ], PExVal, 0xFFEF);
  }
}}
}
}
;class instancepatcher__6{
  public: // v1
  rootc *parent;


int32buffer voiceBuf;        // we render here (enveloped) mixed at our outlet

int      etype;              // etype 'envelope type' (0 off, 1 down, 2 up+down)
uint32_t rampEnv[8];         // range 0..1<<26

int32_t vtype = 0;           // vtype 'voice type' chosen sound generation algorithm 
class voice {
   public:
   int polyIndex;
      
instancepatcher__6 *common;
void Init(voice *parent) {
	if( common->vtype == 1 )
	{
      instancealgo__1::voice* av = &common->get200Algo1()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 2 )
	{
      instancealgo__2::voice* av = &common->get200Algo2()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 3 )
	{
      instancealgo__3::voice* av = &common->get200Algo3()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 4 )
	{
      instancealgo__4::voice* av = &common->get200Algo4()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 5 )
	{
      instancealgo__5::voice* av = &common->get200Algo5()[polyIndex];
      av->Init( av );
	}
	else if( common->vtype == 6 )
	{
      instancealgo__6::voice* av = &common->get200Algo6()[polyIndex];
      av->Init( av );
	}
}
void dsp(void) { }
void dispose(void) {
   if( common->vtype == 1 ) common->get200Algo1()[polyIndex].dispose();
   else if( common->vtype == 2 ) common->get200Algo2()[polyIndex].dispose();
   else if( common->vtype == 3 ) common->get200Algo3()[polyIndex].dispose();
   else if( common->vtype == 4 ) common->get200Algo4()[polyIndex].dispose();
   else if( common->vtype == 5 ) common->get200Algo5()[polyIndex].dispose();
   else if( common->vtype == 6 ) common->get200Algo6()[polyIndex].dispose();
}
void receiveCC(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2) {
  // passthru cc to voice
  if( common->vtype == 1 ) common->get200Algo1()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 2 ) common->get200Algo2()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 3 ) common->get200Algo3()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 4 ) common->get200Algo4()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 5 ) common->get200Algo5()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( common->vtype == 6 ) common->get200Algo6()[polyIndex].MidiInHandler(dev, port, (status&0xF0), data1, data2);

  // ccMGR paramexchange
  if( common->vtype == 1 ) instanceccMGR::setPEx( 1, &common->get200Algo1()[polyIndex], data1, data2 );
  else if( common->vtype == 2 ) instanceccMGR::setPEx( 2, &common->get200Algo2()[polyIndex], data1, data2 );
  else if( common->vtype == 3 ) instanceccMGR::setPEx( 3, &common->get200Algo3()[polyIndex], data1, data2 );
  else if( common->vtype == 4 ) instanceccMGR::setPEx( 4, &common->get200Algo4()[polyIndex], data1, data2 );
  else if( common->vtype == 5 ) instanceccMGR::setPEx( 5, &common->get200Algo5()[polyIndex], data1, data2 );
  else if( common->vtype == 6 ) instanceccMGR::setPEx( 6, &common->get200Algo6()[polyIndex], data1, data2 );
}

};

static voice * getVoices(void){
    static voice v[8];
    return v;
}

static instancealgo__1::voice * get200Algo1(){
	static instancealgo__1::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__2::voice * get200Algo2(){
	static instancealgo__2::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__3::voice * get200Algo3(){
	static instancealgo__3::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__4::voice * get200Algo4(){
	static instancealgo__4::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__5::voice * get200Algo5(){
	static instancealgo__5::voice v[8] __attribute__ ((section (".sdram")));
	return v;
}
static instancealgo__6::voice * get200Algo6(){
	static instancealgo__6::voice v[8] __attribute__ ((section (".sdram")));
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
int8_t pressed[8]; // 0 means released, 1 pressed, 3 sustain, 2 releasing
  public: void Init(rootc * _parent) {
parent = _parent;
for(int vi=0;vi<8;vi++){
   if( vtype == 1 ) setParamBatch( instancealgo__1::GetInitParams(), instancealgo__1::NPEXCH, &get200Algo1()[vi].PExch[0] );
   else if( vtype == 2 ) setParamBatch( instancealgo__2::GetInitParams(), instancealgo__2::NPEXCH, &get200Algo2()[vi].PExch[0] );
   else if( vtype == 3 ) setParamBatch( instancealgo__3::GetInitParams(), instancealgo__3::NPEXCH, &get200Algo3()[vi].PExch[0] );
   else if( vtype == 4 ) setParamBatch( instancealgo__4::GetInitParams(), instancealgo__4::NPEXCH, &get200Algo4()[vi].PExch[0] );
   else if( vtype == 5 ) setParamBatch( instancealgo__5::GetInitParams(), instancealgo__5::NPEXCH, &get200Algo5()[vi].PExch[0] );
   else if( vtype == 6 ) setParamBatch( instancealgo__6::GetInitParams(), instancealgo__6::NPEXCH, &get200Algo6()[vi].PExch[0] );
}

int vi; for(vi=0;vi<8;vi++) {
   voice *v = &getVoices()[vi];
   v->polyIndex = vi;
   v->common = this;
   v->Init(&getVoices()[vi]); 
   notePlaying[vi]=0;
   voicePriority[vi]=0;

   rampEnv[vi] = 0; // range 0..1<<27
}

priority=0;
sustain=0;
etype=0;
}
  public: void Dispose() {
int vi; for(vi=0;vi<8;vi++) {
  voice *v = &getVoices()[vi];
  v->dispose();
}
}
  public: void dsp (int32buffer  & outlet_outlet__1,
int param_vtype,
int param_etype  ){
etype = param_etype; // etype 'envelope type' (0 off, 1 down, 2 up+down)

bool reset = ( param_vtype != vtype ); // reset when vtype changes
if( reset ){  
 Dispose(); 
 vtype = param_vtype; 
 Init(parent); 
} 

int j; for(j=0;j<BUFSIZE;j++) outlet_outlet__1[j] = 0;

int vi; for(vi=0;vi<8;vi++) {
	
	if( pressed[vi]==0 ) continue; // 0 means released, 1 pressed, 3 sustain, 2 releasing

	// our vtype determines algo dsp
	if( vtype == 1 ){
	  get200Algo1()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo1()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 2 ){
	  get200Algo2()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo2()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 3 ){
	  get200Algo3()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo3()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 4 ){
	  get200Algo4()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo4()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 5 ){
	  get200Algo5()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo5()[vi].instanceoutlet__1_i._outlet[j]; 
	}
	else if( vtype == 6 ){
	  get200Algo6()[vi].dsp(); 
       for(j=0;j<BUFSIZE;j++) voiceBuf[j] = get200Algo6()[vi].instanceoutlet__1_i._outlet[j]; 
	}

	// mix voiceBuf to our outlet (and apply envelope if enabled )
	for(j=0;j<BUFSIZE;j++) {
	  outlet_outlet__1[j] += ___SMMUL( voiceBuf[j], rampEnv[vi] )<<5;

	  if( etype==2 && pressed[vi] == 1 ){          // 1 means pressed
	    if( rampEnv[vi] > 1<<27 ) pressed[vi] = 3; // 3 means sustain
	    else rampEnv[vi] = rampEnv[vi]+(1<<20);    // rapid fade up
	  }

	  if( etype>=1 && pressed[vi] == 2 ){          // 2 means releasing
	    if( rampEnv[vi] < 1 ) pressed[vi] = 0;     // 0 means released
	    else rampEnv[vi] = rampEnv[vi]-(1<<17);    // rapid fade down
	  }
	}
}
}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
static int MAX_VTYPE = 6; // 0=silent

if ( 0 > 0 && dev > 0 && 0 != dev) return;
if ( 0 > 0 && port > 0 && 0 != port) return;

if( status == MIDI_PROGRAM_CHANGE + 13 && (data1<127) ){ // pgm sets 'vtype'
  uint8_t PExVal = (data1 <= MAX_VTYPE) ? data1 : 0; // 0=silent when out of range
  int     PExIdx = rootc::PARAM_INDEX_patcher__1_vtype + (2*(13-8)); // KLUDGE
  PExParameterChange( &parent->PExch[ PExIdx ], PExVal, 0xFFEF);

} else if( status == MIDI_PROGRAM_CHANGE + 13 && (data1==127) ){ // request statedump
  uint8_t txChan = 13;

  if( vtype == 0 ){ instanceccMGR::txState( 0, nullptr, txChan ); }
  else if( vtype == 1 ){ instanceccMGR::txState( 1, &get200Algo1()[0].PExch[0], txChan ); }
  else if( vtype == 2 ){ instanceccMGR::txState( 2, &get200Algo2()[0].PExch[0], txChan ); }
  else if( vtype == 3 ){ instanceccMGR::txState( 3, &get200Algo3()[0].PExch[0], txChan ); }
  else if( vtype == 4 ){ instanceccMGR::txState( 4, &get200Algo4()[0].PExch[0], txChan ); }
  else if( vtype == 5 ){ instanceccMGR::txState( 5, &get200Algo5()[0].PExch[0], txChan ); }
  else if( vtype == 6 ){ instanceccMGR::txState( 6, &get200Algo5()[0].PExch[0], txChan ); }

  // KLUDGE report cc72 release time 'etype' state
  int PExIdx   = rootc::PARAM_INDEX_patcher__1_etype + (2*(13-8)); // KLUDGE
  int txDat2   = patchMeta.pPExch[ PExIdx ].modvalue * 46;  // range 0..2 maps to 0..127
  int txCCdat1 = 72;
  MidiSend3((midi_device_t) MIDI_DEVICE_DIN, 1, txChan + MIDI_CONTROL_CHANGE, txCCdat1&0x7F, txDat2&0x7F);

} else if ((status == MIDI_NOTE_ON + 13) && (data2)) {
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
  pressed[mini] = 1; // 2 means releasing, 1 means pressed, 0 means released

  if( etype==2 ) rampEnv[mini] = 0; // etype 0 off, 1 down, 2 up+down
  else rampEnv[mini] = 1<<27;       // rampEnv range 0..1<<27

  if( vtype == 1 ) get200Algo1()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 2 ) get200Algo2()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 3 ) get200Algo3()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 4 ) get200Algo4()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 5 ) get200Algo5()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  else if( vtype == 6 ) get200Algo6()[mini].MidiInHandler(dev, port, (status&0xF0), data1, data2);
  
  
} else if (((status == MIDI_NOTE_ON + 13) && (!data2))||
          (status == MIDI_NOTE_OFF + 13)) {
          	
  // check MIDI_NOTE_OFF or MIDI_NOTE_ON with zero velo - do not passthru to voices
  int i; for(i=0;i<8;i++){
    if ((notePlaying[i] == data1) && pressed[i]){
      voicePriority[i] = priority++;
      pressed[i] = 2; // 2 means releasing, 1 means pressed, 0 means released

      if( etype==0 ) pressed[i] = 0;
    }
  }
} else if (status == 13 + MIDI_CONTROL_CHANGE) {
  int i; for(i=0;i<8;i++) getVoices()[i].receiveCC(dev, port, status, data1, data2);

  if( data1==72 ) {              // cc72 release time sets 'etype'
    uint8_t PExVal = data2 / 46; // range 0..127 maps to 0..2 
    int     PExIdx = rootc::PARAM_INDEX_patcher__1_etype + (2*(13-8));  // KLUDGE
    PExParameterChange( &parent->PExch[ PExIdx ], PExVal, 0xFFEF);
  }
}}
}
}
;class instancesum8__1{
  public: // v1
  rootc *parent;
uint8_t lmix; // bitmask for left mix
uint8_t rmix; // bitmask for right mix

uint32_t gain_1, gain_2, gain_3, gain_4, gain_5, gain_6, gain_7, gain_8;

// cpu efficiency -vs- storage, we precompute l r gains
uint32_t lgain_1, lgain_2, lgain_3, lgain_4, lgain_5, lgain_6, lgain_7, lgain_8;
uint32_t rgain_1, rgain_2, rgain_3, rgain_4, rgain_5, rgain_6, rgain_7, rgain_8;

inline uint8_t mixBitChan( uint8_t rxChan )
{
  // alter as appropriate for desired behaviour
  // 0b00000001 (1)  for inlet_in1 signal
  // 0b01000000 (64) for inlet_in7 signal
  
  if( rxChan <= 5 )  return 0;   // 0 means invalid
  if( rxChan == 6 )  return 1;   // rxChan6  ch7  0b00000001 inlet_in1
  if( rxChan == 7 )  return 2;   
  if( rxChan == 8 )  return 4;   
  if( rxChan == 11 ) return 8;   // rxChan11 ch12 0b00001000 inlet_in4
  if( rxChan == 12 ) return 16;
  if( rxChan == 13 ) return 32;
  if( rxChan == 9 )  return 64;  // rxChan9  ch10 0b01000000 inlet_in7
  if( rxChan == 10 ) return 128;
  if( rxChan >= 14 ) return 0;   // 0 means invalid
}
  public: void Init(rootc * _parent) {
parent = _parent;
gain_1 = gain_2 = gain_3 = gain_4 = gain_5 = gain_6 = gain_7 = gain_8 = (100<<24); // unity gain

lmix = rmix = 255; // all eight bits set means inputs mix to both l and r outputs

// cpu efficiency -vs- storage, we precompute l r gains
lgain_1 = lgain_2 = lgain_3 = lgain_4 = lgain_5 = lgain_6 = lgain_7 = lgain_8 = 0;
rgain_1 = rgain_2 = rgain_3 = rgain_4 = rgain_5 = rgain_6 = rgain_7 = rgain_8 = 0;
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
int32buffer  & outlet_l,
int32buffer  & outlet_r  ){
// cpu efficiency -vs- storage, we precompute l r gains
lgain_1 = (lmix&1)   ? gain_1 : 0;
lgain_2 = (lmix&2)   ? gain_2 : 0;
lgain_3 = (lmix&4)   ? gain_3 : 0;
lgain_4 = (lmix&8)   ? gain_4 : 0;
lgain_5 = (lmix&16)  ? gain_5 : 0;
lgain_6 = (lmix&32)  ? gain_6 : 0;
lgain_7 = (lmix&64)  ? gain_7 : 0;
lgain_8 = (lmix&128) ? gain_8 : 0;

rgain_1 = (rmix&1)   ? gain_1 : 0;
rgain_2 = (rmix&2)   ? gain_2 : 0;
rgain_3 = (rmix&4)   ? gain_3 : 0;
rgain_4 = (rmix&8)   ? gain_4 : 0;
rgain_5 = (rmix&16)  ? gain_5 : 0;
rgain_6 = (rmix&32)  ? gain_6 : 0;
rgain_7 = (rmix&64)  ? gain_7 : 0;
rgain_8 = (rmix&127) ? gain_8 : 0;
int buffer_index;
for(buffer_index=0;buffer_index<BUFSIZE;buffer_index++) {
// mix signals to either l or r outputs or both
outlet_l[buffer_index] = ___SMMUL(lgain_1,inlet_in1[buffer_index]);
outlet_l[buffer_index] = ___SMMLA(lgain_2,inlet_in2[buffer_index], outlet_l[buffer_index]);
outlet_l[buffer_index] = ___SMMLA(lgain_3,inlet_in3[buffer_index], outlet_l[buffer_index]);
outlet_l[buffer_index] = ___SMMLA(lgain_4,inlet_in4[buffer_index], outlet_l[buffer_index]);
outlet_l[buffer_index] = ___SMMLA(lgain_5,inlet_in5[buffer_index], outlet_l[buffer_index]);
outlet_l[buffer_index] = ___SMMLA(lgain_6,inlet_in6[buffer_index], outlet_l[buffer_index]);
outlet_l[buffer_index] = ___SMMLA(lgain_7,inlet_in7[buffer_index], outlet_l[buffer_index]);
outlet_l[buffer_index] = ___SMMLA(lgain_8,inlet_in8[buffer_index], outlet_l[buffer_index]);

outlet_r[buffer_index] = ___SMMUL(rgain_1,inlet_in1[buffer_index]);
outlet_r[buffer_index] = ___SMMLA(rgain_2,inlet_in2[buffer_index], outlet_r[buffer_index]);
outlet_r[buffer_index] = ___SMMLA(rgain_3,inlet_in3[buffer_index], outlet_r[buffer_index]);
outlet_r[buffer_index] = ___SMMLA(rgain_4,inlet_in4[buffer_index], outlet_r[buffer_index]);
outlet_r[buffer_index] = ___SMMLA(rgain_5,inlet_in5[buffer_index], outlet_r[buffer_index]);
outlet_r[buffer_index] = ___SMMLA(rgain_6,inlet_in6[buffer_index], outlet_r[buffer_index]);
outlet_r[buffer_index] = ___SMMLA(rgain_7,inlet_in7[buffer_index], outlet_r[buffer_index]);
outlet_r[buffer_index] = ___SMMLA(rgain_8,inlet_in8[buffer_index], outlet_r[buffer_index]);
}
}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if( (status&0xF0) == MIDI_CONTROL_CHANGE && data1 == 7 ){
  uint8_t rxChan = status&0x0F;
  uint8_t chBits = mixBitChan( rxChan ); // e.g. 0b01000000 for inlet_in7 signal

  if( chBits == 0 ) return; // no further processing

  int32_t g               = data2<<24;  // 32bit
  if( chBits&1 )   gain_1 = g;
  if( chBits&2 )   gain_2 = g;
  if( chBits&4 )   gain_3 = g;
  if( chBits&8 )   gain_4 = g;
  if( chBits&16 )  gain_5 = g;
  if( chBits&32 )  gain_6 = g;
  if( chBits&64 )  gain_7 = g;
  if( chBits&128 ) gain_8 = g;
}
else if( (status&0xF0) == MIDI_CONTROL_CHANGE && data1 == 10 ){
  uint8_t rxChan = status&0x0F;
  uint8_t chBits = mixBitChan( rxChan ); // e.g. 0b01000000 for inlet_in7 signal

  if( chBits == 0 ) return; // no further processing
  
  if( data2 >= 0  && data2 <= 47 ) { lmix |=  chBits; rmix &= ~chBits; } // left only
  if( data2 >= 48 && data2 <= 80 ) { lmix |=  chBits; rmix |=  chBits; } // both
  if( data2 >= 81 && data2 <= 127 ){ lmix &= ~chBits; rmix |=  chBits; } // right only
}
else if( (status&0xF0) == MIDI_PROGRAM_CHANGE && data1 == 127 )
{
  uint8_t rxChan = status&0x0F;
  uint8_t chBits = mixBitChan( rxChan ); // e.g. 0b01000000 for inlet_in7 signal

  if( chBits == 0 ) return; // no further processing

  uint8_t st = MIDI_CONTROL_CHANGE|rxChan;          

  uint8_t d1 = 7;                                     // cc7 vol
  uint8_t d2 = 100;
  if( chBits&1 )   d2 = gain_1>>24;
  if( chBits&2 )   d2 = gain_2>>24;
  if( chBits&4 )   d2 = gain_3>>24;
  if( chBits&8 )   d2 = gain_4>>24;
  if( chBits&16 )  d2 = gain_5>>24;
  if( chBits&32 )  d2 = gain_6>>24;
  if( chBits&64 )  d2 = gain_7>>24;
  if( chBits&128 ) d2 = gain_8>>24;
  
  MidiSend3((midi_device_t) MIDI_DEVICE_DIN, 1, st, d1, d2);
  
  d1 = 10;                                          // cc10 pan
  d2 = 64;

  if(  (lmix&chBits) && !(rmix&chBits) )  d2 = 0;   // left only
  if(  (lmix&chBits) &&  (rmix&chBits)  ) d2 = 64;  // both
  if( !(lmix&chBits) &&  (rmix&chBits) )  d2 = 127; // right only

  MidiSend3((midi_device_t) MIDI_DEVICE_DIN, 1, st, d1, d2);
  
}}
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

  public: void Init(instancefourkit__10 * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX__dash_c__1_c].pfunction = pfun_unsigned_clamp;
  
  
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
	int i; for(i=0;i<max_length;i++){ sample[i]=0; } // fail? silence
	return;
}
f_read(&FileObject, (char *)sample, sizeof(_sample),&bytes_read);
f_close(&FileObject);

int i=bytes_read/2;                    // file 'end' 16 bit per sample
for(;i<max_length;i++){ sample[i]=0; } // silence
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

  public: void Init(instancefourkit__10 * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX__dash_c__2_c].pfunction = pfun_unsigned_clamp;
  
  
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
	int i; for(i=0;i<max_length;i++){ sample[i]=0; } // fail? silence
	return;
}
f_read(&FileObject, (char *)sample, sizeof(_sample),&bytes_read);
f_close(&FileObject);

int i=bytes_read/2;                    // file 'end' 16 bit per sample
for(;i<max_length;i++){ sample[i]=0; } // silence
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

  public: void Init(instancefourkit__10 * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX__dash_c__3_c].pfunction = pfun_unsigned_clamp;
  
  
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
	int i; for(i=0;i<max_length;i++){ sample[i]=0; } // fail? silence
	return;
}
f_read(&FileObject, (char *)sample, sizeof(_sample),&bytes_read);
f_close(&FileObject);

int i=bytes_read/2;                    // file 'end' 16 bit per sample
for(;i<max_length;i++){ sample[i]=0; } // silence
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
    int32buffer  net13Latch;
    int32buffer  net14Latch;
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
    int32buffer  net6;
    int32_t  net7;
    int32_t  net8;
    int32_t  net9;
    bool  net10;
    bool  net11;
    int32_t  net12;
    int32buffer  net13;
    int32buffer  net14;
    int32buffer  net15;
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
  instanceflashplay__1_i.dsp(net4, net5, net6);
  instancesum4__1_i.dsp(net6, net14Latch, net13Latch, zerobuffer, net15);
  instanceoutlet__1_i.dsp(net15);
  instancekeyb__2_i.dsp(net2, (bool &)UNCONNECTED_OUTPUT, net10, UNCONNECTED_OUTPUT, UNCONNECTED_OUTPUT);
  instancebipolar2unipolar__2_i.dsp(net2, net3);
  instance_dash_c__2_i.dsp(net3, net9, PExch[PARAM_INDEX__dash_c__2_c].finalvalue);
  instanceflashplay__2_i.dsp(net9, net10, net14);
  instancekeyb__3_i.dsp(net7, (bool &)UNCONNECTED_OUTPUT, net11, UNCONNECTED_OUTPUT, UNCONNECTED_OUTPUT);
  instancebipolar2unipolar__3_i.dsp(net7, net8);
  instance_dash_c__3_i.dsp(net8, net12, PExch[PARAM_INDEX__dash_c__3_c].finalvalue);
  instanceflashplay__3_i.dsp(net12, net11, net13);
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
   for(i=0;i<BUFSIZE;i++)
      net13Latch[i]=net13[i];
   for(i=0;i<BUFSIZE;i++)
      net14Latch[i]=net14[i];
//--------- </net latch copy> ----------//
      for(i=0;i<BUFSIZE;i++) outlet_outlet__1[i] = instanceoutlet__1_i._outlet[i];

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ( 0 > 0 && dev > 0 && 0 != dev) return;
if ( 0 > 0 && port > 0 && 0 != port) return;
instancekeyb__1_i.MidiInHandler(dev, port, status, data1, data2);
instancekeyb__2_i.MidiInHandler(dev, port, status, data1, data2);
instancekeyb__3_i.MidiInHandler(dev, port, status, data1, data2);
}
}
}
;class instancefourkit__11{
  public: // v1
  rootc *parent;
    static const uint32_t NPEXCH = 2;
    ParameterExchange_t PExch[NPEXCH];
    int32_t displayVector[3];
    static const uint32_t NPRESETS = 0;
    static const uint32_t NPRESET_ENTRIES = 0;
    static const uint32_t NMODULATIONSOURCES = 0;
    static const uint32_t NMODULATIONTARGETS = 0;
    int32_t PExModulationPrevVal[1][NMODULATIONSOURCES];
/* modsource defines */
/* parameter instance indices */
static const int PARAM_INDEX__dash_c__3_c = 0;
static const int PARAM_INDEX__dash_c__4_c = 1;
/* controller classes */
/* object classes */
class instancekeyb__3{
  public: // v1
  instancefourkit__11 *parent;
int8_t _note;
int32_t _gate;
int32_t _gate2;
uint8_t _velo;
uint8_t _rvelo;
uint32_t np[67-36+1];
uint32_t p;

  public: void Init(instancefourkit__11 * _parent) {
parent = _parent;
_gate = 0;
_gate2 = 0;
_note = 0;
p = 1;
int j;
for(j=0;j<67-36+1;j++) np[j]=0;

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
if ((status == MIDI_NOTE_ON + 10) && (data2)) {
  if ((data1 >= 36)&&(data1 <= 67)) {
    _velo = data2;
    _note = data1-64;
    _gate = 1<<27;
    _gate2 = 0;
    np[data1-36]=p++;
  }
} else if (((status == MIDI_NOTE_ON + 10) && (!data2))||
          (status == MIDI_NOTE_OFF + 10)) {
if ((data1 >= 36)&&(data1 <= 67)) {
   _rvelo = data2;
np[data1-36]=0;
int j;
int np2 = 0;
int n2 = 0;
for(j=0;j<67-36+1;j++){
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
} else if ((status == 10 + MIDI_CONTROL_CHANGE)&&(data1 == MIDI_C_ALL_NOTES_OFF)) {
  _gate = 0;
}
}
}
}
;class instancebipolar2unipolar__3{
  public: // v1
  instancefourkit__11 *parent;
  public: void Init(instancefourkit__11 * _parent) {
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
  instancefourkit__11 *parent;

  public: void Init(instancefourkit__11 * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX__dash_c__3_c].pfunction = pfun_unsigned_clamp;
  
  
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
  instancefourkit__11 *parent;
const static int max_length = 16*16384;
int16_t *sample;
uint32_t _pos = max_length;
int ntrig=0;
  public: void Init(instancefourkit__11 * _parent) {
parent = _parent;
static int16_t _sample[max_length] __attribute__ ((section (".sdram")));
sample = &_sample[0];
FIL FileObject;
FRESULT err;
UINT bytes_read;
const char fn[] = "/zp-kit2.wav";
err = f_open(&FileObject, fn, FA_READ | FA_OPEN_EXISTING);
if (err != FR_OK) {
	int i; for(i=0;i<max_length;i++){ sample[i]=0; } // fail? silence
	return;
}
f_read(&FileObject, (char *)sample, sizeof(_sample),&bytes_read);
f_close(&FileObject);

int i=bytes_read/2;                    // file 'end' 16 bit per sample
for(;i<max_length;i++){ sample[i]=0; } // silence
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
  instancefourkit__11 *parent;
  public: void Init(instancefourkit__11 * _parent) {
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
;class instanceoutlet__1{
  public: // v1
  instancefourkit__11 *parent;
int32buffer _outlet;

  public: void Init(instancefourkit__11 * _parent) {
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
;class instancekeyb__4{
  public: // v1
  instancefourkit__11 *parent;
int8_t _note;
int32_t _gate;
int32_t _gate2;
uint8_t _velo;
uint8_t _rvelo;
uint32_t np[100-68+1];
uint32_t p;

  public: void Init(instancefourkit__11 * _parent) {
parent = _parent;
_gate = 0;
_gate2 = 0;
_note = 0;
p = 1;
int j;
for(j=0;j<100-68+1;j++) np[j]=0;

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
if ((status == MIDI_NOTE_ON + 10) && (data2)) {
  if ((data1 >= 68)&&(data1 <= 100)) {
    _velo = data2;
    _note = data1-64;
    _gate = 1<<27;
    _gate2 = 0;
    np[data1-68]=p++;
  }
} else if (((status == MIDI_NOTE_ON + 10) && (!data2))||
          (status == MIDI_NOTE_OFF + 10)) {
if ((data1 >= 68)&&(data1 <= 100)) {
   _rvelo = data2;
np[data1-68]=0;
int j;
int np2 = 0;
int n2 = 0;
for(j=0;j<100-68+1;j++){
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
} else if ((status == 10 + MIDI_CONTROL_CHANGE)&&(data1 == MIDI_C_ALL_NOTES_OFF)) {
  _gate = 0;
}
}
}
}
;class instancebipolar2unipolar__4{
  public: // v1
  instancefourkit__11 *parent;
  public: void Init(instancefourkit__11 * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (const int32_t  inlet_i,
int32_t  & outlet_o  ){
   outlet_o= (inlet_i>>1)+(1<<26);

}
}
;class instance_dash_c__4{
  public: // v1
  instancefourkit__11 *parent;

  public: void Init(instancefourkit__11 * _parent) {
parent = _parent;
parent->PExch[PARAM_INDEX__dash_c__4_c].pfunction = pfun_unsigned_clamp;
  
  
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
  instancefourkit__11 *parent;
const static int max_length = 16*16384;
int16_t *sample;
uint32_t _pos = max_length;
int ntrig=0;
  public: void Init(instancefourkit__11 * _parent) {
parent = _parent;
static int16_t _sample[max_length] __attribute__ ((section (".sdram")));
sample = &_sample[0];
FIL FileObject;
FRESULT err;
UINT bytes_read;
const char fn[] = "/zp-kit2.wav";
err = f_open(&FileObject, fn, FA_READ | FA_OPEN_EXISTING);
if (err != FR_OK) {
	int i; for(i=0;i<max_length;i++){ sample[i]=0; } // fail? silence
	return;
}
f_read(&FileObject, (char *)sample, sizeof(_sample),&bytes_read);
f_close(&FileObject);

int i=bytes_read/2;                    // file 'end' 16 bit per sample
for(;i<max_length;i++){ sample[i]=0; } // silence
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
     instancekeyb__3 instancekeyb__3_i;
     instancebipolar2unipolar__3 instancebipolar2unipolar__3_i;
     instance_dash_c__3 instance_dash_c__3_i;
     instanceflashplay__1 instanceflashplay__1_i;
     instancesum4__1 instancesum4__1_i;
     instanceoutlet__1 instanceoutlet__1_i;
     instancekeyb__4 instancekeyb__4_i;
     instancebipolar2unipolar__4 instancebipolar2unipolar__4_i;
     instance_dash_c__4 instance_dash_c__4_i;
     instanceflashplay__2 instanceflashplay__2_i;
/* net latches */
    int32buffer  net4Latch;
static const int polyIndex = 0;
   static int32_t * GetInitParams(void){
      static const int32_t p[2]= {
      37748736,
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
   for(j=0;j<2;j++){
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
   instancekeyb__3_i.Init(this );
   instancebipolar2unipolar__3_i.Init(this );
   instance_dash_c__3_i.Init(this );
   instanceflashplay__1_i.Init(this );
   instancesum4__1_i.Init(this );
   instanceoutlet__1_i.Init(this );
   instancekeyb__4_i.Init(this );
   instancebipolar2unipolar__4_i.Init(this );
   instance_dash_c__4_i.Init(this );
   instanceflashplay__2_i.Init(this );
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
   instanceflashplay__2_i.Dispose();
   instance_dash_c__4_i.Dispose();
   instancebipolar2unipolar__4_i.Dispose();
   instancekeyb__4_i.Dispose();
   instanceoutlet__1_i.Dispose();
   instancesum4__1_i.Dispose();
   instanceflashplay__1_i.Dispose();
   instance_dash_c__3_i.Dispose();
   instancebipolar2unipolar__3_i.Dispose();
   instancekeyb__3_i.Dispose();

}
  public: void dsp (int32buffer  & outlet_outlet__1  ){
int i; /*...*/
//--------- <nets> -----------//
    int32_t  net0;
    int32_t  net1;
    int32_t  net2;
    int32_t  net3;
    int32buffer  net4;
    int32buffer  net5;
    int32_t  net6;
    bool  net7;
    bool  net8;
    int32_t  net9;
    int32buffer  net10;
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instancekeyb__3_i.dsp(net0, (bool &)UNCONNECTED_OUTPUT, net7, UNCONNECTED_OUTPUT, UNCONNECTED_OUTPUT);
  instancebipolar2unipolar__3_i.dsp(net0, net1);
  instance_dash_c__3_i.dsp(net1, net6, PExch[PARAM_INDEX__dash_c__3_c].finalvalue);
  instanceflashplay__1_i.dsp(net6, net7, net5);
  instancesum4__1_i.dsp(net5, net4Latch, zerobuffer, zerobuffer, net10);
  instanceoutlet__1_i.dsp(net10);
  instancekeyb__4_i.dsp(net3, (bool &)UNCONNECTED_OUTPUT, net8, UNCONNECTED_OUTPUT, UNCONNECTED_OUTPUT);
  instancebipolar2unipolar__4_i.dsp(net3, net2);
  instance_dash_c__4_i.dsp(net2, net9, PExch[PARAM_INDEX__dash_c__4_c].finalvalue);
  instanceflashplay__2_i.dsp(net9, net8, net4);
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
   for(i=0;i<BUFSIZE;i++)
      net4Latch[i]=net4[i];
//--------- </net latch copy> ----------//
      for(i=0;i<BUFSIZE;i++) outlet_outlet__1[i] = instanceoutlet__1_i._outlet[i];

}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if ( 0 > 0 && dev > 0 && 0 != dev) return;
if ( 0 > 0 && port > 0 && 0 != port) return;
instancekeyb__3_i.MidiInHandler(dev, port, status, data1, data2);
instancekeyb__4_i.MidiInHandler(dev, port, status, data1, data2);
}
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
  if( vtype==6 ) PExIdx = ccToPExAlgo6( data1 );

  if( PExIdx==-1 ) return; // abort

  int PExVal = data2<<20;
  if( vtype==1 && PExBipAlgo1(PExIdx) ){ PExVal = (PExVal-(1<<26))<<1; }
  if( vtype==2 && PExBipAlgo2(PExIdx) ){ PExVal = (PExVal-(1<<26))<<1; }
  if( vtype==3 && PExBipAlgo3(PExIdx) ){ PExVal = (PExVal-(1<<26))<<1; }
  if( vtype==4 && PExBipAlgo4(PExIdx) ){ PExVal = (PExVal-(1<<26))<<1; }
  if( vtype==5 && PExBipAlgo5(PExIdx) ){ PExVal = (PExVal-(1<<26))<<1; }
  if( vtype==6 && PExBipAlgo6(PExIdx) ){ PExVal = (PExVal-(1<<26))<<1; }

  if( vtype==1 ) PExParameterChange( &((instancealgo__1::voice*)parent)->PExch[ PExIdx ], PExVal, 0xFFEF );
  if( vtype==2 ) PExParameterChange( &((instancealgo__2::voice*)parent)->PExch[ PExIdx ], PExVal, 0xFFEF );
  if( vtype==3 ) PExParameterChange( &((instancealgo__3::voice*)parent)->PExch[ PExIdx ], PExVal, 0xFFEF );
  if( vtype==4 ) PExParameterChange( &((instancealgo__4::voice*)parent)->PExch[ PExIdx ], PExVal, 0xFFEF );
  if( vtype==5 ) PExParameterChange( &((instancealgo__5::voice*)parent)->PExch[ PExIdx ], PExVal, 0xFFEF );
  if( vtype==6 ) PExParameterChange( &((instancealgo__6::voice*)parent)->PExch[ PExIdx ], PExVal, 0xFFEF );
}

static void txState( int vtype, ParameterExchange_t *PE, uint8_t txChan ){
  uint8_t MIN_CC = 16;         // cc16..25 with vtype 1,3
  uint8_t MAX_CC = 25;

  if( vtype == 2) MAX_CC = 22; // cc16..22 with vtype 2
  if( vtype == 4) MAX_CC = 22; // cc16..22 with vtype 4
  if( vtype == 5) MAX_CC = 30; // cc16..30 with vtype 5
  if( vtype == 6) MAX_CC = 29; // cc16..29 with vtype 6

  MidiSend2((midi_device_t) MIDI_DEVICE_DIN, 1, txChan + MIDI_PROGRAM_CHANGE, vtype&0x7F ); //2byte 
  for(int txCCdat1=MIN_CC; txCCdat1<=MAX_CC; txCCdat1++){ txStateCC( vtype, PE, txCCdat1, txChan ); }
}

static void txStateCC( int vtype, ParameterExchange_t *PE, uint8_t txCCdat1, uint8_t txChan ){
	int PExIdx = -1;
	if( vtype == 1 ) PExIdx = ccToPExAlgo1( txCCdat1 );
	if( vtype == 2 ) PExIdx = ccToPExAlgo2( txCCdat1 );
	if( vtype == 3 ) PExIdx = ccToPExAlgo3( txCCdat1 );	
	if( vtype == 4 ) PExIdx = ccToPExAlgo4( txCCdat1 );	
	if( vtype == 5 ) PExIdx = ccToPExAlgo5( txCCdat1 );
	if( vtype == 6 ) PExIdx = ccToPExAlgo6( txCCdat1 );

	if( PExIdx != -1 ){
  		int txDat2 = PE[ PExIdx ].modvalue; // range 32bit
  		
  	  	if( vtype==1 && PExBipAlgo1( PExIdx ) ){ txDat2 = (txDat2>>1) + (1<<26); }
  	  	if( vtype==2 && PExBipAlgo2( PExIdx ) ){ txDat2 = (txDat2>>1) + (1<<26); }
  	  	if( vtype==3 && PExBipAlgo3( PExIdx ) ){ txDat2 = (txDat2>>1) + (1<<26); }
  	  	if( vtype==4 && PExBipAlgo4( PExIdx ) ){ txDat2 = (txDat2>>1) + (1<<26); }
  	  	if( vtype==5 && PExBipAlgo5( PExIdx ) ){ txDat2 = (txDat2>>1) + (1<<26); }
  	  	if( vtype==6 && PExBipAlgo6( PExIdx ) ){ txDat2 = (txDat2>>1) + (1<<26); }
  	  	
  	  	txDat2 = txDat2 >> 20;              // range 0..128
	     txDat2 = (txDat2!=128)?txDat2:127;  // range 0..127
	     MidiSend3((midi_device_t) MIDI_DEVICE_DIN, 1, txChan + MIDI_CONTROL_CHANGE, txCCdat1&0x7F, txDat2&0x7F);
  	}
}

static int ccToPExAlgo1( uint8_t cc ) __attribute__ ((section (".sdram"))) {
 if( 16==cc ){ return instancealgo__1::voice::PARAM_INDEX_fm__1_timbre; }
 if( 17==cc ){ return instancealgo__1::voice::PARAM_INDEX_fm__1_color; }
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
static int PExBipAlgo1( int idx ) __attribute__ ((section (".sdram"))) {
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
 if( 16==cc ){ return instancealgo__2::voice::PARAM_INDEX_sinefold__1_timbre; }
 // omit 17
 if( 18==cc ){ return instancealgo__2::voice::PARAM_INDEX_a__time_a; }
 if( 19==cc ){ return instancealgo__2::voice::PARAM_INDEX_a__vel_amp; }
 if( 20==cc ){ return instancealgo__2::voice::PARAM_INDEX_env__t_time; }
 if( 21==cc ){ return instancealgo__2::voice::PARAM_INDEX_env__t_vt; }
 if( 22==cc ){ return instancealgo__2::voice::PARAM_INDEX_env__t_env; }
 return -1;
}
static int PExBipAlgo2( int idx ) __attribute__ ((section (".sdram"))) {
 if( instancealgo__2::voice::PARAM_INDEX_a__time_a  ==idx ){ return 1; }
 if( instancealgo__2::voice::PARAM_INDEX_a__vel_amp ==idx ){ return 1; }
 if( instancealgo__2::voice::PARAM_INDEX_env__t_time==idx ){ return 1; }
 if( instancealgo__2::voice::PARAM_INDEX_env__t_vt  ==idx ){ return 1; }
 if( instancealgo__2::voice::PARAM_INDEX_env__t_env ==idx ){ return 1; }
 return 0;
}

static int ccToPExAlgo3( uint8_t cc ) __attribute__ ((section (".sdram"))) {
 if( 16==cc ){ return instancealgo__3::voice::PARAM_INDEX_wtables__1_timbre; }
 if( 17==cc ){ return instancealgo__3::voice::PARAM_INDEX_wtables__1_color; }
 if( 18==cc ){ return instancealgo__3::voice::PARAM_INDEX_a__time_a; }
 if( 19==cc ){ return instancealgo__3::voice::PARAM_INDEX_a__vel_amp; }
 if( 20==cc ){ return instancealgo__3::voice::PARAM_INDEX_env__t_time; }
 if( 21==cc ){ return instancealgo__3::voice::PARAM_INDEX_env__t_vt; }
 if( 22==cc ){ return instancealgo__3::voice::PARAM_INDEX_env__t_env; }
 if( 23==cc ){ return instancealgo__3::voice::PARAM_INDEX_env__c_time; }
 if( 24==cc ){ return instancealgo__3::voice::PARAM_INDEX_env__c_vt; }
 if( 25==cc ){ return instancealgo__3::voice::PARAM_INDEX_env__c_env; }
 return -1;
}
static int PExBipAlgo3( int idx ) __attribute__ ((section (".sdram"))) {
 if( instancealgo__3::voice::PARAM_INDEX_a__time_a  ==idx ){ return 1; }
 if( instancealgo__3::voice::PARAM_INDEX_a__vel_amp ==idx ){ return 1; }
 if( instancealgo__3::voice::PARAM_INDEX_env__t_time==idx ){ return 1; }	
 if( instancealgo__3::voice::PARAM_INDEX_env__t_vt  ==idx ){ return 1; }
 if( instancealgo__3::voice::PARAM_INDEX_env__t_env ==idx ){ return 1; }
 if( instancealgo__3::voice::PARAM_INDEX_env__c_time==idx ){ return 1; }	
 if( instancealgo__3::voice::PARAM_INDEX_env__c_vt  ==idx ){ return 1; }
 if( instancealgo__3::voice::PARAM_INDEX_env__c_env ==idx ){ return 1; }
 return 0;
}

static int ccToPExAlgo4( uint8_t cc ) __attribute__ ((section (".sdram"))) {
 if( 16==cc ){ return instancealgo__4::voice::PARAM_INDEX_buzz__1_timbre; }
 // omit 17
 if( 18==cc ){ return instancealgo__4::voice::PARAM_INDEX_a__time_a; }
 if( 19==cc ){ return instancealgo__4::voice::PARAM_INDEX_a__vel_amp; }
 if( 20==cc ){ return instancealgo__4::voice::PARAM_INDEX_env__t_time; }
 if( 21==cc ){ return instancealgo__4::voice::PARAM_INDEX_env__t_vt; }
 if( 22==cc ){ return instancealgo__4::voice::PARAM_INDEX_env__t_env; }
 return -1;
}
static int PExBipAlgo4( int idx ) __attribute__ ((section (".sdram"))){
 if( instancealgo__4::voice::PARAM_INDEX_a__time_a  ==idx ){ return 1; }	
 if( instancealgo__4::voice::PARAM_INDEX_a__vel_amp ==idx ){ return 1; }
 if( instancealgo__4::voice::PARAM_INDEX_env__t_time==idx ){ return 1; }
 if( instancealgo__4::voice::PARAM_INDEX_env__t_vt  ==idx ){ return 1; }
 if( instancealgo__4::voice::PARAM_INDEX_env__t_env ==idx ){ return 1; }
 return 0;
}

static int ccToPExAlgo5( uint8_t cc ) __attribute__ ((section (".sdram"))) {
 if( 16==cc ){ return instancealgo__5::voice::PARAM_INDEX_tmo__1_Hrm1; }
 if( 17==cc ){ return instancealgo__5::voice::PARAM_INDEX_tmo__1_Hrm2; }
 if( 18==cc ){ return instancealgo__5::voice::PARAM_INDEX_a__time_a; }
 if( 19==cc ){ return instancealgo__5::voice::PARAM_INDEX_a__vel_amp; }
 if( 20==cc ){ return instancealgo__5::voice::PARAM_INDEX_env__t_time; }
 if( 21==cc ){ return instancealgo__5::voice::PARAM_INDEX_env__t_vt; }
 if( 22==cc ){ return instancealgo__5::voice::PARAM_INDEX_env__t_env; }
 if( 23==cc ){ return instancealgo__5::voice::PARAM_INDEX_env__c_time; }
 if( 24==cc ){ return instancealgo__5::voice::PARAM_INDEX_env__c_vt; }
 if( 25==cc ){ return instancealgo__5::voice::PARAM_INDEX_env__c_env; }
 if( 26==cc ){ return instancealgo__5::voice::PARAM_INDEX_env__s_time; }
 if( 27==cc ){ return instancealgo__5::voice::PARAM_INDEX_env__s_vt; }
 if( 28==cc ){ return instancealgo__5::voice::PARAM_INDEX_env__s_env; }
 if( 29==cc ){ return instancealgo__5::voice::PARAM_INDEX_tmo__1_Hrm3; }
 if( 30==cc ){ return instancealgo__5::voice::PARAM_INDEX_tmo__1_lfo; }
 return -1;
}
static int PExBipAlgo5( int idx ) __attribute__ ((section (".sdram"))){
 if( instancealgo__5::voice::PARAM_INDEX_tmo__1_Hrm1== idx ){ return 1; }
 if( instancealgo__5::voice::PARAM_INDEX_tmo__1_Hrm2== idx ){ return 1; }
 if( instancealgo__5::voice::PARAM_INDEX_a__time_a  == idx ){ return 1; }
 if( instancealgo__5::voice::PARAM_INDEX_a__vel_amp == idx ){ return 1; }
 if( instancealgo__5::voice::PARAM_INDEX_env__t_time== idx ){ return 1; }
 if( instancealgo__5::voice::PARAM_INDEX_env__t_vt  == idx ){ return 1; }
 if( instancealgo__5::voice::PARAM_INDEX_env__t_env == idx ){ return 1; }
 if( instancealgo__5::voice::PARAM_INDEX_env__c_time== idx ){ return 1; }
 if( instancealgo__5::voice::PARAM_INDEX_env__c_vt  == idx ){ return 1; }
 if( instancealgo__5::voice::PARAM_INDEX_env__c_env == idx ){ return 1; }
 if( instancealgo__5::voice::PARAM_INDEX_env__s_time== idx ){ return 1; }
 if( instancealgo__5::voice::PARAM_INDEX_env__s_vt  == idx ){ return 1; }
 if( instancealgo__5::voice::PARAM_INDEX_env__s_env == idx ){ return 1; }
 if( instancealgo__5::voice::PARAM_INDEX_tmo__1_Hrm3== idx ){ return 1; }
 if( instancealgo__5::voice::PARAM_INDEX_tmo__1_lfo == idx ){ return 1; }
 return 0;
}

static int ccToPExAlgo6( uint8_t cc ) __attribute__ ((section (".sdram"))) {
 if( 16==cc ){ return instancealgo__6::voice::PARAM_INDEX_timbre_c; }
 if( 17==cc ){ return instancealgo__6::voice::PARAM_INDEX_colour_c; }
 if( 18==cc ){ return instancealgo__6::voice::PARAM_INDEX_a__time_d; }
 if( 19==cc ){ return instancealgo__6::voice::PARAM_INDEX_a__vel_amp; }
 if( 20==cc ){ return instancealgo__6::voice::PARAM_INDEX_env__t_time; }
 if( 21==cc ){ return instancealgo__6::voice::PARAM_INDEX_env__t_vt; }
 if( 22==cc ){ return instancealgo__6::voice::PARAM_INDEX_env__t_env; }
 if( 23==cc ){ return instancealgo__6::voice::PARAM_INDEX_env__c_time; }
 if( 24==cc ){ return instancealgo__6::voice::PARAM_INDEX_env__c_vt; }
 if( 25==cc ){ return instancealgo__6::voice::PARAM_INDEX_env__c_env; }
 if( 26==cc ){ return instancealgo__6::voice::PARAM_INDEX_env__s_time; }
 if( 27==cc ){ return instancealgo__6::voice::PARAM_INDEX_env__s_vt; }
 if( 28==cc ){ return instancealgo__6::voice::PARAM_INDEX_env__s_env; }
 if( 29==cc ){ return instancealgo__6::voice::PARAM_INDEX_shape_c; }
 return -1;
}
static int PExBipAlgo6( int idx ) __attribute__ ((section (".sdram"))){
 if( instancealgo__6::voice::PARAM_INDEX_a__time_d  == idx ){ return 1; }
 if( instancealgo__6::voice::PARAM_INDEX_a__vel_amp == idx ){ return 1; }
 if( instancealgo__6::voice::PARAM_INDEX_env__t_time== idx ){ return 1; }
 if( instancealgo__6::voice::PARAM_INDEX_env__t_vt  == idx ){ return 1; }
 if( instancealgo__6::voice::PARAM_INDEX_env__t_env == idx ){ return 1; }
 if( instancealgo__6::voice::PARAM_INDEX_env__c_time== idx ){ return 1; }
 if( instancealgo__6::voice::PARAM_INDEX_env__c_vt  == idx ){ return 1; }
 if( instancealgo__6::voice::PARAM_INDEX_env__c_env == idx ){ return 1; }
 if( instancealgo__6::voice::PARAM_INDEX_env__s_time== idx ){ return 1; }
 if( instancealgo__6::voice::PARAM_INDEX_env__s_vt  == idx ){ return 1; }
 if( instancealgo__6::voice::PARAM_INDEX_env__s_env == idx ){ return 1; }
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
;class instanceloader{
  public: // v1
  rootc *parent;
  public: void Init(rootc * _parent) {
parent = _parent;
}
  public: void Dispose() {
}
  public: void dsp (  ){
}
void MidiInHandler(midi_device_t dev, uint8_t port, uint8_t status, uint8_t data1, uint8_t data2) {
{
if( (status&0xF0) == MIDI_PROGRAM_CHANGE ) // any channel
{
	if( data1 == 70 ){ LoadPatch("/start.bin"); }
	if( data1 == 71 ){ LoadPatch("/ks-multi28a/patch.bin"); }
	if( data1 == 72 ){ LoadPatch("/ks-multi28b/patch.bin"); }
}}
}
}
;/* controller instances */
/* object instances */
     instanceident instanceident_i;
     instancealgo__1 instancealgo__1_i;
     instancealgo__2 instancealgo__2_i;
     instancealgo__3 instancealgo__3_i;
     instancealgo__4 instancealgo__4_i;
     instancealgo__5 instancealgo__5_i;
     instancealgo__6 instancealgo__6_i;
     instancepatcher__1 instancepatcher__1_i;
     instancepatcher__2 instancepatcher__2_i;
     instancepatcher__3 instancepatcher__3_i;
     instancepatcher__4 instancepatcher__4_i;
     instancepatcher__5 instancepatcher__5_i;
     instancepatcher__6 instancepatcher__6_i;
     instancesum8__1 instancesum8__1_i;
     instanceout__1 instanceout__1_i;
     instancefourkit__10 instancefourkit__10_i;
     instancefourkit__11 instancefourkit__11_i;
     instanceccMGR instanceccMGR_i;
     instanceloader instanceloader_i;
/* net latches */
    int32buffer  net2Latch;
    int32buffer  net3Latch;
static const int polyIndex = 0;
   static int32_t * GetInitParams(void){
      static const int32_t p[12]= {
      1,
      0,
      1,
      0,
      1,
      0,
      1,
      0,
      1,
      0,
      1,
      0
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
   for(j=0;j<12;j++){
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
   instanceident_i.Init(this );
   instancealgo__1_i.Init(this );
   instancealgo__2_i.Init(this );
   instancealgo__3_i.Init(this );
   instancealgo__4_i.Init(this );
   instancealgo__5_i.Init(this );
   instancealgo__6_i.Init(this );
   instancepatcher__1_i.Init(this );
   instancepatcher__2_i.Init(this );
   instancepatcher__3_i.Init(this );
   instancepatcher__4_i.Init(this );
   instancepatcher__5_i.Init(this );
   instancepatcher__6_i.Init(this );
   instancesum8__1_i.Init(this );
   instanceout__1_i.Init(this, displayVector[3], displayVector[4] );
   instancefourkit__10_i.Init(this );
   instancefourkit__11_i.Init(this );
   instanceccMGR_i.Init(this );
   instanceloader_i.Init(this );
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
   instanceloader_i.Dispose();
   instanceccMGR_i.Dispose();
   instancefourkit__11_i.Dispose();
   instancefourkit__10_i.Dispose();
   instanceout__1_i.Dispose();
   instancesum8__1_i.Dispose();
   instancepatcher__6_i.Dispose();
   instancepatcher__5_i.Dispose();
   instancepatcher__4_i.Dispose();
   instancepatcher__3_i.Dispose();
   instancepatcher__2_i.Dispose();
   instancepatcher__1_i.Dispose();
   instancealgo__6_i.Dispose();
   instancealgo__5_i.Dispose();
   instancealgo__4_i.Dispose();
   instancealgo__3_i.Dispose();
   instancealgo__2_i.Dispose();
   instancealgo__1_i.Dispose();
   instanceident_i.Dispose();
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
    int32buffer  net8;
    int32buffer  net9;
//--------- </nets> ----------//
//--------- <zero> ----------//
  int32_t UNCONNECTED_OUTPUT;
  static const int32_t UNCONNECTED_INPUT=0;
  static const int32buffer zerobuffer = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  int32buffer UNCONNECTED_OUTPUT_BUFFER;
//--------- </zero> ----------//
//--------- <controller calls> ----------//
//--------- <object calls> ----------//
  instanceident_i.dsp();
  instancealgo__1_i.dsp(UNCONNECTED_OUTPUT_BUFFER);
  instancealgo__2_i.dsp(UNCONNECTED_OUTPUT_BUFFER);
  instancealgo__3_i.dsp(UNCONNECTED_OUTPUT_BUFFER);
  instancealgo__4_i.dsp(UNCONNECTED_OUTPUT_BUFFER);
  instancealgo__5_i.dsp(UNCONNECTED_OUTPUT_BUFFER);
  instancealgo__6_i.dsp(UNCONNECTED_OUTPUT_BUFFER);
  instancepatcher__1_i.dsp(net4, PExch[PARAM_INDEX_patcher__1_vtype].finalvalue, PExch[PARAM_INDEX_patcher__1_etype].finalvalue);
  instancepatcher__2_i.dsp(net9, PExch[PARAM_INDEX_patcher__2_vtype].finalvalue, PExch[PARAM_INDEX_patcher__2_etype].finalvalue);
  instancepatcher__3_i.dsp(net8, PExch[PARAM_INDEX_patcher__3_vtype].finalvalue, PExch[PARAM_INDEX_patcher__3_etype].finalvalue);
  instancepatcher__4_i.dsp(net7, PExch[PARAM_INDEX_patcher__4_vtype].finalvalue, PExch[PARAM_INDEX_patcher__4_etype].finalvalue);
  instancepatcher__5_i.dsp(net6, PExch[PARAM_INDEX_patcher__5_vtype].finalvalue, PExch[PARAM_INDEX_patcher__5_etype].finalvalue);
  instancepatcher__6_i.dsp(net5, PExch[PARAM_INDEX_patcher__6_vtype].finalvalue, PExch[PARAM_INDEX_patcher__6_etype].finalvalue);
  instancesum8__1_i.dsp(net4, net9, net8, net7, net6, net5, net3Latch, net2Latch, net0, net1);
  instanceout__1_i.dsp(net0, net1, displayVector[3], displayVector[4]);
  instancefourkit__10_i.dsp(net3);
  instancefourkit__11_i.dsp(net2);
  instanceccMGR_i.dsp();
  instanceloader_i.dsp();
//--------- </object calls> ----------//
//--------- <net latch copy> ----------//
   for(i=0;i<BUFSIZE;i++)
      net2Latch[i]=net2[i];
   for(i=0;i<BUFSIZE;i++)
      net3Latch[i]=net3[i];
//--------- </net latch copy> ----------//
}

void MidiInHandler(midi_device_t dev, uint8_t port,uint8_t status, uint8_t data1, uint8_t data2){
instancealgo__1_i.MidiInHandler(dev, port, status, data1, data2);
instancealgo__2_i.MidiInHandler(dev, port, status, data1, data2);
instancealgo__3_i.MidiInHandler(dev, port, status, data1, data2);
instancealgo__4_i.MidiInHandler(dev, port, status, data1, data2);
instancealgo__5_i.MidiInHandler(dev, port, status, data1, data2);
instancealgo__6_i.MidiInHandler(dev, port, status, data1, data2);
instancepatcher__1_i.MidiInHandler(dev, port, status, data1, data2);
instancepatcher__2_i.MidiInHandler(dev, port, status, data1, data2);
instancepatcher__3_i.MidiInHandler(dev, port, status, data1, data2);
instancepatcher__4_i.MidiInHandler(dev, port, status, data1, data2);
instancepatcher__5_i.MidiInHandler(dev, port, status, data1, data2);
instancepatcher__6_i.MidiInHandler(dev, port, status, data1, data2);
instancesum8__1_i.MidiInHandler(dev, port, status, data1, data2);
instancefourkit__10_i.MidiInHandler(dev, port, status, data1, data2);
instancefourkit__11_i.MidiInHandler(dev, port, status, data1, data2);
instanceloader_i.MidiInHandler(dev, port, status, data1, data2);
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
  if (fwid != 0x3BBA8761) {
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
  patchMeta.numPEx = 12;
  patchMeta.patchID = -1210374238;
  extern char _sdram_dyn_start;
  extern char _sdram_dyn_end;
  sdram_init(&_sdram_dyn_start,&_sdram_dyn_end);
  root.Init();
  patchMeta.fptr_applyPreset = ApplyPreset;
  patchMeta.fptr_patch_dispose = PatchDispose;
  patchMeta.fptr_MidiInHandler = PatchMidiInHandler;
  patchMeta.fptr_dsp_process = PatchProcess;
}
