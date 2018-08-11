#include "parser.hh"

int main()
{
    OBJParser parser("cube.obj");

    auto meshes = parser.meshes_get();
    auto vertices = parser.vertices_get();

    return 0;
}
