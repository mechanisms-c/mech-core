
[mech-home-link]: https://github.com/mechanisms/mech "Home repository for mechanisms"

# mech-core

This library contains the core mechanisms and C code for describing mechanisms.

See [Mechanisms Home][mech-home-link] for more information and other libraries.

Supported Mechanisms:

* *[num](#num-mechanism)* - a long primitive as a mechanism

# Supported Mechanisms

## <a name="num-mechanism"></a> num mechanism

Primitive which holds a single long numerical value.

```c
MechInstPtr num23 = num(23);
evalInt(num23); // returns 23
evalReal(num23); // returns 23.0

```

# Setup

TBD
