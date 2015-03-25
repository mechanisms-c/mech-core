////
////  equal.c
////  mechanisms
////
////  Created on: 3/22/15
////  authors:
////    Eric Hosick <erichosick@gmail.com>
////  license:
////    The MIT License (MIT)
////    Copyright (c) 2015 Eric Hosick
////
//
//#include <assert.h>
//#include <math.h> // NAN
//#include "mathMech.h"
//#include "coreMech.h"
//
//bool eqlIntBool(MechInstPtr this) {
//    DATA_GET(DualArg);
//    MAKE_DUAL_CALL(evalInt, ==)
//};
//
//MechType eqlIntMech = {
//    .majorVer = 1,
//    .minorVer = 0,
//    .flags = 0,
//    .dataSize = sizeof(DualArg),
//    .name = "equal",
//    .lookup = &nullVoid,
//    .delete = &nullVoid,
//    .evalInt = &nullInt,
//    .evalReal = &nullReal,
//    .evalBool = &eqlIntBool
//};
//
//MechInstPtr eqlInt(MechInstPtr left, MechInstPtr right) {
//    MechInstPtr this = mechAlloc(&eqlIntMech);
//    if(this) {
//        DATA_GET(DualArg);
//        data->left = left;
//        data->right = right;
//    }
//    return this;
//}
//
//
//
//
//
