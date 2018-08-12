#include "types.hh"

Point Point::operator+(const Point& p)
{
    return Point{x + p.x, y + p.y, z + p.z};
}

Point& Point::operator+=(const Point& p)
{
    x += p.x;
    y += p.y;
    z += p.z;

    return *this;
}

Point Point::operator-(const Point& p)
{
    return Point{x - p.x, y - p.y, z - p.z};
}

Point& Point::operator-=(const Point& p)
{
    x -= p.x;
    y -= p.y;
    z -= p.z;

    return *this;
}

Point Point::operator*(const Point& p)
{
    return Point{x * p.x, y * p.y, z * p.z};
}

Point& Point::operator*=(const Point& p)
{
    x *= p.x;
    y *= p.y;
    z *= p.z;

    return *this;
}
