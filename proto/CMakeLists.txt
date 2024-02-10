
set (target_protoc protoc)

file(GLOB config ./config/*.proto)
file(GLOB datatable ./datatable/*.proto)
file(GLOB packet ./packet/*.proto)
file(GLOB property ./property/*.proto)

file(GLOB config_generated ./config_generated/*.cc ./config_generated/*.h)
file(GLOB datatable_generated ./datatable_generated/*.cc ./datatable_generated/*.h)
file(GLOB packet_generated ./packet_generated/*.cc ./packet_generated/*.h)
file(GLOB property_generated ./property_generated/*.cc ./property_generated/*.h)

source_group(config FILES ${config})
source_group(datatable FILES ${datatable})
source_group(packet FILES ${packet})
source_group(property FILES ${property})
source_group(config_generated FILES ${config_generated})
source_group(datatable_generated FILES ${datatable_generated})
source_group(packet_generated FILES ${packet_generated})
source_group(property_generated FILES ${property_generated})

set(path_protoc ${CMAKE_SOURCE_DIR}/external/protoc-21.12/bin/protoc.exe)

add_custom_target(${target_protoc}
 COMMAND ${path_protoc} --proto_path=${CMAKE_SOURCE_DIR}/proto/config/ --cpp_out=${CMAKE_SOURCE_DIR}/proto/config_generated/ ${CMAKE_SOURCE_DIR}/proto/config/*.proto
 #COMMAND ${path_protoc} --proto_path=${CMAKE_SOURCE_DIR}/proto/datatable/ --cpp_out=${CMAKE_SOURCE_DIR}/proto/datatable_generated/ ${CMAKE_SOURCE_DIR}/proto/datatable/*.proto
 #COMMAND ${path_protoc} --proto_path=${CMAKE_SOURCE_DIR}/proto/packet/ --cpp_out=${CMAKE_SOURCE_DIR}/proto/packet_generated/ ${CMAKE_SOURCE_DIR}/proto/packet/*.proto
 #COMMAND ${path_protoc} --proto_path=${CMAKE_SOURCE_DIR}/proto/property/ --cpp_out=${CMAKE_SOURCE_DIR}/proto/property_generated/ ${CMAKE_SOURCE_DIR}/proto/property/*.proto
 SOURCES ${config} ${datatable} ${packet} ${property}
   ${config_generated} ${datatable_generated}
   ${packet_generated} ${property_generated})

### Add source to this project's executable.
set (target_protobong protobong)

set(Protobuf_USE_STATIC_LIBS ON)
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows-static-md")
find_package(Protobuf REQUIRED)

add_library (${target_protobong} STATIC)

target_sources (${target_protobong}
 PRIVATE ${config_generated}
 PRIVATE ${datatable_generated}
 PRIVATE ${packet_generated}
 PRIVATE ${property_generated}
 PRIVATE ${PROTO_SRCS}
 PRIVATE ${PROTO_HDRS}
)

### Properties
set_target_properties(${target_protobong}
    PROPERTIES
    CXX_STANDARD 20
    DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
)

target_include_directories(${target_protobong} PRIVATE .
                                                  PUBLIC ${dir_proto}
                                                  PUBLIC ${Protobuf_INCLUDE_DIRS})

target_link_libraries(${target_protobong} PUBLIC $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows-static-md/debug/lib/libprotobufd.lib>
                                                    $<$<CONFIG:Release>:${Protobuf_LIBRARIES}>)
