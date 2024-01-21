### CMakeList.txt : CMake project for ari, include source and define
### project specific logic here.
###

set(target ari)

file(GLOB include ../include/*.h)
file(GLOB source ./*.cpp ./*.h)

source_group(include FILES ${include})
source_group(source FILES ${source})

### Add source to this project's executable.
#add_executable(ari ${include} ${source})
add_library(${target} SHARED ${include} ${source})

###
if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE Release)
endif (NOT CMAKE_BUILD_TYPE)

set_target_properties(${target}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../../../bin"
)

