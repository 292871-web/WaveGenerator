#ifndef OBJ_EXPORTER_HPP
#define OBJ_EXPORTER_HPP

#include <string>
#include <vector>
#include "point.hpp"

class ObjExporter {
  public: 
    void save(const std::string& filename, const std::vector<Point>& points, int gridPoints);
};

#endif
