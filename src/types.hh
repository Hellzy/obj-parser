#pragma once
#include <vector>

struct Point
{
    double x, y, z;

    /*
     * Simple addition between two Points
     */

    Point operator+(const Point& p);

    Point& operator+=(const Point& p);

    Point operator-(const Point& p);

    Point& operator-=(const Point& p);

    /*
     * Simple multiplication between two Points
     */

    Point operator*(const Point& p);

    Point& operator*=(const Point& p);

    /*
     * Simple multiplication between a Point and a scalar
     */

    template <typename T>
    Point operator*(T scalar)
    {
        return Point{x * scalar, y * scalar, z * scalar};
    }

    template <typename T>
    Point& operator*=(T scalar)
    {
        x *= scalar;
        y *= scalar;
        z *= scalar;

        return *this;
    }
};

using point_t = Point;

struct Vertex
{
    point_t pos;
    //normal
    //texture
};

using vertex_t = Vertex;

struct Mesh
{
    std::vector<vertex_t> vertices;
    //material indices
    //...
};

using mesh_t = Mesh;
