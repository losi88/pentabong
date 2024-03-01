### CMakeList.txt : CMake project for ari, include source and define
### project specific logic here.
###

set(target testclient)

file(GLOB source ./*.cpp ./*.h)

source_group(source FILES ${source})

### Add source to this project's executable.
add_executable(${target} ${source})

set_target_properties(${target}
    PROPERTIES
    CXX_STANDARD 20
    RUNTIME_OUTPUT_DIRECTORY ${dir_bin}
    DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
)

target_include_directories(${target} PRIVATE .
                                        PRIVATE ${dir_asio_include})
