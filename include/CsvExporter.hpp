#ifndef CSV_EXPORTER_HPP
#define CSV_EXPORTER_HPP

#include <string>
#include <vector>
#include "Point.hpp"

class CsvExporter {
  public: 
    void save(const std::string& filename, const std::vector<AdvPoint>& coordinates, int gridPoints);
};

#endif
