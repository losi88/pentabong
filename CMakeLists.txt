# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.12)

project(pentabong)

# Include sub-projects.
add_subdirectory (framework)
#add_subdirectory (server)
#add_subdirectory (source)