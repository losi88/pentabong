set(target aoi_test)

file(GLOB source ./*.cpp)

source_group(source FILES ${source})

add_executable(${target} ${source})

set_target_properties(${target}
	PROPERTIES
	CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebugDLL$<$<CONFIG:Debug>:Debug>")

add_test(NAME ${target} COMMAND ${target})

target_include_directories(${target} PRIVATE ${dir_gtest_include}
                                     PRIVATE ${dir_aoi_include}
                                     PRIVATE ${dir_proto_include})

target_link_libraries(${target} PRIVATE ${path_gtest_lib})
target_link_libraries(${target} PRIVATE protobong)
target_link_libraries(${target} PRIVATE aoi)