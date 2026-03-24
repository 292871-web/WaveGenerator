#pragma once
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
class AdvWaveGenerator {
  public:
      AdvWaveGenerator(int grid_var, float boxSize, float timeMax, float timeResolution);
      std::vector<AdvPoint> AdvGenerateCoordinates();
  private:
    int m_gridPoints;
    float m_boxSize;
    float m_timeMax;
    float m_timeResolution;
};
#endif
