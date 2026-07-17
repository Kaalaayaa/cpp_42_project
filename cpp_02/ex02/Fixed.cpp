#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    fixed_nb = 0;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    fixed_nb = n << FRACTIONAL_BITS;
}

Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called" << std::endl;
    fixed_nb = roundf(n * (1 << FRACTIONAL_BITS));
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    fixed_nb = other.fixed_nb;;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return fixed_nb;
}

void Fixed::setRawBits(int const raw)
{
    fixed_nb = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(fixed_nb) / (1 << FRACTIONAL_BITS);
}

int Fixed::toInt(void) const
{
    return fixed_nb >> FRACTIONAL_BITS;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_nb)
{
    os << fixed_nb.toFloat();
    return os;
}