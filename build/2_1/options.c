/* Generated by Nimrod Compiler v0.8.9 */
/*   (c) 2010 Andreas Rumpf */

typedef long int NI;
typedef unsigned long int NU;
#include "nimbase.h"

#include <pthread.h>
typedef struct TY42019 TY42019;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef struct TY42013 TY42013;
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct TY10602 TY10602;
typedef struct TY10990 TY10990;
typedef struct TY10618 TY10618;
typedef struct TY10614 TY10614;
typedef struct TY10610 TY10610;
typedef struct TY10988 TY10988;
typedef struct TY44008 TY44008;
typedef struct TY4177 TY4177;
typedef struct TY37578 TY37578;
typedef struct E_Base E_Base;
typedef struct TNimObject TNimObject;
typedef struct TSafePoint TSafePoint;
typedef struct TY42015 TY42015;
typedef struct TY44006 TY44006;
typedef struct TY44004 TY44004;
struct TNimType {
NI size;
NU8 kind;
NU8 flags;
TNimType* base;
TNimNode* node;
void* finalizer;
};
struct TY42019 {
TNimType* m_type;
TY42013* Head;
TY42013* Tail;
NI Counter;
};
struct TNimNode {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
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
struct TY37578 {
NimStringDesc* Head;
NimStringDesc* Tail;
};
typedef NimStringDesc* TY45253[4];
typedef NimStringDesc* TY45273[3];
struct TNimObject {
TNimType* m_type;
};
struct E_Base {
  TNimObject Sup;
E_Base* parent;
NCSTRING name;
NimStringDesc* message;
};
struct TSafePoint {
TSafePoint* prev;
NI status;
E_Base* exc;
jmp_buf context;
};
struct TY42013 {
  TNimObject Sup;
TY42013* Prev;
TY42013* Next;
};
struct TY42015 {
  TY42013 Sup;
NimStringDesc* Data;
};
typedef NimStringDesc* TY45353[1];
typedef NI TY8614[16];
struct TY10610 {
TY10610* Next;
NI Key;
TY8614 Bits;
};
struct TY44004 {
NimStringDesc* Key;
NimStringDesc* Val;
};
struct TY44008 {
  TNimObject Sup;
NI Counter;
TY44006* Data;
NU8 Mode;
};
struct TY4177 {
  TGenericSeq Sup;
  NimStringDesc* data[SEQ_DECL_SIZE];
};
struct TY44006 {
  TGenericSeq Sup;
  TY44004 data[SEQ_DECL_SIZE];
};
static N_INLINE(void, asgnRefNoCycle)(void** Dest_11818, void* Src_11819);
static N_INLINE(TY10602*, Usrtocell_11036)(void* Usr_11038);
static N_INLINE(NI, Atomicinc_2801)(NI* Memloc_2804, NI X_2805);
static N_INLINE(NI, Atomicdec_2806)(NI* Memloc_2809, NI X_2810);
static N_INLINE(void, Rtladdzct_11658)(TY10602* C_11660);
N_NOINLINE(void, Addzct_11025)(TY10618* S_11028, TY10602* C_11029);
N_NIMCALL(NimStringDesc*, copyString)(NimStringDesc* Src_17308);
N_NIMCALL(void*, newSeq)(TNimType* Typ_12804, NI Len_12805);
N_NIMCALL(NIM_BOOL, Existsconfigvar_45129)(NimStringDesc* Key_45131);
N_NIMCALL(NIM_BOOL, Haskey_44033)(TY44008* T_44035, NimStringDesc* Key_44036);
N_NIMCALL(NimStringDesc*, Getconfigvar_45132)(NimStringDesc* Key_45134);
N_NIMCALL(NimStringDesc*, Get_44029)(TY44008* T_44031, NimStringDesc* Key_44032);
N_NIMCALL(void, Setconfigvar_45135)(NimStringDesc* Key_45137, NimStringDesc* Val_45138);
N_NIMCALL(void, Put_44024)(TY44008* T_44026, NimStringDesc* Key_44027, NimStringDesc* Val_44028);
N_NIMCALL(NimStringDesc*, Getoutfile_45142)(NimStringDesc* Filename_45144, NimStringDesc* Ext_45145);
N_NIMCALL(NimStringDesc*, nosChangeFileExt)(NimStringDesc* Filename_38020, NimStringDesc* Ext_38021);
N_NIMCALL(void, Addimplicitmod_45139)(NimStringDesc* Filename_45141);
static N_INLINE(NI, addInt)(NI A_5603, NI B_5604);
N_NOINLINE(void, raiseOverflow)(void);
N_NIMCALL(TGenericSeq*, setLengthSeq)(TGenericSeq* Seq_17603, NI Elemsize_17604, NI Newlen_17605);
N_NOINLINE(void, raiseIndexError)(void);
N_NIMCALL(NimStringDesc*, Getprefixdir_45106)(void);
N_NIMCALL(void, nosSplitPath)(NimStringDesc* Path_37577, TY37578* Result);
N_NIMCALL(NimStringDesc*, nosgetApplicationDir)(void);
N_NIMCALL(NimStringDesc*, Shortendir_45198)(NimStringDesc* Dir_45200);
static N_INLINE(void, appendString)(NimStringDesc* Dest_17392, NimStringDesc* Src_17393);
static N_INLINE(void, appendChar)(NimStringDesc* Dest_17409, NIM_CHAR C_17410);
N_NIMCALL(NimStringDesc*, rawNewString)(NI Space_17287);
N_NIMCALL(NIM_BOOL, nsuStartsWith)(NimStringDesc* S_24769, NimStringDesc* Prefix_24770);
N_NIMCALL(NimStringDesc*, copyStr)(NimStringDesc* S_1748, NI First_1749);
N_NIMCALL(NimStringDesc*, nosgetCurrentDir)(void);
N_NIMCALL(NimStringDesc*, Removetrailingdirsep_45222)(NimStringDesc* Path_45224);
static N_INLINE(NI, subInt)(NI A_5803, NI B_5804);
N_NIMCALL(NimStringDesc*, copyStrLast)(NimStringDesc* S_1752, NI First_1753, NI Last_1754);
N_NIMCALL(NimStringDesc*, Togeneratedfile_45102)(NimStringDesc* Path_45104, NimStringDesc* Ext_45105);
N_NIMCALL(NimStringDesc*, nosJoinPathOpenArray)(NimStringDesc** Parts_37487, NI Parts_37487Len0);
N_NIMCALL(NimStringDesc*, Completegeneratedfilepath_45098)(NimStringDesc* F_45100, NIM_BOOL Createsubdir_45101);
static N_INLINE(void, pushSafePoint)(TSafePoint* S_4435);
N_NIMCALL(void, noscreateDir)(NimStringDesc* Dir_39603);
static N_INLINE(void, popSafePoint)(void);
static N_INLINE(E_Base*, getCurrentException)(void);
static N_INLINE(void, popCurrentException)(void);
static N_INLINE(void, asgnRef)(void** Dest_11814, void* Src_11815);
static N_INLINE(void, Incref_11802)(TY10602* C_11804);
static N_INLINE(NIM_BOOL, Canbecycleroot_11040)(TY10602* C_11042);
static N_INLINE(void, Rtladdcycleroot_11652)(TY10602* C_11654);
N_NOINLINE(void, Incl_10874)(TY10614* S_10877, TY10602* Cell_10878);
static N_INLINE(void, Decref_11664)(TY10602* C_11666);
N_NIMCALL(void, reraiseException)(void);
N_NIMCALL(NimStringDesc*, nosJoinPath)(NimStringDesc* Head_37403, NimStringDesc* Tail_37404);
N_NIMCALL(NimStringDesc*, Rawfindfile_45294)(NimStringDesc* F_45296);
N_NIMCALL(NIM_BOOL, nosexistsFile)(NimStringDesc* Filename_36003);
N_NIMCALL(void, chckObj)(TNimType* Obj_5375, TNimType* Subclass_5376);
N_NIMCALL(NimStringDesc*, Findfile_45087)(NimStringDesc* F_45089);
N_NIMCALL(NimStringDesc*, nsuToLowerStr)(NimStringDesc* S_23448);
N_NIMCALL(NI, Binarystrsearch_45146)(NimStringDesc** X_45149, NI X_45149Len0, NimStringDesc* Y_45150);
static N_INLINE(NI, divInt)(NI A_6203, NI B_6204);
N_NOINLINE(void, raiseDivByZero)(void);
N_NIMCALL(NI, nsuCmpIgnoreCase)(NimStringDesc* A_23595, NimStringDesc* B_23596);
N_NIMCALL(TY44008*, Newstringtable_44019)(NimStringDesc** Keyvaluepairs_44022, NI Keyvaluepairs_44022Len0, NU8 Mode_44023);
N_NIMCALL(void, Writeln_45287)(FILE* F_45290, NimStringDesc* X_45291);
N_NIMCALL(void, Write_3458)(FILE* F_3460, NimStringDesc* S_3461);
NIM_CONST NU32 Checksoptions_45072 = 1022;
STRING_LITERAL(TMP45086, "", 0);
STRING_LITERAL(TMP45255, "nimcache", 8);
STRING_LITERAL(TMP45293, "cannot create directory: ", 25);
STRING_LITERAL(TMP45354, "\012", 1);
NU32 Goptions_45075;
NU32 Gglobaloptions_45077;
NI8 Gexitcode_45078;
TY42019 Searchpaths_45079;
extern TNimType* NTI42019; /* TLinkedList */
NimStringDesc* Outfile_45080;
extern TY10990 Gch_11010;
NimStringDesc* Gindexfile_45081;
NU8 Gcmd_45082;
NI Gverbosity_45083;
NI Gnumberofprocessors_45084;
TY44008* Gconfigvars_45108;
NimStringDesc* Libpath_45109;
NimStringDesc* Projectpath_45110;
NIM_BOOL Gkeepcomments_45111;
TY4177* Gimplicitmods_45128;
extern TNimType* NTI4177; /* seq[string] */
extern TSafePoint* excHandler;
extern TNimType* NTI422; /* EOS */
extern E_Base* Currexception_4432;
extern TNimType* NTI42015; /* TStrEntry */
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
N_NIMCALL(NIM_BOOL, Existsconfigvar_45129)(NimStringDesc* Key_45131) {
NIM_BOOL Result_45154;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "existsConfigVar";
F.prev = framePtr;
F.filename = "rod/options.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_45154 = 0;
F.line = 110;F.filename = "options.nim";
Result_45154 = Haskey_44033(Gconfigvars_45108, Key_45131);
framePtr = framePtr->prev;
return Result_45154;
}
N_NIMCALL(NimStringDesc*, Getconfigvar_45132)(NimStringDesc* Key_45134) {
NimStringDesc* Result_45158;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "getConfigVar";
F.prev = framePtr;
F.filename = "rod/options.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_45158 = 0;
F.line = 113;F.filename = "options.nim";
Result_45158 = Get_44029(Gconfigvars_45108, Key_45134);
framePtr = framePtr->prev;
return Result_45158;
}
N_NIMCALL(void, Setconfigvar_45135)(NimStringDesc* Key_45137, NimStringDesc* Val_45138) {
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "setConfigVar";
F.prev = framePtr;
F.filename = "rod/options.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
F.line = 116;F.filename = "options.nim";
Put_44024(Gconfigvars_45108, Key_45137, Val_45138);
framePtr = framePtr->prev;
}
N_NIMCALL(NimStringDesc*, Getoutfile_45142)(NimStringDesc* Filename_45144, NimStringDesc* Ext_45145) {
NimStringDesc* Result_45167;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "getOutFile";
F.prev = framePtr;
F.filename = "rod/options.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_45167 = 0;
F.line = 119;F.filename = "options.nim";
if (!!(((Outfile_45080) && (Outfile_45080)->Sup.len == 0))) goto LA2;
F.line = 119;F.filename = "options.nim";
Result_45167 = copyString(Outfile_45080);
goto LA1;
LA2: ;
F.line = 120;F.filename = "options.nim";
Result_45167 = nosChangeFileExt(Filename_45144, Ext_45145);
LA1: ;
framePtr = framePtr->prev;
return Result_45167;
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
N_NIMCALL(void, Addimplicitmod_45139)(NimStringDesc* Filename_45141) {
NI Length_45171;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "addImplicitMod";
F.prev = framePtr;
F.filename = "rod/options.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Length_45171 = 0;
F.line = 124;F.filename = "options.nim";
Length_45171 = Gimplicitmods_45128->Sup.len;
F.line = 125;F.filename = "options.nim";
Gimplicitmods_45128 = (TY4177*) setLengthSeq(&(Gimplicitmods_45128)->Sup, sizeof(NimStringDesc*), addInt(Length_45171, 1));
F.line = 126;F.filename = "options.nim";
if ((NU)(Length_45171) >= (NU)(Gimplicitmods_45128->Sup.len)) raiseIndexError();
asgnRefNoCycle((void**) &Gimplicitmods_45128->data[Length_45171], copyString(Filename_45141));
framePtr = framePtr->prev;
}
N_NIMCALL(NimStringDesc*, Getprefixdir_45106)(void) {
NimStringDesc* Result_45196;
NimStringDesc* LOC1;
TY37578 LOC2;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "getPrefixDir";
F.prev = framePtr;
F.filename = "rod/options.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_45196 = 0;
F.line = 129;F.filename = "options.nim";
LOC1 = 0;
LOC1 = nosgetApplicationDir();
memset((void*)&LOC2, 0, sizeof(LOC2));
nosSplitPath(LOC1, &LOC2);
Result_45196 = copyString(LOC2.Head);
framePtr = framePtr->prev;
return Result_45196;
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
static N_INLINE(void, appendChar)(NimStringDesc* Dest_17409, NIM_CHAR C_17410) {
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "appendChar";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/system/sysstr.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
F.line = 154;F.filename = "sysstr.nim";
(*Dest_17409).data[((*Dest_17409).Sup.len)-0] = C_17410;
F.line = 155;F.filename = "sysstr.nim";
(*Dest_17409).data[((NI32)((*Dest_17409).Sup.len + 1))-0] = 0;
F.line = 156;F.filename = "sysstr.nim";
(*Dest_17409).Sup.len += 1;
framePtr = framePtr->prev;
}
N_NIMCALL(NimStringDesc*, Shortendir_45198)(NimStringDesc* Dir_45200) {
NimStringDesc* Result_45201;
NimStringDesc* Prefix_45206;
NimStringDesc* LOC1;
NimStringDesc* LOC2;
NIM_BOOL LOC4;
NimStringDesc* LOC7;
NimStringDesc* LOC8;
NIM_BOOL LOC10;
NimStringDesc* LOC13;
NIM_BOOL LOC15;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "shortenDir";
F.prev = framePtr;
F.filename = "rod/options.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_45201 = 0;
Prefix_45206 = 0;
F.line = 133;F.filename = "options.nim";
LOC1 = 0;
LOC2 = 0;
LOC2 = Getprefixdir_45106();
LOC1 = rawNewString(LOC2->Sup.len + 1);
appendString(LOC1, LOC2);
appendChar(LOC1, 47);
Prefix_45206 = LOC1;
F.line = 134;F.filename = "options.nim";
LOC4 = nsuStartsWith(Dir_45200, Prefix_45206);
if (!LOC4) goto LA5;
F.line = 135;F.filename = "options.nim";
F.line = 135;F.filename = "options.nim";
Result_45201 = copyStr(Dir_45200, Prefix_45206->Sup.len);
goto BeforeRet;
LA5: ;
F.line = 136;F.filename = "options.nim";
LOC7 = 0;
LOC8 = 0;
LOC8 = nosgetCurrentDir();
LOC7 = rawNewString(LOC8->Sup.len + 1);
appendString(LOC7, LOC8);
appendChar(LOC7, 47);
Prefix_45206 = LOC7;
F.line = 137;F.filename = "options.nim";
LOC10 = nsuStartsWith(Dir_45200, Prefix_45206);
if (!LOC10) goto LA11;
F.line = 138;F.filename = "options.nim";
F.line = 138;F.filename = "options.nim";
Result_45201 = copyStr(Dir_45200, Prefix_45206->Sup.len);
goto BeforeRet;
LA11: ;
F.line = 139;F.filename = "options.nim";
LOC13 = 0;
LOC13 = rawNewString(Projectpath_45110->Sup.len + 1);
appendString(LOC13, Projectpath_45110);
appendChar(LOC13, 47);
Prefix_45206 = LOC13;
F.line = 141;F.filename = "options.nim";
LOC15 = nsuStartsWith(Dir_45200, Prefix_45206);
if (!LOC15) goto LA16;
F.line = 142;F.filename = "options.nim";
F.line = 142;F.filename = "options.nim";
Result_45201 = copyStr(Dir_45200, Prefix_45206->Sup.len);
goto BeforeRet;
LA16: ;
F.line = 143;F.filename = "options.nim";
Result_45201 = copyString(Dir_45200);
BeforeRet: ;
framePtr = framePtr->prev;
return Result_45201;
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
N_NIMCALL(NimStringDesc*, Removetrailingdirsep_45222)(NimStringDesc* Path_45224) {
NimStringDesc* Result_45225;
NIM_BOOL LOC2;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "removeTrailingDirSep";
F.prev = framePtr;
F.filename = "rod/options.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_45225 = 0;
F.line = 146;F.filename = "options.nim";
LOC2 = (0 < Path_45224->Sup.len);
if (!(LOC2)) goto LA3;
if ((NU)(subInt(Path_45224->Sup.len, 1)) > (NU)(Path_45224->Sup.len)) raiseIndexError();
LOC2 = ((NU8)(Path_45224->data[subInt(Path_45224->Sup.len, 1)]) == (NU8)(47));
LA3: ;
if (!LOC2) goto LA4;
F.line = 147;F.filename = "options.nim";
Result_45225 = copyStrLast(Path_45224, 0, subInt(Path_45224->Sup.len, 2));
goto LA1;
LA4: ;
F.line = 149;F.filename = "options.nim";
Result_45225 = copyString(Path_45224);
LA1: ;
framePtr = framePtr->prev;
return Result_45225;
}
N_NIMCALL(NimStringDesc*, Togeneratedfile_45102)(NimStringDesc* Path_45104, NimStringDesc* Ext_45105) {
NimStringDesc* Result_45240;
TY37578 LOC1;
NimStringDesc* Head_45241;
NimStringDesc* Tail_45242;
NimStringDesc* LOC5;
TY45253 LOC6;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "toGeneratedFile";
F.prev = framePtr;
F.filename = "rod/options.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_45240 = 0;
F.line = 152;F.filename = "options.nim";
memset((void*)&LOC1, 0, sizeof(LOC1));
nosSplitPath(Path_45104, &LOC1);
Head_45241 = 0;
Head_45241 = copyString(LOC1.Head);
Tail_45242 = 0;
Tail_45242 = copyString(LOC1.Tail);
F.line = 153;F.filename = "options.nim";
if (!(0 < Head_45241->Sup.len)) goto LA3;
F.line = 153;F.filename = "options.nim";
LOC5 = 0;
LOC5 = rawNewString(Head_45241->Sup.len + 1);
appendString(LOC5, Head_45241);
appendChar(LOC5, 47);
Head_45241 = Shortendir_45198(LOC5);
LA3: ;
F.line = 154;F.filename = "options.nim";
memset((void*)&LOC6, 0, sizeof(LOC6));
LOC6[0] = copyString(Projectpath_45110);
LOC6[1] = copyString(((NimStringDesc*) &TMP45255));
LOC6[2] = copyString(Head_45241);
LOC6[3] = nosChangeFileExt(Tail_45242, Ext_45105);
Result_45240 = nosJoinPathOpenArray(LOC6, 4);
framePtr = framePtr->prev;
return Result_45240;
}
static N_INLINE(void, pushSafePoint)(TSafePoint* S_4435) {
(*S_4435).prev = excHandler;
excHandler = S_4435;
}
static N_INLINE(void, popSafePoint)(void) {
excHandler = (*excHandler).prev;
}
static N_INLINE(E_Base*, getCurrentException)(void) {
E_Base* Result_19204;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "getCurrentException";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/system.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_19204 = 0;
F.line = 1582;F.filename = "system.nim";
Result_19204 = Currexception_4432;
framePtr = framePtr->prev;
return Result_19204;
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
static N_INLINE(void, popCurrentException)(void) {
asgnRef((void**) &Currexception_4432, (*Currexception_4432).parent);
}
N_NIMCALL(NimStringDesc*, Completegeneratedfilepath_45098)(NimStringDesc* F_45100, NIM_BOOL Createsubdir_45101) {
NimStringDesc* Result_45260;
TY37578 LOC1;
NimStringDesc* Head_45261;
NimStringDesc* Tail_45262;
NimStringDesc* LOC5;
NimStringDesc* LOC6;
NimStringDesc* Subdir_45275;
TY45273 LOC7;
TSafePoint TMP45292;
NimStringDesc* LOC11;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "completeGeneratedFilePath";
F.prev = framePtr;
F.filename = "rod/options.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_45260 = 0;
F.line = 157;F.filename = "options.nim";
memset((void*)&LOC1, 0, sizeof(LOC1));
nosSplitPath(F_45100, &LOC1);
Head_45261 = 0;
Head_45261 = copyString(LOC1.Head);
Tail_45262 = 0;
Tail_45262 = copyString(LOC1.Tail);
F.line = 158;F.filename = "options.nim";
if (!(0 < Head_45261->Sup.len)) goto LA3;
F.line = 158;F.filename = "options.nim";
LOC5 = 0;
LOC5 = rawNewString(Head_45261->Sup.len + 1);
appendString(LOC5, Head_45261);
appendChar(LOC5, 47);
LOC6 = 0;
LOC6 = Shortendir_45198(LOC5);
Head_45261 = Removetrailingdirsep_45222(LOC6);
LA3: ;
Subdir_45275 = 0;
F.line = 159;F.filename = "options.nim";
memset((void*)&LOC7, 0, sizeof(LOC7));
LOC7[0] = copyString(Projectpath_45110);
LOC7[1] = copyString(((NimStringDesc*) &TMP45255));
LOC7[2] = copyString(Head_45261);
Subdir_45275 = nosJoinPathOpenArray(LOC7, 3);
F.line = 160;F.filename = "options.nim";
if (!Createsubdir_45101) goto LA9;
F.line = 161;F.filename = "options.nim";
pushSafePoint(&TMP45292);
TMP45292.status = setjmp(TMP45292.context);
framePtr = (TFrame*)&F;
if (TMP45292.status == 0) {
F.line = 162;F.filename = "options.nim";
noscreateDir(Subdir_45275);
popSafePoint();
} else {
popSafePoint();
if (getCurrentException()->Sup.m_type == NTI422) {
F.line = 164;F.filename = "options.nim";
LOC11 = 0;
LOC11 = rawNewString(Subdir_45275->Sup.len + 25);
appendString(LOC11, ((NimStringDesc*) &TMP45293));
appendString(LOC11, Subdir_45275);
Writeln_45287(stdout, LOC11);
F.line = 165;F.filename = "options.nim";
exit(1);
TMP45292.status = 0;popCurrentException();}
}
if (TMP45292.status != 0) reraiseException();
LA9: ;
F.line = 166;F.filename = "options.nim";
Result_45260 = nosJoinPath(Subdir_45275, Tail_45262);
framePtr = framePtr->prev;
return Result_45260;
}
N_NIMCALL(NimStringDesc*, Rawfindfile_45294)(NimStringDesc* F_45296) {
NimStringDesc* Result_45297;
NIM_BOOL LOC2;
TY42015* It_45298;
NIM_BOOL LOC7;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "rawFindFile";
F.prev = framePtr;
F.filename = "rod/options.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_45297 = 0;
F.line = 169;F.filename = "options.nim";
LOC2 = nosexistsFile(F_45296);
if (!LOC2) goto LA3;
F.line = 170;F.filename = "options.nim";
Result_45297 = copyString(F_45296);
goto LA1;
LA3: ;
It_45298 = 0;
F.line = 172;F.filename = "options.nim";
if (Searchpaths_45079.Head) chckObj((*Searchpaths_45079.Head).Sup.m_type, NTI42015);
It_45298 = ((TY42015*) (Searchpaths_45079.Head));
F.line = 173;F.filename = "options.nim";
while (1) {
if (!!((It_45298 == NIM_NIL))) goto LA5;
F.line = 174;F.filename = "options.nim";
Result_45297 = nosJoinPath((*It_45298).Data, F_45296);
F.line = 175;F.filename = "options.nim";
LOC7 = nosexistsFile(Result_45297);
if (!LOC7) goto LA8;
F.line = 175;F.filename = "options.nim";
goto BeforeRet;
LA8: ;
F.line = 176;F.filename = "options.nim";
if ((*It_45298).Sup.Next) chckObj((*(*It_45298).Sup.Next).Sup.m_type, NTI42015);
It_45298 = ((TY42015*) ((*It_45298).Sup.Next));
} LA5: ;
F.line = 177;F.filename = "options.nim";
Result_45297 = copyString(((NimStringDesc*) &TMP45086));
LA1: ;
BeforeRet: ;
framePtr = framePtr->prev;
return Result_45297;
}
N_NIMCALL(NimStringDesc*, Findfile_45087)(NimStringDesc* F_45089) {
NimStringDesc* Result_45314;
NimStringDesc* LOC4;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "FindFile";
F.prev = framePtr;
F.filename = "rod/options.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_45314 = 0;
F.line = 180;F.filename = "options.nim";
Result_45314 = Rawfindfile_45294(F_45089);
F.line = 181;F.filename = "options.nim";
if (!(Result_45314->Sup.len == 0)) goto LA2;
F.line = 181;F.filename = "options.nim";
LOC4 = 0;
LOC4 = nsuToLowerStr(F_45089);
Result_45314 = Rawfindfile_45294(LOC4);
LA2: ;
framePtr = framePtr->prev;
return Result_45314;
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
N_NIMCALL(NI, Binarystrsearch_45146)(NimStringDesc** X_45149, NI X_45149Len0, NimStringDesc* Y_45150) {
NI Result_45324;
NI A_45325;
NI B_45336;
NI Mid_45339;
NI C_45340;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "binaryStrSearch";
F.prev = framePtr;
F.filename = "rod/options.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_45324 = 0;
A_45325 = 0;
F.line = 184;F.filename = "options.nim";
A_45325 = 0;
B_45336 = 0;
F.line = 185;F.filename = "options.nim";
B_45336 = subInt(X_45149Len0, 1);
F.line = 186;F.filename = "options.nim";
while (1) {
if (!(A_45325 <= B_45336)) goto LA1;
Mid_45339 = 0;
F.line = 187;F.filename = "options.nim";
Mid_45339 = divInt(addInt(A_45325, B_45336), 2);
C_45340 = 0;
F.line = 188;F.filename = "options.nim";
if ((NU)(Mid_45339) >= (NU)(X_45149Len0)) raiseIndexError();
C_45340 = nsuCmpIgnoreCase(X_45149[Mid_45339], Y_45150);
F.line = 189;F.filename = "options.nim";
if (!(C_45340 < 0)) goto LA3;
F.line = 190;F.filename = "options.nim";
A_45325 = addInt(Mid_45339, 1);
goto LA2;
LA3: ;
if (!(0 < C_45340)) goto LA5;
F.line = 192;F.filename = "options.nim";
B_45336 = subInt(Mid_45339, 1);
goto LA2;
LA5: ;
F.line = 194;F.filename = "options.nim";
F.line = 194;F.filename = "options.nim";
Result_45324 = Mid_45339;
goto BeforeRet;
LA2: ;
} LA1: ;
F.line = 195;F.filename = "options.nim";
Result_45324 = -1;
BeforeRet: ;
framePtr = framePtr->prev;
return Result_45324;
}
N_NIMCALL(void, Writeln_45287)(FILE* F_45290, NimStringDesc* X_45291) {
Write_3458(F_45290, X_45291);
Write_3458(F_45290, ((NimStringDesc*) &TMP45354));
}
N_NOINLINE(void, optionsInit)(void) {
TY45353 LOC1;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "options";
F.prev = framePtr;
F.filename = "rod/options.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
F.line = 63;F.filename = "options.nim";
Goptions_45075 = 105022;
F.line = 66;F.filename = "options.nim";
Gglobaloptions_45077 = 8;
Searchpaths_45079.m_type = NTI42019;
F.line = 69;F.filename = "options.nim";
asgnRefNoCycle((void**) &Outfile_45080, copyString(((NimStringDesc*) &TMP45086)));
F.line = 70;F.filename = "options.nim";
asgnRefNoCycle((void**) &Gindexfile_45081, copyString(((NimStringDesc*) &TMP45086)));
F.line = 71;F.filename = "options.nim";
Gcmd_45082 = ((NU8) 0);
F.line = 96;F.filename = "options.nim";
asgnRefNoCycle((void**) &Libpath_45109, copyString(((NimStringDesc*) &TMP45086)));
F.line = 97;F.filename = "options.nim";
asgnRefNoCycle((void**) &Projectpath_45110, copyString(((NimStringDesc*) &TMP45086)));
F.line = 98;F.filename = "options.nim";
Gkeepcomments_45111 = NIM_TRUE;
F.line = 99;F.filename = "options.nim";
asgnRefNoCycle((void**) &Gimplicitmods_45128, (TY4177*) newSeq(NTI4177, 0));
F.line = 197;F.filename = "options.nim";
memset((void*)&LOC1, 0, sizeof(LOC1));
asgnRefNoCycle((void**) &Gconfigvars_45108, Newstringtable_44019(LOC1, 0, ((NU8) 2)));
framePtr = framePtr->prev;
}

