#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed abc, pbc, pab, pac;

    abc = ((a.getx() * (b.gety() - c.gety())) + (b.getx() * (c.gety() - b.gety())) + (c.getx() * (a.gety() - c.gety()))) / 2;
    if(abc < 0)
        abc = abc * -1;
    pbc = ((point.getx() * (b.gety() - c.gety())) + (b.getx() * (c.gety() - b.gety())) + (c.getx() * (point.gety() - c.gety()))) / 2;
    if(pbc < 0)
        pbc = pbc * -1;
    pab = ((point.getx() * (a.gety() - b.gety())) + (a.getx() * (b.gety() - a.gety())) + (b.getx() * (point.gety() - b.gety()))) / 2;
    if(pab < 0)
        pab = pab * -1;
    pac = ((point.getx() * (a.gety() - c.gety())) + (a.getx() * (c.gety() - b.gety())) + (c.getx() * (point.gety() - c.gety()))) / 2;
    if(pac < 0)
        pac = pac * -1;
    return (abc == pbc + pab + pac);
}