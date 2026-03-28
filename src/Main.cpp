#include "../include/WaveGenerator.hpp"
#include "../include/ObjExporter.hpp"
#include "../include/Exporter.hpp"
#include "../include/CLI11.hpp"
#include "../include/config.hpp"
#include <string>
#include <omp.h>



int main(int argc, char **argv) {
    double start = omp_get_wtime();
    appConfig config;
    CLI::App app;
    app.add_option("-p,--program", config.program, "Which program u are choosing, avaible are: \n- o for generating an static obj \n- a for generating an animation")->required();
    app.add_option("-r,--resolution", config.resolution, "How acurate the animation will be");
    app.add_option("-s,--sizeBox", config.sizeBox, "How big is going to be the plot");
    app.add_option("-t,--timeResolution", config.timeResolution, "How accurate the time between animation's frames will be");
    app.add_option("-m,--timeMax", config.timeMax, "How long the animation will be");
    CLI11_PARSE(app, argc, argv);
    //#debugging std::cout << "Wybrano format: " << program << "\n";
    if (config.program == 'o') {
      WaveGenerator generator(config.resolution, config.sizeBox);
      auto points = generator.generateCoordinates();
      
      ObjExporter exporter;
      exporter.save("../output/obj/QuantumWave.obj", points, config.resolution);
    } else if (config.program == 'a') {
    // std::cout << "Wybrano format: " << program << "\n";
      AdvWaveGenerator generator(config.resolution, config.sizeBox, config.timeMax, config.timeResolution);
      auto coordinates = generator.AdvGenerateCoordinates();
      
      CsvExporter csvExporter;
      csvExporter.save("../output/csv/QuantumWave.csv", coordinates, config.resolution);
      
      BinExporter binExporter;
      binExporter.save("../output/bin/QuantumWave.bin", coordinates);
    }
    double end = omp_get_wtime();
    std::cout << "Took " << end-start << " seconds\n";
    return 0;
}
