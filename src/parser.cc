#include <iostream>

#include "parser.hh"

/***
 * Only handles a subset of obj files
 * - triangle faces only
 * - doesn't care about textures, materials or vector normals
 */

void OBJParser::load(std::string filename)
{
    std::ifstream ifs(filename);

    while (ifs.good() && !ifs.eof())
    {
        std::string tok;
        ifs >> tok;

        if (!tok.compare("v"))
            process_vertex(ifs);
        else if (!tok.compare("vt"))
            process_vertex_texture(ifs);
        else if (!tok.compare("f"))
            process_face(ifs);
        else
            std::cerr << "Rejected: " << tok << '\n';
    }
}

inline
void OBJParser::process_vertex(std::ifstream& ifs)
{
    double x, y, z;

    ifs >> x >> y >> z;
    vertices_.push_back({x, y, z});
}

inline
void OBJParser::process_vertex_texture(std::ifstream& ifs)
{
    double x, y;
    ifs >> x >> y;
    vt_.push_back(point_t{x, y, 0});
}

inline
void OBJParser::process_face(std::ifstream& ifs)
{
    mesh_t mesh;

    for (int i = 0; i < 3; ++i)
    {
        size_t idx;
        ifs >> idx;
        ((vertex_t*)&mesh)[i] = vertices_[idx - 1]; // index starts at 1
        /* Ugly trick to embed the mesh creation in the loop */
    }

    meshes_.push_back(mesh);
}
