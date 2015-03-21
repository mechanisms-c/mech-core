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

#include <math.h> // NAN
#include "writeLn.h"

// className Mechanism
static int64_t writeLnInt(MechInstPtr this) {
    if(this) {
        DATA_GET(SingleArgData);
        long result = evalInt(data->left);
        printf("%li\n", result);
        return result;
    }
    return NAN;
};

static double writeLnReal(MechInstPtr this) {
    if(this) {
        DATA_GET(SingleArgData);
        double result = evalReal(data->left);
        printf("%f\n", result);
        return result;
    }
    return NAN;
};

MechType writeLnType = {
    .majorVer = 1,
    .minorVer = 0,
    .flags = 0,
    .dataSize = sizeof(SingleArgData),
    .name = "writeLn",
    .lookup = NULL,
    .delete = NULL,
    .evalNum = &writeLnInt,
    .evalReal = &writeLnReal,
    .evalBool = NULL
};

MechInstPtr writeLn(MechInstPtr text) {
    MechInstPtr this = mechAlloc(&writeLnType);
    if(this) {
        DATA_GET(SingleArgData);
        data->left = text;
    }
    return this;
}
