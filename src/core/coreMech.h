////
////  core.h
////  mechanisms
////
////  Created on: 3/21/1 5
////  authors:
////    Eric Hosick <erichosick@gmail.com>
////  license:
////    The MIT License (MIT)
////    Copyright (c) 2015 Eric Hosick
////
//
//#ifndef __mechanisms__core__mech__
//#define __mechanisms__core__mech__
//
//#include <stdbool.h>
//
//// NOTE: About assertions
////   ALL mechanism instances must have a MechType
////   assert(this->class);
//
//// See Mechanism below
//typedef struct MechInstStruct MechInstStruct;
//typedef MechInstStruct* MechInstPtr;
//
//// Function signatures
//typedef void (*voidFPtr)(MechInstPtr);
//typedef int64_t (*intFPtr)(MechInstPtr);
//typedef double (*realFPtr)(MechInstPtr);
//typedef bool (*boolFPtr)(MechInstPtr);
//
//
//// See Mechanism below
//typedef struct MechType MechType;
//typedef MechType* MechTypePtr;
//
//
//// Class: Aggregates functions to define a Mechanism.
//struct MechType {
//    MechTypePtr mechType;
//    uint8_t     majorVer;  // Major Version
//    uint8_t     minorVer;  // Minor Version
//    uint32_t    flags;     // Set aside for flags
//    uint32_t    dataSize;  // Associated data size
//    char*       name;      // name of the mechanism
//    voidFPtr    lookup;    // vlookup table for user extension
//    voidFPtr    delete;    // free memory allocation
//    intFPtr     evalInt;   // evaluated as integer
//    realFPtr    evalReal;  // evaluated as a double
//    boolFPtr    evalBool;  // evaluated as a boolean
//};
//
//// Mechanism instance structure
//struct MechInstStruct {
//    MechTypePtr mechType;
//    MechInstPtr error;
//};
//
//
//
//// Single left argument mechansims
//typedef struct {
//    MechTypePtr mechType;
//    MechInstPtr error;
//    MechInstPtr left;
//} SingleArg;

//// Dual left + right argument mechansims
//typedef struct {
//    MechInstPtr left;
//    MechInstPtr right;
//} DualArg;


//void mechFree(MechInstPtr this);
//
//MechInstPtr mechAlloc(MechTypePtr mechType);
//MechInstPtr mechAllocSingleArg(MechTypePtr mechType);
//
//int64_t evalInt(MechInstPtr this);
//double evalReal(MechInstPtr this);
//bool evalBool(MechInstPtr this);
//
//int64_t nullInt(MechInstPtr this);
//double nullReal(MechInstPtr this);
//bool nullBool(MechInstPtr this);
//void nullVoid(MechInstPtr this);
//MechInstPtr null();
//
//
//MechInstPtr singleArgNull();
//
//MechInstPtr dualArgNull();
////MechInstPtr null();
//
//#define DATA_GET(dataType) dataType* data = (dataType*)(this + sizeof(MechInstStruct));
//#define MAKE_CALL(function, default) return this && this->mechType && this->mechType->function ? (this->mechType->function)(this) : default;

// NULL STUFF
//
//const uint32_t FLAG_ISNULL = 0x01; // 1
//
//
//
//
//#endif /* defined(__mechanisms__core__mech__) */
//
