cmake_minimum_required(VERSION 3.30)

# set(CMAKE_CXX_FLAGS "--gcc-install-dir=/usr/lib/gcc/x86_64-linux-gnu/13")

# CPP is only used for testing.
project(ds_modems_c VERSION 0.1.0 LANGUAGES C CXX)

# download CPM.cmake
file(
  DOWNLOAD
  https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.40.8/CPM.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
  EXPECTED_HASH SHA256=78ba32abdf798bc616bab7c73aac32a17bbd7b06ad9e26a6add69de8f3ae4791
)
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

CPMAddPackage("gh:catchorg/Catch2@3.13.0")

add_subdirectory(src)

enable_testing()
add_subdirectory(tests)
# # add dependencies here
# CPMAddPackage(...)

