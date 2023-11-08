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

Fixed dist(Point a, Point b)
{
    Fixed r = ((b.getx() - a.getx()) * (b.getx() - a.getx()) + (b.gety() - a.gety()) * (b.gety() - a.gety()));
    return Fixed(sqrt(r.toFloat()));
}
bool check(Point p, Point a, Point b)
{
    if(dist(a, b) == dist(p, a) + dist(p, b))
        return 1;
    return 0;
}

    //if(check(point, a, b) || check(point, a, c) || check(point, b, c))
    //    return 1;
