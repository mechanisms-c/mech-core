//
//  empty.c
//  mechanisms
//
//  Created by Eric Hosick on 3/28/15.
//  Copyright (c) 2015 Eric Hosick. All rights reserved.
//

#include <math.h>     // NAN
#include <stdbool.h>  // boolean
#include "mechType.h" // MechType
#include "empty.h"

// An empty/null Mechanism.
typedef struct {
    Mech type;
    Mech error;
    Mech p01;
    Mech p02;
    Mech p03;
    Mech p04;
    Mech p05;
    Mech p06;
    Mech p07;
    Mech p08;
    Mech p09;
    Mech p10;
    Mech p11;
    Mech p12;
    Mech p13;
    Mech p14;
    Mech p15;
    Mech p16;
    Mech p17;
    Mech p18;
    Mech p19;
    Mech p20;
} EmptyStruct;

// The one empty instance
EmptyStruct emptyMech = {
    .type = (Mech)&emptyMech,
    .error = (Mech)&emptyMech,
    .p01 = (Mech)&emptyMech,
    .p02 = (Mech)&emptyMech,
    .p03 = (Mech)&emptyMech,
    .p04 = (Mech)&emptyMech,
    .p05 = (Mech)&emptyMech,
    .p06 = (Mech)&emptyMech,
    .p07 = (Mech)&emptyMech,
    .p08 = (Mech)&emptyMech,
    .p09 = (Mech)&emptyMech,
    .p10 = (Mech)&emptyMech,
    .p11 = (Mech)&emptyMech,
    .p12 = (Mech)&emptyMech,
    .p13 = (Mech)&emptyMech,
    .p14 = (Mech)&emptyMech,
    .p15 = (Mech)&emptyMech,
    .p16 = (Mech)&emptyMech,
    .p17 = (Mech)&emptyMech,
    .p18 = (Mech)&emptyMech,
    .p19 = (Mech)&emptyMech,
    .p20 = (Mech)&emptyMech
};

Mech EMPTY = (Mech)&emptyMech;

static int64_t emptyInt(Mech this) {
    return NAN;
};

static double emptyReal(Mech this) {
    return NAN;
};

static bool emptyBool(Mech this) {
    return false;
}

static char* emptyStr(Mech this) {
    return "";
}

static char emptyChar(Mech this) {
    return 0;
}

static Mech emptyMechF(Mech this) {
    return EMPTY;
}

static void emptyVoid(Mech this) {
}

MechTypeStruct emptyType = {
    .type = &emptyType,
    .error = (Mech)&emptyType,
    .majorVer = 1,
    .minorVer = 0,
    .flags = 0,
    .dataSize = sizeof(EmptyStruct),
    .name = "empty",
    .lookup = &emptyVoid,
    .delete = &emptyVoid,
    .evalInt = &emptyInt,
    .evalReal = &emptyReal,
    .evalBool = &emptyBool,
    .evalStr = &emptyStr,
    .evalChar = &emptyChar,
    .evalMech = &emptyMechF,
    .evalVoid = &emptyVoid
};

Mech EMPTY_MECH = (Mech)&emptyType;

Mech empty() {
    return EMPTY_MECH;
}