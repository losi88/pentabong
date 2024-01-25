### CMakeList.txt : CMake project for ari, include source and define
### project specific logic here.
###

set(target ari)

file(GLOB include ../include/ari/*.h)
file(GLOB source ./*.cpp ./*.h ./*.ixx)

source_group(include FILES ${include})
source_group(source FILES ${source})

### Add source to this project's executable.
add_library(${target} SHARED)

target_sources(${target}
    PRIVATE ../include/ari/ari.h
    PRIVATE ari.cpp
    PUBLIC
        FILE_SET cxx_modules
        TYPE CXX_MODULES
        FILES foo.ixx
)

### Properties
set_target_properties(${target}
    PROPERTIES
    CXX_STANDARD 20
    DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
)

include_directories(${target} . ${dir_ari_include})

add_compile_definitions(ARI_EXPORTS)
