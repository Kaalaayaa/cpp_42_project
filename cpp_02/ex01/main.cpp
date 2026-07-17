/*
===============================================================================
42 C++ Module 02 - ex01 : Fixed-point Number Class

A float is a number that can have a decimal (fractional) part.

Goal:
Implement a useful fixed-point number class that can be constructed from
integers and floats, and converted back to both representations.

What I should understand:
- A fixed-point number stores a real number as an integer with a fixed number
  of fractional bits.
- This exercise uses 8 fractional bits, meaning the scaling factor is 2^8 = 256.
- The real value is stored internally as:
      raw_value = real_value * 256
- The stored integer (_rawBits) is the only data member.

Conversions:
- int -> Fixed:
      _rawBits = integer << 8;
  (multiply by 256)

- float -> Fixed:
      _rawBits = roundf(float * 256);
  (round to the nearest representable fixed-point value)

- Fixed -> float:
      return (float)_rawBits / 256;

- Fixed -> int:
      return _rawBits >> 8;
  (divide by 256 and discard the fractional part)

Why roundf()?
- A float usually cannot be represented exactly as a fixed-point number.
- roundf() stores the closest possible value instead of simply truncating it.

Operator << overload:
- Allows printing a Fixed object directly with:
      std::cout << fixed;
- It outputs the floating-point representation by calling toFloat().

Concepts learned:
- Fixed-point representation.
- Bit shifting (<< and >>) for multiplying/dividing by powers of two.
- Converting between integer, float, and fixed-point formats.
- Constructor overloading.
- Const member functions.
- Operator overloading (<<).
- Separating interface (.hpp) from implementation (.cpp).

Questions the evaluator may ask:
1. What is a fixed-point number?
2. Why use 8 fractional bits?
3. Why multiply/divide by 256?
4. Why use bit shifts for integers?
5. Why is roundf() necessary?
6. Why does operator<< call toFloat()?
7. Why are toFloat() and toInt() const?
8. What is actually stored inside the class?
9. What precision do you lose when converting back to int?
10. Why use fixed-point instead of float?

Key formulas:
- scale = 1 << fractionalBits = 256
- raw = int << 8
- raw = roundf(float * 256)
- float = raw / 256.0f
- int = raw >> 8

One-sentence summary:
This exercise teaches how fixed-point numbers work by storing scaled integers,
converting between int, float, and fixed-point values, and exposing the value
through constructors, conversion functions, and the << operator.
===============================================================================
*/

#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}