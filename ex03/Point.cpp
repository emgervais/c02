#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
} 

Point::Point(const float x, const float y) :  _x(x), _y(y)
{
}

Point::Point(const Point& rhs) : _x(rhs._x), _y(rhs._y)
{

}

Point::~Point(void) {

}

Point& Point::operator=(const Point& rhs) {
    ( Fixed ) this->_x = rhs._x;
    ( Fixed ) this->_y = rhs._y;
    return *this;
}

Fixed Point::getx() const {
    return this->_x;
}

Fixed Point::gety() const {
    return this->_y;
}

bool Point::operator==(const Point& rhs) const {
    if(rhs.getx() == this->getx() && rhs.gety() == this->gety())
        return 0;
    return 1;
}

