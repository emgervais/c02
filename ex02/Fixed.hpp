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

        bool operator<(const Fixed& rhs) const;
        bool operator<=(const Fixed& rhs) const;
        bool operator>(const Fixed& rhs) const;
        bool operator>=(const Fixed& rhs) const;
        bool operator==(const Fixed& rhs) const;
        bool operator!=(const Fixed& rhs) const;

        Fixed operator*(const Fixed& rhs) const;
        Fixed operator/(const Fixed& rhs) const;
        Fixed operator-(const Fixed& rhs) const;
        Fixed operator+(const Fixed& rhs) const;

        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);

        static Fixed& min( Fixed &a, Fixed &b );
        static const Fixed& min( const Fixed &a, const Fixed &b );
        static Fixed& max( Fixed &a, Fixed &b );
        static const Fixed& max( const Fixed &a, const Fixed &b );
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );