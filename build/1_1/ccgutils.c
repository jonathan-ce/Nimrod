/* Generated by Nimrod Compiler v0.8.9 */
/*   (c) 2010 Andreas Rumpf */

typedef long int NI;
typedef unsigned long int NU;
#include "nimbase.h"

typedef struct TY49563 TY49563;
typedef struct TY49561 TY49561;
typedef struct TY49559 TY49559;
typedef struct TY48005 TY48005;
typedef struct TNimObject TNimObject;
typedef struct TGenericSeq TGenericSeq;
typedef struct TY49551 TY49551;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef struct TY49549 TY49549;
typedef struct TY49525 TY49525;
typedef struct TY49547 TY49547;
typedef struct TY49539 TY49539;
typedef struct TY46008 TY46008;
typedef struct NimStringDesc NimStringDesc;
typedef struct TY41532 TY41532;
typedef struct TY48011 TY48011;
typedef struct TY49519 TY49519;
typedef struct TY49529 TY49529;
typedef struct TY49527 TY49527;
typedef struct TY49543 TY49543;
typedef struct TY37013 TY37013;
struct TY49559 {
TY48005* Key;
TNimObject* Val;
};
struct TGenericSeq {
NI len;
NI space;
};
struct TY49563 {
NI Counter;
TY49561* Data;
};
typedef TY49563 TY153023[40];
struct TNimType {
NI size;
NU8 kind;
NU8 flags;
TNimType* base;
TNimNode* node;
void* finalizer;
};
struct TNimObject {
TNimType* m_type;
};
struct TY48005 {
  TNimObject Sup;
NI Id;
};
struct TY49539 {
NU8 K;
NU8 S;
NU8 Flags;
TY49551* T;
TY46008* R;
NI A;
};
struct TY49551 {
  TY48005 Sup;
NU8 Kind;
TY49549* Sons;
TY49525* N;
NU8 Flags;
NU8 Callconv;
TY49547* Owner;
TY49547* Sym;
NI64 Size;
NI Align;
NI Containerid;
TY49539 Loc;
};
struct TNimNode {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
typedef NIM_CHAR TY239[100000001];
struct NimStringDesc {
  TGenericSeq Sup;
TY239 data;
};
struct TY41532 {
NI16 Line;
NI16 Col;
NI32 Fileindex;
};
struct TY49525 {
TY49551* Typ;
NimStringDesc* Comment;
TY41532 Info;
NU8 Flags;
NU8 Kind;
union {
struct {NI64 Intval;
} S1;
struct {NF64 Floatval;
} S2;
struct {NimStringDesc* Strval;
} S3;
struct {TY49547* Sym;
} S4;
struct {TY48011* Ident;
} S5;
struct {TY49519* Sons;
} S6;
} KindU;
};
struct TY49529 {
TNimType* m_type;
NI Counter;
TY49527* Data;
};
struct TY49547 {
  TY48005 Sup;
NU8 Kind;
NU8 Magic;
TY49551* Typ;
TY48011* Name;
TY41532 Info;
TY49547* Owner;
NU32 Flags;
TY49529 Tab;
TY49525* Ast;
NU32 Options;
NI Position;
NI Offset;
TY49539 Loc;
TY49543* Annex;
};
struct TY46008 {
  TNimObject Sup;
TY46008* Left;
TY46008* Right;
NI Length;
NimStringDesc* Data;
};
struct TY48011 {
  TY48005 Sup;
NimStringDesc* S;
TY48011* Next;
NI H;
};
struct TY37013 {
  TNimObject Sup;
TY37013* Prev;
TY37013* Next;
};
struct TY49543 {
  TY37013 Sup;
NU8 Kind;
NIM_BOOL Generated;
TY46008* Name;
TY49525* Path;
};
struct TY49561 {
  TGenericSeq Sup;
  TY49559 data[SEQ_DECL_SIZE];
};
struct TY49549 {
  TGenericSeq Sup;
  TY49551* data[SEQ_DECL_SIZE];
};
struct TY49519 {
  TGenericSeq Sup;
  TY49525* data[SEQ_DECL_SIZE];
};
struct TY49527 {
  TGenericSeq Sup;
  TY49547* data[SEQ_DECL_SIZE];
};
N_NIMCALL(void, Inittypetables_153025)(void);
N_NIMCALL(void, Initidtable_49754)(TY49563* X_49757);
static N_INLINE(NI, addInt)(NI A_5603, NI B_5604);
N_NOINLINE(void, raiseOverflow)(void);
N_NIMCALL(TY49551*, Getuniquetype_153020)(TY49551* Key_153022);
N_NIMCALL(TNimObject*, Idtableget_53166)(TY49563 T_53168, TY48005* Key_53169);
N_NIMCALL(void, chckObj)(TNimType* Obj_5375, TNimType* Subclass_5376);
N_NIMCALL(void, Idtableput_53174)(TY49563* T_53177, TY48005* Key_53178, TNimObject* Val_53179);
N_NIMCALL(TY49551*, Lastson_49812)(TY49551* N_49814);
N_NIMCALL(NIM_BOOL, Idtablehasobjectaskey_53180)(TY49563 T_53182, TY48005* Key_53183);
N_NOINLINE(void, raiseIndexError)(void);
N_NIMCALL(NIM_BOOL, Sametype_91048)(TY49551* X_91050, TY49551* Y_91051);
N_NIMCALL(TNimObject*, Tablegettype_153016)(TY49563 Tab_153018, TY49551* Key_153019);
N_NIMCALL(NimStringDesc*, Tocchar_153007)(NIM_CHAR C_153009);
static N_INLINE(void, appendChar)(NimStringDesc* Dest_17209, NIM_CHAR C_17210);
N_NIMCALL(NimStringDesc*, nsuToOctal)(NIM_CHAR C_23043);
static N_INLINE(void, appendString)(NimStringDesc* Dest_17192, NimStringDesc* Src_17193);
N_NIMCALL(NimStringDesc*, rawNewString)(NI Space_17087);
N_NIMCALL(NimStringDesc*, nimCharToStr)(NIM_CHAR X_17928);
N_NIMCALL(TY46008*, Makecstring_153010)(NimStringDesc* S_153012);
N_NIMCALL(NimStringDesc*, copyString)(NimStringDesc* Src_17108);
static N_INLINE(NI, subInt)(NI A_5803, NI B_5804);
static N_INLINE(NI, modInt)(NI A_6403, NI B_6404);
N_NOINLINE(void, raiseDivByZero)(void);
N_NIMCALL(NimStringDesc*, addChar)(NimStringDesc* S_1603, NIM_CHAR C_1604);
N_NIMCALL(NimStringDesc*, resizeString)(NimStringDesc* Dest_17182, NI Addlen_17183);
N_NIMCALL(void, App_46031)(TY46008** A_46034, TY46008* B_46035);
N_NIMCALL(TY46008*, Torope_46046)(NimStringDesc* S_46048);
N_NIMCALL(NimStringDesc*, setLengthStr)(NimStringDesc* S_17225, NI Newlen_17226);
N_NIMCALL(TY46008*, Makellvmstring_153013)(NimStringDesc* S_153015);
N_NIMCALL(NimStringDesc*, nsuToHex)(NI64 X_23450, NI Len_23451);
STRING_LITERAL(TMP153221, "\"", 1);
STRING_LITERAL(TMP153222, "\015\012", 2);
STRING_LITERAL(TMP153254, "c\"", 2);
STRING_LITERAL(TMP153255, "\\00\"", 4);
TY153023 Gtypetable_153024;
extern TNimType* NTI49551; /* TType */
static N_INLINE(NI, addInt)(NI A_5603, NI B_5604) {
NI Result_5605;
NIM_BOOL LOC2;
Result_5605 = 0;
Result_5605 = (NI32)((NU32)(A_5603) + (NU32)(B_5604));
LOC2 = (0 <= (NI32)(Result_5605 ^ A_5603));
if (LOC2) goto LA3;
LOC2 = (0 <= (NI32)(Result_5605 ^ B_5604));
LA3: ;
if (!LOC2) goto LA4;
goto BeforeRet;
LA4: ;
raiseOverflow();
BeforeRet: ;
return Result_5605;
}
N_NIMCALL(void, Inittypetables_153025)(void) {
NU8 I_153056;
NU8 Res_153060;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "initTypeTables";
F.prev = framePtr;
F.filename = "rod/ccgutils.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
I_153056 = 0;
Res_153060 = 0;
F.line = 1019;F.filename = "system.nim";
Res_153060 = ((NU8) 0);
F.line = 1020;F.filename = "system.nim";
while (1) {
if (!(Res_153060 <= ((NU8) 39))) goto LA1;
F.line = 1019;F.filename = "system.nim";
I_153056 = Res_153060;
F.line = 25;F.filename = "ccgutils.nim";
Initidtable_49754(&Gtypetable_153024[(I_153056)-0]);
F.line = 1022;F.filename = "system.nim";
Res_153060 = addInt(Res_153060, 1);
} LA1: ;
framePtr = framePtr->prev;
}
N_NIMCALL(TY49551*, Getuniquetype_153020)(TY49551* Key_153022) {
TY49551* Result_153066;
TY49551* T_153067;
NU8 K_153068;
TNimObject* LOC4;
TY49551* LOC8;
NIM_BOOL LOC10;
NI H_153114;
NI HEX3Atmp_153128;
NI Res_153130;
NIM_BOOL LOC15;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "GetUniqueType";
F.prev = framePtr;
F.filename = "rod/ccgutils.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_153066 = 0;
T_153067 = 0;
K_153068 = 0;
F.line = 32;F.filename = "ccgutils.nim";
Result_153066 = Key_153022;
F.line = 33;F.filename = "ccgutils.nim";
if (!(Key_153022 == NIM_NIL)) goto LA2;
F.line = 33;F.filename = "ccgutils.nim";
goto BeforeRet;
LA2: ;
F.line = 34;F.filename = "ccgutils.nim";
K_153068 = (*Key_153022).Kind;
F.line = 35;F.filename = "ccgutils.nim";
switch (K_153068) {
case ((NU8) 17):
case ((NU8) 14):
F.line = 63;F.filename = "ccgutils.nim";
LOC4 = 0;
LOC4 = Idtableget_53166(Gtypetable_153024[(K_153068)-0], &Key_153022->Sup);
if (LOC4) chckObj((*LOC4).m_type, NTI49551);
Result_153066 = ((TY49551*) (LOC4));
F.line = 64;F.filename = "ccgutils.nim";
if (!(Result_153066 == NIM_NIL)) goto LA6;
F.line = 65;F.filename = "ccgutils.nim";
Idtableput_53174(&Gtypetable_153024[(K_153068)-0], &Key_153022->Sup, &Key_153022->Sup.Sup);
F.line = 66;F.filename = "ccgutils.nim";
Result_153066 = Key_153022;
LA6: ;
break;
case ((NU8) 11):
case ((NU8) 13):
case ((NU8) 15):
F.line = 68;F.filename = "ccgutils.nim";
LOC8 = 0;
LOC8 = Lastson_49812(Key_153022);
Result_153066 = Getuniquetype_153020(LOC8);
break;
case ((NU8) 25):
break;
default:
F.line = 74;F.filename = "ccgutils.nim";
LOC10 = Idtablehasobjectaskey_53180(Gtypetable_153024[(K_153068)-0], &Key_153022->Sup);
if (!LOC10) goto LA11;
F.line = 74;F.filename = "ccgutils.nim";
goto BeforeRet;
LA11: ;
H_153114 = 0;
HEX3Atmp_153128 = 0;
F.line = 75;F.filename = "ccgutils.nim";
HEX3Atmp_153128 = (Gtypetable_153024[(K_153068)-0].Data->Sup.len-1);
Res_153130 = 0;
F.line = 1019;F.filename = "system.nim";
Res_153130 = 0;
F.line = 1020;F.filename = "system.nim";
while (1) {
if (!(Res_153130 <= HEX3Atmp_153128)) goto LA13;
F.line = 1019;F.filename = "system.nim";
H_153114 = Res_153130;
F.line = 76;F.filename = "ccgutils.nim";
if ((NU)(H_153114) >= (NU)(Gtypetable_153024[(K_153068)-0].Data->Sup.len)) raiseIndexError();
if (Gtypetable_153024[(K_153068)-0].Data->data[H_153114].Key) chckObj((*Gtypetable_153024[(K_153068)-0].Data->data[H_153114].Key).Sup.m_type, NTI49551);
T_153067 = ((TY49551*) (Gtypetable_153024[(K_153068)-0].Data->data[H_153114].Key));
F.line = 77;F.filename = "ccgutils.nim";
LOC15 = !((T_153067 == NIM_NIL));
if (!(LOC15)) goto LA16;
LOC15 = Sametype_91048(T_153067, Key_153022);
LA16: ;
if (!LOC15) goto LA17;
F.line = 78;F.filename = "ccgutils.nim";
F.line = 78;F.filename = "ccgutils.nim";
Result_153066 = T_153067;
goto BeforeRet;
LA17: ;
F.line = 1022;F.filename = "system.nim";
Res_153130 = addInt(Res_153130, 1);
} LA13: ;
F.line = 79;F.filename = "ccgutils.nim";
Idtableput_53174(&Gtypetable_153024[(K_153068)-0], &Key_153022->Sup, &Key_153022->Sup.Sup);
break;
}
BeforeRet: ;
framePtr = framePtr->prev;
return Result_153066;
}
N_NIMCALL(TNimObject*, Tablegettype_153016)(TY49563 Tab_153018, TY49551* Key_153019) {
TNimObject* Result_153137;
TY49551* T_153138;
NIM_BOOL LOC2;
NI H_153159;
NI HEX3Atmp_153172;
NI Res_153174;
NIM_BOOL LOC11;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "TableGetType";
F.prev = framePtr;
F.filename = "rod/ccgutils.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_153137 = 0;
T_153138 = 0;
F.line = 84;F.filename = "ccgutils.nim";
Result_153137 = Idtableget_53166(Tab_153018, &Key_153019->Sup);
F.line = 85;F.filename = "ccgutils.nim";
LOC2 = (Result_153137 == NIM_NIL);
if (!(LOC2)) goto LA3;
LOC2 = (0 < Tab_153018.Counter);
LA3: ;
if (!LOC2) goto LA4;
H_153159 = 0;
HEX3Atmp_153172 = 0;
F.line = 88;F.filename = "ccgutils.nim";
HEX3Atmp_153172 = (Tab_153018.Data->Sup.len-1);
Res_153174 = 0;
F.line = 1019;F.filename = "system.nim";
Res_153174 = 0;
F.line = 1020;F.filename = "system.nim";
while (1) {
if (!(Res_153174 <= HEX3Atmp_153172)) goto LA6;
F.line = 1019;F.filename = "system.nim";
H_153159 = Res_153174;
F.line = 89;F.filename = "ccgutils.nim";
if ((NU)(H_153159) >= (NU)(Tab_153018.Data->Sup.len)) raiseIndexError();
if (Tab_153018.Data->data[H_153159].Key) chckObj((*Tab_153018.Data->data[H_153159].Key).Sup.m_type, NTI49551);
T_153138 = ((TY49551*) (Tab_153018.Data->data[H_153159].Key));
F.line = 90;F.filename = "ccgutils.nim";
if (!!((T_153138 == NIM_NIL))) goto LA8;
F.line = 91;F.filename = "ccgutils.nim";
LOC11 = Sametype_91048(T_153138, Key_153019);
if (!LOC11) goto LA12;
F.line = 92;F.filename = "ccgutils.nim";
F.line = 92;F.filename = "ccgutils.nim";
if ((NU)(H_153159) >= (NU)(Tab_153018.Data->Sup.len)) raiseIndexError();
Result_153137 = Tab_153018.Data->data[H_153159].Val;
goto BeforeRet;
LA12: ;
LA8: ;
F.line = 1022;F.filename = "system.nim";
Res_153174 = addInt(Res_153174, 1);
} LA6: ;
LA4: ;
BeforeRet: ;
framePtr = framePtr->prev;
return Result_153137;
}
static N_INLINE(void, appendChar)(NimStringDesc* Dest_17209, NIM_CHAR C_17210) {
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "appendChar";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/system/sysstr.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
F.line = 154;F.filename = "sysstr.nim";
(*Dest_17209).data[((*Dest_17209).Sup.len)-0] = C_17210;
F.line = 155;F.filename = "sysstr.nim";
(*Dest_17209).data[((NI32)((*Dest_17209).Sup.len + 1))-0] = 0;
F.line = 156;F.filename = "sysstr.nim";
(*Dest_17209).Sup.len += 1;
framePtr = framePtr->prev;
}
static N_INLINE(void, appendString)(NimStringDesc* Dest_17192, NimStringDesc* Src_17193) {
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "appendString";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/system/sysstr.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
F.line = 150;F.filename = "sysstr.nim";
memcpy(((NCSTRING) (&(*Dest_17192).data[((*Dest_17192).Sup.len)-0])), ((NCSTRING) ((*Src_17193).data)), ((NI32) ((NI32)((NI32)((*Src_17193).Sup.len + 1) * 1))));
F.line = 151;F.filename = "sysstr.nim";
(*Dest_17192).Sup.len += (*Src_17193).Sup.len;
framePtr = framePtr->prev;
}
N_NIMCALL(NimStringDesc*, Tocchar_153007)(NIM_CHAR C_153009) {
NimStringDesc* Result_153180;
NimStringDesc* LOC1;
NimStringDesc* LOC2;
NimStringDesc* LOC3;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "toCChar";
F.prev = framePtr;
F.filename = "rod/ccgutils.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_153180 = 0;
F.line = 95;F.filename = "ccgutils.nim";
switch (((NU8)(C_153009))) {
case 0 ... 31:
case 128 ... 255:
F.line = 96;F.filename = "ccgutils.nim";
LOC1 = 0;
LOC2 = 0;
LOC2 = nsuToOctal(C_153009);
LOC1 = rawNewString(LOC2->Sup.len + 1);
appendChar(LOC1, 92);
appendString(LOC1, LOC2);
Result_153180 = LOC1;
break;
case 39:
case 34:
case 92:
F.line = 97;F.filename = "ccgutils.nim";
LOC3 = 0;
LOC3 = rawNewString(2);
appendChar(LOC3, 92);
appendChar(LOC3, C_153009);
Result_153180 = LOC3;
break;
default:
F.line = 98;F.filename = "ccgutils.nim";
Result_153180 = nimCharToStr(C_153009);
break;
}
framePtr = framePtr->prev;
return Result_153180;
}
static N_INLINE(NI, subInt)(NI A_5803, NI B_5804) {
NI Result_5805;
NIM_BOOL LOC2;
Result_5805 = 0;
Result_5805 = (NI32)((NU32)(A_5803) - (NU32)(B_5804));
LOC2 = (0 <= (NI32)(Result_5805 ^ A_5803));
if (LOC2) goto LA3;
LOC2 = (0 <= (NI32)(Result_5805 ^ (NI32)((NU32) ~(B_5804))));
LA3: ;
if (!LOC2) goto LA4;
goto BeforeRet;
LA4: ;
raiseOverflow();
BeforeRet: ;
return Result_5805;
}
static N_INLINE(NI, modInt)(NI A_6403, NI B_6404) {
NI Result_6405;
Result_6405 = 0;
if (!(B_6404 == 0)) goto LA2;
raiseDivByZero();
LA2: ;
Result_6405 = (NI32)(A_6403 % B_6404);
goto BeforeRet;
BeforeRet: ;
return Result_6405;
}
N_NIMCALL(TY46008*, Makecstring_153010)(NimStringDesc* S_153012) {
TY46008* Result_153198;
NimStringDesc* Res_153200;
NI I_153210;
NI HEX3Atmp_153216;
NI Res_153218;
TY46008* LOC5;
NimStringDesc* LOC6;
TY46008* LOC7;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "makeCString";
F.prev = framePtr;
F.filename = "rod/ccgutils.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_153198 = 0;
Res_153200 = 0;
F.line = 107;F.filename = "ccgutils.nim";
Result_153198 = NIM_NIL;
F.line = 108;F.filename = "ccgutils.nim";
Res_153200 = copyString(((NimStringDesc*) &TMP153221));
I_153210 = 0;
HEX3Atmp_153216 = 0;
F.line = 109;F.filename = "ccgutils.nim";
HEX3Atmp_153216 = subInt(addInt(S_153012->Sup.len, 0), 1);
Res_153218 = 0;
F.line = 1019;F.filename = "system.nim";
Res_153218 = 0;
F.line = 1020;F.filename = "system.nim";
while (1) {
if (!(Res_153218 <= HEX3Atmp_153216)) goto LA1;
F.line = 1019;F.filename = "system.nim";
I_153210 = Res_153218;
F.line = 110;F.filename = "ccgutils.nim";
if (!(modInt(addInt(subInt(I_153210, 0), 1), 64) == 0)) goto LA3;
F.line = 111;F.filename = "ccgutils.nim";
Res_153200 = addChar(Res_153200, 34);
F.line = 112;F.filename = "ccgutils.nim";
Res_153200 = resizeString(Res_153200, 2);
appendString(Res_153200, ((NimStringDesc*) &TMP153222));
F.line = 113;F.filename = "ccgutils.nim";
LOC5 = 0;
LOC5 = Torope_46046(Res_153200);
App_46031(&Result_153198, LOC5);
F.line = 114;F.filename = "ccgutils.nim";
Res_153200 = setLengthStr(Res_153200, 1);
F.line = 115;F.filename = "ccgutils.nim";
if ((NU)(0) > (NU)(Res_153200->Sup.len)) raiseIndexError();
Res_153200->data[0] = 34;
LA3: ;
F.line = 116;F.filename = "ccgutils.nim";
if ((NU)(I_153210) > (NU)(S_153012->Sup.len)) raiseIndexError();
LOC6 = 0;
LOC6 = Tocchar_153007(S_153012->data[I_153210]);
Res_153200 = resizeString(Res_153200, LOC6->Sup.len + 0);
appendString(Res_153200, LOC6);
F.line = 1022;F.filename = "system.nim";
Res_153218 = addInt(Res_153218, 1);
} LA1: ;
F.line = 117;F.filename = "ccgutils.nim";
Res_153200 = addChar(Res_153200, 34);
F.line = 118;F.filename = "ccgutils.nim";
LOC7 = 0;
LOC7 = Torope_46046(Res_153200);
App_46031(&Result_153198, LOC7);
framePtr = framePtr->prev;
return Result_153198;
}
N_NIMCALL(TY46008*, Makellvmstring_153013)(NimStringDesc* S_153015) {
TY46008* Result_153226;
NimStringDesc* Res_153228;
NI I_153238;
NI HEX3Atmp_153249;
NI Res_153251;
TY46008* LOC5;
NimStringDesc* LOC6;
TY46008* LOC7;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "makeLLVMString";
F.prev = framePtr;
F.filename = "rod/ccgutils.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_153226 = 0;
Res_153228 = 0;
F.line = 124;F.filename = "ccgutils.nim";
Result_153226 = NIM_NIL;
F.line = 125;F.filename = "ccgutils.nim";
Res_153228 = copyString(((NimStringDesc*) &TMP153254));
I_153238 = 0;
HEX3Atmp_153249 = 0;
F.line = 126;F.filename = "ccgutils.nim";
HEX3Atmp_153249 = subInt(addInt(S_153015->Sup.len, 0), 1);
Res_153251 = 0;
F.line = 1019;F.filename = "system.nim";
Res_153251 = 0;
F.line = 1020;F.filename = "system.nim";
while (1) {
if (!(Res_153251 <= HEX3Atmp_153249)) goto LA1;
F.line = 1019;F.filename = "system.nim";
I_153238 = Res_153251;
F.line = 127;F.filename = "ccgutils.nim";
if (!(modInt(addInt(subInt(I_153238, 0), 1), 64) == 0)) goto LA3;
F.line = 128;F.filename = "ccgutils.nim";
LOC5 = 0;
LOC5 = Torope_46046(Res_153228);
App_46031(&Result_153226, LOC5);
F.line = 129;F.filename = "ccgutils.nim";
Res_153228 = setLengthStr(Res_153228, 0);
LA3: ;
F.line = 130;F.filename = "ccgutils.nim";
if ((NU)(I_153238) > (NU)(S_153015->Sup.len)) raiseIndexError();
switch (((NU8)(S_153015->data[I_153238]))) {
case 0 ... 31:
case 128 ... 255:
case 34:
case 92:
F.line = 132;F.filename = "ccgutils.nim";
Res_153228 = addChar(Res_153228, 92);
F.line = 133;F.filename = "ccgutils.nim";
if ((NU)(I_153238) > (NU)(S_153015->Sup.len)) raiseIndexError();
LOC6 = 0;
LOC6 = nsuToHex(((NI64) (((NU8)(S_153015->data[I_153238])))), 2);
Res_153228 = resizeString(Res_153228, LOC6->Sup.len + 0);
appendString(Res_153228, LOC6);
break;
default:
F.line = 134;F.filename = "ccgutils.nim";
if ((NU)(I_153238) > (NU)(S_153015->Sup.len)) raiseIndexError();
Res_153228 = addChar(Res_153228, S_153015->data[I_153238]);
break;
}
F.line = 1022;F.filename = "system.nim";
Res_153251 = addInt(Res_153251, 1);
} LA1: ;
F.line = 135;F.filename = "ccgutils.nim";
Res_153228 = resizeString(Res_153228, 4);
appendString(Res_153228, ((NimStringDesc*) &TMP153255));
F.line = 136;F.filename = "ccgutils.nim";
LOC7 = 0;
LOC7 = Torope_46046(Res_153228);
App_46031(&Result_153226, LOC7);
framePtr = framePtr->prev;
return Result_153226;
}
N_NOINLINE(void, ccgutilsInit)(void) {
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "ccgutils";
F.prev = framePtr;
F.filename = "rod/ccgutils.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
F.line = 138;F.filename = "ccgutils.nim";
Inittypetables_153025();
framePtr = framePtr->prev;
}

