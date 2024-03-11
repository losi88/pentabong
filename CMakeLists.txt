# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.28)

project(pentabong)

set(CMAKE_DEBUG_POSTFIX _d)

set(dir_bin ${CMAKE_SOURCE_DIR}/bin)
set(dir_lib ${CMAKE_SOURCE_DIR}/lib)

set(dir_ari_include ${CMAKE_SOURCE_DIR}/framework/ari/include)
set(dir_bong_include ${CMAKE_SOURCE_DIR}/framework/bong/include)
set(dir_senbong_include ${CMAKE_SOURCE_DIR}/server/senbong/include)
set(dir_aoi_include ${CMAKE_SOURCE_DIR}/framework/aoi/include)

set(dir_proto_include ${CMAKE_SOURCE_DIR}/proto)
set(dir_protobuf_include ${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows-static-md/include)
set(path_protobuf_lib ${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows-static-md/lib)
#set(dir_protobuf_include ${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows/include)
#set(path_protobuf_lib ${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows/lib)

set(dir_asio_include ${CMAKE_SOURCE_DIR}/external/asio-1.28.0/include)

set(dir_gtest_include ${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows-static-md/include)
set(path_gtest_lib
    $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows-static-md/debug/lib/gtest.lib>
	$<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows-static-md/lib/gtest.lib>)

foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${dir_bin})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${dir_bin})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${dir_lib})
endforeach( OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES )

# Include sub-projects.
add_subdirectory (framework)
add_subdirectory (proto)
add_subdirectory (server)
add_subdirectory (source)
add_subdirectory (testclient)