#include <cmath>
#include <iostream>
#include <iomanip>
#include "../include/WaveGenerator.hpp"

WaveGenerator::WaveGenerator(int grid_var, float boxSize) : m_gridPoints(grid_var), m_boxSize(boxSize){}

std::vector<Point> WaveGenerator::generateCoordinates() {
  std::vector<Point> points;
  float stepSize = m_boxSize/static_cast<float>(m_gridPoints - 1);
  for (int i = 0; i<m_gridPoints; i++){
      for (int n = 0; n<m_gridPoints; n++){
        Point p;
        p.x = static_cast<float>(i+1)*stepSize;
        p.y = static_cast<float>(n+1)*stepSize;
        p.z = std::abs(std::pow(std::sin(9*M_PI*p.x/m_boxSize), 2)*std::pow(std::sin(9*M_PI*p.y/m_boxSize), 2));
        points.push_back(p);
      }
    }
    return points;
}



AdvWaveGenerator::AdvWaveGenerator(int grid_var, float boxSize, float timeMax, float timeResolution) : m_gridPoints(grid_var), m_boxSize(boxSize), m_timeMax(timeMax), m_timeResolution(timeResolution){}

std::vector<AdvPoint> AdvWaveGenerator::AdvGenerateCoordinates() {
  std::vector<AdvPoint> coordinates;
  float stepSize = m_boxSize/static_cast<float>(m_gridPoints - 1);
  int w = 1;
  for (float t = 0.0f; t <= m_timeMax; t+= m_timeResolution){
    for (int i = 0; i<m_gridPoints; i++){
        for (int n = 0; n<m_gridPoints; n++){
          AdvPoint c;
          c.x = static_cast<float>(i+1)*stepSize;
          c.y = static_cast<float>(n+1)*stepSize;
          c.t = t;
          c.z = std::abs(std::pow(std::sin(1*M_PI*c.x/m_boxSize - w*c.t), 2)*std::pow(std::sin(1*M_PI*c.y/m_boxSize - w*c.t), 2));
          coordinates.push_back(c);
        }
      }
    }
    return coordinates;
}
