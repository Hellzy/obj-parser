#pragma once
#include <fstream>
#include <string>
#include <tuple>
#include <utility>

#include "types.hh"
#include "mtl_parser.hh"

class OBJParser
{
public:
    OBJParser() = default;
    OBJParser(std::string filename) { load(filename); }

    void load(std::string filename);

    std::vector<mesh_t>&& meshes_get() { return std::move(meshes_); }
    std::vector<vertex_t>&& vertices_get() { return std::move(vertices_); }
    std::vector<dev_mat_t>&& mats_get() { return std::move(mats_vec_); }

private:
    void process_vertex_texture(std::ifstream& ifs);
    void process_face(std::ifstream& ifs);
    std::tuple<size_t, size_t, size_t> get_vertex_info(std::ifstream& str);
    void process_mtl(std::ifstream& ifs);
    void set_cur_mat(std::ifstream& ifs);

    template <typename T>
    void process_tricoords(std::ifstream& ifs, std::vector<T>& v);

private:
    std::vector<mesh_t> meshes_;
    std::vector<vertex_t> vertices_;
    std::vector<point_t> vt_;
    std::vector<point_t> n_;
    std::map<std::string, host_mat_t> mats_;
    std::vector<dev_mat_t> mats_vec_;
    size_t cur_mat_idx = 0;
};

#include "parser.hxx"
