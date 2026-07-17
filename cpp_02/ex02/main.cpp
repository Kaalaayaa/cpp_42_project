/*
    Exercise 02 - Operator overloading

    Goal:
    Make the Fixed class behave like a normal number type (int/float).

    1) Comparison operators:
       Overload:
       >  <  >=  <=  ==  !=

       These return bool and compare the actual fixed-point values.

       Example:
       if (a < b)
       becomes:
       a.operator<(b)


    2) Arithmetic operators:
       Overload:
       +  -  *  /

       These return a new Fixed object containing the result.

       Example:
       a + b
       becomes:
       a.operator+(b)


    3) Increment / decrement operators:
       Overload:
       ++a  (pre-increment)
       a++  (post-increment)
       --a  (pre-decrement)
       a--  (post-decrement)

       The smallest possible change (epsilon) is one raw bit:
       fixed_nb++;

       Because:
       FRACTIONAL_BITS = 8
       smallest step = 1 / 256


    4) Static min/max functions:

       Static means they belong to the class, not an object.

       Called like:
       Fixed::min(a, b);
       Fixed::max(a, b);

       Two versions exist:
       - one for normal Fixed references
       - one for const Fixed references


    Important:
       Operator overloading teaches C++ how to use operators
       with your custom class.

       Example:
       std::cout << fixed;
       a + b;
       a < b;

       are converted internally into function calls.

       The goal is to make Fixed behave like a built-in number.
*/

#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}