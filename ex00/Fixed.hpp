#ifndef FIXED_H
#define FIXED_H

#include <iostream>


class Fixed{
    private:
        int fnumber;
        static const int bits = 8;
    public:
        Fixed();
        Fixed(const Fixed& fx);
        Fixed& operator=(const Fixed& fx);
        ~Fixed();
        int  getRawBits( void ) const;
        void setRawBits( int const raw );
};


#endif