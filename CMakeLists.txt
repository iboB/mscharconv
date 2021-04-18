cmake_minimum_required(VERSION 3.10)

project(mscharconv)

add_library(mscharconv INTERFACE)
target_include_directories(mscharconv INTERFACE include)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    set(dev_mode ON)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_EXTENSIONS OFF)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

    if(NOT MSVC)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
    endif()
else()
    set(dev_mode OFF)
endif()

option(MSCHARCONV_BUILD_TESTS "mscharconv: build tests" ${dev_mode})
option(MSCHARCONV_BUILD_EXAMPLES "mscharconv: build examples" ${dev_mode})

if(MSCHARCONV_BUILD_EXAMPLES)
    add_subdirectory(example)
endif()

if(MSCHARCONV_BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()
