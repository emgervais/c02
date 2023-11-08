#include "Fixed.hpp"

Fixed::Fixed(void) : _point(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& rhs) {
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(rhs.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->_point = rhs.getRawBits(); 
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw) {
    this->_point = raw;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_point;
}