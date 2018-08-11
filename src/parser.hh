#pragma once
#include <string>

#include "types.hh"

class OBJParser
{
public:
    OBJParser() = default;
    OBJParser(std::string filename) { load(filename); }

    void load(std::string filename);

    std::vector<mesh_t> meshes_get() { return meshes; }
    std::vector<vertex_t> vertices_get() { return vertices; }

private:
    std::vector<mesh_t> meshes;
    std::vector<vertex_t> vertices;
};
