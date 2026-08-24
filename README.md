# Example package that uses Stitched

This package demonstrates how the [Stitched](https://github.com/code4hep/stitched-alpha2) framework can be used.

Example usage with Spack package manager
```sh
# Set up spack
git clone --depth=2 https://github.com/spack/spack.git
source spack/share/spack/setup-env.sh

spack compiler find
# if the system does not have GCC 14 yet, install it from spack
spack install gcc@14

# Add Code4hep package repository
spack repo add https://github.com/code4hep/c4h-spack-packages

# Install ROOT first with many features that are not needed turned off
# Note: An actual physics package using Stitched might want to enable some of these
spack install root@6.36.12 davix=false dcache=false gdml=false geom=false gsl=false math=false minuit=false opengl=false roofit=false tmva-cpu=false tmva-cudnn=false unuran=false vdt=false webgui=false x=false %gcc@14

# Install and set up Stitched
spack install stitched
spack load stitched
source $(which stitched_env.sh)

# Clone the test package
git clone https://github.com/code4hep/stitched-example.git

Method 1: build it directly by yourself
cd stitched-example
cmake -S . -B build
cd build
cmake --build
source example_env.sh
cd ..
cmsRun examplepackage_cfg.py

Method 2: spack development environment
mkdir dev-env
spack env create -d dev-env
spack env activate dev-env
spack develop --path stitched-example
spack install stitched-example
source $(which example_env.sh)
cmsRun stitched-example/examplepackage_cfg.py
```
