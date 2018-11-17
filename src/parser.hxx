#pragma once
#include "parser.hh"

template <typename T>
void OBJParser::process_tricoords(std::ifstream& ifs, std::vector<T>& v)
{
    double x, y, z;

    ifs >> x >> y >> z;
    v.push_back({x, y, z});
}
