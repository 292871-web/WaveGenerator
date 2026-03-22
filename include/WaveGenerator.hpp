#ifndef WAVE_GENERATOR_HPP
#define WAVE_GENERATOR_HPP

#include <vector>
#include "Point.hpp"

class WaveGenerator {
  public:
    WaveGenerator(int grid_var, float boxSize);
    std::vector<Point> generateCoordinates();
    
  private:
    int m_gridPoints;
    float m_boxSize;
};
#endif
