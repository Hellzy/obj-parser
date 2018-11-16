#pragma once
#include <fstream>
#include <string>
#include <tuple>

#include "types.hh"

class OBJParser
{
public:
    OBJParser() = default;
    OBJParser(std::string filename) { load(filename); }

    void load(std::string filename);

    std::vector<mesh_t> meshes_get() { return meshes_; }
    std::vector<vertex_t> vertices_get() { return vertices_; }

private:
    void process_vertex(std::ifstream& ifs);
    void process_vertex_texture(std::ifstream& ifs);
    void process_face(std::ifstream& ifs);
    std::tuple<size_t, size_t, size_t> get_vertex_info(std::ifstream& str);

private:
    std::vector<mesh_t> meshes_;
    std::vector<vertex_t> vertices_;
    std::vector<point_t> vt_;
};
