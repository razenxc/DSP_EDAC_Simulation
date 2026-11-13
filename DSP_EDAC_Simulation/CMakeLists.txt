# CMakeList.txt : CMake project for DSP_EDAC_Simulation, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (DSP_EDAC_Simulation "main.cxx" "basic_methods.cxx" "utils.cxx")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DSP_EDAC_Simulation PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
