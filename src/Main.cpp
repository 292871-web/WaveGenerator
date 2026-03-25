#include "../include/WaveGenerator.hpp"
#include "../include/ObjExporter.hpp"
#include "../include/CsvExporter.hpp"
#include "../include/CLI11.hpp"
#include <string>

int resolution=100;
float sizeBox=10.0f;
float timeMax=10.0f;
float timeResolution=1.0f;
char program = 'i';

int main(int argc, char **argv) {
    CLI::App app;
    app.add_option("-p,--program", program, "Which program u are choosing, avaible are: \n- o for generating an static obj \n- a for generating an animation")->required();
    app.add_option("-r,--resolution", resolution, "How acurate the animation will be");
    app.add_option("-s,--sizeBox", sizeBox, "How big is going to be the plot");
    app.add_option("-t,--timeResolution", timeResolution, "How accurate the time between animation's frames will be");
    app.add_option("-m,--timeMax", timeMax, "How long the animation will be");
    CLI11_PARSE(app, argc, argv);
    if (program = 'o') {
    WaveGenerator generator(resolution, sizeBox);
    auto points = generator.generateCoordinates();
    
    ObjExporter exporter;
    exporter.save("../output/QuantumWave.obj", points, resolution);
    } else if (program = 'a') {
    AdvWaveGenerator generator(resolution, sizeBox, timeMax, timeResolution);
    auto coordinates = generator.AdvGenerateCoordinates();
    
    CsvExporter exporter;
    exporter.save("../output/QuantumWave.csv", coordinates, resolution);
    }
    return 0;
}
