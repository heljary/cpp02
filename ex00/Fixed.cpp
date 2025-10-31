#include "Fixed.hpp"


Fixed::Fixed()
{
    fnumber = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fx)
{
    std::cout << "Copy constructor called" << std::endl;
    fnumber = fx.getRawBits();
}
Fixed& Fixed::operator=(const Fixed& fx){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &fx)
        fnumber = fx.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return fnumber;
}

void Fixed::setRawBits(int const raw)
{
    fnumber = raw;
}
Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
};