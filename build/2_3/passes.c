/* Generated by Nimrod Compiler v0.8.9 */
/*   (c) 2010 Andreas Rumpf */

typedef long int NI;
typedef unsigned long int NU;
#include "nimbase.h"

typedef struct TY54547 TY54547;
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct TY54525 TY54525;
typedef struct TY53005 TY53005;
typedef struct TNimObject TNimObject;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef struct TY54551 TY54551;
typedef struct TY53011 TY53011;
typedef struct TY46532 TY46532;
typedef struct TY54529 TY54529;
typedef struct TY54527 TY54527;
typedef struct TY54539 TY54539;
typedef struct TY51008 TY51008;
typedef struct TY54543 TY54543;
typedef struct TY54549 TY54549;
typedef struct TY54519 TY54519;
typedef struct TY103006 TY103006;
typedef struct TY103002 TY103002;
typedef struct TY91031 TY91031;
typedef struct TY73013 TY73013;
typedef struct TY90028 TY90028;
typedef struct TY79011 TY79011;
typedef struct TY75267 TY75267;
typedef struct TY75263 TY75263;
typedef struct TY42013 TY42013;
typedef struct TY4177 TY4177;
typedef struct TY91029 TY91029;
typedef struct TY58223 TY58223;
typedef struct TY58221 TY58221;
typedef struct TY58219 TY58219;
typedef struct TY54563 TY54563;
typedef struct TY54561 TY54561;
typedef struct TY54559 TY54559;
typedef struct TY74015 TY74015;
typedef struct TY75434 TY75434;
struct TGenericSeq {
NI len;
NI space;
};
typedef NIM_CHAR TY239[100000001];
struct NimStringDesc {
  TGenericSeq Sup;
TY239 data;
};
typedef N_NIMCALL_PTR(TY54547*, TY103044) (NimStringDesc* Filename_103045);
typedef N_NIMCALL_PTR(TY54525*, TY103048) (NimStringDesc* Filename_103049);
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
struct TY46532 {
NI16 Line;
NI16 Col;
int Fileindex;
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
typedef N_NIMCALL_PTR(TY103002*, TY103007) (TY54547* Module_103008, NimStringDesc* Filename_103009);
typedef N_NIMCALL_PTR(TY103002*, TY103012) (TY54547* Module_103013, NimStringDesc* Filename_103014, TY91031* Rd_103015);
typedef N_NIMCALL_PTR(TY54525*, TY103018) (TY103002* P_103019, TY54525* N_103020);
typedef N_NIMCALL_PTR(TY54525*, TY103023) (TY103002* P_103024, TY54525* Toplevelstmt_103025);
struct TY103006 {
TY103007 Open;
TY103012 Opencached;
TY103018 Close;
TY103023 Process;
};
typedef TY103006 TY103130[10];
struct TY79011 {
TY75267* Lex;
TY75263* Tok;
};
struct TY90028 {
NU8 Skin;
TY79011 Parser;
};
typedef TY103002* TY103128[10];
struct TY73013 {
  TNimObject Sup;
NU8 Kind;
FILE* F;
NimStringDesc* S;
NI Rd;
NI Wr;
};
struct TNimNode {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
struct TY53011 {
  TY53005 Sup;
NimStringDesc* S;
TY53011* Next;
NI H;
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
struct TY103002 {
  TNimObject Sup;
};
struct TY58219 {
NI Key;
NI Val;
};
struct TY58223 {
NI Counter;
TY58221* Data;
};
struct TY91029 {
NI Lastidxkey;
NI Lastidxval;
TY58223 Tab;
TY51008* R;
NI Offset;
};
struct TY54559 {
TY53005* Key;
TNimObject* Val;
};
struct TY54563 {
NI Counter;
TY54561* Data;
};
struct TY91031 {
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
TY91029 Index;
TY91029 Imports;
NI Readerindex;
NI Line;
NI Moduleid;
TY54563 Syms;
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
struct TY75267 {
  TY74015 Sup;
NimStringDesc* Filename;
TY75434* Indentstack;
NI Dedent;
NI Indentahead;
};
struct TY75263 {
TNimType* m_type;
NU8 Toktype;
NI Indent;
TY53011* Ident;
NI64 Inumber;
NF64 Fnumber;
NU8 Base;
NimStringDesc* Literal;
TY75263* Next;
};
struct TY54527 {
  TGenericSeq Sup;
  TY54547* data[SEQ_DECL_SIZE];
};
struct TY54549 {
  TGenericSeq Sup;
  TY54551* data[SEQ_DECL_SIZE];
};
struct TY54519 {
  TGenericSeq Sup;
  TY54525* data[SEQ_DECL_SIZE];
};
struct TY4177 {
  TGenericSeq Sup;
  NimStringDesc* data[SEQ_DECL_SIZE];
};
struct TY58221 {
  TGenericSeq Sup;
  TY58219 data[SEQ_DECL_SIZE];
};
struct TY54561 {
  TGenericSeq Sup;
  TY54559 data[SEQ_DECL_SIZE];
};
struct TY75434 {
  TGenericSeq Sup;
  NI data[SEQ_DECL_SIZE];
};
N_NIMCALL(NIM_BOOL, Astneeded_103041)(TY54547* S_103043);
N_NOINLINE(void, raiseFieldError)(NimStringDesc* F_5275);
N_NOINLINE(void, raiseIndexError)(void);
N_NIMCALL(void, Registerpass_103028)(TY103006* P_103030);
static N_INLINE(NI, addInt)(NI A_5603, NI B_5604);
N_NOINLINE(void, raiseOverflow)(void);
N_NIMCALL(void, Openpasses_103149)(TY103002** A_103152, TY54547* Module_103153, NimStringDesc* Filename_103154);
static N_INLINE(NI, subInt)(NI A_5803, NI B_5804);
N_NIMCALL(void, Openpassescached_103184)(TY103002** A_103187, TY54547* Module_103188, NimStringDesc* Filename_103189, TY91031* Rd_103190);
N_NIMCALL(void, Closepasses_103205)(TY103002** A_103208);
N_NIMCALL(void, Processtoplevelstmt_103224)(TY54525* N_103226, TY103002** A_103228);
N_NIMCALL(void, Processtoplevelstmtcached_103244)(TY54525* N_103246, TY103002** A_103248);
N_NIMCALL(void, Closepassescached_103264)(TY103002** A_103267);
N_NIMCALL(void, Processmodule_103035)(TY54547* Module_103037, NimStringDesc* Filename_103038, TY73013* Stream_103039, TY91031* Rd_103040);
N_NIMCALL(TY73013*, Llstreamopen_73032)(NimStringDesc* Filename_73034, NU8 Mode_73035);
N_NIMCALL(void, Rawmessage_46553)(NU8 Msg_46555, NimStringDesc* Arg_46556);
N_NIMCALL(void, Openparsers_90034)(TY90028* P_90037, NimStringDesc* Filename_90038, TY73013* Inputstream_90039);
N_NIMCALL(TY54525*, Parsetoplevelstmt_90048)(TY90028* P_90051);
N_NIMCALL(void, Closeparsers_90040)(TY90028* P_90043);
N_NIMCALL(void, Idsynchronizationpoint_54698)(NI Idrange_54700);
N_NIMCALL(TY54525*, Loadinitsection_91067)(TY91031* R_91069);
N_NIMCALL(NI, Sonslen_54803)(TY54525* N_54805);
N_NIMCALL(void, Initpass_103031)(TY103006* P_103034);
static NIM_CONST TY54999 TMP103124 = {
0xEC, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
;STRING_LITERAL(TMP103125, "sons", 4);
TY103044 Gimportmodule_103047;
TY103048 Gincludefile_103051;
TY103130 Gpasses_103132;
NI Gpasseslen_103133;
N_NIMCALL(NIM_BOOL, Astneeded_103041)(TY54547* S_103043) {
NIM_BOOL Result_103055;
NIM_BOOL LOC2;
NIM_BOOL LOC3;
NIM_BOOL LOC4;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "astNeeded";
F.prev = framePtr;
F.filename = "rod/passes.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_103055 = 0;
F.line = 54;F.filename = "passes.nim";
LOC4 = ((393216 &(1<<(((*S_103043).Kind)&31)))!=0);
if (!(LOC4)) goto LA5;
LOC4 = ((2050 & (*S_103043).Flags) == 0);
LA5: ;
LOC3 = LOC4;
if (!(LOC3)) goto LA6;
LOC3 = !(((*(*S_103043).Typ).Callconv == ((NU8) 5)));
LA6: ;
LOC2 = LOC3;
if (!(LOC2)) goto LA7;
if (((TMP103124[(*(*S_103043).Ast).Kind/8] &(1<<((*(*S_103043).Ast).Kind%8)))!=0)) raiseFieldError(((NimStringDesc*) &TMP103125));
if ((NU)(1) >= (NU)((*(*S_103043).Ast).KindU.S6.Sons->Sup.len)) raiseIndexError();
LOC2 = ((*(*S_103043).Ast).KindU.S6.Sons->data[1] == NIM_NIL);
LA7: ;
if (!LOC2) goto LA8;
F.line = 57;F.filename = "passes.nim";
Result_103055 = NIM_FALSE;
goto LA1;
LA8: ;
F.line = 59;F.filename = "passes.nim";
Result_103055 = NIM_TRUE;
LA1: ;
framePtr = framePtr->prev;
return Result_103055;
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
N_NIMCALL(void, Registerpass_103028)(TY103006* P_103030) {
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "registerPass";
F.prev = framePtr;
F.filename = "rod/passes.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
F.line = 72;F.filename = "passes.nim";
if ((NU)(Gpasseslen_103133) > (NU)(9)) raiseIndexError();
Gpasses_103132[(Gpasseslen_103133)-0] = (*P_103030);
F.line = 73;F.filename = "passes.nim";
Gpasseslen_103133 = addInt(Gpasseslen_103133, 1);
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
N_NIMCALL(void, Openpasses_103149)(TY103002** A_103152, TY54547* Module_103153, NimStringDesc* Filename_103154) {
NI I_103177;
NI HEX3Atmp_103179;
NI Res_103181;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "openPasses";
F.prev = framePtr;
F.filename = "rod/passes.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
I_103177 = 0;
HEX3Atmp_103179 = 0;
F.line = 76;F.filename = "passes.nim";
HEX3Atmp_103179 = subInt(Gpasseslen_103133, 1);
Res_103181 = 0;
F.line = 1019;F.filename = "system.nim";
Res_103181 = 0;
F.line = 1020;F.filename = "system.nim";
while (1) {
if (!(Res_103181 <= HEX3Atmp_103179)) goto LA1;
F.line = 1019;F.filename = "system.nim";
I_103177 = Res_103181;
F.line = 77;F.filename = "passes.nim";
if ((NU)(I_103177) > (NU)(9)) raiseIndexError();
if (!!(((void*) (Gpasses_103132[(I_103177)-0].Open)) == 0)) goto LA3;
F.line = 77;F.filename = "passes.nim";
if ((NU)(I_103177) > (NU)(9)) raiseIndexError();
if ((NU)(I_103177) > (NU)(9)) raiseIndexError();
A_103152[(I_103177)-0] = Gpasses_103132[(I_103177)-0].Open(Module_103153, Filename_103154);
goto LA2;
LA3: ;
F.line = 78;F.filename = "passes.nim";
if ((NU)(I_103177) > (NU)(9)) raiseIndexError();
A_103152[(I_103177)-0] = NIM_NIL;
LA2: ;
F.line = 1022;F.filename = "system.nim";
Res_103181 = addInt(Res_103181, 1);
} LA1: ;
framePtr = framePtr->prev;
}
N_NIMCALL(void, Openpassescached_103184)(TY103002** A_103187, TY54547* Module_103188, NimStringDesc* Filename_103189, TY91031* Rd_103190) {
NI I_103198;
NI HEX3Atmp_103200;
NI Res_103202;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "openPassesCached";
F.prev = framePtr;
F.filename = "rod/passes.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
I_103198 = 0;
HEX3Atmp_103200 = 0;
F.line = 82;F.filename = "passes.nim";
HEX3Atmp_103200 = subInt(Gpasseslen_103133, 1);
Res_103202 = 0;
F.line = 1019;F.filename = "system.nim";
Res_103202 = 0;
F.line = 1020;F.filename = "system.nim";
while (1) {
if (!(Res_103202 <= HEX3Atmp_103200)) goto LA1;
F.line = 1019;F.filename = "system.nim";
I_103198 = Res_103202;
F.line = 83;F.filename = "passes.nim";
if ((NU)(I_103198) > (NU)(9)) raiseIndexError();
if (!!(((void*) (Gpasses_103132[(I_103198)-0].Opencached)) == 0)) goto LA3;
F.line = 84;F.filename = "passes.nim";
if ((NU)(I_103198) > (NU)(9)) raiseIndexError();
if ((NU)(I_103198) > (NU)(9)) raiseIndexError();
A_103187[(I_103198)-0] = Gpasses_103132[(I_103198)-0].Opencached(Module_103188, Filename_103189, Rd_103190);
goto LA2;
LA3: ;
F.line = 86;F.filename = "passes.nim";
if ((NU)(I_103198) > (NU)(9)) raiseIndexError();
A_103187[(I_103198)-0] = NIM_NIL;
LA2: ;
F.line = 1022;F.filename = "system.nim";
Res_103202 = addInt(Res_103202, 1);
} LA1: ;
framePtr = framePtr->prev;
}
N_NIMCALL(void, Closepasses_103205)(TY103002** A_103208) {
TY54525* M_103209;
NI I_103217;
NI HEX3Atmp_103219;
NI Res_103221;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "closePasses";
F.prev = framePtr;
F.filename = "rod/passes.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
M_103209 = 0;
F.line = 89;F.filename = "passes.nim";
M_103209 = NIM_NIL;
I_103217 = 0;
HEX3Atmp_103219 = 0;
F.line = 90;F.filename = "passes.nim";
HEX3Atmp_103219 = subInt(Gpasseslen_103133, 1);
Res_103221 = 0;
F.line = 1019;F.filename = "system.nim";
Res_103221 = 0;
F.line = 1020;F.filename = "system.nim";
while (1) {
if (!(Res_103221 <= HEX3Atmp_103219)) goto LA1;
F.line = 1019;F.filename = "system.nim";
I_103217 = Res_103221;
F.line = 91;F.filename = "passes.nim";
if ((NU)(I_103217) > (NU)(9)) raiseIndexError();
if (!!(((void*) (Gpasses_103132[(I_103217)-0].Close)) == 0)) goto LA3;
F.line = 91;F.filename = "passes.nim";
if ((NU)(I_103217) > (NU)(9)) raiseIndexError();
if ((NU)(I_103217) > (NU)(9)) raiseIndexError();
M_103209 = Gpasses_103132[(I_103217)-0].Close(A_103208[(I_103217)-0], M_103209);
LA3: ;
F.line = 92;F.filename = "passes.nim";
if ((NU)(I_103217) > (NU)(9)) raiseIndexError();
A_103208[(I_103217)-0] = NIM_NIL;
F.line = 1022;F.filename = "system.nim";
Res_103221 = addInt(Res_103221, 1);
} LA1: ;
framePtr = framePtr->prev;
}
N_NIMCALL(void, Processtoplevelstmt_103224)(TY54525* N_103226, TY103002** A_103228) {
TY54525* M_103229;
NI I_103237;
NI HEX3Atmp_103239;
NI Res_103241;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "processTopLevelStmt";
F.prev = framePtr;
F.filename = "rod/passes.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
M_103229 = 0;
F.line = 96;F.filename = "passes.nim";
M_103229 = N_103226;
I_103237 = 0;
HEX3Atmp_103239 = 0;
F.line = 97;F.filename = "passes.nim";
HEX3Atmp_103239 = subInt(Gpasseslen_103133, 1);
Res_103241 = 0;
F.line = 1019;F.filename = "system.nim";
Res_103241 = 0;
F.line = 1020;F.filename = "system.nim";
while (1) {
if (!(Res_103241 <= HEX3Atmp_103239)) goto LA1;
F.line = 1019;F.filename = "system.nim";
I_103237 = Res_103241;
F.line = 98;F.filename = "passes.nim";
if ((NU)(I_103237) > (NU)(9)) raiseIndexError();
if (!!(((void*) (Gpasses_103132[(I_103237)-0].Process)) == 0)) goto LA3;
F.line = 98;F.filename = "passes.nim";
if ((NU)(I_103237) > (NU)(9)) raiseIndexError();
if ((NU)(I_103237) > (NU)(9)) raiseIndexError();
M_103229 = Gpasses_103132[(I_103237)-0].Process(A_103228[(I_103237)-0], M_103229);
LA3: ;
F.line = 1022;F.filename = "system.nim";
Res_103241 = addInt(Res_103241, 1);
} LA1: ;
framePtr = framePtr->prev;
}
N_NIMCALL(void, Processtoplevelstmtcached_103244)(TY54525* N_103246, TY103002** A_103248) {
TY54525* M_103249;
NI I_103257;
NI HEX3Atmp_103259;
NI Res_103261;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "processTopLevelStmtCached";
F.prev = framePtr;
F.filename = "rod/passes.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
M_103249 = 0;
F.line = 102;F.filename = "passes.nim";
M_103249 = N_103246;
I_103257 = 0;
HEX3Atmp_103259 = 0;
F.line = 103;F.filename = "passes.nim";
HEX3Atmp_103259 = subInt(Gpasseslen_103133, 1);
Res_103261 = 0;
F.line = 1019;F.filename = "system.nim";
Res_103261 = 0;
F.line = 1020;F.filename = "system.nim";
while (1) {
if (!(Res_103261 <= HEX3Atmp_103259)) goto LA1;
F.line = 1019;F.filename = "system.nim";
I_103257 = Res_103261;
F.line = 104;F.filename = "passes.nim";
if ((NU)(I_103257) > (NU)(9)) raiseIndexError();
if (!!(((void*) (Gpasses_103132[(I_103257)-0].Opencached)) == 0)) goto LA3;
F.line = 104;F.filename = "passes.nim";
if ((NU)(I_103257) > (NU)(9)) raiseIndexError();
if ((NU)(I_103257) > (NU)(9)) raiseIndexError();
M_103249 = Gpasses_103132[(I_103257)-0].Process(A_103248[(I_103257)-0], M_103249);
LA3: ;
F.line = 1022;F.filename = "system.nim";
Res_103261 = addInt(Res_103261, 1);
} LA1: ;
framePtr = framePtr->prev;
}
N_NIMCALL(void, Closepassescached_103264)(TY103002** A_103267) {
TY54525* M_103268;
NI I_103276;
NI HEX3Atmp_103278;
NI Res_103280;
NIM_BOOL LOC3;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "closePassesCached";
F.prev = framePtr;
F.filename = "rod/passes.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
M_103268 = 0;
F.line = 107;F.filename = "passes.nim";
M_103268 = NIM_NIL;
I_103276 = 0;
HEX3Atmp_103278 = 0;
F.line = 108;F.filename = "passes.nim";
HEX3Atmp_103278 = subInt(Gpasseslen_103133, 1);
Res_103280 = 0;
F.line = 1019;F.filename = "system.nim";
Res_103280 = 0;
F.line = 1020;F.filename = "system.nim";
while (1) {
if (!(Res_103280 <= HEX3Atmp_103278)) goto LA1;
F.line = 1019;F.filename = "system.nim";
I_103276 = Res_103280;
F.line = 109;F.filename = "passes.nim";
if ((NU)(I_103276) > (NU)(9)) raiseIndexError();
LOC3 = !(((void*) (Gpasses_103132[(I_103276)-0].Opencached)) == 0);
if (!(LOC3)) goto LA4;
if ((NU)(I_103276) > (NU)(9)) raiseIndexError();
LOC3 = !(((void*) (Gpasses_103132[(I_103276)-0].Close)) == 0);
LA4: ;
if (!LOC3) goto LA5;
F.line = 110;F.filename = "passes.nim";
if ((NU)(I_103276) > (NU)(9)) raiseIndexError();
if ((NU)(I_103276) > (NU)(9)) raiseIndexError();
M_103268 = Gpasses_103132[(I_103276)-0].Close(A_103267[(I_103276)-0], M_103268);
LA5: ;
F.line = 111;F.filename = "passes.nim";
if ((NU)(I_103276) > (NU)(9)) raiseIndexError();
A_103267[(I_103276)-0] = NIM_NIL;
F.line = 1022;F.filename = "system.nim";
Res_103280 = addInt(Res_103280, 1);
} LA1: ;
framePtr = framePtr->prev;
}
N_NIMCALL(void, Processmodule_103035)(TY54547* Module_103037, NimStringDesc* Filename_103038, TY73013* Stream_103039, TY91031* Rd_103040) {
TY90028 P_103289;
TY54525* N_103290;
TY103128 A_103291;
TY73013* S_103292;
NI I_103360;
NI HEX3Atmp_103378;
NI LOC18;
NI Res_103380;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "processModule";
F.prev = framePtr;
F.filename = "rod/passes.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
memset((void*)&P_103289, 0, sizeof(P_103289));
N_103290 = 0;
memset((void*)&A_103291, 0, sizeof(A_103291));
S_103292 = 0;
F.line = 120;F.filename = "passes.nim";
if (!(Rd_103040 == NIM_NIL)) goto LA2;
F.line = 121;F.filename = "passes.nim";
Openpasses_103149(A_103291, Module_103037, Filename_103038);
F.line = 122;F.filename = "passes.nim";
if (!(Stream_103039 == NIM_NIL)) goto LA5;
F.line = 123;F.filename = "passes.nim";
S_103292 = Llstreamopen_73032(Filename_103038, ((NU8) 0));
F.line = 124;F.filename = "passes.nim";
if (!(S_103292 == NIM_NIL)) goto LA8;
F.line = 125;F.filename = "passes.nim";
Rawmessage_46553(((NU8) 2), Filename_103038);
F.line = 126;F.filename = "passes.nim";
goto BeforeRet;
LA8: ;
goto LA4;
LA5: ;
F.line = 128;F.filename = "passes.nim";
S_103292 = Stream_103039;
LA4: ;
F.line = 129;F.filename = "passes.nim";
while (1) {
F.line = 130;F.filename = "passes.nim";
Openparsers_90034(&P_103289, Filename_103038, S_103292);
F.line = 131;F.filename = "passes.nim";
while (1) {
F.line = 132;F.filename = "passes.nim";
N_103290 = Parsetoplevelstmt_90048(&P_103289);
F.line = 133;F.filename = "passes.nim";
if (!(N_103290 == NIM_NIL)) goto LA13;
F.line = 133;F.filename = "passes.nim";
goto LA11;
LA13: ;
F.line = 134;F.filename = "passes.nim";
Processtoplevelstmt_103224(N_103290, A_103291);
} LA11: ;
F.line = 135;F.filename = "passes.nim";
Closeparsers_90040(&P_103289);
F.line = 136;F.filename = "passes.nim";
if (!!(((*S_103292).Kind == ((NU8) 3)))) goto LA16;
F.line = 136;F.filename = "passes.nim";
goto LA10;
LA16: ;
} LA10: ;
F.line = 137;F.filename = "passes.nim";
Closepasses_103205(A_103291);
F.line = 139;F.filename = "passes.nim";
Idsynchronizationpoint_54698(1000);
goto LA1;
LA2: ;
F.line = 141;F.filename = "passes.nim";
Openpassescached_103184(A_103291, Module_103037, Filename_103038, Rd_103040);
F.line = 142;F.filename = "passes.nim";
N_103290 = Loadinitsection_91067(Rd_103040);
I_103360 = 0;
HEX3Atmp_103378 = 0;
F.line = 143;F.filename = "passes.nim";
LOC18 = Sonslen_54803(N_103290);
HEX3Atmp_103378 = subInt(LOC18, 1);
Res_103380 = 0;
F.line = 1019;F.filename = "system.nim";
Res_103380 = 0;
F.line = 1020;F.filename = "system.nim";
while (1) {
if (!(Res_103380 <= HEX3Atmp_103378)) goto LA19;
F.line = 1019;F.filename = "system.nim";
I_103360 = Res_103380;
F.line = 143;F.filename = "passes.nim";
if (((TMP103124[(*N_103290).Kind/8] &(1<<((*N_103290).Kind%8)))!=0)) raiseFieldError(((NimStringDesc*) &TMP103125));
if ((NU)(I_103360) >= (NU)((*N_103290).KindU.S6.Sons->Sup.len)) raiseIndexError();
Processtoplevelstmtcached_103244((*N_103290).KindU.S6.Sons->data[I_103360], A_103291);
F.line = 1022;F.filename = "system.nim";
Res_103380 = addInt(Res_103380, 1);
} LA19: ;
F.line = 144;F.filename = "passes.nim";
Closepassescached_103264(A_103291);
LA1: ;
BeforeRet: ;
framePtr = framePtr->prev;
}
N_NIMCALL(void, Initpass_103031)(TY103006* P_103034) {
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "initPass";
F.prev = framePtr;
F.filename = "rod/passes.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
F.line = 147;F.filename = "passes.nim";
(*P_103034).Open = NIM_NIL;
F.line = 148;F.filename = "passes.nim";
(*P_103034).Opencached = NIM_NIL;
F.line = 149;F.filename = "passes.nim";
(*P_103034).Close = NIM_NIL;
F.line = 150;F.filename = "passes.nim";
(*P_103034).Process = NIM_NIL;
framePtr = framePtr->prev;
}
N_NOINLINE(void, passesInit)(void) {
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "passes";
F.prev = framePtr;
F.filename = "rod/passes.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
framePtr = framePtr->prev;
}

