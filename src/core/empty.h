//
//  empty.h
//  mechanisms
//
//  Created by Eric Hosick on 3/28/15.
//  Copyright (c) 2015 Eric Hosick. All rights reserved.
//

// There is no concept of NULL within this framework.
// Mechanisms are the fundamental data type (and code)
// and NULL is no exception.
//
// EMPTY is the new NULL. In code you can no longer do:
//
//    if (ptr) { .. }
//
// You must do
//
//    if (EMPTY == ptr ) { .. }
//
// Why? Becaues the empty mechanism does not allocate
// memory but instead returns a pointer to EMPTY.
// Any mechanism that is unable to allocate memory to
// create an instance of itself will return EMPTY (instead
// of NULL).
//

#ifndef __mechanisms__empty__
#define __mechanisms__empty__

#include <stdio.h>
#include "mechType.h" // Mech

// The "NULL" mechanism instance.
extern Mech EMPTY;
extern Mech EMPTY_MECH;

// An empty mechanism.
Mech empty();

#endif /* defined(__mechanisms__empty__) */
