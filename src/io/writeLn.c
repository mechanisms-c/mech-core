//
//  writeLn.c
//  mechanisms
//
//  Created on: 3/21/15
//  authors:
//    Eric Hosick <erichosick@gmail.com>
//  license:
//    The MIT License (MIT)
//    Copyright (c) 2015 Eric Hosick
//

#include "mechCore.h"
#include "writeLn.h"

static int64_t asInt(Mech this) {
    int64_t result = evalInt(((SingleArgStruct*)this)->left);
    printf("%lli\n", result);
    return result;
};

static double asReal(Mech this) {
    double result = evalReal(((SingleArgStruct*)this)->left);
    printf("%f\n", result);
    return result;
};

static bool asBool(Mech this) {
    bool result = evalBool(((SingleArgStruct*)this)->left);
    printf("%i\n", result);
    return result;
}

static char* asStr(Mech this) {
    char* result = evalStr(((SingleArgStruct*)this)->left);
    printf("%s\n", result);
    return result;
}

static char asChar(Mech this) {
    char result = evalChar(((SingleArgStruct*)this)->left);
    printf("%c\n", result);
    return result;
}

static Mech asMechF(Mech this) {
    return this; // TODO: What does it mean to print a mechanism?
}

MechTypeStruct writeLnMech = {
    .type = &writeLnMech,
    .error = NULL,
    .majorVer = 1,
    .minorVer = 0,
    .flags = 0,
    .dataSize = sizeof(SingleArgStruct),
    .name = "writeLn",
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

Mech writeLn(Mech left) {
    Mech this = mechAlloc(&writeLnMech);
    if(EMPTY != this) {
        ((SingleArgMech)this)->left = left;
    }
    return this;
}
