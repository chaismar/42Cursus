#include "Fixed.hpp"

Fixed::Fixed()
{
    this->val_fix = 0;
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &cp)
{
    std::cout << "Copy constructor called\n";
    *this = cp;
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
    std::cout<<"getRawBits member function called\n";
    //std::cout<<this->val_fix << "\n";
    return this->val_fix;
}

void Fixed::setRawBits(int const raw)
{
    std::cout<<"setRawBits member function called\n";
    this->val_fix = raw;
    //std::cout<<this->val_fix<<"\n";
    return ;
}
