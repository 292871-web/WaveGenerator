#include "../include/Exporter.hpp"
#include <fstream>
#include <iostream>

void BinExporter::save(const std::string& filename, const std::vector<AdvPoint>& coordinates) {
std::ofstream file(filename, std::ios::binary);

if (coordinates.empty()) {
    std::cout << "BLAD: Wektor jest pusty! Nie ma czego zapisywac.\n";
    return;
}
  std::size_t length = coordinates.size()*sizeof(coordinates[0]);
  file.write(reinterpret_cast<const char*>(coordinates.data()),length);
  file.close();
  return;
}
