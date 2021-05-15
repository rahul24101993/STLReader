#include <fstream>
#include <iostream>
#include "ReadStl.h"


std::ostream& operator<<(std::ostream& out, const point point) {
   out << "{" << point.x_coordinate << ", " << point.y_coordinate << ", " << point.z_coordinate << "}" << std::endl;
   return out;
}

std::ostream& operator<<(std::ostream& out, const triangle& triangle) {
   out << "Triangle" << std::endl;
   std::cout << "Normal ";
   out << triangle.normal << std::endl;
   std::cout << "Vertex1 ";
   out << triangle.vertex1 << std::endl;
   std::cout << "Vertex2 ";
   out << triangle.vertex2 << std::endl;
   std::cout << "Vertex3 ";
   out << triangle.vertex3 << std::endl;
   return out;
}

float extractCoordinate(std::ifstream& s) {
    char coordinate[sizeof(float)];
    s.read(coordinate, 4);
    float* fptr = (float*)coordinate;
    return *fptr;
}

point extractPoint(std::ifstream& s) {
    float x = extractCoordinate(s);
    float y = extractCoordinate(s);
    float z = extractCoordinate(s);
    return point(x, y, z);
}

stlReader readStl(const std::string& stl_path) {
    std::ifstream stl_file(stl_path, std::ios::binary);
    char header[80];
    char numberOfTriangles[4];
    stl_file.read(header, 80);
    stl_file.read(numberOfTriangles, 4);
    stlReader data(header);
    int inumberOfTriangles = *((int*)numberOfTriangles);
    for (unsigned int i = 0; i < inumberOfTriangles; i++) {
        auto normal      = extractPoint(stl_file);
        auto vertex1     = extractPoint(stl_file);
        auto vertex2     = extractPoint(stl_file);
        auto vertex3     = extractPoint(stl_file);
        data.triangles.push_back(triangle(normal, vertex1, vertex2, vertex3));
        char attribute[2];
        stl_file.read(attribute, 2);
     }
        return data;
}
