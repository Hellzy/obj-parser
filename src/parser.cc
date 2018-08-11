#include <fstream>

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
        char c = ifs.get();

        if (c == 'v')
        {
            double x, y, z;

            ifs >> x >> y >> z;
            vertices.push_back({x, y, z});
        }
        else if (c == 'f')
        {
            mesh_t mesh;

            for (int i = 0; i < 3; ++i)
            {
                size_t idx;
                ifs >> idx;
                mesh.vertex_indices.push_back(idx);
            }

            meshes.push_back(mesh);
        }
    }
}
