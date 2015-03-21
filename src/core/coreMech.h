//
//  core.h
//  mechanisms
//
//  Created on: 3/21/15
//  authors:
//    Eric Hosick <erichosick@gmail.com>
//  license:
//    The MIT License (MIT)
//    Copyright (c) 2015 Eric Hosick
//

#ifndef __mechanisms__core__mech__
#define __mechanisms__core__mech__

#include <stdbool.h>

// NOTE: About assertions
//   assert(this->class); // ALL mechanism instances must have a MechType

// See Mechanism below
typedef struct MechInstStruct MechInstStruct;
typedef MechInstStruct* MechInstPtr;

// Function signatures
typedef void (*freeFPtr)(MechInstPtr);    // Free a mechanism
typedef int64_t (*intFPtr)(MechInstPtr);
typedef double (*realFPtr)(MechInstPtr);
typedef bool (*boolFPtr)(MechInstPtr);

// Class: Aggregates functions to define a Mechanism.
typedef struct {
    uint8_t  majorVer;  // Major Version
    uint8_t  minorVer;  // Minor Version
    uint32_t flags;     // Set aside for flags
    uint32_t dataSize;  // Associated data size
    char*    name;     // name of the mechanism
    void*    lookup;   // vlookup table for user extension
    freeFPtr delete;    // delete function for mechanism
    intFPtr  evalNum;   // evaluated as integer
    realFPtr evalReal;  // evaluated as a double
    boolFPtr evalBool;  // evaluated as a boolean
} MechType;

// Mechanism instance structure
struct MechInstStruct {
    MechType* mechType;
    void* data;
};

void mechFree(MechInstPtr this);
MechInstPtr mechAlloc(MechType* mechType);

int64_t evalInt(MechInstPtr this);
double evalReal(MechInstPtr this);
bool evalBool(MechInstPtr this);

// Single left argument mechansims
typedef struct {
    MechInstPtr left;
} SingleArgData;

// Dual left + right argument mechansims
typedef struct {
    MechInstPtr left;
    MechInstPtr right;
} DualArgData;

#define DATA_GET(dataType) dataType* data = (dataType*)(this + sizeof(MechInstStruct));
#define MAKE_CALL(function, default) return this && this->mechType && this->mechType->function ? (this->mechType->function)(this) : default;

#endif /* defined(__mechanisms__core__mech__) */

