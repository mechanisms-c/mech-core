//
//  num.c
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
    return ((NumStruct*)this)->d;
};

static double asReal(Mech this) {
    return (double)((NumStruct*)this)->d;
};

static bool asBool(Mech this) {
    return 0 < ((NumStruct*)this)->d;
}

static char* asStr(Mech this) {
    return ""; // TODO
}

static char asChar(Mech this) {
    return 0; // TODO
}

static Mech asMechF(Mech this) {
    return this; // TODO
}

MechTypeStruct numMech = {
    .type = &numMech,
    .error = NULL,
    .majorVer = 1,
    .minorVer = 0,
    .flags = 0,
    .dataSize = sizeof(NumStruct),
    .name = "num",
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


MechTypeStruct numEmptyMech = {
    .type = &numMech,
    .error = NULL,
    .majorVer = 1,
    .minorVer = 0,
    .flags = 0x01,
    .dataSize = sizeof(NumStruct),
    .name = "numEmpty",
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
NumStruct emptyNum = {
    .type = &numEmptyMech,
    .error = NULL,
    .d = INT64_NAN
};

Mech num(int64_t d) {
    NumStruct* this = (NumStruct*)malloc(sizeof(NumStruct));
    if(NULL != this) {
        this->type = &numMech;
        this->d = d;
    } else {
        this = &emptyNum;
    }
    return (Mech)this;
}
