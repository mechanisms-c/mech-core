//
//  main.c
//  mechanisms
//
//  Created on: 3/21/15
//  authors:
//    Eric Hosick <erichosick@gmail.com>
//  license:
//    The MIT License (MIT)
//    Copyright (c) 2015 Eric Hosick
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mechCore.h"
#include "primitives.h"
#include "writeLn.h"
#include "mmath.h"

#include "mathTest.h"

int main() {
    Mech result = mathTest();
    return (evalBool(result));
}
