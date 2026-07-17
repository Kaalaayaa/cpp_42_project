/*
===============================================================================
42 C++ Module 02 - ex00 : Fixed-point Number Class (Orthodox Canonical Form)

Goal:
Create a Fixed class following the Orthodox Canonical Form (Rule of Three).
For now, the class does NOT convert numbers yet. It only stores a raw fixed-point
value and implements the canonical functions.

What I should understand:
- This exercise is mainly about the Orthodox Canonical Form.
- The class stores one integer (_rawBits) representing a fixed-point number.
- The value is initialized to 0 by default.
- The number of fractional bits is always 8.
- No mathematical conversion happens yet (that comes in ex01).

Class members:
Private:
- int _rawBits;
    Stores the raw fixed-point value.

- static const int _fractionalBits = 8;
    Number of fractional bits shared by every Fixed object.

Public:
- Default constructor
- Copy constructor
- Copy assignment operator
- Destructor
- getRawBits()
- setRawBits()

Orthodox Canonical Form (Rule of Three):
Every class that manages resources or defines copy behavior should implement:

1. Default constructor
   Creates a new object.

2. Copy constructor
   Creates a new object as a copy of another.

3. Copy assignment operator
   Copies the contents of one existing object into another existing object.

4. Destructor
   Cleans up the object when it goes out of scope.

Even though this class doesn't manage dynamic memory, the exercise teaches the
canonical form used throughout C++.

Flow of object creation:
Fixed a;        // Default constructor
Fixed b(a);     // Copy constructor
Fixed c;
c = a;          // Copy assignment operator

Object destruction:
When an object leaves scope, its destructor is automatically called.

getRawBits():
- Returns the internal integer exactly as it is stored.
- Does NOT perform any conversion.

setRawBits():
- Replaces the internal raw value.
- Does NOT perform any conversion.

Concepts learned:
- Orthodox Canonical Form (Rule of Three).
- Constructors and destructors.
- Copy constructor.
- Copy assignment operator.
- Encapsulation (private data + public getters/setters).
- Static class members.
- Const member functions.

Questions the evaluator may ask:

1. What is the Orthodox Canonical Form?
2. Why do we need a copy constructor?
3. What is the difference between the copy constructor and assignment operator?
4. Why is _fractionalBits static?
5. Why is _fractionalBits const?
6. Why is getRawBits() const?
7. What is stored inside the class?
8. Why don't we convert values yet?
9. When is the destructor called?
10. Why is the member variable private?

One-sentence summary:
This exercise introduces the Orthodox Canonical Form by creating a simple class
that stores a raw fixed-point value while implementing all the canonical special
member functions correctly.
===============================================================================
*/

#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed b( a );
    Fixed c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}