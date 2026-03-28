#ifndef EXPORTER_HPP
#define EXPORTER_HPP

//debbuging


#include <string>
#include <vector>
#include "Point.hpp"

class CsvExporter {
  public: 
    void save(const std::string& filename, const std::vector<AdvPoint>& coordinates, int gridPoints);
};
class BinExporter {
  public: 
    void save(const std::string& filename, const std::vector<AdvPoint>& coordinates);
};

#endif
