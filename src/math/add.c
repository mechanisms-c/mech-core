//
//  add.c
//  mechanisms
//
//  Created on: 4/04/15
//  authors:
//    Eric Hosick <erichosick@gmail.com>
//  license:
//    The MIT License (MIT)
//    Copyright (c) 2015 Eric Hosick
//

#include "mechCore.h"

static int64_t asInt(Mech this) {
    return evalInt(((DualArgMech)this)->left) + evalInt(((DualArgMech)this)->right);
};

static double asReal(Mech this) {
    return (double)asInt(this);
};

static bool asBool(Mech this) {
    return 0 < asInt(this);
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

MechTypeStruct addMech = {
    .type = &addMech,
    .error = NULL,
    .majorVer = 1,
    .minorVer = 0,
    .flags = 0,
    .dataSize = sizeof(DualArgStruct),
    .name = "add",
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

Mech add(Mech left, Mech right) {
    Mech this = mechAlloc(&addMech);
    if(EMPTY != this) {
        ((DualArgMech)this)->left = left;
        ((DualArgMech)this)->right= right;
    }
    return this;
}
