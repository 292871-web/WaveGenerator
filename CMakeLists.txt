cmake_minimum_required(VERSION 3.10)
project(QuantumWave)
set(CMAKE_CXX_STANDARD 17)

add_executable(WaveGenerator main.cpp ObjExporter.cpp WaveGenerator.cpp)
