# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.12)

project(pentabong)

set(CMAKE_DEBUG_POSTFIX _d)

set(dir_bin ${CMAKE_CURRENT_LIST_DIR}/bin)
set(dir_lib ${CMAKE_CURRENT_LIST_DIR}/lib)

set(dir_ari_include ${CMAKE_CURRENT_LIST_DIR}/framework/ari/include)

foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    message(OUTPUTCONFIG: ${OUTPUTCONFIG})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${dir_bin})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${dir_bin})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${dir_lib})
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )

# Include sub-projects.
add_subdirectory (framework)
#add_subdirectory (server)
add_subdirectory (source)