#include <iostream> 

class Fixed {
    private :
        int _point;
        const static int _bits = 8;
    public :
        Fixed(void);
        Fixed(const Fixed& rhs);
        Fixed(const int nbr);
        Fixed(const float nbr);
        Fixed& operator=(const Fixed& rhs);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );