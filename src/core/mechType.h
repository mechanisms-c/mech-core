//
//  mechType.h
//  mechanisms
//
//  Created by Eric Hosick on 3/24/15.
//  Copyright (c) 2015 Eric Hosick. All rights reserved.
//

#ifndef __mechanisms__mechType__
#define __mechanisms__mechType__

#include <stdio.h>

#include <stdio.h>   // int*_t
#include <stdbool.h> // bool

typedef struct MechTypeStruct MechTypeStruct;
typedef MechTypeStruct* MechType;

#define MECH_HEADER\
Mech type;\
Mech error;\

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
    MechType type;
    Mech error;
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
    MechType  type;
    Mech      error;
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

#endif /* defined(__mechanisms__mechType__) */
