
set(target hello_test)

file(GLOB source ./*.cpp)

source_group(source FILES ${source})

add_executable(${target} ${source})

set_target_properties(${target}
	PROPERTIES
	MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

add_test(NAME ${target} COMMAND ${target})

include_directories(${target} ${CMAKE_SOURCE_DIR}/external/googletest-1.14.0/include)

target_link_libraries(${target}
	$<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}/external/googletest-1.14.0/debug/gtest.lib>
	$<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}/external/googletest-1.14.0/release/gtest.lib>)