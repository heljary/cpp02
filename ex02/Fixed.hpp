#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed{
    private:
        int fnumber;
        static const int bits = 8;
    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float fn);
        Fixed(const Fixed& fx);
        Fixed& operator=(const Fixed& fx);
        Fixed& operator+(const Fixed& fx);
        friend std::ostream& operator<<(std::ostream& out,const Fixed& fx);
        ~Fixed();
        float toFloat( void ) const;
        int toInt( void ) const;
};
#endif