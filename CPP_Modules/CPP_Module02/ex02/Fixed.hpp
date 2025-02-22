#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed{
public :
    Fixed();
    Fixed(Fixed const &cp);
    Fixed(const int i);
    Fixed(const float f);
    ~Fixed();
    
    bool operator>(Fixed const & rhs);
    bool operator>=(Fixed const & rhs);
    bool operator<(Fixed const & rhs);
    bool operator<=(Fixed const & rhs);
    bool operator==(Fixed const & rhs);
    bool operator!=(Fixed const & rhs);
    
    Fixed & operator=(Fixed const & rhs);
    Fixed operator+(Fixed const & rhs) const;
    Fixed operator-(Fixed const & rhs) const;
    Fixed operator*(Fixed const & rhs) const;
    Fixed operator/(Fixed const & rhs) const;

    Fixed & operator--();
    Fixed & operator++();

    Fixed operator--(int);
    Fixed operator++(int);

    static const Fixed & min(const Fixed & a, const Fixed & b );
	static const Fixed & max(const Fixed & a, const Fixed & b );

    static Fixed & min(Fixed & a, Fixed & b );
    static Fixed & max(Fixed & a, Fixed & b );

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