cmake_minimum_required(VERSION 3.10)

project(mscharconv)

add_library(mscharconv INTERFACE)
target_include_directories(mscharconv INTERFACE include)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    set(dev_mode ON)
    set(CMAKE_CXX_STANDARD 17)
else()
    set(dev_mode OFF)
endif()

option(MSCHARCONV_BUILD_TESTS "mscharconv: build tests" ${dev_mode})

if(MSCHARCONV_BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()