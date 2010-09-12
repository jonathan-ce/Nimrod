/* Generated by Nimrod Compiler v0.8.9 */
/*   (c) 2010 Andreas Rumpf */

typedef long int NI;
typedef unsigned long int NU;
#include "nimbase.h"

#include <time.h>
#include <sys/select.h>
#include <sys/time.h>
typedef struct TY27602 TY27602;
typedef struct TNimObject TNimObject;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
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
struct TY27602 {
  TNimObject Sup;
NI Second;
NI Minute;
NI Hour;
NI Monthday;
NU8 Month;
NI Year;
NU8 Weekday;
NI Yearday;
};
struct TNimNode {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
typedef NU8 TY27848[7];
typedef NI TY27857[7];
struct TGenericSeq {
NI len;
NI space;
};
typedef NIM_CHAR TY239[100000001];
struct NimStringDesc {
  TGenericSeq Sup;
TY239 data;
};
N_NIMCALL(NIM_BOOL, ntLtTime)(NI A_27639, NI B_27640);
N_NIMCALL(NIM_BOOL, ntLeTime)(NI A_27646, NI B_27647);
N_NIMCALL(TY27602, Tmtotimeinfo_27843)(struct tm* Tm_27845);
static N_INLINE(NI, chckRange)(NI I_4410, NI A_4411, NI B_4412);
N_NOINLINE(void, raiseRangeError)(NI64 Val_5218);
static N_INLINE(NI, addInt)(NI A_5603, NI B_5604);
N_NOINLINE(void, raiseOverflow)(void);
N_NOINLINE(void, raiseIndexError)(void);
N_NIMCALL(struct tm, Timeinfototm_27852)(TY27602* T_27854);
static N_INLINE(NI, subInt)(NI A_5803, NI B_5804);
N_NIMCALL(NI64, ntDiffTime)(NI A_27635, NI B_27636);
N_NIMCALL(NI, Getstartmilsecs_27651)(void);
static N_INLINE(NI, divInt)(NI A_6203, NI B_6204);
N_NOINLINE(void, raiseDivByZero)(void);
N_NIMCALL(NI, Gettime_27616)(void);
N_NIMCALL(TY27602, Getlocaltime_27618)(NI T_27620);
N_NIMCALL(TY27602, Getgmtime_27621)(NI T_27623);
N_NIMCALL(NI, Timeinfototime_27624)(TY27602* Timeinfo_27626);
N_NIMCALL(NimStringDesc*, Tostringtillnl_28421)(NCSTRING P_28423);
N_NIMCALL(NimStringDesc*, copyString)(NimStringDesc* Src_17308);
N_NIMCALL(NimStringDesc*, addChar)(NimStringDesc* S_1603, NIM_CHAR C_1604);
N_NIMCALL(NimStringDesc*, HEX24_27627)(TY27602* Timeinfo_27629);
N_NIMCALL(NimStringDesc*, HEX24_27630)(NI Time_27632);
N_NIMCALL(NI64, Unixtimetowintime_28457)(NI T_28459);
N_NIMCALL(NI64, mulInt64)(NI64 A_5579, NI64 B_5580);
static N_INLINE(NI64, addInt64)(NI64 A_5529, NI64 B_5530);
N_NIMCALL(NI, Wintimetounixtime_28461)(NI64 T_28463);
static N_INLINE(NI64, subInt64)(NI64 A_5538, NI64 B_5539);
static N_INLINE(NI64, divInt64)(NI64 A_5561, NI64 B_5562);
N_NIMCALL(NI64, chckRange64)(NI64 I_5323, NI64 A_5324, NI64 B_5325);
N_NIMCALL(NF, ntepochTime)(void);
N_NIMCALL(NF, ntcpuTime)(void);
N_NIMCALL(NimStringDesc*, ntgetDateStr)(void);
N_NIMCALL(NimStringDesc*, nimIntToStr)(NI X_18003);
static N_INLINE(void, appendString)(NimStringDesc* Dest_17392, NimStringDesc* Src_17393);
static N_INLINE(void, appendChar)(NimStringDesc* Dest_17409, NIM_CHAR C_17410);
N_NIMCALL(NimStringDesc*, nsuIntToStr)(NI X_24471, NI Minchars_24472);
N_NIMCALL(NimStringDesc*, rawNewString)(NI Space_17287);
N_NIMCALL(NimStringDesc*, ntgetClockStr)(void);
NIM_CONST TY27848 Weekdays_27847 = {((NU8) 6),
((NU8) 0),
((NU8) 1),
((NU8) 2),
((NU8) 3),
((NU8) 4),
((NU8) 5)}
;
extern NIM_CONST TY27848 Weekdays_27847;
NIM_CONST TY27857 Weekdays_27856 = {1,
2,
3,
4,
5,
6,
0}
;
extern NIM_CONST TY27857 Weekdays_27856;
STRING_LITERAL(TMP29009, "", 0);
extern TNimType* NTI27602; /* TTimeInfo */
N_NIMCALL(NIM_BOOL, ntLtTime)(NI A_27639, NI B_27640) {
NIM_BOOL Result_27641;
NI64 LOC1;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "<";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/pure/times.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_27641 = 0;
F.line = 137;F.filename = "times.nim";
LOC1 = ntDiffTime(A_27639, B_27640);
Result_27641 = (LOC1 < 0);
framePtr = framePtr->prev;
return Result_27641;
}
N_NIMCALL(NIM_BOOL, ntLeTime)(NI A_27646, NI B_27647) {
NIM_BOOL Result_27648;
NI64 LOC1;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "<=";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/pure/times.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_27648 = 0;
F.line = 142;F.filename = "times.nim";
LOC1 = ntDiffTime(A_27646, B_27647);
Result_27648 = (LOC1 <= 0);
framePtr = framePtr->prev;
return Result_27648;
}
static N_INLINE(NI, chckRange)(NI I_4410, NI A_4411, NI B_4412) {
NI Result_5316;
NIM_BOOL LOC2;
Result_5316 = 0;
LOC2 = (A_4411 <= I_4410);
if (!(LOC2)) goto LA3;
LOC2 = (I_4410 <= B_4412);
LA3: ;
if (!LOC2) goto LA4;
Result_5316 = I_4410;
goto BeforeRet;
goto LA1;
LA4: ;
raiseRangeError(((NI64) (I_4410)));
LA1: ;
BeforeRet: ;
return Result_5316;
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
N_NIMCALL(TY27602, Tmtotimeinfo_27843)(struct tm* Tm_27845) {
TY27602 Result_27846;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "tmToTimeInfo";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/pure/times.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
memset((void*)&Result_27846, 0, sizeof(Result_27846));
Result_27846.Sup.m_type = NTI27602;
F.line = 207;F.filename = "times.nim";
Result_27846.Second = ((NI) (((NI) ((*Tm_27845).tm_sec))));
F.line = 208;F.filename = "times.nim";
Result_27846.Minute = ((NI) (((NI) ((*Tm_27845).tm_min))));
F.line = 209;F.filename = "times.nim";
Result_27846.Hour = ((NI) (((NI) ((*Tm_27845).tm_hour))));
F.line = 210;F.filename = "times.nim";
Result_27846.Monthday = ((NI) (((NI) ((*Tm_27845).tm_mday))));
F.line = 211;F.filename = "times.nim";
Result_27846.Month = ((NU8)chckRange((*Tm_27845).tm_mon, ((NU8) 0), ((NU8) 11)));
F.line = 212;F.filename = "times.nim";
Result_27846.Year = ((NI) (addInt((*Tm_27845).tm_year, ((NI32) 1900))));
F.line = 213;F.filename = "times.nim";
if ((NU)(((NI) ((*Tm_27845).tm_wday))) > (NU)(6)) raiseIndexError();
Result_27846.Weekday = Weekdays_27847[(((NI) ((*Tm_27845).tm_wday)))-0];
F.line = 214;F.filename = "times.nim";
Result_27846.Yearday = ((NI) (((NI) ((*Tm_27845).tm_yday))));
framePtr = framePtr->prev;
return Result_27846;
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
N_NIMCALL(struct tm, Timeinfototm_27852)(TY27602* T_27854) {
struct tm Result_27855;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "timeInfoToTM";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/pure/times.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
memset((void*)&Result_27855, 0, sizeof(Result_27855));
F.line = 219;F.filename = "times.nim";
Result_27855.tm_sec = ((int) ((*T_27854).Second));
F.line = 220;F.filename = "times.nim";
Result_27855.tm_min = ((int) ((*T_27854).Minute));
F.line = 221;F.filename = "times.nim";
Result_27855.tm_hour = ((int) ((*T_27854).Hour));
F.line = 222;F.filename = "times.nim";
Result_27855.tm_mday = ((int) ((*T_27854).Monthday));
F.line = 223;F.filename = "times.nim";
Result_27855.tm_mon = ((int) ((*T_27854).Month));
F.line = 224;F.filename = "times.nim";
Result_27855.tm_year = ((int) (subInt((*T_27854).Year, 1900)));
F.line = 225;F.filename = "times.nim";
Result_27855.tm_wday = ((int) (Weekdays_27856[((*T_27854).Weekday)-0]));
F.line = 226;F.filename = "times.nim";
Result_27855.tm_yday = ((int) ((*T_27854).Yearday));
F.line = 227;F.filename = "times.nim";
Result_27855.tm_isdst = ((NI32) -1);
framePtr = framePtr->prev;
return Result_27855;
}
N_NIMCALL(NI64, ntDiffTime)(NI A_27635, NI B_27636) {
NI64 Result_27869;
NF LOC1;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "-";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/pure/times.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_27869 = 0;
F.line = 231;F.filename = "times.nim";
F.line = 231;F.filename = "times.nim";
LOC1 = difftime(A_27635, B_27636);
Result_27869 = float64ToInt64(((NF64) (LOC1)));
goto BeforeRet;
BeforeRet: ;
framePtr = framePtr->prev;
return Result_27869;
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
N_NIMCALL(NI, Getstartmilsecs_27651)(void) {
NI Result_28003;
NI LOC1;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "getStartMilsecs";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/pure/times.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_28003 = 0;
F.line = 239;F.filename = "times.nim";
LOC1 = clock();
Result_28003 = divInt(((NI) (LOC1)), divInt(CLOCKS_PER_SEC, 1000));
framePtr = framePtr->prev;
return Result_28003;
}
N_NIMCALL(NI, Gettime_27616)(void) {
NI Result_28403;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "getTime";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/pure/times.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_28403 = 0;
F.line = 246;F.filename = "times.nim";
F.line = 246;F.filename = "times.nim";
Result_28403 = time(NIM_NIL);
goto BeforeRet;
BeforeRet: ;
framePtr = framePtr->prev;
return Result_28403;
}
N_NIMCALL(TY27602, Getlocaltime_27618)(NI T_27620) {
TY27602 Result_28407;
NI A_28408;
struct tm* LOC1;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "getLocalTime";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/pure/times.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
memset((void*)&Result_28407, 0, sizeof(Result_28407));
Result_28407.Sup.m_type = NTI27602;
A_28408 = 0;
F.line = 248;F.filename = "times.nim";
A_28408 = T_27620;
F.line = 249;F.filename = "times.nim";
LOC1 = localtime(&A_28408);
Result_28407 = Tmtotimeinfo_27843(&(*LOC1));
framePtr = framePtr->prev;
return Result_28407;
}
N_NIMCALL(TY27602, Getgmtime_27621)(NI T_27623) {
TY27602 Result_28413;
NI A_28414;
struct tm* LOC1;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "getGMTime";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/pure/times.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
memset((void*)&Result_28413, 0, sizeof(Result_28413));
Result_28413.Sup.m_type = NTI27602;
A_28414 = 0;
F.line = 254;F.filename = "times.nim";
A_28414 = T_27623;
F.line = 255;F.filename = "times.nim";
LOC1 = gmtime(&A_28414);
Result_28413 = Tmtotimeinfo_27843(&(*LOC1));
framePtr = framePtr->prev;
return Result_28413;
}
N_NIMCALL(NI, Timeinfototime_27624)(TY27602* Timeinfo_27626) {
NI Result_28419;
TY27602 Ctimeinfo_28420;
struct tm LOC1;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "TimeInfoToTime";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/pure/times.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_28419 = 0;
memset((void*)&Ctimeinfo_28420, 0, sizeof(Ctimeinfo_28420));
F.line = 260;F.filename = "times.nim";
Ctimeinfo_28420 = (*Timeinfo_27626);
Ctimeinfo_28420.Sup.m_type = NTI27602;
F.line = 262;F.filename = "times.nim";
F.line = 262;F.filename = "times.nim";
LOC1 = Timeinfototm_27852(&Ctimeinfo_28420);
Result_28419 = mktime(&LOC1);
goto BeforeRet;
BeforeRet: ;
framePtr = framePtr->prev;
return Result_28419;
}
N_NIMCALL(NimStringDesc*, Tostringtillnl_28421)(NCSTRING P_28423) {
NimStringDesc* Result_28424;
NI I_28425;
NIM_BOOL LOC2;
NIM_BOOL LOC3;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "toStringTillNL";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/pure/times.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_28424 = 0;
F.line = 265;F.filename = "times.nim";
Result_28424 = copyString(((NimStringDesc*) &TMP29009));
I_28425 = 0;
F.line = 266;F.filename = "times.nim";
I_28425 = 0;
F.line = 267;F.filename = "times.nim";
while (1) {
LOC3 = !(((NU8)(P_28423[I_28425]) == (NU8)(0)));
if (!(LOC3)) goto LA4;
LOC3 = !(((NU8)(P_28423[I_28425]) == (NU8)(10)));
LA4: ;
LOC2 = LOC3;
if (!(LOC2)) goto LA5;
LOC2 = !(((NU8)(P_28423[I_28425]) == (NU8)(13)));
LA5: ;
if (!LOC2) goto LA1;
F.line = 268;F.filename = "times.nim";
Result_28424 = addChar(Result_28424, P_28423[I_28425]);
F.line = 269;F.filename = "times.nim";
I_28425 = addInt(I_28425, 1);
} LA1: ;
framePtr = framePtr->prev;
return Result_28424;
}
N_NIMCALL(NimStringDesc*, HEX24_27627)(TY27602* Timeinfo_27629) {
NimStringDesc* Result_28447;
NCSTRING P_28448;
struct tm LOC1;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "$";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/pure/times.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_28447 = 0;
P_28448 = 0;
F.line = 273;F.filename = "times.nim";
LOC1 = Timeinfototm_27852(Timeinfo_27629);
P_28448 = asctime(&LOC1);
F.line = 274;F.filename = "times.nim";
Result_28447 = Tostringtillnl_28421(P_28448);
framePtr = framePtr->prev;
return Result_28447;
}
N_NIMCALL(NimStringDesc*, HEX24_27630)(NI Time_27632) {
NimStringDesc* Result_28452;
NI A_28453;
NCSTRING LOC1;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "$";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/pure/times.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_28452 = 0;
A_28453 = 0;
F.line = 278;F.filename = "times.nim";
A_28453 = Time_27632;
F.line = 279;F.filename = "times.nim";
F.line = 279;F.filename = "times.nim";
LOC1 = ctime(&A_28453);
Result_28452 = Tostringtillnl_28421(LOC1);
goto BeforeRet;
BeforeRet: ;
framePtr = framePtr->prev;
return Result_28452;
}
static N_INLINE(NI64, addInt64)(NI64 A_5529, NI64 B_5530) {
NI64 Result_5531;
NIM_BOOL LOC2;
Result_5531 = 0;
Result_5531 = (NI64)((NU64)(A_5529) + (NU64)(B_5530));
LOC2 = (0 <= (Result_5531 ^ A_5529));
if (LOC2) goto LA3;
LOC2 = (0 <= (Result_5531 ^ B_5530));
LA3: ;
if (!LOC2) goto LA4;
goto BeforeRet;
LA4: ;
raiseOverflow();
BeforeRet: ;
return Result_5531;
}
N_NIMCALL(NI64, Unixtimetowintime_28457)(NI T_28459) {
NI64 Result_28460;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "unixTimeToWinTime";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/pure/times.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_28460 = 0;
F.line = 287;F.filename = "times.nim";
Result_28460 = addInt64(mulInt64(((NI64) (T_28459)), 10000000), IL64(116444736000000000));
framePtr = framePtr->prev;
return Result_28460;
}
static N_INLINE(NI64, subInt64)(NI64 A_5538, NI64 B_5539) {
NI64 Result_5540;
NIM_BOOL LOC2;
Result_5540 = 0;
Result_5540 = (NI64)((NU64)(A_5538) - (NU64)(B_5539));
LOC2 = (0 <= (Result_5540 ^ A_5538));
if (LOC2) goto LA3;
LOC2 = (0 <= (Result_5540 ^ ~(B_5539)));
LA3: ;
if (!LOC2) goto LA4;
goto BeforeRet;
LA4: ;
raiseOverflow();
BeforeRet: ;
return Result_5540;
}
static N_INLINE(NI64, divInt64)(NI64 A_5561, NI64 B_5562) {
NI64 Result_5563;
NIM_BOOL LOC5;
Result_5563 = 0;
if (!(B_5562 == 0)) goto LA2;
raiseDivByZero();
LA2: ;
LOC5 = (A_5561 == (IL64(-9223372036854775807) - IL64(1)));
if (!(LOC5)) goto LA6;
LOC5 = (B_5562 == -1);
LA6: ;
if (!LOC5) goto LA7;
raiseOverflow();
LA7: ;
Result_5563 = (NI64)(A_5561 / B_5562);
goto BeforeRet;
BeforeRet: ;
return Result_5563;
}
N_NIMCALL(NI, Wintimetounixtime_28461)(NI64 T_28463) {
NI Result_28464;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "winTimeToUnixTime";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/pure/times.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_28464 = 0;
F.line = 291;F.filename = "times.nim";
Result_28464 = ((NI)chckRange64(divInt64(subInt64(T_28463, IL64(116444736000000000)), 10000000), (-2147483647 -1), 2147483647));
framePtr = framePtr->prev;
return Result_28464;
}
N_NIMCALL(NF, ntepochTime)(void) {
NF Result_28467;
struct timeval A_28468;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "epochTime";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/pure/times.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_28467 = 0;
memset((void*)&A_28468, 0, sizeof(A_28468));
F.line = 297;F.filename = "times.nim";
gettimeofday(&A_28468, NIM_NIL);
F.line = 298;F.filename = "times.nim";
Result_28467 = (((double) (A_28468.tv_sec)) + (((double) (A_28468.tv_usec)) * 0.00100000));
framePtr = framePtr->prev;
return Result_28467;
}
N_NIMCALL(NF, ntcpuTime)(void) {
NF Result_28603;
NI LOC1;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "cpuTime";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/pure/times.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_28603 = 0;
F.line = 311;F.filename = "times.nim";
LOC1 = clock();
Result_28603 = (((double) (((NI) (LOC1)))) / ((double) (CLOCKS_PER_SEC)));
framePtr = framePtr->prev;
return Result_28603;
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
N_NIMCALL(NimStringDesc*, ntgetDateStr)(void) {
NimStringDesc* Result_29012;
TY27602 Ti_29013;
NI LOC1;
NimStringDesc* LOC2;
NimStringDesc* LOC3;
NimStringDesc* LOC4;
NimStringDesc* LOC5;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "getDateStr";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/pure/times.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_29012 = 0;
memset((void*)&Ti_29013, 0, sizeof(Ti_29013));
F.line = 365;F.filename = "times.nim";
LOC1 = Gettime_27616();
Ti_29013 = Getlocaltime_27618(LOC1);
Ti_29013.Sup.m_type = NTI27602;
F.line = 366;F.filename = "times.nim";
LOC2 = 0;
LOC3 = 0;
LOC3 = nimIntToStr(Ti_29013.Year);
LOC4 = 0;
LOC4 = nsuIntToStr(addInt(Ti_29013.Month, 1), 2);
LOC5 = 0;
LOC5 = nsuIntToStr(((NI) (Ti_29013.Monthday)), 2);
LOC2 = rawNewString(LOC3->Sup.len + LOC4->Sup.len + LOC5->Sup.len + 2);
appendString(LOC2, LOC3);
appendChar(LOC2, 45);
appendString(LOC2, LOC4);
appendChar(LOC2, 45);
appendString(LOC2, LOC5);
Result_29012 = LOC2;
framePtr = framePtr->prev;
return Result_29012;
}
N_NIMCALL(NimStringDesc*, ntgetClockStr)(void) {
NimStringDesc* Result_29047;
TY27602 Ti_29048;
NI LOC1;
NimStringDesc* LOC2;
NimStringDesc* LOC3;
NimStringDesc* LOC4;
NimStringDesc* LOC5;
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "getClockStr";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/pure/times.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
Result_29047 = 0;
memset((void*)&Ti_29048, 0, sizeof(Ti_29048));
F.line = 371;F.filename = "times.nim";
LOC1 = Gettime_27616();
Ti_29048 = Getlocaltime_27618(LOC1);
Ti_29048.Sup.m_type = NTI27602;
F.line = 372;F.filename = "times.nim";
LOC2 = 0;
LOC3 = 0;
LOC3 = nsuIntToStr(((NI) (Ti_29048.Hour)), 2);
LOC4 = 0;
LOC4 = nsuIntToStr(((NI) (Ti_29048.Minute)), 2);
LOC5 = 0;
LOC5 = nsuIntToStr(((NI) (Ti_29048.Second)), 2);
LOC2 = rawNewString(LOC3->Sup.len + LOC4->Sup.len + LOC5->Sup.len + 2);
appendString(LOC2, LOC3);
appendChar(LOC2, 58);
appendString(LOC2, LOC4);
appendChar(LOC2, 58);
appendString(LOC2, LOC5);
Result_29047 = LOC2;
framePtr = framePtr->prev;
return Result_29047;
}
N_NOINLINE(void, timesInit)(void) {
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "times";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/pure/times.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
framePtr = framePtr->prev;
}

