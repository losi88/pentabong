# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.28)

project(pentabong)

set(CMAKE_DEBUG_POSTFIX _d)

set(dir_bin ${CMAKE_SOURCE_DIR}/bin)
set(dir_lib ${CMAKE_SOURCE_DIR}/lib)

set(dir_ari_include ${CMAKE_SOURCE_DIR}/framework/ari/include)

set(dir_proto_config ${CMAKE_SOURCE_DIR}/proto/config_generated)
set(dir_proto_datatable ${CMAKE_SOURCE_DIR}/proto/datatable_generated)
set(dir_proto_packet${CMAKE_SOURCE_DIR}/proto/packet_generated)
set(dir_proto_property ${CMAKE_SOURCE_DIR}/proto/property_generated)

foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${dir_bin})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${dir_bin})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${dir_lib})
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )

# Include sub-projects.
add_subdirectory (framework)
add_subdirectory (proto)
#add_subdirectory (server)
add_subdirectory (source)