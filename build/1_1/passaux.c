/* Generated by Nimrod Compiler v0.8.9 */
/*   (c) 2010 Andreas Rumpf */

typedef long int NI;
typedef unsigned long int NU;
#include "nimbase.h"

typedef struct TY99002 TY99002;
typedef struct TY49547 TY49547;
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct TY48005 TY48005;
typedef struct TNimObject TNimObject;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef struct TY49551 TY49551;
typedef struct TY48011 TY48011;
typedef struct TY41532 TY41532;
typedef struct TY49529 TY49529;
typedef struct TY49527 TY49527;
typedef struct TY49525 TY49525;
typedef struct TY49539 TY49539;
typedef struct TY46008 TY46008;
typedef struct TY49543 TY49543;
typedef struct TY49519 TY49519;
typedef struct TY99006 TY99006;
typedef struct TY87031 TY87031;
typedef struct TY10402 TY10402;
typedef struct TY7804 TY7804;
typedef struct TY10790 TY10790;
typedef struct TY10418 TY10418;
typedef struct TY10414 TY10414;
typedef struct TY10410 TY10410;
typedef struct TY10788 TY10788;
typedef struct TY49549 TY49549;
typedef struct TY37013 TY37013;
typedef struct TY4177 TY4177;
typedef struct TY87029 TY87029;
typedef struct TY53223 TY53223;
typedef struct TY53221 TY53221;
typedef struct TY53219 TY53219;
typedef struct TY49563 TY49563;
typedef struct TY49561 TY49561;
typedef struct TY49559 TY49559;
struct TGenericSeq {
NI len;
NI space;
};
typedef NIM_CHAR TY239[100000001];
struct NimStringDesc {
  TGenericSeq Sup;
TY239 data;
};
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
struct TY41532 {
NI16 Line;
NI16 Col;
NI32 Fileindex;
};
struct TY49529 {
TNimType* m_type;
NI Counter;
TY49527* Data;
};
struct TY49539 {
NU8 K;
NU8 S;
NU8 Flags;
TY49551* T;
TY46008* R;
NI A;
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
struct TY48011 {
  TY48005 Sup;
NimStringDesc* S;
TY48011* Next;
NI H;
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
typedef N_NIMCALL_PTR(TY99002*, TY99007) (TY49547* Module_99008, NimStringDesc* Filename_99009);
typedef N_NIMCALL_PTR(TY99002*, TY99012) (TY49547* Module_99013, NimStringDesc* Filename_99014, TY87031* Rd_99015);
typedef N_NIMCALL_PTR(TY49525*, TY99018) (TY99002* P_99019, TY49525* N_99020);
typedef N_NIMCALL_PTR(TY49525*, TY99023) (TY99002* P_99024, TY49525* Toplevelstmt_99025);
struct TY99006 {
TY99007 Open;
TY99012 Opencached;
TY99018 Close;
TY99023 Process;
};
typedef NU8 TY49999[16];
struct TY10402 {
NI Refcount;
TNimType* Typ;
};
typedef N_STDCALL_PTR(void, TY7816) (TY7804* L_7818);
struct TY10418 {
NI Len;
NI Cap;
TY10402** D;
};
struct TY10414 {
NI Counter;
NI Max;
TY10410* Head;
TY10410** Data;
};
struct TY7804 {
void* Debuginfo;
NI32 Lockcount;
NI32 Recursioncount;
NI Owningthread;
NI Locksemaphore;
NI32 Reserved;
};
struct TY10788 {
NI Stackscans;
NI Cyclecollections;
NI Maxthreshold;
NI Maxstacksize;
NI Maxstackcells;
NI Cycletablesize;
};
struct TY10790 {
TY10418 Zct;
TY10418 Decstack;
TY10414 Cycleroots;
TY10418 Tempstack;
TY7804 Cyclerootslock;
TY7804 Zctlock;
TY10788 Stat;
};
typedef N_STDCALL_PTR(void, TY7820) (TY7804* L_7822);
struct TY99002 {
  TNimObject Sup;
};
struct TNimNode {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
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
struct TY46008 {
  TNimObject Sup;
TY46008* Left;
TY46008* Right;
NI Length;
NimStringDesc* Data;
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
struct TY53219 {
NI Key;
NI Val;
};
struct TY53223 {
NI Counter;
TY53221* Data;
};
struct TY87029 {
NI Lastidxkey;
NI Lastidxval;
TY53223 Tab;
TY46008* R;
NI Offset;
};
struct TY49559 {
TY48005* Key;
TNimObject* Val;
};
struct TY49563 {
NI Counter;
TY49561* Data;
};
struct TY87031 {
  TNimObject Sup;
NI Pos;
NimStringDesc* S;
NU32 Options;
NU8 Reason;
TY4177* Moddeps;
TY4177* Files;
NI Dataidx;
NI Convertersidx;
NI Initidx;
NI Interfidx;
NI Compilerprocsidx;
NI Cgenidx;
NimStringDesc* Filename;
TY87029 Index;
TY87029 Imports;
NI Readerindex;
NI Line;
NI Moduleid;
TY49563 Syms;
};
typedef NI TY8414[16];
struct TY10410 {
TY10410* Next;
NI Key;
TY8414 Bits;
};
struct TY49527 {
  TGenericSeq Sup;
  TY49547* data[SEQ_DECL_SIZE];
};
struct TY49519 {
  TGenericSeq Sup;
  TY49525* data[SEQ_DECL_SIZE];
};
struct TY49549 {
  TGenericSeq Sup;
  TY49551* data[SEQ_DECL_SIZE];
};
struct TY4177 {
  TGenericSeq Sup;
  NimStringDesc* data[SEQ_DECL_SIZE];
};
struct TY53221 {
  TGenericSeq Sup;
  TY53219 data[SEQ_DECL_SIZE];
};
struct TY49561 {
  TGenericSeq Sup;
  TY49559 data[SEQ_DECL_SIZE];
};
N_NIMCALL(TY99002*, Verboseopen_182008)(TY49547* S_182010, NimStringDesc* Filename_182011);
N_NIMCALL(void, Rawmessage_41553)(NU8 Msg_41555, NimStringDesc* Arg_41556);
N_NIMCALL(TY49525*, Verboseprocess_182015)(TY99002* Context_182017, TY49525* N_182018);
N_NIMCALL(void, Internalerror_41571)(NimStringDesc* Errmsg_41573);
N_NIMCALL(void, Limessage_41562)(TY41532 Info_41564, NU8 Msg_41565, NimStringDesc* Arg_41566);
N_NIMCALL(NimStringDesc*, nimIntToStr)(NI X_17803);
N_NIMCALL(TY99006, Verbosepass_182004)(void);
N_NIMCALL(void, Initpass_99031)(TY99006* P_99034);
N_NIMCALL(TY49525*, Cleanup_182040)(TY99002* C_182042, TY49525* N_182043);
N_NIMCALL(NI, Sonslen_49803)(TY49525* N_49805);
static N_INLINE(NI, subInt)(NI A_5803, NI B_5804);
N_NOINLINE(void, raiseOverflow)(void);
N_NOINLINE(void, raiseFieldError)(NimStringDesc* F_5275);
N_NOINLINE(void, raiseIndexError)(void);
static N_INLINE(NI, addInt)(NI A_5603, NI B_5604);
N_NIMCALL(TY49547*, Getmodule_53206)(TY49547* S_53208);
N_NIMCALL(NIM_BOOL, Astneeded_99041)(TY49547* S_99043);
static N_INLINE(void, asgnRefNoCycle)(void** Dest_11618, void* Src_11619);
static N_INLINE(TY10402*, Usrtocell_10836)(void* Usr_10838);
static N_INLINE(NI, Atomicinc_2801)(NI* Memloc_2804, NI X_2805);
static N_INLINE(NI, Atomicdec_2806)(NI* Memloc_2809, NI X_2810);
static N_INLINE(void, Rtladdzct_11458)(TY10402* C_11460);
N_NOINLINE(void, Addzct_10825)(TY10418* S_10828, TY10402* C_10829);
N_NIMCALL(TY99006, Cleanuppass_182006)(void);
STRING_LITERAL(TMP182035, "logpass: context is not nil", 27);
static NIM_CONST TY49999 TMP182166 = {
0xEC, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
;STRING_LITERAL(TMP182167, "sons", 4);
static NIM_CONST TY49999 TMP182168 = {
0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
;STRING_LITERAL(TMP182169, "sym", 3);
extern NI Gverbosity_40083;
extern NI Gid_49692;
extern NU32 Gglobaloptions_40077;
extern TY7816 Dl_7815;
extern TY10790 Gch_10810;
extern TY7820 Dl_7819;
N_NIMCALL(TY99002*, Verboseopen_182008)(TY49547* S_182010, NimStringDesc* Filename_182011) {
TY99002* Result_182012;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "verboseOpen";
F.prev = framePtr;
F.filename = "rod/passaux.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_182012 = 0;
F.line = 21;F.filename = "passaux.nim";
Result_182012 = NIM_NIL;
F.line = 22;F.filename = "passaux.nim";
if (!(0 < Gverbosity_40083)) goto LA2;
F.line = 22;F.filename = "passaux.nim";
Rawmessage_41553(((NU8) 230), (*(*S_182010).Name).S);
LA2: ;
framePtr = framePtr->prev;
return Result_182012;
}
N_NIMCALL(TY49525*, Verboseprocess_182015)(TY99002* Context_182017, TY49525* N_182018) {
TY49525* Result_182019;
NimStringDesc* LOC7;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "verboseProcess";
F.prev = framePtr;
F.filename = "rod/passaux.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_182019 = 0;
F.line = 25;F.filename = "passaux.nim";
Result_182019 = N_182018;
F.line = 26;F.filename = "passaux.nim";
if (!!((Context_182017 == NIM_NIL))) goto LA2;
F.line = 26;F.filename = "passaux.nim";
Internalerror_41571(((NimStringDesc*) &TMP182035));
LA2: ;
F.line = 27;F.filename = "passaux.nim";
if (!(Gverbosity_40083 == 3)) goto LA5;
F.line = 27;F.filename = "passaux.nim";
LOC7 = 0;
LOC7 = nimIntToStr(Gid_49692);
Limessage_41562((*N_182018).Info, ((NU8) 230), LOC7);
LA5: ;
framePtr = framePtr->prev;
return Result_182019;
}
N_NIMCALL(TY99006, Verbosepass_182004)(void) {
TY99006 Result_182038;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "verbosePass";
F.prev = framePtr;
F.filename = "rod/passaux.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
memset((void*)&Result_182038, 0, sizeof(Result_182038));
F.line = 30;F.filename = "passaux.nim";
Initpass_99031(&Result_182038);
F.line = 31;F.filename = "passaux.nim";
Result_182038.Open = Verboseopen_182008;
F.line = 32;F.filename = "passaux.nim";
Result_182038.Process = Verboseprocess_182015;
framePtr = framePtr->prev;
return Result_182038;
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
static N_INLINE(TY10402*, Usrtocell_10836)(void* Usr_10838) {
TY10402* Result_10839;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "usrToCell";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/system/gc.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_10839 = 0;
F.line = 100;F.filename = "gc.nim";
Result_10839 = ((TY10402*) ((NI32)((NU32)(((NI) (Usr_10838))) - (NU32)(((NI) (((NI)sizeof(TY10402))))))));
framePtr = framePtr->prev;
return Result_10839;
}
static N_INLINE(NI, Atomicinc_2801)(NI* Memloc_2804, NI X_2805) {
NI Result_7208;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "atomicInc";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/system/systhread.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_7208 = 0;
F.line = 29;F.filename = "systhread.nim";
Result_7208 = __sync_add_and_fetch(Memloc_2804, X_2805);
framePtr = framePtr->prev;
return Result_7208;
}
static N_INLINE(NI, Atomicdec_2806)(NI* Memloc_2809, NI X_2810) {
NI Result_7406;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "atomicDec";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/system/systhread.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_7406 = 0;
F.line = 37;F.filename = "systhread.nim";
Result_7406 = __sync_sub_and_fetch(Memloc_2809, X_2810);
framePtr = framePtr->prev;
return Result_7406;
}
static N_INLINE(void, Rtladdzct_11458)(TY10402* C_11460) {
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "rtlAddZCT";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/system/gc.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
F.line = 211;F.filename = "gc.nim";
if (!NIM_TRUE) goto LA2;
F.line = 211;F.filename = "gc.nim";
Dl_7815(&Gch_10810.Zctlock);
LA2: ;
F.line = 212;F.filename = "gc.nim";
Addzct_10825(&Gch_10810.Zct, C_11460);
F.line = 213;F.filename = "gc.nim";
if (!NIM_TRUE) goto LA5;
F.line = 213;F.filename = "gc.nim";
Dl_7819(&Gch_10810.Zctlock);
LA5: ;
framePtr = framePtr->prev;
}
static N_INLINE(void, asgnRefNoCycle)(void** Dest_11618, void* Src_11619) {
TY10402* C_11620;
NI LOC4;
TY10402* C_11622;
NI LOC9;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "asgnRefNoCycle";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/system/gc.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
F.line = 244;F.filename = "gc.nim";
if (!!((Src_11619 == NIM_NIL))) goto LA2;
C_11620 = 0;
F.line = 245;F.filename = "gc.nim";
C_11620 = Usrtocell_10836(Src_11619);
F.line = 246;F.filename = "gc.nim";
LOC4 = Atomicinc_2801(&(*C_11620).Refcount, 8);
LA2: ;
F.line = 247;F.filename = "gc.nim";
if (!!(((*Dest_11618) == NIM_NIL))) goto LA6;
C_11622 = 0;
F.line = 248;F.filename = "gc.nim";
C_11622 = Usrtocell_10836((*Dest_11618));
F.line = 249;F.filename = "gc.nim";
LOC9 = Atomicdec_2806(&(*C_11622).Refcount, 8);
if (!((NU32)(LOC9) < (NU32)(8))) goto LA10;
F.line = 250;F.filename = "gc.nim";
Rtladdzct_11458(C_11622);
LA10: ;
LA6: ;
F.line = 251;F.filename = "gc.nim";
(*Dest_11618) = Src_11619;
framePtr = framePtr->prev;
}
N_NIMCALL(TY49525*, Cleanup_182040)(TY99002* C_182042, TY49525* N_182043) {
TY49525* Result_182044;
TY49547* S_182045;
NI I_182079;
NI HEX3Atmp_182161;
NI LOC4;
NI Res_182163;
TY49525* LOC6;
NIM_BOOL LOC11;
TY49547* LOC12;
NIM_BOOL LOC14;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "cleanUp";
F.prev = framePtr;
F.filename = "rod/passaux.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_182044 = 0;
S_182045 = 0;
F.line = 36;F.filename = "passaux.nim";
Result_182044 = N_182043;
F.line = 38;F.filename = "passaux.nim";
if (!((Gglobaloptions_40077 &(1<<((((NU8) 4))&31)))!=0)) goto LA2;
F.line = 38;F.filename = "passaux.nim";
goto BeforeRet;
LA2: ;
F.line = 39;F.filename = "passaux.nim";
switch ((*N_182043).Kind) {
case ((NU8) 101):
I_182079 = 0;
HEX3Atmp_182161 = 0;
F.line = 41;F.filename = "passaux.nim";
LOC4 = Sonslen_49803(N_182043);
HEX3Atmp_182161 = subInt(LOC4, 1);
Res_182163 = 0;
F.line = 1019;F.filename = "system.nim";
Res_182163 = 0;
F.line = 1020;F.filename = "system.nim";
while (1) {
if (!(Res_182163 <= HEX3Atmp_182161)) goto LA5;
F.line = 1019;F.filename = "system.nim";
I_182079 = Res_182163;
F.line = 41;F.filename = "passaux.nim";
if (((TMP182166[(*N_182043).Kind/8] &(1<<((*N_182043).Kind%8)))!=0)) raiseFieldError(((NimStringDesc*) &TMP182167));
if ((NU)(I_182079) >= (NU)((*N_182043).KindU.S6.Sons->Sup.len)) raiseIndexError();
LOC6 = 0;
LOC6 = Cleanup_182040(C_182042, (*N_182043).KindU.S6.Sons->data[I_182079]);
F.line = 1022;F.filename = "system.nim";
Res_182163 = addInt(Res_182163, 1);
} LA5: ;
break;
case ((NU8) 69):
case ((NU8) 70):
F.line = 43;F.filename = "passaux.nim";
if (((TMP182166[(*N_182043).Kind/8] &(1<<((*N_182043).Kind%8)))!=0)) raiseFieldError(((NimStringDesc*) &TMP182167));
if ((NU)(0) >= (NU)((*N_182043).KindU.S6.Sons->Sup.len)) raiseIndexError();
if (!((*(*N_182043).KindU.S6.Sons->data[0]).Kind == ((NU8) 3))) goto LA8;
F.line = 44;F.filename = "passaux.nim";
if (((TMP182166[(*N_182043).Kind/8] &(1<<((*N_182043).Kind%8)))!=0)) raiseFieldError(((NimStringDesc*) &TMP182167));
if ((NU)(0) >= (NU)((*N_182043).KindU.S6.Sons->Sup.len)) raiseIndexError();
if (!(((TMP182168[(*(*N_182043).KindU.S6.Sons->data[0]).Kind/8] &(1<<((*(*N_182043).KindU.S6.Sons->data[0]).Kind%8)))!=0))) raiseFieldError(((NimStringDesc*) &TMP182169));
S_182045 = (*(*N_182043).KindU.S6.Sons->data[0]).KindU.S4.Sym;
F.line = 45;F.filename = "passaux.nim";
LOC12 = 0;
LOC12 = Getmodule_53206(S_182045);
LOC11 = !((((*LOC12).Flags &(1<<((((NU8) 28))&31)))!=0));
if (!(LOC11)) goto LA13;
LOC14 = Astneeded_99041(S_182045);
LOC11 = !(LOC14);
LA13: ;
if (!LOC11) goto LA15;
F.line = 46;F.filename = "passaux.nim";
if (((TMP182166[(*(*S_182045).Ast).Kind/8] &(1<<((*(*S_182045).Ast).Kind%8)))!=0)) raiseFieldError(((NimStringDesc*) &TMP182167));
if ((NU)(4) >= (NU)((*(*S_182045).Ast).KindU.S6.Sons->Sup.len)) raiseIndexError();
asgnRefNoCycle((void**) &(*(*S_182045).Ast).KindU.S6.Sons->data[4], NIM_NIL);
LA15: ;
LA8: ;
break;
default:
break;
}
BeforeRet: ;
framePtr = framePtr->prev;
return Result_182044;
}
N_NIMCALL(TY99006, Cleanuppass_182006)(void) {
TY99006 Result_182172;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "cleanupPass";
F.prev = framePtr;
F.filename = "rod/passaux.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
memset((void*)&Result_182172, 0, sizeof(Result_182172));
F.line = 51;F.filename = "passaux.nim";
Initpass_99031(&Result_182172);
F.line = 52;F.filename = "passaux.nim";
Result_182172.Process = Cleanup_182040;
F.line = 53;F.filename = "passaux.nim";
Result_182172.Close = Cleanup_182040;
framePtr = framePtr->prev;
return Result_182172;
}
N_NOINLINE(void, passauxInit)(void) {
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "passaux";
F.prev = framePtr;
F.filename = "rod/passaux.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
framePtr = framePtr->prev;
}

