# CMakeList.txt : CMake project for ari, include source and define
# project specific logic here.
#

file(GLOB include ../include/*.h)
file(GLOB source ./*.cpp ./*.h)

source_group(include FILES ${include})
source_group(source FILES ${source})

# Add source to this project's executable.
add_executable(ari ${include} ${source})

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(target ari)
set_target_properties(${target}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../../bin"
)

message(STATUS "CMAKE_CURRENT_LIST_DIR : ${CMAKE_CURRENT_LIST_DIR}")
message(STATUS "CMAKE_CURRENT_LIST_FILE : ${CMAKE_CURRENT_LIST_FILE}")
message(STATUS "CMAKE_CURRENT_LIST_LINE : ${CMAKE_CURRENT_LIST_LINE}")
message(STATUS "CMAKE_PARENT_LIST_FILE : ${CMAKE_PARENT_LIST_FILE}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR : ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "CMAKE_CURRENT_BINARY_DIR : ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "CMAKE_SOURCE_DIR : ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_BINARY_DIR : ${CMAKE_BINARY_DIR}")
message(STATUS "PROJECT_SOURCE_DIR : ${PROJECT_SOURCE_DIR}")
message(STATUS "PROJECT_BINARY_DIR : ${PROJECT_BINARY_DIR}")

# TODO: Add tests and install targets if needed.
