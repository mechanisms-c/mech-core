////  writeLn.c
////  mechanisms
////
////  Created on: 3/21/15
////  authors:
////    Eric Hosick <erichosick@gmail.com>
////  license:
////    The MIT License (MIT)
////    Copyright (c) 2015 Eric Hosick
////
//
//#include <math.h> // NAN
//#include <assert.h> // assert
//#include "writeLn.h" // printf
//
//static int64_t writeLnInt(Mech this) {
//    assert(this);
//    DATA_GET(SingleArg);
//    int64_t result = evalInt(data->left);
//    printf("%lli\n", result);
//    return result;
//};
//
//static double writeLnReal(Mech this) {
//    assert(this);
//    SingleArg* data = (SingleArg*)(this + sizeof(MechInstStruct));
//    double result = evalReal(data->left);
//    printf("%f\n", result);
//    return result;
//};
//
//static bool writeLnBool(Mech this) {
//    assert(this);
//    DATA_GET(SingleArg);
//    bool result = evalBool(data->left);
//    printf("%i\n", result);
//    return result;
//}
//
//MechType writeLnType = {
//    .majorVer = 1,
//    .minorVer = 0,
//    .flags = 0,
//    .dataSize = sizeof(SingleArg),
//    .name = "writeLn",
//    .lookup = &nullVoid,
//    .delete = &nullVoid,
//    .evalInt = &writeLnInt,
//    .evalReal = &writeLnReal,
//    .evalBool = &writeLnBool
//};
//
//Object writeLn(Object text) {
//    Mech this = mechAlloc(&writeLnType);
//    if(this) {
//        DATA_GET(SingleArg);
//        data->left = text;
//    }
//    return this;
//}
