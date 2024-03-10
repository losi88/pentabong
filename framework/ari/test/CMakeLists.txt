
set(target ari_test)

file(GLOB source ./*.cpp)

source_group(source FILES ${source})

add_executable(${target} ${source})

set_target_properties(${target}
	PROPERTIES
	MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

add_test(NAME ${target} COMMAND ${target})

target_include_directories(${target} PRIVATE ${dir_gtest_include}
																																								PRIVATE ${dir_ari_include})

target_link_libraries(${target} ${path_gtest_lib})
target_link_libraries(${target} ari)
