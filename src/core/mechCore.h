//
//  mechCore.h
//  mechanisms
//
//  Created on: 3/24/15
//  authors:
//    Eric Hosick <erichosick@gmail.com>
//  license:
//    The MIT License (MIT)
//    Copyright (c) 2015 Eric Hosick
//
//  Notes:
//    Assert that mechanism has a type
//    assert(this->mechType);

#ifndef __mechanisms__mechCore__
#define __mechanisms__mechCore__

#include <stdio.h> // int*_t
#include <stdbool.h> // bool

// Object instance of a Mechanism.
typedef struct ObjectStruct ObjectStruct;
typedef ObjectStruct* Object;
struct ObjectStruct {
    Object type;
    Object error;
};

// Function signatures
typedef void    (*voidFPtr)(Object);
typedef int64_t (*intFPtr )(Object);
typedef double  (*realFPtr)(Object);
typedef bool    (*boolFPtr)(Object);
typedef char*   (*strFPtr )(Object);
typedef char    (*charFPtr)(Object);
typedef Object  (*objFPtr )(Object);

// Base type object instance structure.
typedef struct MechanismStruct MechanismStruct;
typedef MechanismStruct* Mechanism;
struct MechanismStruct {
    Object      type;
    Object      error;
    uint8_t     majorVer;  // Major Version
    uint8_t     minorVer;  // Minor Version
    uint32_t    flags;     // Set aside for flags
    uint32_t    dataSize;  // Associated data size
    char*       name;      // name of the mechanism
    voidFPtr    lookup;    // vlookup table for user extension
    voidFPtr    delete;    // free memory allocation
    intFPtr     evalInt;   // evaluated as integer
    realFPtr    evalReal;  // evaluated as a double
    boolFPtr    evalBool;  // evaluated as a boolean
    strFPtr     evalStr;   // evaluated as a string (char*)
    charFPtr    evalChar;  // evaluated as a character
    objFPtr     evalObj;   // evaluated as a mechanism
};

#endif /* defined(__mechanisms__mechCore__) */
