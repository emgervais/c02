#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _point(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& rhs) {
    //std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(rhs.getRawBits());
}

Fixed::Fixed(const int nbr) : _point(nbr << _bits)
{
    //std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nbr) : _point(std::roundf(nbr * (1 << _bits)))
{
    //std::cout << "Float constructor called" << std::endl;
}
Fixed& Fixed::operator=(const Fixed& rhs) {
    //std::cout << "Copy assignment operator called" << std::endl;
    this->_point = rhs.getRawBits(); 
    return *this;
}

Fixed::~Fixed() {
    //std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw) {
    this->_point = raw;
}

int Fixed::getRawBits(void) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return this->_point;
}

float Fixed::toFloat(void) const {
    return static_cast<float>( this->getRawBits() ) / ( 1 << this->_bits );
}

int Fixed::toInt(void) const {
    return this->_point >> this->_bits;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i ) {
    o << i.toFloat();
    return o;
}

bool Fixed::operator<(const Fixed& rhs) const {
    return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>(const Fixed& rhs) const {
    return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed& rhs) const {
    return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed& rhs) const {
    return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed& rhs) const {
    return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed& rhs) const {
    return this->getRawBits() != rhs.getRawBits();
}

Fixed Fixed::operator*(const Fixed& rhs) const {
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed& rhs) const {
    return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed Fixed::operator+(const Fixed& rhs) const {
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed& rhs) const {
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed& Fixed::operator++(void) {
    ++this->_point;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed a(*this);

    a._point = this->_point++;
    return a;
}

Fixed& Fixed::operator--(void) {
    --this->_point;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed a(*this);

    a._point = this->_point--;
    return a;
}

Fixed& Fixed::min( Fixed &a, Fixed &b ) {
    if(b > a)
        return a;
    return b;
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b ) {
    if(b > a)
        return a;
    return b;
}

Fixed& Fixed::max( Fixed &a, Fixed &b ) {
    if(b < a)
        return a;
    return b;
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b ) {
    if(b < a)
        return a;
    return b;
}