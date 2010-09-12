/* Generated by Nimrod Compiler v0.8.9 */
/*   (c) 2010 Andreas Rumpf */

typedef long int NI;
typedef unsigned long int NU;
#include "nimbase.h"

#include <math.h>
#include <time.h>
typedef struct TY95802 TY95802;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
struct TNimType {
NI size;
NU8 kind;
NU8 flags;
TNimType* base;
TNimNode* node;
void* finalizer;
};
struct TY95802 {
TNimType* m_type;
NI N;
NF Sum;
NF Min;
NF Max;
NF Mean;
NF Oldm;
NF Olds;
NF News;
};
struct TNimNode {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
N_NIMCALL(NU8, Classify_95212)(NF X_95214);
N_NIMCALL(NI, Binom_95216)(NI N_95218, NI K_95219);
N_NIMCALL(NI, Fac_95253)(NI N_95255);
N_NIMCALL(NIM_BOOL, Ispoweroftwo_95270)(NI X_95272);
N_NIMCALL(NI, Nextpoweroftwo_95276)(NI X_95278);
N_NIMCALL(NI, Countbits32_95413)(NI32 N_95415);
N_NIMCALL(NF, Mean_95428)(NF* X_95431, NI X_95431Len0);
N_NIMCALL(NF, Variance_95495)(NF* X_95498, NI X_95498Len0);
N_NIMCALL(NF, Log2_95540)(NF X_95542);
N_NIMCALL(void, Randomize_95529)(void);
N_NIMCALL(NI, Random_95526)(NI Max_95528);
N_NIMCALL(void, Push_95811)(TY95802* S_95814, NF X_95815);
N_NIMCALL(NF, Variance_95830)(TY95802* S_95832);
N_NIMCALL(NF, Standarddeviation_95836)(TY95802* S_95838);
N_NIMCALL(NF, Sum_95438)(NF* X_95442, NI X_95442Len0);
N_NIMCALL(NU8, Classify_95212)(NF X_95214) {
NU8 Result_95215;
Result_95215 = 0;
if (!(X_95214 == 0.00000)) goto LA2;
if (!((1.00000 / X_95214) == INF)) goto LA5;
Result_95215 = ((NU8) 2);
goto BeforeRet;
goto LA4;
LA5: ;
Result_95215 = ((NU8) 3);
goto BeforeRet;
LA4: ;
LA2: ;
if (!((X_95214 * 0.500000) == X_95214)) goto LA8;
if (!(0.00000 < X_95214)) goto LA11;
Result_95215 = ((NU8) 5);
goto BeforeRet;
goto LA10;
LA11: ;
Result_95215 = ((NU8) 6);
goto BeforeRet;
LA10: ;
LA8: ;
if (!!((X_95214 == X_95214))) goto LA14;
Result_95215 = ((NU8) 4);
goto BeforeRet;
LA14: ;
Result_95215 = ((NU8) 0);
goto BeforeRet;
BeforeRet: ;
return Result_95215;
}
N_NIMCALL(NI, Binom_95216)(NI N_95218, NI K_95219) {
NI Result_95220;
NI I_95247;
NI Res_95250;
Result_95220 = 0;
if (!(K_95219 <= 0)) goto LA2;
Result_95220 = 1;
goto BeforeRet;
LA2: ;
if (!(N_95218 < (NI32)(2 * K_95219))) goto LA5;
Result_95220 = Binom_95216(N_95218, (NI32)(N_95218 - K_95219));
goto BeforeRet;
LA5: ;
Result_95220 = N_95218;
I_95247 = 0;
Res_95250 = 0;
Res_95250 = 2;
while (1) {
if (!(Res_95250 <= K_95219)) goto LA7;
I_95247 = Res_95250;
Result_95220 = (NI32)((NI32)(Result_95220 * (NI32)((NI32)(N_95218 + 1) - I_95247)) / I_95247);
Res_95250 += 1;
} LA7: ;
BeforeRet: ;
return Result_95220;
}
N_NIMCALL(NI, Fac_95253)(NI N_95255) {
NI Result_95256;
NI I_95264;
NI Res_95267;
Result_95256 = 0;
Result_95256 = 1;
I_95264 = 0;
Res_95267 = 0;
Res_95267 = 2;
while (1) {
if (!(Res_95267 <= N_95255)) goto LA1;
I_95264 = Res_95267;
Result_95256 = (NI32)(Result_95256 * I_95264);
Res_95267 += 1;
} LA1: ;
return Result_95256;
}
N_NIMCALL(NIM_BOOL, Ispoweroftwo_95270)(NI X_95272) {
NIM_BOOL Result_95273;
Result_95273 = 0;
Result_95273 = ((NI32)(X_95272 & ((NI32)-(X_95272))) == X_95272);
goto BeforeRet;
BeforeRet: ;
return Result_95273;
}
N_NIMCALL(NI, Nextpoweroftwo_95276)(NI X_95278) {
NI Result_95279;
Result_95279 = 0;
Result_95279 = (NI32)(X_95278 - 1);
Result_95279 = (NI32)(Result_95279 | (NI32)((NU32)(Result_95279) >> (NU32)(16)));
Result_95279 = (NI32)(Result_95279 | (NI32)((NU32)(Result_95279) >> (NU32)(8)));
Result_95279 = (NI32)(Result_95279 | (NI32)((NU32)(Result_95279) >> (NU32)(4)));
Result_95279 = (NI32)(Result_95279 | (NI32)((NU32)(Result_95279) >> (NU32)(2)));
Result_95279 = (NI32)(Result_95279 | (NI32)((NU32)(Result_95279) >> (NU32)(1)));
Result_95279 += 1;
return Result_95279;
}
N_NIMCALL(NI, Countbits32_95413)(NI32 N_95415) {
NI Result_95416;
NI32 V_95417;
Result_95416 = 0;
V_95417 = 0;
V_95417 = N_95415;
V_95417 = (NI32)((NU32)(V_95417) - (NU32)((NI32)((NI32)((NU32)(V_95417) >> (NU32)(((NI32) 1))) & ((NI32) 1431655765))));
V_95417 = (NI32)((NU32)((NI32)(V_95417 & ((NI32) 858993459))) + (NU32)((NI32)((NI32)((NU32)(V_95417) >> (NU32)(((NI32) 2))) & ((NI32) 858993459))));
Result_95416 = ((NI) ((NI32)((NU32)((NI32)((NU32)((NI32)((NI32)((NU32)(V_95417) + (NU32)((NI32)((NU32)(V_95417) >> (NU32)(((NI32) 4))))) & ((NI32) 252645135))) * (NU32)(((NI32) 16843009)))) >> (NU32)(((NI32) 24)))));
return Result_95416;
}
N_NIMCALL(NF, Mean_95428)(NF* X_95431, NI X_95431Len0) {
NF Result_95432;
NF LOC1;
Result_95432 = 0;
LOC1 = Sum_95438(X_95431, X_95431Len0);
Result_95432 = (LOC1 / ((double) (X_95431Len0)));
return Result_95432;
}
N_NIMCALL(NF, Variance_95495)(NF* X_95498, NI X_95498Len0) {
NF Result_95499;
NF M_95500;
NI I_95508;
NI HEX3Atmp_95521;
NI Res_95523;
NF Diff_95509;
Result_95499 = 0;
Result_95499 = 0.00000;
M_95500 = 0;
M_95500 = Mean_95428(X_95498, X_95498Len0);
I_95508 = 0;
HEX3Atmp_95521 = 0;
HEX3Atmp_95521 = (X_95498Len0-1);
Res_95523 = 0;
Res_95523 = 0;
while (1) {
if (!(Res_95523 <= HEX3Atmp_95521)) goto LA1;
I_95508 = Res_95523;
Diff_95509 = 0;
Diff_95509 = (X_95498[I_95508] - M_95500);
Result_95499 = (Result_95499 + (Diff_95509 * Diff_95509));
Res_95523 += 1;
} LA1: ;
Result_95499 = (Result_95499 / ((double) (X_95498Len0)));
return Result_95499;
}
N_NIMCALL(NF, Log2_95540)(NF X_95542) {
NF Result_95543;
NF LOC1;
NF LOC2;
Result_95543 = 0;
LOC1 = log(X_95542);
LOC2 = log(2.00000);
Result_95543 = (LOC1 / LOC2);
goto BeforeRet;
BeforeRet: ;
return Result_95543;
}
N_NIMCALL(void, Randomize_95529)(void) {
NI32 LOC1;
LOC1 = time(NIM_NIL);
srand(LOC1);
}
N_NIMCALL(NI, Random_95526)(NI Max_95528) {
NI Result_95605;
NI32 LOC1;
Result_95605 = 0;
LOC1 = rand();
Result_95605 = (NI32)(((NI) (LOC1)) % Max_95528);
goto BeforeRet;
BeforeRet: ;
return Result_95605;
}
N_NIMCALL(void, Push_95811)(TY95802* S_95814, NF X_95815) {
(*S_95814).N += 1;
if (!((*S_95814).N == 1)) goto LA2;
(*S_95814).Oldm = X_95815;
(*S_95814).Mean = X_95815;
(*S_95814).Olds = 0.00000;
goto LA1;
LA2: ;
(*S_95814).Mean = ((*S_95814).Oldm + ((X_95815 - (*S_95814).Oldm) / ((double) ((*S_95814).N))));
(*S_95814).News = ((*S_95814).Olds + ((X_95815 - (*S_95814).Oldm) * (X_95815 - (*S_95814).Mean)));
(*S_95814).Oldm = (*S_95814).Mean;
(*S_95814).Olds = (*S_95814).News;
LA1: ;
(*S_95814).Sum = ((*S_95814).Sum + X_95815);
if (!(X_95815 < (*S_95814).Min)) goto LA5;
(*S_95814).Min = X_95815;
LA5: ;
if (!((*S_95814).Max < X_95815)) goto LA8;
(*S_95814).Max = X_95815;
LA8: ;
}
N_NIMCALL(NF, Variance_95830)(TY95802* S_95832) {
NF Result_95833;
Result_95833 = 0;
if (!(1 < (*S_95832).N)) goto LA2;
Result_95833 = ((*S_95832).News / ((double) ((NI32)((*S_95832).N - 1))));
LA2: ;
return Result_95833;
}
N_NIMCALL(NF, Standarddeviation_95836)(TY95802* S_95838) {
NF Result_95839;
NF LOC1;
Result_95839 = 0;
LOC1 = Variance_95830(S_95838);
Result_95839 = sqrt(LOC1);
return Result_95839;
}
N_NIMCALL(NF, Sum_95438)(NF* X_95442, NI X_95442Len0) {
NF Result_95443;
NF I_95479;
NI I_95492;
Result_95443 = 0;
I_95479 = 0;
I_95492 = 0;
I_95492 = 0;
while (1) {
if (!(I_95492 < X_95442Len0)) goto LA1;
I_95479 = X_95442[I_95492];
Result_95443 = (Result_95443 + I_95479);
I_95492 += 1;
} LA1: ;
return Result_95443;
}
N_NOINLINE(void, mathInit)(void) {
volatile struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename;NI len;
} F;
F.procname = "math";
F.prev = framePtr;
F.filename = "/home/andreas/projects/nimrod/lib/pure/math.nim";
F.line = 0;
framePtr = (TFrame*)&F;
F.len = 0;
framePtr = framePtr->prev;
}

