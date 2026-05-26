# DataFormats library
file(GLOB SOURCES src/*.cc)
file(GLOB HEADERS interface/*.h)

add_library(examplepackage_DataFormats SHARED ${SOURCES})

# Need to be defined before dictionary generation for ROOT's macros to
# know the include paths
target_include_directories(examplepackage_DataFormats
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

# Generate ROOT dictionary if classes_def.xml exists
# Generate dictionary
stitched_generate_dictionary(examplepackage_DataFormats_dict
    ${CMAKE_CURRENT_SOURCE_DIR}/src/classes.h
    LINKDEF ${CMAKE_CURRENT_SOURCE_DIR}/src/classes_def.xml
    MODULE examplepackage_DataFormats
    OPTIONS --reflex
)

# Associate headers with the target using FILE_SET
target_sources(examplepackage_DataFormats
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS ${CMAKE_SOURCE_DIR}
        FILES ${HEADERS}
)

target_link_libraries(examplepackage_DataFormats
    PUBLIC
        Stitched::stitched_DataFormats_Common
        ROOT::Core
)

set_target_properties(examplepackage_DataFormats PROPERTIES
    VERSION 1.0.0
    SOVERSION 1
)
