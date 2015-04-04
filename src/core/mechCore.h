//
//  mechCore.h
//  mechanisms
//
//  Created on: 3/24/15
//  authors:
//    Eric Hosick <erichosick@gmail.com>
//  license:
//    The MIT License (MIT)
//    Copyright (c) 2015 Eric Hosick
//
//  Notes:
//    Assert that mechanism has a type
//    assert(this->mechType);

#ifndef __mechanisms__mechCore__
#define __mechanisms__mechCore__

#include "mechType.h"

void mechFree(Mech this);
Mech mechAlloc(MechType this);

int64_t evalInt   (Mech this);
double  evalReal  (Mech this);
bool    evalBool  (Mech this);
char*   evalStr   (Mech this);
char    evalChar  (Mech this);
Mech    evalMechF (Mech this);
void    evalVoid  (Mech this);

bool    mechIsStatic (Mech this);
bool    mechIsNotStatic (Mech this);

// Empty/Null Mechanisms

void    emptyVoid(Mech this);

// The "NULL" mechanism instance.
extern Mech EMPTY;

// The empty mechanism.
Mech empty();

#endif /* defined(__mechanisms__mechCore__) */
