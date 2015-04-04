//
//  empty.c
//  mechanisms
//
//  Created on: 3/28/15
//  authors:
//    Eric Hosick <erichosick@gmail.com>
//  license:
//    The MIT License (MIT)
//    Copyright (c) 2015 Eric Hosick
//

#include <math.h>     // NAN
#include <stdbool.h>  // boolean
#include "mechType.h" // MechType
#include "mechMath.h" // INT64_MIN
#include "mechCore.h"

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

static int64_t asInt(Mech this) {
    return INT64_NAN;
};

static double asReal(Mech this) {
    return NAN;
};

static bool asBool(Mech this) {
    return false;
}

static char* asStr(Mech this) {
    return "";
}

static char asChar(Mech this) {
    return 0;
}

static Mech asMechF(Mech this) {
    return EMPTY;
}

MechTypeStruct emptyType = {
    .type = &emptyType,
    .error = (Mech)&emptyType,
    .majorVer = 1,
    .minorVer = 0,
    .flags = 0x01L,
    .dataSize = sizeof(EmptyStruct),
    .name = "empty",
    .lookup = &emptyVoid,
    .delete = &emptyVoid,
    .evalInt = &asInt,
    .evalReal = &asReal,
    .evalBool = &asBool,
    .evalStr = &asStr,
    .evalChar = &asChar,
    .evalMech = &asMechF,
    .evalVoid = &emptyVoid
};

Mech EMPTY_MECH = (Mech)&emptyType;

// The one empty instance
EmptyStruct emptyMech = {
    .type = (Mech)&emptyType,
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

Mech empty() {
    return EMPTY;
}