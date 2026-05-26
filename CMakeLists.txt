cmake_minimum_required(VERSION 3.16)
project(ExampleProject)

# Include GNUInstallDirs early so variables are available for environment scripts
include(GNUInstallDirs)

# Find the CMSSW package
find_package(Stitched REQUIRED)

# Add compile options
add_compile_options(-Wall -Werror=return-type -Wno-attributes)
add_link_options(LINKER:-z,defs)

# Set output directories
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_subdirectory(DataFormats)
add_subdirectory(ExampleProject)

stitched_generate_plugincache(
  PLUGIN_TARGETS
  ExampleProjectPlugin
)
