#define NULL 0
#define true 1
#define false 0
#define TWO 2

typedef enum {Ident1, Ident2, Ident3, Ident4, Ident5} Enumeration;
typedef int OneToFifty;
typedef int Array1Dim[50];
typedef int Array2Dim[50][50];

struct Record {
    struct Record *PtrComp;
    int Discr;
    Enumeration EnumComp;
    int IntComp;
    char StringComp[31];
};

int PageFound;
int i;
int j;
int PrintHeading;
int Run;
struct Record *PtrVal, *NextRecord;
int IntLoc;
char CharLoc;
int Array1[50];
int Array2[50][50];
char String[31], String1[31];
int IntGlob;
char CharGlob;
int Array1Glob[50];
char StringGlob[31];
int BoolGlob;
char Char1Loc, Char2Loc;
int IntLoc1, IntLoc2, IntLoc3;
char StrLoc1[31], StrLoc2[31];
int EndTime;
int StartTime;
int UserTime;
int Microseconds;
int Dhrystones_Per_Second;
int Iterations;
int Result;

int G_Array[8];

void Proc_1(struct Record *PtrParIn);
void Proc_2(int *IntParRef);
void Proc_3(struct Record *PtrParOut);
void Proc_4(void);
void Proc_5(void);
void Proc_6(int EnumParIn, int *EnumParOut);
void Proc_7(int IntParI1, int IntParI2, int *IntParOut);
void Proc_8(int Array1Par[50], int Array2Par[50][50], int IntParI1, int IntParI2, int *IntParOut);
int Func_1(char CharPar1, char CharPar2);
int Func_2(char *StrParI1, char *StrParI2);
int Func_3(Enumeration EnumParIn);

void Proc_1(struct Record *PtrParIn) {
    struct Record *NextRecord = PtrParIn->PtrComp;
    if (NextRecord == NULL) {
        PtrParIn->IntComp = 5;
    } else {
        PtrParIn->IntComp = NextRecord->IntComp;
    }
    PtrParIn->PtrComp = PtrParIn;
    return;
}

void Proc_2(int *IntParRef) {
    *IntParRef += 2;
    CharLoc = 'A';
    return;
}

void Proc_3(struct Record *PtrParOut) {
    if (PtrParOut->PtrComp == NULL) {
        PtrParOut->IntComp = 1;
    } else {
        IntLoc = PtrParOut->IntComp;
        PtrParOut->IntComp = IntLoc + 1;
    }
    return;
}

void Proc_4() {
    BoolGlob = !BoolGlob;
    return;
}

void Proc_5() {
    CharGlob = 'B';
    return;
}

void Proc_6(int EnumParIn, int *EnumParOut) {
    *EnumParOut = EnumParIn;
    if (!Func_3(EnumParIn)) {
        *EnumParOut = Ident4;
    }
    switch(EnumParIn) {
        case Ident1: *EnumParOut = Ident1; break;
        case Ident2: IntLoc = 200; break;
        case Ident3: IntLoc = 100; break;
        case Ident4: break;
        case Ident5: *EnumParOut = Ident5; break;
    }
    return;
}

void Proc_7(int IntParI1, int IntParI2, int *IntParOut) {
    IntLoc = IntParI1 + IntParI2;
    *IntParOut = IntLoc;
    return;
}

void Proc_8(int Array1Par[50], int Array2Par[50][50], int IntParI1, int IntParI2, int *IntParOut) {
    int i;
    IntLoc = IntParI1 + IntParI2;
    for (i = 0; i < 50; i++) {
        Array1Par[i] = Array2Par[IntLoc][i];
    }
    Array2Par[IntLoc][48] = IntLoc;
    *IntParOut = Array2Par[IntLoc][48];
    return;
}

int Func_1(char CharPar1, char CharPar2) {
    if (CharPar1 == CharPar2) {
        return true;
    }
    return false;
}

int Func_2(char *StrParI1, char *StrParI2) {
    int i;
    i = 0;
    while ((i < 31) && (StrParI1[i] == StrParI2[i])) {
        if (i < 30) i++;
        else break;
    }
    if (i == 31) return 0;
    return StrParI1[i] - StrParI2[i];
}

int Func_3(Enumeration EnumParIn) {
    int EnumLoc = EnumParIn;
    if (EnumLoc == 0) return true;
    return false;
}

void main() {
    OneToFifty IntLoc;
    int IntLoc1, IntLoc2, IntLoc3;
    char CharLoc;
    Enumeration EnumLoc;
    int stk[256];
    
    Iterations = 100;
    
    IntGlob = 0;
    BoolGlob = false;
    Char1Loc = 'A';
    Char2Loc = 'B';
    for (i = 0; i < 50; i++) Array1Glob[i] = i;
    for (i = 0; i < 31; i++) StringGlob[i] = 'C';
    StringGlob[30] = 0;
    
    struct Record Record1, Record2;
    Record1.PtrComp = &Record2;
    Record1.Discr = Ident1;
    Record1.EnumComp = Ident2;
    Record1.IntComp = 1;
    for (i = 0; i < 31; i++) Record1.StringComp[i] = 'A';
    Record1.StringComp[30] = 0;
    
    Record2.PtrComp = &Record1;
    Record2.Discr = Ident2;
    Record2.EnumComp = Ident1;
    Record2.IntComp = 2;
    for (i = 0; i < 31; i++) Record2.StringComp[i] = 'B';
    Record2.StringComp[30] = 0;
    
    PtrVal = &Record1;
    stk[255] = 0x80040000;
    
    for (Run = 1; Run <= Iterations; Run++) {
        Proc_1(&Record1);
        Proc_2(&IntLoc1);
        Proc_3(&Record2);
        Proc_4();
        Proc_5();
        Proc_6(Ident1, &EnumLoc);
        Proc_7(10, 25, &IntLoc2);
        Proc_8(Array1, Array2, 1, 10, &IntLoc3);
        if (Func_1('A', 'a')) IntLoc = 1;
        if (Func_1('A', 'A')) IntLoc = 2;
        IntLoc2 = Func_2(String1, String);
        while (IntLoc3 == IntLoc2) Proc_4();
        EnumLoc = Ident2;
    }
    
    Result = Run;
    
    volatile int *out = (volatile int *)0x100;
    out[0] = Result;
    out[1] = 0xDEADBEEF;
    
    while(1);
}
