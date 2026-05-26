# DataFormats library
file(GLOB SOURCES src/*.cc)
file(GLOB HEADERS *.h)

add_library(Example_DataFormats SHARED ${SOURCES})
add_library(Example::DataFormats ALIAS Example_DataFormats)

# Need to be defined before dictionary generation for ROOT's macros to
# know the include paths
target_include_directories(Example_DataFormats
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

# Generate ROOT dictionary if classes_def.xml exists
# Generate dictionary
stitched_generate_dictionary(Example_DataFormats_dict
    ${CMAKE_CURRENT_SOURCE_DIR}/src/classes.h
    LINKDEF ${CMAKE_CURRENT_SOURCE_DIR}/src/classes_def.xml
    MODULE Example_DataFormats
    OPTIONS --reflex
)

# Associate headers with the target using FILE_SET
target_sources(Example_DataFormats
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS ${CMAKE_SOURCE_DIR}
        FILES ${HEADERS}
)

target_link_libraries(Example_DataFormats
    PUBLIC
        Stitched::DataFormats_Common
        ROOT::Core
)

set_target_properties(Example_DataFormats PROPERTIES
    VERSION 1.0.0
    SOVERSION 1
)
