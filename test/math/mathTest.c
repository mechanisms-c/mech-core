//
//  mathTest.c
//  mechanisms
//
//  Created by Eric Hosick on 4/4/15.
//  Copyright (c) 2015 Eric Hosick. All rights reserved.
//

#include "mathTest.h"
#include "mechCore.h"
#include "mmath.h"
#include "primitives.h"

static Mech mathEqIntTest() {
    evalBool(eqInt(num(3), num(3)));
    return EMPTY;
}

Mech mathTest() {
    mathEqIntTest();
    return EMPTY;
}