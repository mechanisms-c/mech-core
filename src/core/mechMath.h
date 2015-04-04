//
//  mechMath.c
//  mechanisms
//
//  Created on: 3/29/15
//  authors:
//    Eric Hosick <erichosick@gmail.com>
//  license:
//    The MIT License (MIT)
//    Copyright (c) 2015 Eric Hosick
//

#ifndef __mechanisms__mechMath__
#define __mechanisms__mechMath__

#define INT64_INF_POS   9223372036854775807LL

#define INT64_NAN      (-INT64_INF_POS-1)
#define INT64_INF_NEG  (-INT64_INF_POS-2)

#undef INT64_MIN
#define INT64_MIN      (-INT64_INF_POS-3)

#undef INT64_MAX
#define INT64_MAX      (INT64_INF_POS-1 )

#endif /* defined(__mechanisms__mechMath__) */