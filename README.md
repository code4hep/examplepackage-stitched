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

# Clone and build the test package
git clone https://github.com/code4hep/examplepackage-stitched.git
cd examplepackage-stitched
cmake -S . -B build
cd build
cmake --build
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/lib
cd ..
cmsRun examplepackage_cfg.py
```
