#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed{
public :
    Fixed();
    Fixed(const Fixed &cp);
    Fixed(const int i);
    Fixed(const float f);
    ~Fixed();

    Fixed & operator=(Fixed const & rhs);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    
    float toFloat( void ) const;
    int toInt( void ) const;

private :
    int val_fix;
    static const int nbr_frac_bit = 8;
};

std::ostream &  operator<<(std::ostream & o, Fixed const & rhs);
#endif 