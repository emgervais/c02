#include <iostream> 

class Fixed {
    private :
        int _point;
        const static int _bits = 8;
    public :
        Fixed(void);
        Fixed(const Fixed& rhs);
        Fixed& operator=(const Fixed& rhs);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};