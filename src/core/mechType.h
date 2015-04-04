//
//  mechType.h
//  mechanisms
//
//  Created on: 3/24/15
//  authors:
//    Eric Hosick <erichosick@gmail.com>
//  license:
//    The MIT License (MIT)
//    Copyright (c) 2015 Eric Hosick
//

#ifndef __mechanisms__mechType__
#define __mechanisms__mechType__

#include <stdio.h>   // int*_t
#include <stdbool.h> // bool

typedef struct MechTypeStruct MechTypeStruct;
typedef MechTypeStruct* MechType;

#define MECH_HEADER \
    MechType  type;\
    Mech      error;\

// A Mechanism instance is stored in Structures
// that always start with the following two fields:
//
// struct SomeStruct {
//     Mech type;  // Mechanism type (see MechType)
//     Mech error; // Instance errors.
//     // .. other fields
// };
//
// Mech (Mechanisms) is the fundamental data type.
// Everything is a Mechanism: even NULL (see empty.h).
// All instances are cast to a Mech.
typedef struct MechStruct MechStruct;
typedef MechStruct* Mech;
struct MechStruct {
    MECH_HEADER
};

// A Mechanism's algorithm can return one or more
// primitive types (different Catamorphism /
// transformations). These function signatures
// define the available catamorphisms.
typedef int64_t (*intFPtr )(Mech);
typedef double  (*realFPtr)(Mech);
typedef bool    (*boolFPtr)(Mech);
typedef char*   (*strFPtr )(Mech);
typedef char    (*charFPtr)(Mech);
typedef Mech    (*objFPtr )(Mech);
typedef void    (*voidFPtr)(Mech);

// TODO: Add more transformations

// Defines a Mechanism type. A mechanism type
// is some meta data (type, error, majorVer,
// minorVer, flags and dataSize) and a set
// of function pointers for each primitive type
// (catamorphisms / transformation).
// A Mechanism type is also an instance of a
// mechanism.
struct MechTypeStruct {
    MECH_HEADER
    uint8_t   majorVer;  // Major Version
    uint8_t   minorVer;  // Minor Version
    uint32_t  flags;     // Set aside for flags
    uint32_t  dataSize;  // Associated data size
    char*     name;      // name of the mechanism
    voidFPtr  lookup;    // "vlookup" table for user extension
    voidFPtr  delete;    // free memory allocation
    intFPtr   evalInt;   // evaluated as integer
    realFPtr  evalReal;  // evaluated as a double
    boolFPtr  evalBool;  // evaluated as a boolean
    strFPtr   evalStr;   // evaluated as a string (char*)
    charFPtr  evalChar;  // evaluated as a character
    objFPtr   evalMech;  // evaluated as a mechanism
    voidFPtr  evalVoid;  // evaluated with no result
};


// Flags to uniquely identify a mechanism
extern const uint32_t FLAG2_IS_STATIC;

// Common Mechanism Structures

typedef struct SingleArgStruct SingleArgStruct;
typedef SingleArgStruct* SingleArgMech;
struct SingleArgStruct {
    MECH_HEADER
    Mech      left;
};

typedef struct DualArgStruct DualArgStruct;
typedef DualArgStruct* DualArgMech;
struct DualArgStruct {
    MECH_HEADER
    Mech      left;
    Mech      right;
};

typedef struct NumStruct NumStruct;
typedef NumStruct* NumMech;
struct NumStruct {
    MECH_HEADER
    int64_t d;
};

typedef struct RealStruct RealStruct;
typedef RealStruct* RealMech;
struct RealStruct {
    MECH_HEADER
    double d;
};

typedef struct StrStruct StrStruct;
typedef StrStruct* StrMech;
struct StrStruct {
    MECH_HEADER
    char* d;
};

#endif /* defined(__mechanisms__mechType__) */
