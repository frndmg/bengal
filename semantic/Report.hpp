//
// Created by frnd on 12/30/16.
//

#ifndef BENGAL_REPORT_HPP
#define BENGAL_REPORT_HPP

#include <iostream>
#include <fstream>
#include <cstdio>

namespace semantic
{

class Report
{
public:
    template <typename T, typename ...Args>
    void error(const T& node, const char* format, const Args&... args)
    {
        std::cerr << node.position() << " ";
        char str[100]; // TODO: How to change this?
        std::sprintf(str, format, args...);
        std::cerr << str << std::endl;
    }
};

} // semantic namespace

#endif //BENGAL_REPORT_HPP
