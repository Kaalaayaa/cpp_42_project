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
    fixed_nb = other.fixed_nb;
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


bool Fixed::operator>(const Fixed& other) const
{
	return(this->fixed_nb > other.fixed_nb);
}

bool Fixed::operator<(const Fixed& other) const
{
	return(this->fixed_nb < other.fixed_nb);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return(this->fixed_nb >= other.fixed_nb);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return(this->fixed_nb <= other.fixed_nb);
}

bool Fixed::operator==(const Fixed& other) const
{
	return(this->fixed_nb == other.fixed_nb);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return(this->fixed_nb != other.fixed_nb);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	if (other.toFloat() == 0)
	{
		std::cerr << "Error: division by zero" << std::endl;
		return Fixed();
	}
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
	fixed_nb++;
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	fixed_nb++;
	return temp;
}
Fixed& Fixed::operator--()
{
	fixed_nb--;
	return *this;
}
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	fixed_nb--;
	return temp;	
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}