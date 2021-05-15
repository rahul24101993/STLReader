#pragma once
#include <vector>


    struct point {
        float x_coordinate;
        float y_coordinate;
        float z_coordinate;
        point(float x_coordinate, float y_coordinate, float z_coordinate) : x_coordinate(x_coordinate), y_coordinate(y_coordinate), z_coordinate(z_coordinate) {}
    };

    struct triangle {
        point normal;
        point vertex1;
        point vertex2;
        point vertex3;
        triangle(point normal, point vertex1, point vertex2, point vertex3) :
            normal(normal), vertex1(vertex1), vertex2(vertex2), vertex3(vertex3) {}
    };

    struct stlReader {
        std::string name;
        std::vector<triangle> triangles;

        stlReader(std::string name) : name(name) {}
    };
    std::ostream& operator<<(std::ostream& out, const point point);
    std::ostream& operator<<(std::ostream& out, const triangle& triangle);
    stlReader readStl(const std::string& stl_path);




