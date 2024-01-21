### CMakeList.txt : CMake project for ari, include source and define
### project specific logic here.
###

set(target pentabong)

file(GLOB source ./*.cpp ./*.h)

source_group(source FILES ${source})

### Add source to this project's executable.
add_executable(${target} ${source})

set_target_properties(${target}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${dir_bin}
    DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
)

include_directories(${target} . ${dir_ari_include})

target_link_libraries(${target} PRIVATE ari)
