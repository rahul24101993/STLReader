#include <fstream>
#include<iostream>
#include "parse_stl.h"

int main()
{
    auto datas = readStl(""); //insert file name
    std::vector<triangle> triangles = datas.triangles;
    std::cout << "Number of triangles : " << triangles.size() << std::endl;
    std::cout << " " << std::endl;
    int count = 1;
    for (auto data : datas.triangles) {
        std::cout << count<<"th ";
        std::cout << data << std::endl;
        count++;
    }

  }