### CMakeList.txt : CMake project for ari, include source and define
### project specific logic here.
###

set(target ari)

file(GLOB include ../include/ari/*.h)
file(GLOB source ./*.cpp ./*.h)

source_group(include FILES ${include})
source_group(source FILES ${source})

### Add source to this project's executable.
add_library(${target} SHARED ${include} ${source})

set_target_properties(${target}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${dir_bin}
    ARCHIVE_OUTPUT_DIRECTORY ${dir_lib}
    DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX}
)

include_directories(${target} . ${dir_ari_include})

add_compile_definitions(ARI_EXPORTS)
