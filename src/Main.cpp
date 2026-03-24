#include "../include/WaveGenerator.hpp"
#include "../include/ObjExporter.hpp"
#include "../include/CsvExporter.hpp"
#include <string>

int main() {
    const int resolution = 100; // gridPoints
    /*
    WaveGenerator generator(resolution, 10.0f);
    auto points = generator.generateCoordinates();
    
    ObjExporter exporter;
    exporter.save("../output/QuantumWave.obj", points, resolution);
    */
    
    AdvWaveGenerator generator(resolution, 10.0f, 10.0f, 1.0f);
    auto coordinates = generator.AdvGenerateCoordinates();
    
    CsvExporter exporter;
    exporter.save("../output/QuantumWave.csv", coordinates, resolution);

    return 0;
}
