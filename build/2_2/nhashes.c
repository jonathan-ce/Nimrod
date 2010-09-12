/* Generated by Nimrod Compiler v0.8.9 */
/*   (c) 2010 Andreas Rumpf */

typedef long long int NI;
typedef unsigned long long int NU;
#include "nimbase.h"

typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
struct TGenericSeq {
NI len;
NI space;
};
typedef NIM_CHAR TY239[100000001];
struct NimStringDesc {
  TGenericSeq Sup;
TY239 data;
};
N_NIMCALL(NI, Conchash_43040)(NI H_43042, NI Val_43043);
N_NIMCALL(NI, Finishhash_43044)(NI H_43046);
N_NIMCALL(NI, Getdatahash_43024)(void* Data_43026, NI Size_43027);
static N_INLINE(NI, addInt)(NI A_5603, NI B_5604);
N_NOINLINE(void, raiseOverflow)(void);
static N_INLINE(NI, subInt)(NI A_5803, NI B_5804);
N_NIMCALL(NI, Hashptr_43028)(void* P_43030);
N_NIMCALL(NI, Gethash_43018)(NCSTRING Str_43020);
N_NIMCALL(NI, Gethashstr_43031)(NimStringDesc* S_43033);
N_NOINLINE(void, raiseIndexError)(void);
N_NIMCALL(NI, Getnormalizedhash_43037)(NimStringDesc* S_43039);
N_NIMCALL(NI, Gethashstrci_43034)(NimStringDesc* S_43036);
N_NIMCALL(NI, Gethashci_43021)(NCSTRING Str_43023);
N_NIMCALL(NI, Conchash_43040)(NI H_43042, NI Val_43043) {
NI Result_43051;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "concHash";
F.prev = framePtr;
F.filename = "rod/nhashes.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_43051 = 0;
F.line = 36;F.filename = "nhashes.nim";
Result_43051 = (NI64)((NU64)(H_43042) + (NU64)(Val_43043));
F.line = 37;F.filename = "nhashes.nim";
Result_43051 = (NI64)((NU64)(Result_43051) + (NU64)((NI64)((NU64)(Result_43051) << (NU64)(10))));
F.line = 38;F.filename = "nhashes.nim";
Result_43051 = (NI64)(Result_43051 ^ (NI64)((NU64)(Result_43051) >> (NU64)(6)));
framePtr = framePtr->prev;
return Result_43051;
}
N_NIMCALL(NI, Finishhash_43044)(NI H_43046) {
NI Result_43055;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "finishHash";
F.prev = framePtr;
F.filename = "rod/nhashes.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_43055 = 0;
F.line = 41;F.filename = "nhashes.nim";
Result_43055 = (NI64)((NU64)(H_43046) + (NU64)((NI64)((NU64)(H_43046) << (NU64)(3))));
F.line = 42;F.filename = "nhashes.nim";
Result_43055 = (NI64)(Result_43055 ^ (NI64)((NU64)(Result_43055) >> (NU64)(11)));
F.line = 43;F.filename = "nhashes.nim";
Result_43055 = (NI64)((NU64)(Result_43055) + (NU64)((NI64)((NU64)(Result_43055) << (NU64)(15))));
framePtr = framePtr->prev;
return Result_43055;
}
static N_INLINE(NI, addInt)(NI A_5603, NI B_5604) {
NI Result_5605;
NIM_BOOL LOC2;
Result_5605 = 0;
Result_5605 = (NI64)((NU64)(A_5603) + (NU64)(B_5604));
LOC2 = (0 <= (NI64)(Result_5605 ^ A_5603));
if (LOC2) goto LA3;
LOC2 = (0 <= (NI64)(Result_5605 ^ B_5604));
LA3: ;
if (!LOC2) goto LA4;
goto BeforeRet;
LA4: ;
raiseOverflow();
BeforeRet: ;
return Result_5605;
}
static N_INLINE(NI, subInt)(NI A_5803, NI B_5804) {
NI Result_5805;
NIM_BOOL LOC2;
Result_5805 = 0;
Result_5805 = (NI64)((NU64)(A_5803) - (NU64)(B_5804));
LOC2 = (0 <= (NI64)(Result_5805 ^ A_5803));
if (LOC2) goto LA3;
LOC2 = (0 <= (NI64)(Result_5805 ^ (NI64)((NU64) ~(B_5804))));
LA3: ;
if (!LOC2) goto LA4;
goto BeforeRet;
LA4: ;
raiseOverflow();
BeforeRet: ;
return Result_5805;
}
N_NIMCALL(NI, Getdatahash_43024)(void* Data_43026, NI Size_43027) {
NI Result_43060;
NI H_43061;
NCSTRING P_43062;
NI I_43063;
NI S_43064;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "GetDataHash";
F.prev = framePtr;
F.filename = "rod/nhashes.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_43060 = 0;
H_43061 = 0;
P_43062 = 0;
I_43063 = 0;
S_43064 = 0;
F.line = 50;F.filename = "nhashes.nim";
H_43061 = 0;
F.line = 51;F.filename = "nhashes.nim";
P_43062 = ((NCSTRING) (Data_43026));
F.line = 52;F.filename = "nhashes.nim";
I_43063 = 0;
F.line = 53;F.filename = "nhashes.nim";
S_43064 = Size_43027;
F.line = 54;F.filename = "nhashes.nim";
while (1) {
if (!(0 < S_43064)) goto LA1;
F.line = 55;F.filename = "nhashes.nim";
H_43061 = (NI64)((NU64)(H_43061) + (NU64)(((NU8)(P_43062[I_43063]))));
F.line = 56;F.filename = "nhashes.nim";
H_43061 = (NI64)((NU64)(H_43061) + (NU64)((NI64)((NU64)(H_43061) << (NU64)(10))));
F.line = 57;F.filename = "nhashes.nim";
H_43061 = (NI64)(H_43061 ^ (NI64)((NU64)(H_43061) >> (NU64)(6)));
F.line = 58;F.filename = "nhashes.nim";
I_43063 = addInt(I_43063, 1);
F.line = 59;F.filename = "nhashes.nim";
S_43064 = subInt(S_43064, 1);
} LA1: ;
F.line = 60;F.filename = "nhashes.nim";
H_43061 = (NI64)((NU64)(H_43061) + (NU64)((NI64)((NU64)(H_43061) << (NU64)(3))));
F.line = 61;F.filename = "nhashes.nim";
H_43061 = (NI64)(H_43061 ^ (NI64)((NU64)(H_43061) >> (NU64)(11)));
F.line = 62;F.filename = "nhashes.nim";
H_43061 = (NI64)((NU64)(H_43061) + (NU64)((NI64)((NU64)(H_43061) << (NU64)(15))));
F.line = 63;F.filename = "nhashes.nim";
Result_43060 = ((NI) (H_43061));
framePtr = framePtr->prev;
return Result_43060;
}
N_NIMCALL(NI, Hashptr_43028)(void* P_43030) {
NI Result_43100;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "hashPtr";
F.prev = framePtr;
F.filename = "rod/nhashes.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_43100 = 0;
F.line = 66;F.filename = "nhashes.nim";
Result_43100 = (NI64)((NU64)(((NI) (P_43030))) >> (NU64)(3));
framePtr = framePtr->prev;
return Result_43100;
}
N_NIMCALL(NI, Gethash_43018)(NCSTRING Str_43020) {
NI Result_43104;
NI H_43105;
NI I_43106;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "GetHash";
F.prev = framePtr;
F.filename = "rod/nhashes.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_43104 = 0;
H_43105 = 0;
I_43106 = 0;
F.line = 72;F.filename = "nhashes.nim";
H_43105 = 0;
F.line = 73;F.filename = "nhashes.nim";
I_43106 = 0;
F.line = 74;F.filename = "nhashes.nim";
while (1) {
if (!!(((NU8)(Str_43020[I_43106]) == (NU8)(0)))) goto LA1;
F.line = 75;F.filename = "nhashes.nim";
H_43105 = (NI64)((NU64)(H_43105) + (NU64)(((NU8)(Str_43020[I_43106]))));
F.line = 76;F.filename = "nhashes.nim";
H_43105 = (NI64)((NU64)(H_43105) + (NU64)((NI64)((NU64)(H_43105) << (NU64)(10))));
F.line = 77;F.filename = "nhashes.nim";
H_43105 = (NI64)(H_43105 ^ (NI64)((NU64)(H_43105) >> (NU64)(6)));
F.line = 78;F.filename = "nhashes.nim";
I_43106 = addInt(I_43106, 1);
} LA1: ;
F.line = 79;F.filename = "nhashes.nim";
H_43105 = (NI64)((NU64)(H_43105) + (NU64)((NI64)((NU64)(H_43105) << (NU64)(3))));
F.line = 80;F.filename = "nhashes.nim";
H_43105 = (NI64)(H_43105 ^ (NI64)((NU64)(H_43105) >> (NU64)(11)));
F.line = 81;F.filename = "nhashes.nim";
H_43105 = (NI64)((NU64)(H_43105) + (NU64)((NI64)((NU64)(H_43105) << (NU64)(15))));
F.line = 82;F.filename = "nhashes.nim";
Result_43104 = ((NI) (H_43105));
framePtr = framePtr->prev;
return Result_43104;
}
N_NIMCALL(NI, Gethashstr_43031)(NimStringDesc* S_43033) {
NI Result_43130;
NI H_43131;
NI I_43156;
NI HEX3Atmp_43163;
NI Res_43165;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "GetHashStr";
F.prev = framePtr;
F.filename = "rod/nhashes.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_43130 = 0;
H_43131 = 0;
F.line = 86;F.filename = "nhashes.nim";
H_43131 = 0;
I_43156 = 0;
HEX3Atmp_43163 = 0;
F.line = 87;F.filename = "nhashes.nim";
HEX3Atmp_43163 = S_43033->Sup.len;
Res_43165 = 0;
F.line = 1019;F.filename = "system.nim";
Res_43165 = 1;
F.line = 1020;F.filename = "system.nim";
while (1) {
if (!(Res_43165 <= HEX3Atmp_43163)) goto LA1;
F.line = 1019;F.filename = "system.nim";
I_43156 = Res_43165;
F.line = 88;F.filename = "nhashes.nim";
if ((NU)(I_43156) > (NU)(S_43033->Sup.len)) raiseIndexError();
H_43131 = (NI64)((NU64)(H_43131) + (NU64)(((NU8)(S_43033->data[I_43156]))));
F.line = 89;F.filename = "nhashes.nim";
H_43131 = (NI64)((NU64)(H_43131) + (NU64)((NI64)((NU64)(H_43131) << (NU64)(10))));
F.line = 90;F.filename = "nhashes.nim";
H_43131 = (NI64)(H_43131 ^ (NI64)((NU64)(H_43131) >> (NU64)(6)));
F.line = 1022;F.filename = "system.nim";
Res_43165 = addInt(Res_43165, 1);
} LA1: ;
F.line = 91;F.filename = "nhashes.nim";
H_43131 = (NI64)((NU64)(H_43131) + (NU64)((NI64)((NU64)(H_43131) << (NU64)(3))));
F.line = 92;F.filename = "nhashes.nim";
H_43131 = (NI64)(H_43131 ^ (NI64)((NU64)(H_43131) >> (NU64)(11)));
F.line = 93;F.filename = "nhashes.nim";
H_43131 = (NI64)((NU64)(H_43131) + (NU64)((NI64)((NU64)(H_43131) << (NU64)(15))));
F.line = 94;F.filename = "nhashes.nim";
Result_43130 = ((NI) (H_43131));
framePtr = framePtr->prev;
return Result_43130;
}
N_NIMCALL(NI, Getnormalizedhash_43037)(NimStringDesc* S_43039) {
NI Result_43171;
NI H_43172;
NIM_CHAR C_43173;
NI I_43183;
NI HEX3Atmp_43219;
NI Res_43221;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "getNormalizedHash";
F.prev = framePtr;
F.filename = "rod/nhashes.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_43171 = 0;
H_43172 = 0;
C_43173 = 0;
F.line = 100;F.filename = "nhashes.nim";
H_43172 = 0;
I_43183 = 0;
HEX3Atmp_43219 = 0;
F.line = 101;F.filename = "nhashes.nim";
HEX3Atmp_43219 = subInt(addInt(S_43039->Sup.len, 0), 1);
Res_43221 = 0;
F.line = 1019;F.filename = "system.nim";
Res_43221 = 0;
F.line = 1020;F.filename = "system.nim";
while (1) {
if (!(Res_43221 <= HEX3Atmp_43219)) goto LA1;
F.line = 1019;F.filename = "system.nim";
I_43183 = Res_43221;
F.line = 102;F.filename = "nhashes.nim";
if ((NU)(I_43183) > (NU)(S_43039->Sup.len)) raiseIndexError();
C_43173 = S_43039->data[I_43183];
F.line = 103;F.filename = "nhashes.nim";
if (!((NU8)(C_43173) == (NU8)(95))) goto LA4;
F.line = 104;F.filename = "nhashes.nim";
goto LA2;
LA4: ;
F.line = 105;F.filename = "nhashes.nim";
if (!(((NU8)(C_43173)) >= ((NU8)(65)) && ((NU8)(C_43173)) <= ((NU8)(90)))) goto LA7;
F.line = 106;F.filename = "nhashes.nim";
C_43173 = ((NIM_CHAR) (((NI) (addInt(((NU8)(C_43173)), 32)))));
LA7: ;
F.line = 107;F.filename = "nhashes.nim";
H_43172 = (NI64)((NU64)(H_43172) + (NU64)(((NU8)(C_43173))));
F.line = 108;F.filename = "nhashes.nim";
H_43172 = (NI64)((NU64)(H_43172) + (NU64)((NI64)((NU64)(H_43172) << (NU64)(10))));
F.line = 109;F.filename = "nhashes.nim";
H_43172 = (NI64)(H_43172 ^ (NI64)((NU64)(H_43172) >> (NU64)(6)));
LA2: ;
F.line = 1022;F.filename = "system.nim";
Res_43221 = addInt(Res_43221, 1);
} LA1: ;
F.line = 110;F.filename = "nhashes.nim";
H_43172 = (NI64)((NU64)(H_43172) + (NU64)((NI64)((NU64)(H_43172) << (NU64)(3))));
F.line = 111;F.filename = "nhashes.nim";
H_43172 = (NI64)(H_43172 ^ (NI64)((NU64)(H_43172) >> (NU64)(11)));
F.line = 112;F.filename = "nhashes.nim";
H_43172 = (NI64)((NU64)(H_43172) + (NU64)((NI64)((NU64)(H_43172) << (NU64)(15))));
F.line = 113;F.filename = "nhashes.nim";
Result_43171 = ((NI) (H_43172));
framePtr = framePtr->prev;
return Result_43171;
}
N_NIMCALL(NI, Gethashstrci_43034)(NimStringDesc* S_43036) {
NI Result_43227;
NI H_43228;
NIM_CHAR C_43229;
NI I_43239;
NI HEX3Atmp_43273;
NI Res_43275;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "GetHashStrCI";
F.prev = framePtr;
F.filename = "rod/nhashes.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_43227 = 0;
H_43228 = 0;
C_43229 = 0;
F.line = 119;F.filename = "nhashes.nim";
H_43228 = 0;
I_43239 = 0;
HEX3Atmp_43273 = 0;
F.line = 120;F.filename = "nhashes.nim";
HEX3Atmp_43273 = subInt(addInt(S_43036->Sup.len, 0), 1);
Res_43275 = 0;
F.line = 1019;F.filename = "system.nim";
Res_43275 = 0;
F.line = 1020;F.filename = "system.nim";
while (1) {
if (!(Res_43275 <= HEX3Atmp_43273)) goto LA1;
F.line = 1019;F.filename = "system.nim";
I_43239 = Res_43275;
F.line = 121;F.filename = "nhashes.nim";
if ((NU)(I_43239) > (NU)(S_43036->Sup.len)) raiseIndexError();
C_43229 = S_43036->data[I_43239];
F.line = 122;F.filename = "nhashes.nim";
if (!(((NU8)(C_43229)) >= ((NU8)(65)) && ((NU8)(C_43229)) <= ((NU8)(90)))) goto LA3;
F.line = 123;F.filename = "nhashes.nim";
C_43229 = ((NIM_CHAR) (((NI) (addInt(((NU8)(C_43229)), 32)))));
LA3: ;
F.line = 124;F.filename = "nhashes.nim";
H_43228 = (NI64)((NU64)(H_43228) + (NU64)(((NU8)(C_43229))));
F.line = 125;F.filename = "nhashes.nim";
H_43228 = (NI64)((NU64)(H_43228) + (NU64)((NI64)((NU64)(H_43228) << (NU64)(10))));
F.line = 126;F.filename = "nhashes.nim";
H_43228 = (NI64)(H_43228 ^ (NI64)((NU64)(H_43228) >> (NU64)(6)));
F.line = 1022;F.filename = "system.nim";
Res_43275 = addInt(Res_43275, 1);
} LA1: ;
F.line = 127;F.filename = "nhashes.nim";
H_43228 = (NI64)((NU64)(H_43228) + (NU64)((NI64)((NU64)(H_43228) << (NU64)(3))));
F.line = 128;F.filename = "nhashes.nim";
H_43228 = (NI64)(H_43228 ^ (NI64)((NU64)(H_43228) >> (NU64)(11)));
F.line = 129;F.filename = "nhashes.nim";
H_43228 = (NI64)((NU64)(H_43228) + (NU64)((NI64)((NU64)(H_43228) << (NU64)(15))));
F.line = 130;F.filename = "nhashes.nim";
Result_43227 = ((NI) (H_43228));
framePtr = framePtr->prev;
return Result_43227;
}
N_NIMCALL(NI, Gethashci_43021)(NCSTRING Str_43023) {
NI Result_43281;
NI H_43282;
NIM_CHAR C_43283;
NI I_43284;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "GetHashCI";
F.prev = framePtr;
F.filename = "rod/nhashes.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_43281 = 0;
H_43282 = 0;
C_43283 = 0;
I_43284 = 0;
F.line = 137;F.filename = "nhashes.nim";
H_43282 = 0;
F.line = 138;F.filename = "nhashes.nim";
I_43284 = 0;
F.line = 139;F.filename = "nhashes.nim";
while (1) {
if (!!(((NU8)(Str_43023[I_43284]) == (NU8)(0)))) goto LA1;
F.line = 140;F.filename = "nhashes.nim";
C_43283 = Str_43023[I_43284];
F.line = 141;F.filename = "nhashes.nim";
if (!(((NU8)(C_43283)) >= ((NU8)(65)) && ((NU8)(C_43283)) <= ((NU8)(90)))) goto LA3;
F.line = 142;F.filename = "nhashes.nim";
C_43283 = ((NIM_CHAR) (((NI) (addInt(((NU8)(C_43283)), 32)))));
LA3: ;
F.line = 143;F.filename = "nhashes.nim";
H_43282 = (NI64)((NU64)(H_43282) + (NU64)(((NU8)(C_43283))));
F.line = 144;F.filename = "nhashes.nim";
H_43282 = (NI64)((NU64)(H_43282) + (NU64)((NI64)((NU64)(H_43282) << (NU64)(10))));
F.line = 145;F.filename = "nhashes.nim";
H_43282 = (NI64)(H_43282 ^ (NI64)((NU64)(H_43282) >> (NU64)(6)));
F.line = 146;F.filename = "nhashes.nim";
I_43284 = addInt(I_43284, 1);
} LA1: ;
F.line = 147;F.filename = "nhashes.nim";
H_43282 = (NI64)((NU64)(H_43282) + (NU64)((NI64)((NU64)(H_43282) << (NU64)(3))));
F.line = 148;F.filename = "nhashes.nim";
H_43282 = (NI64)(H_43282 ^ (NI64)((NU64)(H_43282) >> (NU64)(11)));
F.line = 149;F.filename = "nhashes.nim";
H_43282 = (NI64)((NU64)(H_43282) + (NU64)((NI64)((NU64)(H_43282) << (NU64)(15))));
F.line = 150;F.filename = "nhashes.nim";
Result_43281 = ((NI) (H_43282));
framePtr = framePtr->prev;
return Result_43281;
}
N_NOINLINE(void, nhashesInit)(void) {
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "nhashes";
F.prev = framePtr;
F.filename = "rod/nhashes.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
framePtr = framePtr->prev;
}

