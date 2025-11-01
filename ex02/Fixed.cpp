#include "Fixed.hpp"


Fixed::Fixed()
{
    fnumber = 0;
}

Fixed::Fixed(const int n)
{
    fnumber = n * 256;
}
Fixed::Fixed(const float fn)
{
    fnumber = round(fn * 256);
}
Fixed::Fixed(const Fixed &fx)
{
    *this = fx;
}
//=
Fixed& Fixed::operator=(const Fixed& fx){
    if(this != &fx)
        fnumber = fx.fnumber;
    return *this;
}

// The 4 arithmetic operators
// Addition
Fixed Fixed::operator+(const Fixed& fx) {
    Fixed result;
    result.fnumber = this->fnumber + fx.fnumber;
    return result;
}

// Subtraction
Fixed Fixed::operator-(const Fixed& fx) {
    Fixed result;
    result.fnumber = this->fnumber - fx.fnumber;
    return result;
}

// Multiplication
Fixed Fixed::operator*(const Fixed& fx) {
    Fixed result;
    result.fnumber = (this->fnumber * fx.fnumber) >> bits;
    return result;
}

// Division
Fixed Fixed::operator/(const Fixed& fx) {
    Fixed result;
    result.fnumber = (this->fnumber << bits) / fx.fnumber;
    return result;
}

// • The 6 comparison operators
bool Fixed::operator>(const Fixed& fx) const
{
    return (this->fnumber > fx.fnumber);
}
bool Fixed::operator<(const Fixed& fx) const
{
    return (this->fnumber < fx.fnumber);
}
bool Fixed::operator>=(const Fixed& fx) const
{
    return(this->fnumber >= fx.fnumber);
}
bool Fixed::operator<=(const Fixed& fx) const
{
    return(this->fnumber <= fx.fnumber);
}
bool Fixed::operator==(const Fixed& fx) const
{
    return(this->fnumber == fx.fnumber);
}
bool Fixed::operator!=(const Fixed& fx) const
{
    return(this->fnumber != fx.fnumber);
}


// • The 4 increment/decrement

//pos increment
Fixed& Fixed::operator++()
{
    fnumber++;
    return *this;
}
//pre increment
Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++(*this);
    return temp;
}

//pos decrement
Fixed& Fixed::operator--()
{
    fnumber--;
    return *this;
}
//pre decrement
Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --(*this);
    return temp;
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


//min
Fixed& Fixed::min(Fixed& fx1, Fixed& fx2)
{
    return ((fx1 < fx2) ? fx1 : fx2);
}
const Fixed& Fixed::min(const Fixed& fx1,const Fixed& fx2)
{
    return ((fx1 < fx2) ? fx1 : fx2);
}

//max

Fixed& Fixed::max(Fixed& fx1, Fixed& fx2)
{
    return ((fx1 > fx2) ? fx1 : fx2);
}
const Fixed& Fixed::max(const Fixed& fx1,const Fixed& fx2)
{
    return ((fx1 > fx2) ? fx1 : fx2);
}


Fixed::~Fixed(){
};