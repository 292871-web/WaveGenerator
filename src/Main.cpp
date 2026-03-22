#include "../include/WaveGenerator.hpp"
#include "../include/ObjExporter.hpp"

int main() {
    const int resolution = 100; // gridPoints
    
    WaveGenerator generator(resolution, 10.0f);
    auto points = generator.generateCoordinates();

    ObjExporter exporter;
    exporter.save("../output/QuantumWave.obj", points, resolution);

    return 0;
}
