/* Generated by Nimrod Compiler v0.8.9 */
/*   (c) 2010 Andreas Rumpf */

typedef long long int NI;
typedef unsigned long long int NU;
#include "nimbase.h"

typedef struct TY54525 TY54525;
typedef struct TY54547 TY54547;
typedef struct TY54551 TY54551;
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct TY46532 TY46532;
typedef struct TY53011 TY53011;
typedef struct TY54519 TY54519;
typedef struct TY53005 TY53005;
typedef struct TNimObject TNimObject;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef struct TY54529 TY54529;
typedef struct TY54527 TY54527;
typedef struct TY54539 TY54539;
typedef struct TY51008 TY51008;
typedef struct TY54543 TY54543;
typedef struct TY105012 TY105012;
typedef struct TY58092 TY58092;
typedef struct TY103002 TY103002;
typedef struct TY105006 TY105006;
typedef struct TY58107 TY58107;
typedef struct TY58109 TY58109;
typedef struct TY54900 TY54900;
typedef struct TY54896 TY54896;
typedef struct TY54898 TY54898;
typedef struct TY42019 TY42019;
typedef struct TY42013 TY42013;
typedef struct TY54549 TY54549;
struct TGenericSeq {
NI len;
NI space;
};
typedef NIM_CHAR TY239[100000001];
struct NimStringDesc {
  TGenericSeq Sup;
TY239 data;
};
struct TY46532 {
NI16 Line;
NI16 Col;
int Fileindex;
};
struct TY54525 {
TY54551* Typ;
NimStringDesc* Comment;
TY46532 Info;
NU8 Flags;
NU8 Kind;
union {
struct {NI64 Intval;
} S1;
struct {NF64 Floatval;
} S2;
struct {NimStringDesc* Strval;
} S3;
struct {TY54547* Sym;
} S4;
struct {TY53011* Ident;
} S5;
struct {TY54519* Sons;
} S6;
} KindU;
};
typedef NU8 TY54999[16];
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
struct TY53005 {
  TNimObject Sup;
NI Id;
};
struct TY54529 {
TNimType* m_type;
NI Counter;
TY54527* Data;
};
struct TY54539 {
NU8 K;
NU8 S;
NU8 Flags;
TY54551* T;
TY51008* R;
NI A;
};
struct TY54547 {
  TY53005 Sup;
NU8 Kind;
NU8 Magic;
TY54551* Typ;
TY53011* Name;
TY46532 Info;
TY54547* Owner;
NU32 Flags;
TY54529 Tab;
TY54525* Ast;
NU32 Options;
NI Position;
NI Offset;
TY54539 Loc;
TY54543* Annex;
};
struct TY53011 {
  TY53005 Sup;
NimStringDesc* S;
TY53011* Next;
NI H;
};
struct TY58092 {
NI H;
TY53011* Name;
};
struct TY103002 {
  TNimObject Sup;
};
struct TY58107 {
NI Tos;
TY58109* Stack;
};
struct TY54900 {
NI Counter;
NI Max;
TY54896* Head;
TY54898* Data;
};
struct TY42019 {
TNimType* m_type;
TY42013* Head;
TY42013* Tail;
NI Counter;
};
typedef N_NIMCALL_PTR(TY54525*, TY105032) (TY105012* C_105033, TY54525* N_105034);
typedef N_NIMCALL_PTR(TY54525*, TY105037) (TY105012* C_105038, TY54525* N_105039);
struct TY105012 {
  TY103002 Sup;
TY54547* Module;
TY105006* P;
NI Instcounter;
TY54525* Generics;
NI Lastgenericidx;
TY58107 Tab;
TY54900 Ambiguoussymbols;
TY54527* Converters;
TY42019 Optionstack;
TY42019 Libs;
NIM_BOOL Fromcache;
TY105032 Semconstexpr;
TY105037 Semexpr;
TY54900 Includedfiles;
NimStringDesc* Filename;
TY54529 Userpragmas;
};
struct TY54551 {
  TY53005 Sup;
NU8 Kind;
TY54549* Sons;
TY54525* N;
NU8 Flags;
NU8 Callconv;
TY54547* Owner;
TY54547* Sym;
NI64 Size;
NI Align;
NI Containerid;
TY54539 Loc;
};
struct TNimNode {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
struct TY51008 {
  TNimObject Sup;
TY51008* Left;
TY51008* Right;
NI Length;
NimStringDesc* Data;
};
struct TY42013 {
  TNimObject Sup;
TY42013* Prev;
TY42013* Next;
};
struct TY54543 {
  TY42013 Sup;
NU8 Kind;
NIM_BOOL Generated;
TY51008* Name;
TY54525* Path;
};
struct TY105006 {
TY54547* Owner;
TY54547* Resultsym;
NI Nestedloopcounter;
NI Nestedblockcounter;
};
typedef NI TY8614[8];
struct TY54896 {
TY54896* Next;
NI Key;
TY8614 Bits;
};
struct TY54519 {
  TGenericSeq Sup;
  TY54525* data[SEQ_DECL_SIZE];
};
struct TY54527 {
  TGenericSeq Sup;
  TY54547* data[SEQ_DECL_SIZE];
};
struct TY58109 {
  TGenericSeq Sup;
  TY54529 data[SEQ_DECL_SIZE];
};
struct TY54898 {
  TGenericSeq Sup;
  TY54896* data[SEQ_DECL_SIZE];
};
struct TY54549 {
  TGenericSeq Sup;
  TY54551* data[SEQ_DECL_SIZE];
};
N_NIMCALL(NIM_BOOL, Equalgenericparams_120014)(TY54525* Proca_120016, TY54525* Procb_120017);
N_NIMCALL(NI, Sonslen_54803)(TY54525* N_54805);
static N_INLINE(NI, subInt)(NI A_5803, NI B_5804);
N_NOINLINE(void, raiseOverflow)(void);
N_NOINLINE(void, raiseFieldError)(NimStringDesc* F_5275);
N_NOINLINE(void, raiseIndexError)(void);
N_NIMCALL(void, Internalerror_46567)(TY46532 Info_46569, NimStringDesc* Errmsg_46570);
N_NIMCALL(NIM_BOOL, Sametypeornil_95052)(TY54551* A_95054, TY54551* B_95055);
N_NIMCALL(NIM_BOOL, Exprstructuralequivalent_94035)(TY54525* A_94037, TY54525* B_94038);
static N_INLINE(NI, addInt)(NI A_5603, NI B_5604);
N_NIMCALL(TY54547*, Searchforproc_120004)(TY105012* C_120006, TY54547* Fn_120007, NI Tos_120008);
N_NIMCALL(TY54547*, Initidentiter_58095)(TY58092* Ti_58098, TY54529* Tab_58099, TY53011* S_58100);
N_NIMCALL(NU8, Equalparams_95065)(TY54525* A_95067, TY54525* B_95068);
N_NIMCALL(void, Limessage_46562)(TY46532 Info_46564, NU8 Msg_46565, NimStringDesc* Arg_46566);
N_NIMCALL(TY54547*, Nextidentiter_58101)(TY58092* Ti_58104, TY54529* Tab_58105);
N_NIMCALL(NIM_BOOL, Paramsfitborrow_120256)(TY54525* A_120258, TY54525* B_120259);
N_NIMCALL(void, internalAssert)(NCSTRING File_5054, NI Line_5055, NIM_BOOL Cond_5056);
N_NIMCALL(NIM_BOOL, Equalordistinctof_95056)(TY54551* X_95058, TY54551* Y_95059);
N_NIMCALL(TY54547*, Searchforborrowproc_120009)(TY105012* C_120011, TY54547* Fn_120012, NI Tos_120013);
static NIM_CONST TY54999 TMP120197 = {
0xEC, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
;STRING_LITERAL(TMP120198, "sons", 4);
STRING_LITERAL(TMP120199, "equalGenericParams", 18);
static NIM_CONST TY54999 TMP120200 = {
0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
;STRING_LITERAL(TMP120201, "sym", 3);
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
N_NIMCALL(NIM_BOOL, Equalgenericparams_120014)(TY54525* Proca_120016, TY54525* Procb_120017) {
NIM_BOOL Result_120018;
TY54547* A_120019;
TY54547* B_120020;
NIM_BOOL LOC5;
NI LOC10;
NI LOC11;
NI I_120076;
NI HEX3Atmp_120192;
NI LOC14;
NI Res_120194;
NIM_BOOL LOC23;
NIM_BOOL LOC25;
NIM_BOOL LOC29;
NIM_BOOL LOC34;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "equalGenericParams";
F.prev = framePtr;
F.filename = "rod/procfind.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_120018 = 0;
A_120019 = 0;
B_120020 = 0;
F.line = 26;F.filename = "procfind.nim";
Result_120018 = (Proca_120016 == Procb_120017);
F.line = 27;F.filename = "procfind.nim";
if (!Result_120018) goto LA2;
F.line = 27;F.filename = "procfind.nim";
goto BeforeRet;
LA2: ;
F.line = 28;F.filename = "procfind.nim";
LOC5 = (Proca_120016 == NIM_NIL);
if (LOC5) goto LA6;
LOC5 = (Procb_120017 == NIM_NIL);
LA6: ;
if (!LOC5) goto LA7;
F.line = 28;F.filename = "procfind.nim";
goto BeforeRet;
LA7: ;
F.line = 29;F.filename = "procfind.nim";
LOC10 = Sonslen_54803(Proca_120016);
LOC11 = Sonslen_54803(Procb_120017);
if (!!((LOC10 == LOC11))) goto LA12;
F.line = 29;F.filename = "procfind.nim";
goto BeforeRet;
LA12: ;
I_120076 = 0;
HEX3Atmp_120192 = 0;
F.line = 30;F.filename = "procfind.nim";
LOC14 = Sonslen_54803(Proca_120016);
HEX3Atmp_120192 = subInt(LOC14, 1);
Res_120194 = 0;
F.line = 1019;F.filename = "system.nim";
Res_120194 = 0;
F.line = 1020;F.filename = "system.nim";
while (1) {
if (!(Res_120194 <= HEX3Atmp_120192)) goto LA15;
F.line = 1019;F.filename = "system.nim";
I_120076 = Res_120194;
F.line = 31;F.filename = "procfind.nim";
if (((TMP120197[(*Proca_120016).Kind/8] &(1<<((*Proca_120016).Kind%8)))!=0)) raiseFieldError(((NimStringDesc*) &TMP120198));
if ((NU)(I_120076) >= (NU)((*Proca_120016).KindU.S6.Sons->Sup.len)) raiseIndexError();
if (!!(((*(*Proca_120016).KindU.S6.Sons->data[I_120076]).Kind == ((NU8) 3)))) goto LA17;
F.line = 32;F.filename = "procfind.nim";
Internalerror_46567((*Proca_120016).Info, ((NimStringDesc*) &TMP120199));
LA17: ;
F.line = 33;F.filename = "procfind.nim";
if (((TMP120197[(*Procb_120017).Kind/8] &(1<<((*Procb_120017).Kind%8)))!=0)) raiseFieldError(((NimStringDesc*) &TMP120198));
if ((NU)(I_120076) >= (NU)((*Procb_120017).KindU.S6.Sons->Sup.len)) raiseIndexError();
if (!!(((*(*Procb_120017).KindU.S6.Sons->data[I_120076]).Kind == ((NU8) 3)))) goto LA20;
F.line = 34;F.filename = "procfind.nim";
Internalerror_46567((*Procb_120017).Info, ((NimStringDesc*) &TMP120199));
LA20: ;
F.line = 35;F.filename = "procfind.nim";
if (((TMP120197[(*Proca_120016).Kind/8] &(1<<((*Proca_120016).Kind%8)))!=0)) raiseFieldError(((NimStringDesc*) &TMP120198));
if ((NU)(I_120076) >= (NU)((*Proca_120016).KindU.S6.Sons->Sup.len)) raiseIndexError();
if (!(((TMP120200[(*(*Proca_120016).KindU.S6.Sons->data[I_120076]).Kind/8] &(1<<((*(*Proca_120016).KindU.S6.Sons->data[I_120076]).Kind%8)))!=0))) raiseFieldError(((NimStringDesc*) &TMP120201));
A_120019 = (*(*Proca_120016).KindU.S6.Sons->data[I_120076]).KindU.S4.Sym;
F.line = 36;F.filename = "procfind.nim";
if (((TMP120197[(*Procb_120017).Kind/8] &(1<<((*Procb_120017).Kind%8)))!=0)) raiseFieldError(((NimStringDesc*) &TMP120198));
if ((NU)(I_120076) >= (NU)((*Procb_120017).KindU.S6.Sons->Sup.len)) raiseIndexError();
if (!(((TMP120200[(*(*Procb_120017).KindU.S6.Sons->data[I_120076]).Kind/8] &(1<<((*(*Procb_120017).KindU.S6.Sons->data[I_120076]).Kind%8)))!=0))) raiseFieldError(((NimStringDesc*) &TMP120201));
B_120020 = (*(*Procb_120017).KindU.S6.Sons->data[I_120076]).KindU.S4.Sym;
F.line = 37;F.filename = "procfind.nim";
LOC23 = !(((*(*A_120019).Name).Sup.Id == (*(*B_120020).Name).Sup.Id));
if (LOC23) goto LA24;
LOC25 = Sametypeornil_95052((*A_120019).Typ, (*B_120020).Typ);
LOC23 = !(LOC25);
LA24: ;
if (!LOC23) goto LA26;
F.line = 37;F.filename = "procfind.nim";
goto BeforeRet;
LA26: ;
F.line = 38;F.filename = "procfind.nim";
LOC29 = !(((*A_120019).Ast == NIM_NIL));
if (!(LOC29)) goto LA30;
LOC29 = !(((*B_120020).Ast == NIM_NIL));
LA30: ;
if (!LOC29) goto LA31;
F.line = 39;F.filename = "procfind.nim";
LOC34 = Exprstructuralequivalent_94035((*A_120019).Ast, (*B_120020).Ast);
if (!!(LOC34)) goto LA35;
F.line = 39;F.filename = "procfind.nim";
goto BeforeRet;
LA35: ;
LA31: ;
F.line = 1022;F.filename = "system.nim";
Res_120194 = addInt(Res_120194, 1);
} LA15: ;
F.line = 40;F.filename = "procfind.nim";
Result_120018 = NIM_TRUE;
BeforeRet: ;
framePtr = framePtr->prev;
return Result_120018;
}
N_NIMCALL(TY54547*, Searchforproc_120004)(TY105012* C_120006, TY54547* Fn_120007, NI Tos_120008) {
TY54547* Result_120207;
TY58092 It_120208;
NIM_BOOL LOC6;
NU8 LOC9;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "SearchForProc";
F.prev = framePtr;
F.filename = "rod/procfind.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_120207 = 0;
memset((void*)&It_120208, 0, sizeof(It_120208));
F.line = 44;F.filename = "procfind.nim";
if ((NU)(Tos_120008) >= (NU)((*C_120006).Tab.Stack->Sup.len)) raiseIndexError();
Result_120207 = Initidentiter_58095(&It_120208, &(*C_120006).Tab.Stack->data[Tos_120008], (*Fn_120007).Name);
F.line = 45;F.filename = "procfind.nim";
while (1) {
if (!!((Result_120207 == NIM_NIL))) goto LA1;
F.line = 46;F.filename = "procfind.nim";
if (!((*Result_120207).Kind == (*Fn_120007).Kind)) goto LA3;
F.line = 47;F.filename = "procfind.nim";
if (((TMP120197[(*(*Result_120207).Ast).Kind/8] &(1<<((*(*Result_120207).Ast).Kind%8)))!=0)) raiseFieldError(((NimStringDesc*) &TMP120198));
if ((NU)(1) >= (NU)((*(*Result_120207).Ast).KindU.S6.Sons->Sup.len)) raiseIndexError();
if (((TMP120197[(*(*Fn_120007).Ast).Kind/8] &(1<<((*(*Fn_120007).Ast).Kind%8)))!=0)) raiseFieldError(((NimStringDesc*) &TMP120198));
if ((NU)(1) >= (NU)((*(*Fn_120007).Ast).KindU.S6.Sons->Sup.len)) raiseIndexError();
LOC6 = Equalgenericparams_120014((*(*Result_120207).Ast).KindU.S6.Sons->data[1], (*(*Fn_120007).Ast).KindU.S6.Sons->data[1]);
if (!LOC6) goto LA7;
F.line = 49;F.filename = "procfind.nim";
LOC9 = Equalparams_95065((*(*Result_120207).Typ).N, (*(*Fn_120007).Typ).N);
switch (LOC9) {
case ((NU8) 1):
F.line = 51;F.filename = "procfind.nim";
goto BeforeRet;
break;
case ((NU8) 2):
F.line = 53;F.filename = "procfind.nim";
Limessage_46562((*Fn_120007).Info, ((NU8) 63), (*(*Fn_120007).Name).S);
F.line = 54;F.filename = "procfind.nim";
goto BeforeRet;
break;
case ((NU8) 0):
break;
}
LA7: ;
LA3: ;
F.line = 57;F.filename = "procfind.nim";
if ((NU)(Tos_120008) >= (NU)((*C_120006).Tab.Stack->Sup.len)) raiseIndexError();
Result_120207 = Nextidentiter_58101(&It_120208, &(*C_120006).Tab.Stack->data[Tos_120008]);
} LA1: ;
BeforeRet: ;
framePtr = framePtr->prev;
return Result_120207;
}
N_NIMCALL(NIM_BOOL, Paramsfitborrow_120256)(TY54525* A_120258, TY54525* B_120259) {
NIM_BOOL Result_120260;
NI Length_120261;
TY54547* M_120262;
TY54547* N_120263;
NI LOC2;
NI I_120273;
NI HEX3Atmp_120365;
NI Res_120367;
NIM_BOOL LOC6;
NIM_BOOL LOC9;
NIM_BOOL LOC13;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "paramsFitBorrow";
F.prev = framePtr;
F.filename = "rod/procfind.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_120260 = 0;
Length_120261 = 0;
M_120262 = 0;
N_120263 = 0;
F.line = 63;F.filename = "procfind.nim";
Length_120261 = Sonslen_54803(A_120258);
F.line = 64;F.filename = "procfind.nim";
Result_120260 = NIM_FALSE;
F.line = 65;F.filename = "procfind.nim";
LOC2 = Sonslen_54803(B_120259);
if (!(Length_120261 == LOC2)) goto LA3;
I_120273 = 0;
HEX3Atmp_120365 = 0;
F.line = 66;F.filename = "procfind.nim";
HEX3Atmp_120365 = subInt(Length_120261, 1);
Res_120367 = 0;
F.line = 1019;F.filename = "system.nim";
Res_120367 = 1;
F.line = 1020;F.filename = "system.nim";
while (1) {
if (!(Res_120367 <= HEX3Atmp_120365)) goto LA5;
F.line = 1019;F.filename = "system.nim";
I_120273 = Res_120367;
F.line = 67;F.filename = "procfind.nim";
if (((TMP120197[(*A_120258).Kind/8] &(1<<((*A_120258).Kind%8)))!=0)) raiseFieldError(((NimStringDesc*) &TMP120198));
if ((NU)(I_120273) >= (NU)((*A_120258).KindU.S6.Sons->Sup.len)) raiseIndexError();
if (!(((TMP120200[(*(*A_120258).KindU.S6.Sons->data[I_120273]).Kind/8] &(1<<((*(*A_120258).KindU.S6.Sons->data[I_120273]).Kind%8)))!=0))) raiseFieldError(((NimStringDesc*) &TMP120201));
M_120262 = (*(*A_120258).KindU.S6.Sons->data[I_120273]).KindU.S4.Sym;
F.line = 68;F.filename = "procfind.nim";
if (((TMP120197[(*B_120259).Kind/8] &(1<<((*B_120259).Kind%8)))!=0)) raiseFieldError(((NimStringDesc*) &TMP120198));
if ((NU)(I_120273) >= (NU)((*B_120259).KindU.S6.Sons->Sup.len)) raiseIndexError();
if (!(((TMP120200[(*(*B_120259).KindU.S6.Sons->data[I_120273]).Kind/8] &(1<<((*(*B_120259).KindU.S6.Sons->data[I_120273]).Kind%8)))!=0))) raiseFieldError(((NimStringDesc*) &TMP120201));
N_120263 = (*(*B_120259).KindU.S6.Sons->data[I_120273]).KindU.S4.Sym;
F.line = 69;F.filename = "procfind.nim";
LOC6 = ((*M_120262).Kind == ((NU8) 3));
if (!(LOC6)) goto LA7;
LOC6 = ((*N_120263).Kind == ((NU8) 3));
LA7: ;
internalAssert("rod/procfind.nim", 69, LOC6);
F.line = 70;F.filename = "procfind.nim";
LOC9 = Equalordistinctof_95056((*M_120262).Typ, (*N_120263).Typ);
if (!!(LOC9)) goto LA10;
F.line = 70;F.filename = "procfind.nim";
goto BeforeRet;
LA10: ;
F.line = 1022;F.filename = "system.nim";
Res_120367 = addInt(Res_120367, 1);
} LA5: ;
F.line = 71;F.filename = "procfind.nim";
if (((TMP120197[(*A_120258).Kind/8] &(1<<((*A_120258).Kind%8)))!=0)) raiseFieldError(((NimStringDesc*) &TMP120198));
if ((NU)(0) >= (NU)((*A_120258).KindU.S6.Sons->Sup.len)) raiseIndexError();
if (((TMP120197[(*B_120259).Kind/8] &(1<<((*B_120259).Kind%8)))!=0)) raiseFieldError(((NimStringDesc*) &TMP120198));
if ((NU)(0) >= (NU)((*B_120259).KindU.S6.Sons->Sup.len)) raiseIndexError();
LOC13 = Equalordistinctof_95056((*(*A_120258).KindU.S6.Sons->data[0]).Typ, (*(*B_120259).KindU.S6.Sons->data[0]).Typ);
if (!!(LOC13)) goto LA14;
F.line = 71;F.filename = "procfind.nim";
goto BeforeRet;
LA14: ;
F.line = 72;F.filename = "procfind.nim";
Result_120260 = NIM_TRUE;
LA3: ;
BeforeRet: ;
framePtr = framePtr->prev;
return Result_120260;
}
N_NIMCALL(TY54547*, Searchforborrowproc_120009)(TY105012* C_120011, TY54547* Fn_120012, NI Tos_120013) {
TY54547* Result_120375;
TY58092 It_120376;
NI Scope_120399;
NI Res_120451;
NIM_BOOL LOC4;
NIM_BOOL LOC9;
NIM_BOOL LOC13;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "SearchForBorrowProc";
F.prev = framePtr;
F.filename = "rod/procfind.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_120375 = 0;
memset((void*)&It_120376, 0, sizeof(It_120376));
Scope_120399 = 0;
Res_120451 = 0;
F.line = 1010;F.filename = "system.nim";
Res_120451 = Tos_120013;
F.line = 1011;F.filename = "system.nim";
while (1) {
if (!(0 <= Res_120451)) goto LA1;
F.line = 1010;F.filename = "system.nim";
Scope_120399 = Res_120451;
F.line = 79;F.filename = "procfind.nim";
if ((NU)(Scope_120399) >= (NU)((*C_120011).Tab.Stack->Sup.len)) raiseIndexError();
Result_120375 = Initidentiter_58095(&It_120376, &(*C_120011).Tab.Stack->data[Scope_120399], (*Fn_120012).Name);
F.line = 80;F.filename = "procfind.nim";
while (1) {
if (!!((Result_120375 == NIM_NIL))) goto LA2;
F.line = 82;F.filename = "procfind.nim";
LOC4 = ((*Result_120375).Kind == (*Fn_120012).Kind);
if (!(LOC4)) goto LA5;
LOC4 = !(((*Result_120375).Sup.Id == (*Fn_120012).Sup.Id));
LA5: ;
if (!LOC4) goto LA6;
F.line = 83;F.filename = "procfind.nim";
if (((TMP120197[(*(*Result_120375).Ast).Kind/8] &(1<<((*(*Result_120375).Ast).Kind%8)))!=0)) raiseFieldError(((NimStringDesc*) &TMP120198));
if ((NU)(1) >= (NU)((*(*Result_120375).Ast).KindU.S6.Sons->Sup.len)) raiseIndexError();
if (((TMP120197[(*(*Fn_120012).Ast).Kind/8] &(1<<((*(*Fn_120012).Ast).Kind%8)))!=0)) raiseFieldError(((NimStringDesc*) &TMP120198));
if ((NU)(1) >= (NU)((*(*Fn_120012).Ast).KindU.S6.Sons->Sup.len)) raiseIndexError();
LOC9 = Equalgenericparams_120014((*(*Result_120375).Ast).KindU.S6.Sons->data[1], (*(*Fn_120012).Ast).KindU.S6.Sons->data[1]);
if (!LOC9) goto LA10;
F.line = 85;F.filename = "procfind.nim";
LOC13 = Paramsfitborrow_120256((*(*Fn_120012).Typ).N, (*(*Result_120375).Typ).N);
if (!LOC13) goto LA14;
F.line = 85;F.filename = "procfind.nim";
goto BeforeRet;
LA14: ;
LA10: ;
LA6: ;
F.line = 86;F.filename = "procfind.nim";
if ((NU)(Scope_120399) >= (NU)((*C_120011).Tab.Stack->Sup.len)) raiseIndexError();
Result_120375 = Nextidentiter_58101(&It_120376, &(*C_120011).Tab.Stack->data[Scope_120399]);
} LA2: ;
F.line = 1013;F.filename = "system.nim";
Res_120451 = subInt(Res_120451, 1);
} LA1: ;
BeforeRet: ;
framePtr = framePtr->prev;
return Result_120375;
}
N_NOINLINE(void, procfindInit)(void) {
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "procfind";
F.prev = framePtr;
F.filename = "rod/procfind.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
framePtr = framePtr->prev;
}

