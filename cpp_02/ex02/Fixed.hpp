#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    private:
        int fixed_nb;
        static const int FRACTIONAL_BITS = 8;
    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float n);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const  Fixed& fixed_nb);

#endif