
set (target proto)

file(GLOB config ./config/*.proto)
file(GLOB datatable ./datatable/*.proto)
file(GLOB packet ./packet/*.proto)
file(GLOB property ./property/*.proto)

file(GLOB config_generated ./config_generated/*.cc ./config_generated/*.h)
file(GLOB datatable_generated ./datatable_generated/*.cc ./datatable_generated/*.h)
file(GLOB packet_generated ./packet_generated/*.cc ./packet_generated/*.h)
file(GLOB property_generated ./property_generated/*.cc ./property_generated/*.h)

source_group(config FILES ${config})
source_group(datatable FILES ${datatable})
source_group(packet FILES ${packet})
source_group(property FILES ${property})
source_group(config_generated FILES ${config_generated})
source_group(datatable_generated FILES ${datatable_generated})
source_group(packet_generated FILES ${packet_generated})
source_group(property_generated FILES ${property_generated})

set(protoc ${CMAKE_SOURCE_DIR}/external/protoc-25.2/bin/win64/protoc.exe)

add_custom_target(${target}
	COMMAND ${protoc} --proto_path=${CMAKE_SOURCE_DIR}/proto/config/ --cpp_out=${CMAKE_SOURCE_DIR}/proto/config_generated/ ${CMAKE_SOURCE_DIR}/proto/config/*.proto
	#COMMAND ${protoc} --proto_path=${CMAKE_SOURCE_DIR}/proto/datatable/ --cpp_out=${CMAKE_SOURCE_DIR}/proto/datatable_generated/ ${CMAKE_SOURCE_DIR}/proto/datatable/*.proto
	#COMMAND ${protoc} --proto_path=${CMAKE_SOURCE_DIR}/proto/packet/ --cpp_out=${CMAKE_SOURCE_DIR}/proto/packet_generated/ ${CMAKE_SOURCE_DIR}/proto/packet/*.proto
	#COMMAND ${protoc} --proto_path=${CMAKE_SOURCE_DIR}/proto/property/ --cpp_out=${CMAKE_SOURCE_DIR}/proto/property_generated/ ${CMAKE_SOURCE_DIR}/proto/property/*.proto
	SOURCES ${config} ${datatable} ${packet} ${property}
			${config_generated} ${datatable_generated}
			${packet_generated} ${property_generated})
