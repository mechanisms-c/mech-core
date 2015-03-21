//
//  add.c
//  mechanisms
//
//  Created on: 3/21/15
//  authors:
//    Eric Hosick <erichosick@gmail.com>
//  license:
//    The MIT License (MIT)
//    Copyright (c) 2015 Eric Hosick
//

#include <assert.h>
#include <math.h> // NAN
#include "mathMech.h"
#include "coreMech.h"

// Add Mechanism
int64_t addInt(MechInstPtr this) {
    if(this) {
        DATA_GET(DualArgData);
        return evalInt(data->left) + evalInt(data->right);
    }
    return NAN;
};

double addReal(MechInstPtr this) {
    if(this) {
        DATA_GET(DualArgData);
        return evalReal(data->left) + evalReal(data->right);
    }
    return NAN;
};

MechType addMech = {
    .majorVer = 1,
    .minorVer = 0,
    .flags = 0,
    .dataSize = sizeof(DualArgData),
    .name = "add",
    .lookup = NULL,
    .delete = NULL,
    .evalNum = &addInt,
    .evalReal = &addReal,
    .evalBool = NULL
};

MechInstPtr add(MechInstPtr left, MechInstPtr right) {
    MechInstPtr this = mechAlloc(&addMech);
    if(this) {
        DATA_GET(DualArgData);
        data->left = left;
        data->right = right;
    }
    return this;
}





