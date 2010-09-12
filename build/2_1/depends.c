/* Generated by Nimrod Compiler v0.8.9 */
/*   (c) 2010 Andreas Rumpf */

typedef long int NI;
typedef unsigned long int NU;
#include "nimbase.h"

#include <pthread.h>
typedef struct TY51008 TY51008;
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct TY54525 TY54525;
typedef struct TY103002 TY103002;
typedef struct TY187010 TY187010;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef struct TY54551 TY54551;
typedef struct TY46532 TY46532;
typedef struct TY54547 TY54547;
typedef struct TY53011 TY53011;
typedef struct TY54519 TY54519;
typedef struct TY37715 TY37715;
typedef struct TNimObject TNimObject;
typedef struct TY53005 TY53005;
typedef struct TY54529 TY54529;
typedef struct TY54527 TY54527;
typedef struct TY54539 TY54539;
typedef struct TY54543 TY54543;
typedef struct TY10602 TY10602;
typedef struct TY10990 TY10990;
typedef struct TY10618 TY10618;
typedef struct TY10614 TY10614;
typedef struct TY10610 TY10610;
typedef struct TY10988 TY10988;
typedef struct TY103006 TY103006;
typedef struct TY91031 TY91031;
typedef struct TY54549 TY54549;
typedef struct TY42013 TY42013;
typedef struct TY4177 TY4177;
typedef struct TY91029 TY91029;
typedef struct TY58223 TY58223;
typedef struct TY58221 TY58221;
typedef struct TY58219 TY58219;
typedef struct TY54563 TY54563;
typedef struct TY54561 TY54561;
typedef struct TY54559 TY54559;
struct TGenericSeq {
NI len;
NI space;
};
typedef NIM_CHAR TY239[100000001];
struct NimStringDesc {
  TGenericSeq Sup;
TY239 data;
};
typedef TY51008* TY58695[2];
struct TNimType {
NI size;
NU8 kind;
NU8 flags;
TNimType* base;
TNimNode* node;
void* finalizer;
};
struct TNimNode {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
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
struct TY37715 {
NimStringDesc* Dir;
NimStringDesc* Name;
NimStringDesc* Ext;
};
typedef NU8 TY54999[16];
struct TNimObject {
TNimType* m_type;
};
struct TY103002 {
  TNimObject Sup;
};
struct TY187010 {
  TY103002 Sup;
TY54547* Module;
NimStringDesc* Filename;
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
struct TY10602 {
NI Refcount;
TNimType* Typ;
};
struct TY10618 {
NI Len;
NI Cap;
TY10602** D;
};
struct TY10614 {
NI Counter;
NI Max;
TY10610* Head;
TY10610** Data;
};
struct TY10988 {
NI Stackscans;
NI Cyclecollections;
NI Maxthreshold;
NI Maxstacksize;
NI Maxstackcells;
NI Cycletablesize;
};
struct TY10990 {
TY10618 Zct;
TY10618 Decstack;
TY10614 Cycleroots;
TY10618 Tempstack;
NI Cyclerootslock;
NI Zctlock;
TY10988 Stat;
};
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
struct TY51008 {
  TNimObject Sup;
TY51008* Left;
TY51008* Right;
NI Length;
NimStringDesc* Data;
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
typedef NI TY8614[16];
struct TY10610 {
TY10610* Next;
NI Key;
TY8614 Bits;
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
struct TY54519 {
  TGenericSeq Sup;
  TY54525* data[SEQ_DECL_SIZE];
};
struct TY54527 {
  TGenericSeq Sup;
  TY54547* data[SEQ_DECL_SIZE];
};
struct TY54549 {
  TGenericSeq Sup;
  TY54551* data[SEQ_DECL_SIZE];
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
N_NIMCALL(void, Adddependencyaux_187016)(NimStringDesc* Importing_187018, NimStringDesc* Imported_187019);
N_NIMCALL(void, Appf_51074)(TY51008** C_51077, NimStringDesc* Frmt_51078, TY51008** Args_51080, NI Args_51080Len0);
N_NIMCALL(TY51008*, Torope_51046)(NimStringDesc* S_51048);
N_NIMCALL(TY54525*, Adddotdependency_187026)(TY103002* C_187028, TY54525* N_187029);
N_NIMCALL(void, chckObj)(TNimType* Obj_5375, TNimType* Subclass_5376);
N_NIMCALL(NI, Sonslen_54803)(TY54525* N_54805);
static N_INLINE(NI, subInt)(NI A_5803, NI B_5804);
N_NOINLINE(void, raiseOverflow)(void);
N_NIMCALL(void, nossplitFile)(NimStringDesc* Path_37714, TY37715* Result);
N_NIMCALL(NimStringDesc*, Getmodulefile_108013)(TY54525* N_108015);
N_NOINLINE(void, raiseFieldError)(NimStringDesc* F_5275);
N_NOINLINE(void, raiseIndexError)(void);
N_NIMCALL(NimStringDesc*, copyString)(NimStringDesc* Src_17308);
static N_INLINE(NI, addInt)(NI A_5603, NI B_5604);
N_NIMCALL(void, Generatedot_187006)(NimStringDesc* Project_187008);
N_NIMCALL(void, Writerope_51058)(TY51008* Head_51060, NimStringDesc* Filename_51061);
N_NIMCALL(TY51008*, Ropef_51069)(NimStringDesc* Frmt_51071, TY51008** Args_51073, NI Args_51073Len0);
N_NIMCALL(NimStringDesc*, nosChangeFileExt)(NimStringDesc* Filename_38020, NimStringDesc* Ext_38021);
N_NIMCALL(NimStringDesc*, nosextractFilename)(NimStringDesc* Path_37785);
N_NIMCALL(TY103002*, Myopen_187137)(TY54547* Module_187139, NimStringDesc* Filename_187140);
N_NIMCALL(void*, newObj)(TNimType* Typ_12307, NI Size_12308);
static N_INLINE(void, asgnRef)(void** Dest_11814, void* Src_11815);
static N_INLINE(void, Incref_11802)(TY10602* C_11804);
static N_INLINE(NI, Atomicinc_2801)(NI* Memloc_2804, NI X_2805);
static N_INLINE(NIM_BOOL, Canbecycleroot_11040)(TY10602* C_11042);
static N_INLINE(void, Rtladdcycleroot_11652)(TY10602* C_11654);
N_NOINLINE(void, Incl_10874)(TY10614* S_10877, TY10602* Cell_10878);
static N_INLINE(TY10602*, Usrtocell_11036)(void* Usr_11038);
static N_INLINE(void, Decref_11664)(TY10602* C_11666);
static N_INLINE(NI, Atomicdec_2806)(NI* Memloc_2809, NI X_2810);
static N_INLINE(void, Rtladdzct_11658)(TY10602* C_11660);
N_NOINLINE(void, Addzct_11025)(TY10618* S_11028, TY10602* C_11029);
static N_INLINE(void, asgnRefNoCycle)(void** Dest_11818, void* Src_11819);
N_NIMCALL(TY103006, Gendependpass_187004)(void);
N_NIMCALL(void, Initpass_103031)(TY103006* P_103034);
STRING_LITERAL(TMP187025, "$1 -> $2;$n", 11);
static NIM_CONST TY54999 TMP187125 = {
0xEC, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
;STRING_LITERAL(TMP187126, "sons", 4);
STRING_LITERAL(TMP187134, "digraph $1 {$n$2}$n", 19);
STRING_LITERAL(TMP187135, "", 0);
STRING_LITERAL(TMP187136, "dot", 3);
TY51008* Gdotgraph_187015;
extern TNimType* NTI187010; /* TGen */
extern TNimType* NTI187012; /* PGen */
extern TY10990 Gch_11010;
N_NIMCALL(void, Adddependencyaux_187016)(NimStringDesc* Importing_187018, NimStringDesc* Imported_187019) {
TY58695 LOC1;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "addDependencyAux";
F.prev = framePtr;
F.filename = "rod/depends.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
F.line = 27;F.filename = "depends.nim";
memset((void*)&LOC1, 0, sizeof(LOC1));
LOC1[0] = Torope_51046(Importing_187018);
LOC1[1] = Torope_51046(Imported_187019);
Appf_51074(&Gdotgraph_187015, ((NimStringDesc*) &TMP187025), LOC1, 2);
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
N_NIMCALL(TY54525*, Adddotdependency_187026)(TY103002* C_187028, TY54525* N_187029) {
TY54525* Result_187030;
TY187010* G_187042;
NI I_187065;
NI HEX3Atmp_187113;
NI LOC4;
NI Res_187115;
NimStringDesc* Imported_187078;
NimStringDesc* LOC6;
TY37715 LOC7;
NimStringDesc* Imported_187091;
NimStringDesc* LOC8;
TY37715 LOC9;
NI I_187099;
NI HEX3Atmp_187119;
NI LOC10;
NI Res_187121;
TY54525* LOC12;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "addDotDependency";
F.prev = framePtr;
F.filename = "rod/depends.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_187030 = 0;
F.line = 31;F.filename = "depends.nim";
Result_187030 = N_187029;
F.line = 32;F.filename = "depends.nim";
if (!(N_187029 == NIM_NIL)) goto LA2;
F.line = 32;F.filename = "depends.nim";
goto BeforeRet;
LA2: ;
G_187042 = 0;
F.line = 33;F.filename = "depends.nim";
if (C_187028) chckObj((*C_187028).Sup.m_type, NTI187010);
G_187042 = ((TY187010*) (C_187028));
F.line = 34;F.filename = "depends.nim";
switch ((*N_187029).Kind) {
case ((NU8) 102):
I_187065 = 0;
HEX3Atmp_187113 = 0;
F.line = 36;F.filename = "depends.nim";
LOC4 = Sonslen_54803(N_187029);
HEX3Atmp_187113 = subInt(LOC4, 1);
Res_187115 = 0;
F.line = 1019;F.filename = "system.nim";
Res_187115 = 0;
F.line = 1020;F.filename = "system.nim";
while (1) {
if (!(Res_187115 <= HEX3Atmp_187113)) goto LA5;
F.line = 1019;F.filename = "system.nim";
I_187065 = Res_187115;
Imported_187078 = 0;
F.line = 37;F.filename = "depends.nim";
if (((TMP187125[(*N_187029).Kind/8] &(1<<((*N_187029).Kind%8)))!=0)) raiseFieldError(((NimStringDesc*) &TMP187126));
if ((NU)(I_187065) >= (NU)((*N_187029).KindU.S6.Sons->Sup.len)) raiseIndexError();
LOC6 = 0;
LOC6 = Getmodulefile_108013((*N_187029).KindU.S6.Sons->data[I_187065]);
memset((void*)&LOC7, 0, sizeof(LOC7));
nossplitFile(LOC6, &LOC7);
Imported_187078 = copyString(LOC7.Name);
F.line = 38;F.filename = "depends.nim";
Adddependencyaux_187016((*(*(*G_187042).Module).Name).S, Imported_187078);
F.line = 1022;F.filename = "system.nim";
Res_187115 = addInt(Res_187115, 1);
} LA5: ;
break;
case ((NU8) 103):
Imported_187091 = 0;
F.line = 40;F.filename = "depends.nim";
if (((TMP187125[(*N_187029).Kind/8] &(1<<((*N_187029).Kind%8)))!=0)) raiseFieldError(((NimStringDesc*) &TMP187126));
if ((NU)(0) >= (NU)((*N_187029).KindU.S6.Sons->Sup.len)) raiseIndexError();
LOC8 = 0;
LOC8 = Getmodulefile_108013((*N_187029).KindU.S6.Sons->data[0]);
memset((void*)&LOC9, 0, sizeof(LOC9));
nossplitFile(LOC8, &LOC9);
Imported_187091 = copyString(LOC9.Name);
F.line = 41;F.filename = "depends.nim";
Adddependencyaux_187016((*(*(*G_187042).Module).Name).S, Imported_187091);
break;
case ((NU8) 101):
case ((NU8) 99):
case ((NU8) 106):
case ((NU8) 107):
I_187099 = 0;
HEX3Atmp_187119 = 0;
F.line = 43;F.filename = "depends.nim";
LOC10 = Sonslen_54803(N_187029);
HEX3Atmp_187119 = subInt(LOC10, 1);
Res_187121 = 0;
F.line = 1019;F.filename = "system.nim";
Res_187121 = 0;
F.line = 1020;F.filename = "system.nim";
while (1) {
if (!(Res_187121 <= HEX3Atmp_187119)) goto LA11;
F.line = 1019;F.filename = "system.nim";
I_187099 = Res_187121;
F.line = 43;F.filename = "depends.nim";
if (((TMP187125[(*N_187029).Kind/8] &(1<<((*N_187029).Kind%8)))!=0)) raiseFieldError(((NimStringDesc*) &TMP187126));
if ((NU)(I_187099) >= (NU)((*N_187029).KindU.S6.Sons->Sup.len)) raiseIndexError();
LOC12 = 0;
LOC12 = Adddotdependency_187026(C_187028, (*N_187029).KindU.S6.Sons->data[I_187099]);
F.line = 1022;F.filename = "system.nim";
Res_187121 = addInt(Res_187121, 1);
} LA11: ;
break;
default:
break;
}
BeforeRet: ;
framePtr = framePtr->prev;
return Result_187030;
}
N_NIMCALL(void, Generatedot_187006)(NimStringDesc* Project_187008) {
TY58695 LOC1;
NimStringDesc* LOC2;
NimStringDesc* LOC3;
TY51008* LOC4;
NimStringDesc* LOC5;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "generateDot";
F.prev = framePtr;
F.filename = "rod/depends.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
F.line = 48;F.filename = "depends.nim";
memset((void*)&LOC1, 0, sizeof(LOC1));
LOC2 = 0;
LOC2 = nosextractFilename(Project_187008);
LOC3 = 0;
LOC3 = nosChangeFileExt(LOC2, ((NimStringDesc*) &TMP187135));
LOC1[0] = Torope_51046(LOC3);
LOC1[1] = Gdotgraph_187015;
LOC4 = 0;
LOC4 = Ropef_51069(((NimStringDesc*) &TMP187134), LOC1, 2);
LOC5 = 0;
LOC5 = nosChangeFileExt(Project_187008, ((NimStringDesc*) &TMP187136));
Writerope_51058(LOC4, LOC5);
framePtr = framePtr->prev;
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
static N_INLINE(NIM_BOOL, Canbecycleroot_11040)(TY10602* C_11042) {
NIM_BOOL Result_11043;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "canbeCycleRoot";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/system/gc.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_11043 = 0;
F.line = 103;F.filename = "gc.nim";
Result_11043 = !((((*(*C_11042).Typ).flags &(1<<((((NU8) 1))&7)))!=0));
framePtr = framePtr->prev;
return Result_11043;
}
static N_INLINE(void, Rtladdcycleroot_11652)(TY10602* C_11654) {
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "rtlAddCycleRoot";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/system/gc.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
F.line = 205;F.filename = "gc.nim";
if (!NIM_TRUE) goto LA2;
F.line = 205;F.filename = "gc.nim";
pthread_mutex_lock(&Gch_11010.Cyclerootslock);
LA2: ;
F.line = 206;F.filename = "gc.nim";
Incl_10874(&Gch_11010.Cycleroots, C_11654);
F.line = 207;F.filename = "gc.nim";
if (!NIM_TRUE) goto LA5;
F.line = 207;F.filename = "gc.nim";
pthread_mutex_unlock(&Gch_11010.Cyclerootslock);
LA5: ;
framePtr = framePtr->prev;
}
static N_INLINE(void, Incref_11802)(TY10602* C_11804) {
NI LOC1;
NIM_BOOL LOC3;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "incRef";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/system/gc.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
F.line = 226;F.filename = "gc.nim";
LOC1 = Atomicinc_2801(&(*C_11804).Refcount, 8);
F.line = 227;F.filename = "gc.nim";
LOC3 = Canbecycleroot_11040(C_11804);
if (!LOC3) goto LA4;
F.line = 228;F.filename = "gc.nim";
Rtladdcycleroot_11652(C_11804);
LA4: ;
framePtr = framePtr->prev;
}
static N_INLINE(TY10602*, Usrtocell_11036)(void* Usr_11038) {
TY10602* Result_11039;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "usrToCell";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/system/gc.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_11039 = 0;
F.line = 100;F.filename = "gc.nim";
Result_11039 = ((TY10602*) ((NI32)((NU32)(((NI) (Usr_11038))) - (NU32)(((NI) (((NI)sizeof(TY10602))))))));
framePtr = framePtr->prev;
return Result_11039;
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
static N_INLINE(void, Rtladdzct_11658)(TY10602* C_11660) {
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
pthread_mutex_lock(&Gch_11010.Zctlock);
LA2: ;
F.line = 212;F.filename = "gc.nim";
Addzct_11025(&Gch_11010.Zct, C_11660);
F.line = 213;F.filename = "gc.nim";
if (!NIM_TRUE) goto LA5;
F.line = 213;F.filename = "gc.nim";
pthread_mutex_unlock(&Gch_11010.Zctlock);
LA5: ;
framePtr = framePtr->prev;
}
static N_INLINE(void, Decref_11664)(TY10602* C_11666) {
NI LOC2;
NIM_BOOL LOC5;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "decRef";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/system/gc.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
F.line = 219;F.filename = "gc.nim";
F.line = 220;F.filename = "gc.nim";
LOC2 = Atomicdec_2806(&(*C_11666).Refcount, 8);
if (!((NU32)(LOC2) < (NU32)(8))) goto LA3;
F.line = 221;F.filename = "gc.nim";
Rtladdzct_11658(C_11666);
goto LA1;
LA3: ;
LOC5 = Canbecycleroot_11040(C_11666);
if (!LOC5) goto LA6;
F.line = 223;F.filename = "gc.nim";
Rtladdcycleroot_11652(C_11666);
goto LA1;
LA6: ;
LA1: ;
framePtr = framePtr->prev;
}
static N_INLINE(void, asgnRef)(void** Dest_11814, void* Src_11815) {
TY10602* LOC4;
TY10602* LOC8;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "asgnRef";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/system/gc.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
F.line = 235;F.filename = "gc.nim";
F.line = 237;F.filename = "gc.nim";
if (!!((Src_11815 == NIM_NIL))) goto LA2;
F.line = 237;F.filename = "gc.nim";
LOC4 = Usrtocell_11036(Src_11815);
Incref_11802(LOC4);
LA2: ;
F.line = 238;F.filename = "gc.nim";
if (!!(((*Dest_11814) == NIM_NIL))) goto LA6;
F.line = 238;F.filename = "gc.nim";
LOC8 = Usrtocell_11036((*Dest_11814));
Decref_11664(LOC8);
LA6: ;
F.line = 239;F.filename = "gc.nim";
(*Dest_11814) = Src_11815;
framePtr = framePtr->prev;
}
static N_INLINE(void, asgnRefNoCycle)(void** Dest_11818, void* Src_11819) {
TY10602* C_11820;
NI LOC4;
TY10602* C_11822;
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
if (!!((Src_11819 == NIM_NIL))) goto LA2;
C_11820 = 0;
F.line = 245;F.filename = "gc.nim";
C_11820 = Usrtocell_11036(Src_11819);
F.line = 246;F.filename = "gc.nim";
LOC4 = Atomicinc_2801(&(*C_11820).Refcount, 8);
LA2: ;
F.line = 247;F.filename = "gc.nim";
if (!!(((*Dest_11818) == NIM_NIL))) goto LA6;
C_11822 = 0;
F.line = 248;F.filename = "gc.nim";
C_11822 = Usrtocell_11036((*Dest_11818));
F.line = 249;F.filename = "gc.nim";
LOC9 = Atomicdec_2806(&(*C_11822).Refcount, 8);
if (!((NU32)(LOC9) < (NU32)(8))) goto LA10;
F.line = 250;F.filename = "gc.nim";
Rtladdzct_11658(C_11822);
LA10: ;
LA6: ;
F.line = 251;F.filename = "gc.nim";
(*Dest_11818) = Src_11819;
framePtr = framePtr->prev;
}
N_NIMCALL(TY103002*, Myopen_187137)(TY54547* Module_187139, NimStringDesc* Filename_187140) {
TY103002* Result_187141;
TY187010* G_187142;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "myOpen";
F.prev = framePtr;
F.filename = "rod/depends.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_187141 = 0;
G_187142 = 0;
F.line = 54;F.filename = "depends.nim";
G_187142 = (TY187010*) newObj(NTI187012, sizeof(TY187010));
(*G_187142).Sup.Sup.m_type = NTI187010;
F.line = 55;F.filename = "depends.nim";
asgnRef((void**) &(*G_187142).Module, Module_187139);
F.line = 56;F.filename = "depends.nim";
asgnRefNoCycle((void**) &(*G_187142).Filename, copyString(Filename_187140));
F.line = 57;F.filename = "depends.nim";
Result_187141 = &G_187142->Sup;
framePtr = framePtr->prev;
return Result_187141;
}
N_NIMCALL(TY103006, Gendependpass_187004)(void) {
TY103006 Result_187160;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "genDependPass";
F.prev = framePtr;
F.filename = "rod/depends.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
memset((void*)&Result_187160, 0, sizeof(Result_187160));
F.line = 60;F.filename = "depends.nim";
Initpass_103031(&Result_187160);
F.line = 61;F.filename = "depends.nim";
Result_187160.Open = Myopen_187137;
F.line = 62;F.filename = "depends.nim";
Result_187160.Process = Adddotdependency_187026;
framePtr = framePtr->prev;
return Result_187160;
}
N_NOINLINE(void, dependsInit)(void) {
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "depends";
F.prev = framePtr;
F.filename = "rod/depends.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
framePtr = framePtr->prev;
}

