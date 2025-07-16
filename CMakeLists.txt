cmake_minimum_required(VERSION 3.20)
project(NerdCalculator)

include(cmake/path.cmake)

add_executable(${PROJECT_NAME} ${HPP_FILES} ${CPP_FILES})