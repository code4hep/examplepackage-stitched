file(GLOB PLUGIN_SOURCES plugins/*.cc)

stitched_generate_plugin(
    TARGET ExampleModulesPlugin
    SOURCES ${PLUGIN_SOURCES}
    LINK_LIBRARIES
        Example::DataFormats
        Stitched::FWCore_Framework
        Stitched::FWCore_MessageLogger
        Stitched::FWCore_ParameterSet
)
