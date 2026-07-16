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
        Fixed(const int fixed_nb); // default constructor = called automatically when object is created 
        Fixed(const Fixed& other); // copy constructor = called when creating a new object form another object
        Fixed& operator=(const Fixed& other); // copy assigment operator = called when object already exist 
        ~Fixed(); // destructor = called automitacally when object is destroyed
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif