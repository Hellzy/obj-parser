#include <iostream>

#include "parser.hh"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " 'path/to/obj'\n";
        return 1;
    }

    OBJParser parser(argv[1]);

    auto meshes = parser.meshes_get();
    auto vertices = parser.vertices_get();

    return 0;
}
