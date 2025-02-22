#include "Fixed.hpp"
#include "cmath"

Fixed::Fixed()
{
    val_fix = 0;
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &cp)
{
    std::cout << "Copy constructor called\n";
    val_fix = cp.getRawBits();
}

Fixed::Fixed(const int i)
{
    std::cout << "Int constructor called\n";
    this->val_fix = i * 256;
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called\n";
    this->val_fix = roundf(f * 256);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
    std::cout << "Copy assignment operator called\n";
    this->val_fix = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    return this->val_fix;
}

void Fixed::setRawBits(int const raw)
{
    this->val_fix = raw;
    return ;
}

float Fixed::toFloat(void) const
{
    return (float)this->val_fix / 256;
}

int Fixed::toInt(void) const
{
    return this->val_fix / 256;
}

std::ostream &  operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return o;
}
