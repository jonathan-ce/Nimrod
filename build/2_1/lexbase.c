/* Generated by Nimrod Compiler v0.8.9 */
/*   (c) 2010 Andreas Rumpf */

typedef long int NI;
typedef unsigned long int NU;
#include "nimbase.h"

typedef struct TY74015 TY74015;
typedef struct TNimObject TNimObject;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef struct TY73013 TY73013;
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef NU8 TY21402[32];
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
struct TY74015 {
  TNimObject Sup;
NI Bufpos;
NCSTRING Buf;
NI Buflen;
TY73013* Stream;
NI Linenumber;
NI Sentinel;
NI Linestart;
};
struct TGenericSeq {
NI len;
NI space;
};
typedef NIM_CHAR TY239[100000001];
struct NimStringDesc {
  TGenericSeq Sup;
TY239 data;
};
struct TNimNode {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
struct TY73013 {
  TNimObject Sup;
NU8 Kind;
FILE* F;
NimStringDesc* S;
NI Rd;
NI Wr;
};
N_NIMCALL(void, Closebaselexer_74029)(TY74015* L_74032);
N_NOCONV(void, Dealloc_1784)(void* P_1786);
N_NIMCALL(void, Llstreamclose_73040)(TY73013* S_73042);
N_NIMCALL(void, Fillbuffer_74056)(TY74015* L_74059);
N_NIMCALL(void, internalAssert)(NCSTRING File_5054, NI Line_5055, NIM_BOOL Cond_5056);
static N_INLINE(NI, subInt)(NI A_5803, NI B_5804);
N_NOINLINE(void, raiseOverflow)(void);
static N_INLINE(NI, addInt)(NI A_5603, NI B_5604);
N_NIMCALL(NI, mulInt)(NI A_6603, NI B_6604);
N_NIMCALL(NI, Llstreamread_73043)(TY73013* S_73045, void* Buf_73046, NI Buflen_73047);
static N_INLINE(NI, divInt)(NI A_6203, NI B_6204);
N_NOINLINE(void, raiseDivByZero)(void);
N_NOCONV(void*, Realloc_1780)(void* P_1782, NI Newsize_1783);
N_NIMCALL(NI, Fillbaselexer_74122)(TY74015* L_74125, NI Pos_74126);
N_NIMCALL(NI, Handlecr_74041)(TY74015* L_74044, NI Pos_74045);
N_NIMCALL(NI, Handlelf_74046)(TY74015* L_74049, NI Pos_74050);
N_NIMCALL(void, Skiputf8bom_74174)(TY74015* L_74177);
N_NIMCALL(void, Openbaselexer_74023)(TY74015* L_74026, TY73013* Inputstream_74027, NI Buflen_74028);
N_NOCONV(void*, Alloc_1774)(NI Size_1776);
N_NIMCALL(void, unsureAsgnRef)(void** Dest_11826, void* Src_11827);
N_NIMCALL(NI, Getcolnumber_74037)(TY74015* L_74039, NI Pos_74040);
N_NIMCALL(NimStringDesc*, Getcurrentline_74033)(TY74015* L_74035, NIM_BOOL Marker_74036);
N_NIMCALL(NimStringDesc*, copyString)(NimStringDesc* Src_17308);
N_NIMCALL(NimStringDesc*, addChar)(NimStringDesc* S_1603, NIM_CHAR C_1604);
static N_INLINE(void, appendString)(NimStringDesc* Dest_17392, NimStringDesc* Src_17393);
N_NIMCALL(NimStringDesc*, rawNewString)(NI Space_17287);
N_NIMCALL(NimStringDesc*, nsuRepeatChar)(NI Count_24750, NIM_CHAR C_24751);
NIM_CONST TY21402 Newlines_74012 = {
0x00, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
;
STRING_LITERAL(TMP74280, "", 0);
STRING_LITERAL(TMP74281, "\012", 1);
STRING_LITERAL(TMP74282, "^\012", 2);
N_NIMCALL(void, Closebaselexer_74029)(TY74015* L_74032) {
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "closeBaseLexer";
F.prev = framePtr;
F.filename = "rod/lexbase.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
F.line = 71;F.filename = "lexbase.nim";
Dealloc_1784(((void*) ((*L_74032).Buf)));
F.line = 72;F.filename = "lexbase.nim";
Llstreamclose_73040((*L_74032).Stream);
framePtr = framePtr->prev;
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
static N_INLINE(NI, divInt)(NI A_6203, NI B_6204) {
NI Result_6205;
NIM_BOOL LOC5;
Result_6205 = 0;
if (!(B_6204 == 0)) goto LA2;
raiseDivByZero();
LA2: ;
LOC5 = (A_6203 == (-2147483647 -1));
if (!(LOC5)) goto LA6;
LOC5 = (B_6204 == -1);
LA6: ;
if (!LOC5) goto LA7;
raiseOverflow();
LA7: ;
Result_6205 = (NI32)(A_6203 / B_6204);
goto BeforeRet;
BeforeRet: ;
return Result_6205;
}
N_NIMCALL(void, Fillbuffer_74056)(TY74015* L_74059) {
NI Charsread_74060;
NI Tocopy_74061;
NI S_74062;
NI Oldbuflen_74063;
NI LOC4;
NIM_BOOL LOC10;
void* LOC15;
NI LOC16;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "FillBuffer";
F.prev = framePtr;
F.filename = "rod/lexbase.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Charsread_74060 = 0;
Tocopy_74061 = 0;
S_74062 = 0;
Oldbuflen_74063 = 0;
F.line = 82;F.filename = "lexbase.nim";
internalAssert("rod/lexbase.nim", 82, ((*L_74059).Sentinel < (*L_74059).Buflen));
F.line = 83;F.filename = "lexbase.nim";
Tocopy_74061 = subInt(subInt((*L_74059).Buflen, (*L_74059).Sentinel), 1);
F.line = 84;F.filename = "lexbase.nim";
internalAssert("rod/lexbase.nim", 84, (0 <= Tocopy_74061));
F.line = 85;F.filename = "lexbase.nim";
if (!(0 < Tocopy_74061)) goto LA2;
F.line = 86;F.filename = "lexbase.nim";
memmove(((void*) ((*L_74059).Buf)), ((void*) (&(*L_74059).Buf[addInt((*L_74059).Sentinel, 1)])), mulInt(Tocopy_74061, 1));
LA2: ;
F.line = 88;F.filename = "lexbase.nim";
LOC4 = Llstreamread_73043((*L_74059).Stream, ((void*) (&(*L_74059).Buf[Tocopy_74061])), mulInt(addInt((*L_74059).Sentinel, 1), 1));
Charsread_74060 = divInt(LOC4, 1);
F.line = 90;F.filename = "lexbase.nim";
S_74062 = addInt(Tocopy_74061, Charsread_74060);
F.line = 91;F.filename = "lexbase.nim";
if (!(Charsread_74060 < addInt((*L_74059).Sentinel, 1))) goto LA6;
F.line = 92;F.filename = "lexbase.nim";
(*L_74059).Buf[S_74062] = 0;
F.line = 93;F.filename = "lexbase.nim";
(*L_74059).Sentinel = S_74062;
goto LA5;
LA6: ;
F.line = 96;F.filename = "lexbase.nim";
S_74062 = subInt(S_74062, 1);
F.line = 97;F.filename = "lexbase.nim";
while (1) {
F.line = 98;F.filename = "lexbase.nim";
internalAssert("rod/lexbase.nim", 98, (S_74062 < (*L_74059).Buflen));
F.line = 99;F.filename = "lexbase.nim";
while (1) {
LOC10 = (0 <= S_74062);
if (!(LOC10)) goto LA11;
LOC10 = !((((NU8)((*L_74059).Buf[S_74062])) == ((NU8)(13)) || ((NU8)((*L_74059).Buf[S_74062])) == ((NU8)(10))));
LA11: ;
if (!LOC10) goto LA9;
F.line = 99;F.filename = "lexbase.nim";
S_74062 = subInt(S_74062, 1);
} LA9: ;
F.line = 100;F.filename = "lexbase.nim";
if (!(0 <= S_74062)) goto LA13;
F.line = 102;F.filename = "lexbase.nim";
(*L_74059).Sentinel = S_74062;
F.line = 103;F.filename = "lexbase.nim";
goto LA8;
goto LA12;
LA13: ;
F.line = 107;F.filename = "lexbase.nim";
Oldbuflen_74063 = (*L_74059).Buflen;
F.line = 108;F.filename = "lexbase.nim";
(*L_74059).Buflen = mulInt((*L_74059).Buflen, 2);
F.line = 109;F.filename = "lexbase.nim";
LOC15 = Realloc_1780(((void*) ((*L_74059).Buf)), mulInt((*L_74059).Buflen, 1));
(*L_74059).Buf = ((NCSTRING) (LOC15));
F.line = 110;F.filename = "lexbase.nim";
internalAssert("rod/lexbase.nim", 110, (subInt((*L_74059).Buflen, Oldbuflen_74063) == Oldbuflen_74063));
F.line = 111;F.filename = "lexbase.nim";
LOC16 = Llstreamread_73043((*L_74059).Stream, ((void*) (&(*L_74059).Buf[Oldbuflen_74063])), mulInt(Oldbuflen_74063, 1));
Charsread_74060 = divInt(LOC16, 1);
F.line = 113;F.filename = "lexbase.nim";
if (!(Charsread_74060 < Oldbuflen_74063)) goto LA18;
F.line = 114;F.filename = "lexbase.nim";
(*L_74059).Buf[addInt(Oldbuflen_74063, Charsread_74060)] = 0;
F.line = 115;F.filename = "lexbase.nim";
(*L_74059).Sentinel = addInt(Oldbuflen_74063, Charsread_74060);
F.line = 116;F.filename = "lexbase.nim";
goto LA8;
LA18: ;
F.line = 117;F.filename = "lexbase.nim";
S_74062 = subInt((*L_74059).Buflen, 1);
LA12: ;
} LA8: ;
LA5: ;
framePtr = framePtr->prev;
}
N_NIMCALL(NI, Fillbaselexer_74122)(TY74015* L_74125, NI Pos_74126) {
NI Result_74127;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "fillBaseLexer";
F.prev = framePtr;
F.filename = "rod/lexbase.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_74127 = 0;
F.line = 120;F.filename = "lexbase.nim";
internalAssert("rod/lexbase.nim", 120, (Pos_74126 <= (*L_74125).Sentinel));
F.line = 121;F.filename = "lexbase.nim";
if (!(Pos_74126 < (*L_74125).Sentinel)) goto LA2;
F.line = 122;F.filename = "lexbase.nim";
Result_74127 = addInt(Pos_74126, 1);
goto LA1;
LA2: ;
F.line = 124;F.filename = "lexbase.nim";
Fillbuffer_74056(L_74125);
F.line = 125;F.filename = "lexbase.nim";
(*L_74125).Bufpos = 0;
F.line = 126;F.filename = "lexbase.nim";
Result_74127 = 0;
LA1: ;
F.line = 127;F.filename = "lexbase.nim";
(*L_74125).Linestart = Result_74127;
framePtr = framePtr->prev;
return Result_74127;
}
N_NIMCALL(NI, Handlecr_74041)(TY74015* L_74044, NI Pos_74045) {
NI Result_74137;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "HandleCR";
F.prev = framePtr;
F.filename = "rod/lexbase.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_74137 = 0;
F.line = 130;F.filename = "lexbase.nim";
internalAssert("rod/lexbase.nim", 130, ((NU8)((*L_74044).Buf[Pos_74045]) == (NU8)(13)));
F.line = 131;F.filename = "lexbase.nim";
(*L_74044).Linenumber = addInt((*L_74044).Linenumber, 1);
F.line = 132;F.filename = "lexbase.nim";
Result_74137 = Fillbaselexer_74122(L_74044, Pos_74045);
F.line = 133;F.filename = "lexbase.nim";
if (!((NU8)((*L_74044).Buf[Result_74137]) == (NU8)(10))) goto LA2;
F.line = 134;F.filename = "lexbase.nim";
Result_74137 = Fillbaselexer_74122(L_74044, Result_74137);
LA2: ;
framePtr = framePtr->prev;
return Result_74137;
}
N_NIMCALL(NI, Handlelf_74046)(TY74015* L_74049, NI Pos_74050) {
NI Result_74159;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "HandleLF";
F.prev = framePtr;
F.filename = "rod/lexbase.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_74159 = 0;
F.line = 137;F.filename = "lexbase.nim";
internalAssert("rod/lexbase.nim", 137, ((NU8)((*L_74049).Buf[Pos_74050]) == (NU8)(10)));
F.line = 138;F.filename = "lexbase.nim";
(*L_74049).Linenumber = addInt((*L_74049).Linenumber, 1);
F.line = 139;F.filename = "lexbase.nim";
Result_74159 = Fillbaselexer_74122(L_74049, Pos_74050);
framePtr = framePtr->prev;
return Result_74159;
}
N_NIMCALL(void, Skiputf8bom_74174)(TY74015* L_74177) {
NIM_BOOL LOC2;
NIM_BOOL LOC3;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "skip_UTF_8_BOM";
F.prev = framePtr;
F.filename = "rod/lexbase.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
F.line = 142;F.filename = "lexbase.nim";
LOC3 = ((NU8)((*L_74177).Buf[0]) == (NU8)(239));
if (!(LOC3)) goto LA4;
LOC3 = ((NU8)((*L_74177).Buf[1]) == (NU8)(187));
LA4: ;
LOC2 = LOC3;
if (!(LOC2)) goto LA5;
LOC2 = ((NU8)((*L_74177).Buf[2]) == (NU8)(191));
LA5: ;
if (!LOC2) goto LA6;
F.line = 143;F.filename = "lexbase.nim";
(*L_74177).Bufpos = addInt((*L_74177).Bufpos, 3);
F.line = 144;F.filename = "lexbase.nim";
(*L_74177).Linestart = addInt((*L_74177).Linestart, 3);
LA6: ;
framePtr = framePtr->prev;
}
N_NIMCALL(void, Openbaselexer_74023)(TY74015* L_74026, TY73013* Inputstream_74027, NI Buflen_74028) {
void* LOC1;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "openBaseLexer";
F.prev = framePtr;
F.filename = "rod/lexbase.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
F.line = 147;F.filename = "lexbase.nim";
internalAssert("rod/lexbase.nim", 147, (0 < Buflen_74028));
F.line = 148;F.filename = "lexbase.nim";
(*L_74026).Bufpos = 0;
F.line = 149;F.filename = "lexbase.nim";
(*L_74026).Buflen = Buflen_74028;
F.line = 150;F.filename = "lexbase.nim";
LOC1 = Alloc_1774(mulInt(Buflen_74028, 1));
(*L_74026).Buf = ((NCSTRING) (LOC1));
F.line = 151;F.filename = "lexbase.nim";
(*L_74026).Sentinel = subInt(Buflen_74028, 1);
F.line = 152;F.filename = "lexbase.nim";
(*L_74026).Linestart = 0;
F.line = 153;F.filename = "lexbase.nim";
(*L_74026).Linenumber = 1;
F.line = 154;F.filename = "lexbase.nim";
unsureAsgnRef((void**) &(*L_74026).Stream, Inputstream_74027);
F.line = 155;F.filename = "lexbase.nim";
Fillbuffer_74056(L_74026);
F.line = 156;F.filename = "lexbase.nim";
Skiputf8bom_74174(L_74026);
framePtr = framePtr->prev;
}
N_NIMCALL(NI, Getcolnumber_74037)(TY74015* L_74039, NI Pos_74040) {
NI Result_74220;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "getColNumber";
F.prev = framePtr;
F.filename = "rod/lexbase.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_74220 = 0;
F.line = 159;F.filename = "lexbase.nim";
if (subInt(Pos_74040, (*L_74039).Linestart) == (-2147483647 -1)) raiseOverflow();
Result_74220 = (NI32)abs(subInt(Pos_74040, (*L_74039).Linestart));
framePtr = framePtr->prev;
return Result_74220;
}
static N_INLINE(void, appendString)(NimStringDesc* Dest_17392, NimStringDesc* Src_17393) {
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "appendString";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/system/sysstr.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
F.line = 150;F.filename = "sysstr.nim";
memcpy(((NCSTRING) (&(*Dest_17392).data[((*Dest_17392).Sup.len)-0])), ((NCSTRING) ((*Src_17393).data)), ((int) ((NI32)((NI32)((*Src_17393).Sup.len + 1) * 1))));
F.line = 151;F.filename = "sysstr.nim";
(*Dest_17392).Sup.len += (*Src_17393).Sup.len;
framePtr = framePtr->prev;
}
N_NIMCALL(NimStringDesc*, Getcurrentline_74033)(TY74015* L_74035, NIM_BOOL Marker_74036) {
NimStringDesc* Result_74225;
NI I_74226;
NimStringDesc* LOC2;
NimStringDesc* LOC6;
NI LOC7;
NimStringDesc* LOC8;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "getCurrentLine";
F.prev = framePtr;
F.filename = "rod/lexbase.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_74225 = 0;
F.line = 162;F.filename = "lexbase.nim";
Result_74225 = copyString(((NimStringDesc*) &TMP74280));
I_74226 = 0;
F.line = 163;F.filename = "lexbase.nim";
I_74226 = (*L_74035).Linestart;
F.line = 164;F.filename = "lexbase.nim";
while (1) {
if (!!((((NU8)((*L_74035).Buf[I_74226])) == ((NU8)(13)) || ((NU8)((*L_74035).Buf[I_74226])) == ((NU8)(10)) || ((NU8)((*L_74035).Buf[I_74226])) == ((NU8)(0))))) goto LA1;
F.line = 165;F.filename = "lexbase.nim";
Result_74225 = addChar(Result_74225, (*L_74035).Buf[I_74226]);
F.line = 166;F.filename = "lexbase.nim";
I_74226 = addInt(I_74226, 1);
} LA1: ;
F.line = 167;F.filename = "lexbase.nim";
LOC2 = 0;
LOC2 = rawNewString(Result_74225->Sup.len + 1);
appendString(LOC2, Result_74225);
appendString(LOC2, ((NimStringDesc*) &TMP74281));
Result_74225 = LOC2;
F.line = 168;F.filename = "lexbase.nim";
if (!Marker_74036) goto LA4;
F.line = 169;F.filename = "lexbase.nim";
LOC6 = 0;
LOC7 = Getcolnumber_74037(L_74035, (*L_74035).Bufpos);
LOC8 = 0;
LOC8 = nsuRepeatChar(LOC7, 32);
LOC6 = rawNewString(Result_74225->Sup.len + LOC8->Sup.len + 2);
appendString(LOC6, Result_74225);
appendString(LOC6, LOC8);
appendString(LOC6, ((NimStringDesc*) &TMP74282));
Result_74225 = LOC6;
LA4: ;
framePtr = framePtr->prev;
return Result_74225;
}
N_NOINLINE(void, lexbaseInit)(void) {
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "lexbase";
F.prev = framePtr;
F.filename = "rod/lexbase.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
framePtr = framePtr->prev;
}

