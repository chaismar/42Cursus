#include "Fixed.hpp"
#include "cmath"

Fixed::Fixed()
{
    val_fix = 0;
    // std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &cp)
{
    // std::cout << "Copy constructor called\n";
    val_fix = cp.getRawBits();
}

Fixed::Fixed(const int i)
{
    // std::cout << "Int constructor called\n";
    this->val_fix = i * 256;
}

Fixed::Fixed(const float f)
{
    // std::cout << "Float constructor called\n";
    this->val_fix = roundf(f * 256);
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called\n";
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
    // std::cout << "Copy assignment operator called\n";
    this->val_fix = rhs.getRawBits();
    return *this;
}

Fixed Fixed::operator+(Fixed const & rhs) const
{
    Fixed result(this->toFloat() + rhs.toFloat());
    
    return result;
}

Fixed Fixed::operator-(Fixed const & rhs) const
{
    Fixed result(this->toFloat() - rhs.toFloat());
    
    return result;
}

Fixed Fixed::operator*(Fixed const & rhs) const
{
    Fixed result(this->toFloat() * rhs.toFloat());
    
    return result;
}

Fixed Fixed::operator/(Fixed const & rhs) const
{
    Fixed result(this->toFloat() / rhs.toFloat());
    
    return result;
}

bool Fixed::operator>(Fixed const & rhs)
{
    return (this->val_fix > rhs.val_fix);
}

bool Fixed::operator>=(Fixed const & rhs)
{
    return (this->val_fix >= rhs.val_fix);
}

bool Fixed::operator<(Fixed const & rhs)
{
    return (this->val_fix < rhs.val_fix);
}

bool Fixed::operator<=(Fixed const & rhs)
{
    return (this->val_fix <= rhs.val_fix);
}

bool Fixed::operator==(Fixed const & rhs)
{
    return (this->val_fix == rhs.val_fix);
}

bool Fixed::operator!=(Fixed const & rhs)
{
    return (this->val_fix != rhs.val_fix);
}

Fixed & Fixed::operator--()
{
    this->val_fix--;
    return *this;
}

Fixed & Fixed::operator++()
{
    this->val_fix++;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;
    
    (*this).val_fix--;
    return tmp;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;

    (*this).val_fix++;
    return tmp;
}

const Fixed & Fixed::min(const Fixed & a, const Fixed & b )
{
    if (a.val_fix < b.val_fix)
        return (a);
    return (b);
}

const Fixed & Fixed::max(const Fixed & a, const Fixed & b )
{
    if (a.val_fix >= b.val_fix)
        return (a);
    return (b);
}

Fixed & Fixed::min(Fixed & a, Fixed & b )
{
    if (a <= b)
        return (a);
    return (b);
}

Fixed & Fixed::max(Fixed & a, Fixed & b )
{
    if (a >= b)
        return (a);
    return (b);
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

std::ostream & operator<<( std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
    // std::cout << std:: endl << "RAW: " << rhs.getRawBits();
	// std::cout << std:: endl << "TOINT: " << rhs.toInt();
	// std::cout << std:: endl << "TOFLOAT: " << rhs.toFloat() << "\n";
	return (o);
}
