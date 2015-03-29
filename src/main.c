//
//  mech-core.c
//  mechanisms
//
//  version: 0.1.1
//  Created on: 3/21/15
//  authors:
//    Eric Hosick <erichosick@gmail.com>
//  license:
//    The MIT License (MIT)
//    Copyright (c) 2015 Eric Hosick
//

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <dlfcn.h>
#include "empty.h"
#include "mechCore.h"

int main() {
   
    assert(false == evalBool(empty()));
    
//    Mech num2 = num(-2);
//    evalInt(num2);
    
//    evalBool(
//        writeLn(null())
//    );
//    
//    evalInt(
//        writeLn(
//            add(
//                add(num(-2), num(3)),
//                add(num(4), num(5))
//            )
//        )
//    );
    return 0;
}
