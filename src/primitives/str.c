//
//  str.c
//  mechanisms
//
//  Created on: 3/21/15
//  authors:
//    Eric Hosick <erichosick@gmail.com>
//  license:
//    The MIT License (MIT)
//    Copyright (c) 2015 Eric Hosick
//

#include <stdio.h>   // malloc
#include "primitives.h"
#include "mechCore.h"
#include "mechMath.h" // INT64_NAN

static int64_t asInt(Mech this) {
    return 0;
};

static double asReal(Mech this) {
    return 0;
};

static bool asBool(Mech this) {
    return false;
}

static char* asStr(Mech this) {
    return ((StrStruct*)this)->d;
}

static char asChar(Mech this) {
    return 0; // TODO
}

static Mech asMechF(Mech this) {
    return this;
}

MechTypeStruct strMech = {
    .type = &strMech,
    .error = NULL,
    .majorVer = 1,
    .minorVer = 0,
    .flags = 0,
    .dataSize = sizeof(StrStruct),
    .name = "str",
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

MechTypeStruct strEmptyMech = {
    .type = &strMech,
    .error = NULL,
    .majorVer = 1,
    .minorVer = 0,
    .flags = 0x01,
    .dataSize = sizeof(NumStruct),
    .name = "strEmpty",
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

// The one empty instance
StrStruct strEmpty = {
    .type = &strEmptyMech,
    .error = NULL,
    .d = ""
};

Mech str(char* d) {
    StrStruct* this = (StrStruct*)malloc(sizeof(StrStruct));
    if(NULL != this) {
        this->type = &strMech;
        this->d = d;
    } else {
        this = &strEmpty;
    }
    return (Mech)this;
}
