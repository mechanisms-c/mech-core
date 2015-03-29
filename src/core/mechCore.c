//
//  mechCore.c
//  mechanisms
//
//  Created by Eric Hosick on 3/24/15.
//  Copyright (c) 2015 Eric Hosick. All rights reserved.
//

#include <stdlib.h>  // free

#include "mechType.h"
#include "mechCore.h"
#include "empty.h"

// Free allocated memory of ANY mechanism
void mechFree(Mech this) {
    if (EMPTY != this) { // Never 'free' the EMPTY Mechanism
        (this->type->delete)(this);
        free(this);
    }
}

// Allocate memory for ANY mechanism
// EMPTY Mechanism returned if unable to
// allocate memory.
Mech mechAlloc(MechType mechType) {
    Mech this = malloc(mechType->dataSize);
    if(NULL != this) {
        this->type = mechType;
    } else {
        this = EMPTY;
    }
    return this;
}

// Invoke a mechanism under a given primitive
// data type.

int64_t evalInt(Mech this) {
    int64_t result = (this->type->evalInt)(this);
    return result;
}

double evalReal(Mech this) {
    return (this->type->evalReal)(this);
}

bool evalBool(Mech this) {
    return (this->type->evalBool)(this);
}

char* evalStr(Mech this) {
    return (this->type->evalStr)(this);
}

char evalChar(Mech this) {
    return (this->type->evalChar)(this);
}

Mech evalMechF(Mech this) {
    return (this->type->evalMech)(this);
}

void evalVoid(Mech this) {
    (this->type->evalVoid)(this);
}
