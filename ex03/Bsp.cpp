#include "Point.hpp"
#include <cmath>

Fixed dist(Point a, Point b)
{
    Fixed r = ((b.getx() - a.getx()) * (b.getx() - a.getx()) + (b.gety() - a.gety()) * (b.gety() - a.gety()));
    return Fixed((float) sqrt(r.toFloat()));
}

bool check(Point p, Point a, Point b)
{
    if(dist(a, b) == dist(p, a) + dist(p, b))
        return 1;
    return 0;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    if(check(point, a, b) || check(point, a, c) || check(point, b, c))
        return 0;
    Fixed abc, pbc, pab, pac;

    abc = ((a.getx() * (b.gety() - c.gety())) + (b.getx() * (c.gety() - a.gety())) + (c.getx() * (a.gety() - b.gety()))) / 2;
    if(abc < 0)
        abc = abc * -1;
    pbc = ((point.getx() * (b.gety() - c.gety())) + (b.getx() * (c.gety() - point.gety())) + (c.getx() * (point.gety() - b.gety()))) / 2;
    if(pbc < 0)
        pbc = pbc * -1;
    pab = ((point.getx() * (a.gety() - b.gety())) + (a.getx() * (b.gety() - point.gety())) + (b.getx() * (point.gety() - a.gety()))) / 2;
    if(pab < 0)
        pab = pab * -1;
    pac = ((point.getx() * (a.gety() - c.gety())) + (a.getx() * (c.gety() - point.gety())) + (c.getx() * (point.gety() - a.gety()))) / 2;
    if(pac < 0)
        pac = pac * -1;
    std::cout << abc <<"|" << pbc <<"|" << pab<<"|" << pac << std::endl;
    return (abc == (pbc + pab + pac));
}