#include <fstream>
#include <iomanip>
#include "../include/ObjExporter.hpp"

void ObjExporter::save(const std::string& filename, const std::vector<Point>& points, int grid_var) {
std::ofstream file(filename);
if (!file.is_open()) return;

file << "o QuantumWave\n";


  for (const auto& pt : points){
    file << "v "  << pt.x << " " << pt.y << " " << std::fixed << pt.z << std::endl;
  }
  for (int i = 0; i<grid_var-1; i++){
    for (int n = 0; n<grid_var-1; n++){
    int LG = i*grid_var + n + 1;
    int PG = i*grid_var + n + 2;
    int LD = (i+1)*grid_var + n + 1;
    int PD = (i+1)*grid_var + n + 2;
      file << "f " << LG << " " << LD << " " << PG << std::endl;
      file << "f " << PG << " " << LD << " " << PD << std::endl;
    }
  }
  file.close();
  return;
}

