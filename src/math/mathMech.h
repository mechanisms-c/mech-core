//
//  add.h
//  mechanisms
//
//  Created on: 3/21/15
//  authors:
//    Eric Hosick <erichosick@gmail.com>
//  license:
//    The MIT License (MIT)
//    Copyright (c) 2015 Eric Hosick
//

#ifndef __mechanisms__math__mech__
#define __mechanisms__math__mech__

#include <stdio.h>
#include "coreMech.h"

#define MAKE_DUAL_CALL(function, operation) return function(data->left) operation function(data->right);

MechInstPtr add(MechInstPtr left, MechInstPtr right);

#endif /* defined(__mechanisms__math__mech__) */
