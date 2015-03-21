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

#include <stdlib.h> // free
#include <math.h> // NAN
#include <stdbool.h> // bool
#include "primitives.h"

int64_t numInt(MechInstPtr this) {
    return this ? *((int64_t*)(this + sizeof(MechInstStruct))) : NAN;
};

double numReal(MechInstPtr this) {
    return this ? (double)*((uint64_t*)(this + sizeof(MechInstStruct))) : NAN;
};

bool numBool(MechInstPtr this) {
    return this ? (0 < *((uint64_t*)(this + sizeof(MechInstStruct)))) : false;
};

MechType numMech = {
    .majorVer = 1,
    .minorVer = 0,
    .flags = 0,
    .dataSize = sizeof(int64_t),
    .name = "num",
    .lookup = NULL,
    .delete = NULL,
    .evalNum = &numInt,
    .evalReal = &numReal,
    .evalBool = &numBool
};

MechInstPtr num(int64_t d) {
    MechInstPtr this = mechAlloc(&numMech);
    if(this) {
        int64_t* data = (int64_t*)(this + sizeof(MechInstStruct));
        *data = d;
    }
    return this;
}
