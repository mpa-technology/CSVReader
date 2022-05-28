cmake_minimum_required(VERSION 3.14)

project(CSVReader LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(CSVReader SHARED
  CSVReader.cpp
  CSVReader.hpp
)

target_compile_definitions(CSVReader PRIVATE CSVREADER_LIBRARY)
