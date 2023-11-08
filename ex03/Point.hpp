#include <iostream> 
#include "Fixed.hpp"

class Point {
    private :
        const Fixed _x;
        const Fixed _y;
    public :
        Point(void);
        Point(const float x, const float y);
        Point(const Point& rhs);
        Point& operator=(const Point& rhs);
        ~Point();
        Fixed getx() const;
        Fixed gety() const;
        bool operator==(const Point& rhs) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);