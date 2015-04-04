//
//  mechCore.c
//  mechanisms
//
//  Created on: 3/24/15
//  authors:
//    Eric Hosick <erichosick@gmail.com>
//  license:
//    The MIT License (MIT)
//    Copyright (c) 2015 Eric Hosick
//

#include <stdlib.h>  // free
#include "mechType.h"
#include "mechCore.h"

bool mechIsStatic(Mech this) {
    return FLAG2_IS_STATIC == (this->type->flags && FLAG2_IS_STATIC);
}

bool mechIsNotStatic(Mech this) {
    return FLAG2_IS_STATIC != (this->type->flags && FLAG2_IS_STATIC);
}

// Free allocated memory of ANY mechanism
// Never 'free' a staticalluy allocated Mechanism on the HEAP
void mechFree(Mech this) {
    if (mechIsNotStatic(this)) {
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

// Flags to uniquely identify a mechanism
const uint32_t FLAG2_IS_STATIC = 0x01;

// Invoke a mechanism under a given primitive
// data type.

int64_t evalInt(Mech this) {
    return (this->type->evalInt)(this);
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

void emptyVoid(Mech this) {
}

