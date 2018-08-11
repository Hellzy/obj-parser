#pragma once
#include <vector>

struct Point
{
    double x;
    double y;
    double z;
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
    std::vector<size_t> vertex_indices;
    //material indices
    //...
};

using mesh_t = Mesh;
