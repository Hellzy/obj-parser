#pragma once
#include <fstream>
#include <string>
#include <tuple>

#include "types.hh"
#include "mtl_parser.hh"

class OBJParser
{
public:
    OBJParser() = default;
    OBJParser(std::string filename) { load(filename); }

    void load(std::string filename);

    std::vector<mesh_t> meshes_get() { return meshes_; }
    std::vector<vertex_t> vertices_get() { return vertices_; }
    std::map<std::string, dev_mat_t> mats_get() { return mats_; }

private:
    void process_vertex_texture(std::ifstream& ifs);
    void process_face(std::ifstream& ifs);
    std::tuple<size_t, size_t, size_t> get_vertex_info(std::ifstream& str);
    void process_mtl(std::ifstream& ifs);

    template <typename T>
    void process_tricoords(std::ifstream& ifs, std::vector<T>& v);

private:
    std::vector<mesh_t> meshes_;
    std::vector<vertex_t> vertices_;
    std::vector<point_t> vt_;
    std::vector<point_t> n_;
    std::map<std::string, dev_mat_t> mats_;
};

#include "parser.hxx"
