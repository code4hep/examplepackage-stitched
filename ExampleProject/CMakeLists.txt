set(SOURCES "ExampleAnalyzer.cc" "ExampleProducer.cc")

stitched_generate_plugin(
    TARGET ExampleProjectPlugin
    SOURCES ${SOURCES}
    LINK_LIBRARIES
        examplepackage_DataFormats
        Stitched::stitched_FWCore_Framework
        Stitched::stitched_FWCore_MessageLogger
        Stitched::stitched_FWCore_ParameterSet
)
