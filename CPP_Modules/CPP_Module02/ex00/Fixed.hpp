#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed{
public :
    Fixed();
    Fixed(const Fixed &cp);
    ~Fixed();

    Fixed & operator=(Fixed const & rhs);
    int getRawBits(void) const;
    void setRawBits(int const raw);

private :
    int val_fix;
    static const int nbr_frac_bit = 8;
};
#endif 