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

        // • The 6 comparison operators
        bool operator>(const Fixed& fx) const;
        bool operator<(const Fixed& fx) const;
        bool operator>=(const Fixed& fx) const;
        bool operator<=(const Fixed& fx) const;
        bool operator==(const Fixed& fx) const;
        bool operator!=(const Fixed& fx) const;

        //The 4 arithmetic operators
        Fixed operator*(const Fixed& fx);
        Fixed operator+(const Fixed& fx);
        Fixed operator-(const Fixed& fx);
        Fixed operator/(const Fixed& fx);

        //• The 4 increment/decrement

        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        Fixed& operator=(const Fixed& fx);
        friend std::ostream& operator<<(std::ostream& out,const Fixed& fx);
        ~Fixed();
        float toFloat( void ) const;
        int toInt( void ) const;

        //min
        static Fixed& min(Fixed& fx1,Fixed& fx2);
        static const Fixed& min(const Fixed& fx1,const Fixed& fx2);

        //max
        static Fixed& max(Fixed& fx1,Fixed& fx2);
        static const Fixed& max(const Fixed& fx1,const Fixed& fx2);
        int  getRawBits( void ) const;
        void setRawBits( int const raw );

};
#endif