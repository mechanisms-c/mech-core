//
//  core.c
//  mechanisms
//
//  Created on: 3/21/15
//  authors:
//    Eric Hosick <erichosick@gmail.com>
//  license:
//    The MIT License (MIT)
//    Copyright (c) 2015 Eric Hosick
//
//  See http://www.purplemath.com/modules/numtypes.htm
//

#include <stdio.h> // null
#include <stdlib.h> // free
#include <assert.h> // assert
#include <math.h> // NAN
#include <stdbool.h> // boolean

#include "coreMech.h"

// Free allocated memory of ANY mechanism
void mechFree(MechInstPtr this) {
    if(this) {
        assert(this->mechType);
        if (this->mechType->delete) {
            (this->mechType->delete)(this);
        }
        free(this);
    }
}

// Allocate memory for ANY mechanism
MechInstPtr mechAlloc(MechType* mechType) {
    assert(mechType);
    MechInstPtr this = malloc(sizeof(MechInstStruct) + mechType->dataSize);
    if(this) {
        this->mechType = mechType;
    } // TODO: Warning via a non-null mechanism
    return this;
}

// Invoke a mechanism as a numeric primitive
int64_t evalInt(MechInstPtr this) {
    return this && this->mechType && this->mechType->evalNum ? (this->mechType->evalNum)(this) : NAN;
}

// Invoke a mechanism as a double primitive
double evalReal(MechInstPtr this) {
    return this && this->mechType && this->mechType->evalReal ? (this->mechType->evalReal)(this) : NAN;
}

// Invoke a mechanism as a boolean primitive
// defaults to false
bool evalBool(MechInstPtr this) {
    return this && this->mechType && this->mechType->evalBool ? (this->mechType->evalBool)(this) : false;
}
