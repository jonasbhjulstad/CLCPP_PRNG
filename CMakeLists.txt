cmake_minimum_required(VERSION 3.23.2)
project(CLCPP_PRNG)
include(FetchContent)
# if(NOT ${randomCL_repo_SOURCE_DIR})
FetchContent_Declare(randomCL_repo
GIT_REPOSITORY https://github.com/bstatcomp/RandomCL.git
)
FetchContent_MakeAvailable(randomCL_repo)
file(GLOB RANDOMCL_HEADERS ${randomcl_repo_SOURCE_DIR}/generators/*.h)
add_library(randomCL INTERFACE ${RANDOMCL_HEADERS})
install(TARGETS randomCL EXPORT randomCLCPP 
INCLUDES DESTINATION include)
set(CLCPP_PRNG_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/)
set(CLCPP_RANDOMCL_INCLUDE_DIR ${randomcl_repo_SOURCE_DIR}/generators/)
add_subdirectory(include)
export(EXPORT randomCLCPP
FILE "${CMAKE_CURRENT_BINARY_DIR}/pkg/clcpp_prng-targets.cmake")
# endif()
# Create and install package configuration and version files.
configure_file(
   ${CLCPP_PRNG_SOURCE_DIR}/pkg/clcpp_prng-config.cmake.in
   ${CLCPP_PRNG_BINARY_DIR}/pkg/clcpp_prng-config.cmake @ONLY)

install(FILES ${CLCPP_PRNG_BINARY_DIR}/pkg/clcpp_prng-config.cmake
         DESTINATION lib/cmake/clcpp_prng)
install(FILES ${CLCPP_PRNG_SOURCE_DIR}/include/CLCPP_PRNG.hpp
      DESTINATION include/CLCPP_PRNG)