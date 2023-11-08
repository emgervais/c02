#include <iostream>
#include "Point.hpp"

int main( void ) {
    std::cout << bsp(Point(0, 0), Point(0, 3), Point(3, 0), Point(3, 0)) << std::endl;
    std::cout << bsp(Point(0, 0), Point(0, 3), Point(3, 0), Point(1, 1)) << std::endl;
    std::cout << bsp(Point(0, 0), Point(0, 3), Point(3, 0), Point(10, 0)) << std::endl;
    std::cout << bsp(Point(0, 0), Point(0, 3), Point(3, 0), Point(-3, -10)) << std::endl;
}