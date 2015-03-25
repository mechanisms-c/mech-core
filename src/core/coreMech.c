////
////  core.c
////  mechanisms
////
////  Created on: 3/21/15
////  authors:
////    Eric Hosick <erichosick@gmail.com>
////  license:
////    The MIT License (MIT)
////    Copyright (c) 2015 Eric Hosick
////
////  See http://www.purplemath.com/modules/numtypes.htm
////
//
//#include <stdio.h> // null
//#include <stdlib.h> // free
//#include <assert.h> // assert
//#include <math.h> // NAN
//#include <stdbool.h> // boolean
//
//#include "coreMech.h"
//
//// Free allocated memory of ANY mechanism
//void mechFree(MechInstPtr this) {
//    assert(this);
//    assert(this->mechType);
//    if (!(this->mechType->flags && FLAG_ISNULL)) {
//        (this->mechType->delete)(this);
//        free(this);
//    }
//}
//
//// Allocate memory for ANY mechanism
//MechInstPtr mechAlloc(MechType* mechType) {
//    assert(mechType);
//    MechInstPtr this = malloc(sizeof(MechInstStruct) + mechType->dataSize);
//    if(this) {
//        this->mechType = mechType;
//    } // TODO: Warning via a non-null mechanism
//    return this;
//}
//
//MechInstPtr mechAllocSingleArg(MechType* mechType) {
//    assert(mechType);
//    MechInstPtr this = malloc(sizeof(MechInstStruct) + mechType->dataSize);
//    if(this) {
//        this->mechType = mechType;
//    }
//    return this;
//}
//
//// Invoke as int: default/error NAN
//int64_t evalInt(MechInstPtr this) {
//    MAKE_CALL(evalInt, NAN);
//}
//
//// Invoke as double: default/error NAN
//double evalReal(MechInstPtr this) {
//    MAKE_CALL(evalReal, NAN);
//}
//
//// Invoke as boolean: default/error false
//bool evalBool(MechInstPtr this) {
//    MAKE_CALL(evalBool, false);
//}
//
//
//int64_t nullInt(MechInstPtr this) {
//    return NAN;
//};
//
//double nullReal(MechInstPtr this) {
//    return NAN;
//};
//
//bool nullBool(MechInstPtr this) {
//    return false;
//}
//
//void nullVoid(MechInstPtr this) {
//}
//
//MechType nullType = {
//    .majorVer = 1,
//    .minorVer = 0,
//    .flags = 0,
//    .dataSize = sizeof(SingleArg),
//    .name = "null",
//    .lookup = &nullVoid,
//    .delete = &nullVoid,
//    .evalInt = &nullInt,
//    .evalReal = &nullReal,
//    .evalBool = &nullBool
//};
//
//typedef struct {
//    MechType* mechType;
//    MechInstPtr error;
//    MechInstPtr p01;
//    MechInstPtr p02;
//    MechInstPtr p03;
//    MechInstPtr p04;
//    MechInstPtr p05;
//    MechInstPtr p06;
//    MechInstPtr p07;
//    MechInstPtr p08;
//    MechInstPtr p09;
//    MechInstPtr p10;
//    MechInstPtr p11;
//    MechInstPtr p12;
//    MechInstPtr p13;
//    MechInstPtr p14;
//    MechInstPtr p15;
//    MechInstPtr p16;
//    MechInstPtr p17;
//    MechInstPtr p18;
//    MechInstPtr p19;
//    MechInstPtr p20;
//} NullStruct;
//
//MechInstStruct nullTemp = {
//    .mechType = &nullType,
//    .error = NULL
//};
//
//// One null to rule them all
//NullStruct nullMech = {
//    .mechType = &nullType,
//    .error = &nullTemp,
//    .p01 = &nullTemp,
//    .p02 = &nullTemp,
//    .p03 = &nullTemp,
//    .p04 = &nullTemp
//    // TODO: Setup default error message.
//};
//
//MechInstPtr null() {
//    return (MechInstPtr)&nullMech;
//}
