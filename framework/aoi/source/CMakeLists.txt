### CMakeList.txt : CMake project for aoi, include source and define
### project specific logic here.
###

set(target aoi)

file(GLOB include ../include/ari/*.h)
file(GLOB source ./*.cpp ./*.h)
file(GLOB module ./*.ixx)

source_group(include FILES ${include})
source_group(source FILES ${source} ${module})

### Add source to this project's executable.
add_library(${target} STATIC)

target_sources(${target}
    PRIVATE ${include}
    PRIVATE ${source}
    PUBLIC
        FILE_SET cxx_modules
        TYPE CXX_MODULES
        FILES ${module}
)

### Properties
set_target_properties(${target}
    PROPERTIES
    CXX_STANDARD 20
    DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
)

target_include_directories(${target} PRIVATE .
                                       PRIVATE ${dir_aoi_include})

add_compile_definitions(AOI_EXPORTS)
