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
            process_tricoords(ifs, vertices_);
        else if (!tok.compare("vt"))
            process_vertex_texture(ifs);
        else if (!tok.compare("vn"))
            process_tricoords(ifs, n_);
        else if (!tok.compare("f"))
            process_face(ifs);
        else if (!tok.compare("mtllib"))
            process_mtl(ifs);
        else
            std::cerr << "Rejected: " << tok << '\n';
    }
}

inline
void OBJParser::process_vertex_texture(std::ifstream& ifs)
{
    double x, y;
    ifs >> x >> y;
    vt_.push_back(point_t{x, y, 0});

    /* This loop eats the optional 3rd argument which is always 0 if set */
    while (ifs.peek() != '\n')
        ifs.get();
}

inline
void OBJParser::process_face(std::ifstream& ifs)
{
    mesh_t mesh;

    for (size_t i = 0; i < 3; ++i)
    {
        auto [v_idx, vt_idx, vn_idx] = get_vertex_info(ifs);

        if (vt_idx > 0) //idx == 0 means no '/' was found
            vertices_[v_idx - 1].tex = vt_[vt_idx - 1];  // index starts at 1

        ((vertex_t*)&mesh)[i] = vertices_[v_idx - 1];   // index starts at 1
    }

    meshes_.push_back(mesh);
}

inline
std::tuple<size_t, size_t, size_t> OBJParser::get_vertex_info(std::ifstream& ifs)
{
    std::string seq;
    std::string num;
    size_t offs[3] = {0};
    size_t offs_off = 0;
    size_t lastpos = 0;

    ifs >> seq;

    for (size_t i = 0; i < seq.size(); ++i)
    {
        if (seq[i] == '/')
        {
            if (seq[i - 1] != '/') //discard double slash
                offs[offs_off] = std::stoi(seq.substr(lastpos, i - lastpos));

            lastpos = i + 1;
            ++offs_off;
        }
    }

    if (seq[seq.size() - 1] != '/') //discard double slash
        offs[offs_off] = std::stoi(seq.substr(lastpos, seq.size() - lastpos));

    return {offs[0], offs[1], offs[2]};
}


void OBJParser::process_mtl(std::ifstream& ifs)
{
    std::string filename;

    ifs  >> filename;
    mtlp::MTLParser mtl_p(filename);
    mats_ = mtl_p.mats_get();
}
