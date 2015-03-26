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

// A Mechanism instance is stored in Structures
// that always start with the following two fields:
//
// struct SomeStruct {
//     Object type;
//     Object error;
//     // Object field01
//     // ...
// };
//
// All Mechanism instances are cast to an Object
// (ObjectStructure*).
typedef struct ObjectStruct ObjectStruct;
typedef ObjectStruct* Object;
struct ObjectStruct {
    Object type;    // Mechanism type (see MechanismStruct)
    Object error;   // Instance errors.
};

// A Mechanism's algorithm can return one or more
// primitive types (different Catamorphism /
// transformations). These function signatures
// define the available catamorphisms.
typedef void    (*voidFPtr)(Object);
typedef int64_t (*intFPtr )(Object);
typedef double  (*realFPtr)(Object);
typedef bool    (*boolFPtr)(Object);
typedef char*   (*strFPtr )(Object);
typedef char    (*charFPtr)(Object);
typedef Object  (*objFPtr )(Object);

// Defines a Mechanism type. A mechanism type
// is some meta data (type, error, majorVer,
// minorVer, flags and dataSize) and a set
// of function pointers for each primitive type
// (catamorphisms / transformation).
// A Mechanism type is also an instance of a
// mechanism.
typedef struct MechanismStruct MechanismStruct;
typedef MechanismStruct* Mechanism;
struct MechanismStruct {
    Object      type;      // Mechanism type (see MechanismStruct)
    Object      error;     // Instance errors.
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
