#include "Fixed.hpp"


Fixed::Fixed()
{
    fnumber = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
    fnumber = n * (1 << bits);
    std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float fn)
{
    fnumber = round(fn * (1 << bits));
    std::cout << "Float constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &fx)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fx;
}
Fixed& Fixed::operator=(const Fixed& fx){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &fx)
        fnumber = fx.fnumber;
    return *this;
}
std::ostream& operator<<(std::ostream& out, const Fixed& fx)
{
    out << fx.toFloat();
    return out;
}

int Fixed::toInt(void) const
{
    
    return fnumber >> bits;
}

float Fixed::toFloat( void ) const
{
    return (float)fnumber / (1 << bits);
}


Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
};