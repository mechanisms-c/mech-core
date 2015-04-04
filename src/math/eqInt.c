//
//  eqInt.c
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
#include "mechCore.h"

static int64_t asInt(Mech this) {
    return evalBool(this);
};

static double asReal(Mech this) {
    return evalBool(this);
};

static bool asBool(Mech this) {
    return evalInt(((DualArgMech)this)->left) == evalInt(((DualArgMech)this)->right);
}

static char* asStr(Mech this) {
    return ""; // TODO
}

static char asChar(Mech this) {
    return evalBool(this);
}

static Mech asMechF(Mech this) {
    return this; // TODO
}

MechTypeStruct eqIntMech = {
    .type = &eqIntMech,
    .error = NULL,
    .majorVer = 1,
    .minorVer = 0,
    .flags = 0,
    .dataSize = sizeof(DualArgStruct),
    .name = "eqInt",
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

Mech eqInt(Mech left, Mech right) {
    Mech this = mechAlloc(&eqIntMech);
    if(EMPTY != this) {
        ((DualArgMech)this)->left = left;
        ((DualArgMech)this)->right= right;
    }
    return this;
}
