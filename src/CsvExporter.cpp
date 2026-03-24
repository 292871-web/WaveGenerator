#include "../include/CsvExporter.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>

void CsvExporter::save(const std::string& filename, const std::vector<AdvPoint>& coordinates, int grid_var) {
std::ofstream file(filename);
if (!file.is_open()) return; 
  file << "x,y,z,time"<< std::endl;
  for (auto const& cr : coordinates) {
    file << std::setprecision(3) << cr.t  << "," << std::setprecision(3) << cr.x << "," << std::setprecision(3) << cr.y << "," << std::fixed << std::setprecision(3) << cr.z << std::endl;
  }
  file.close();
  return;
}
