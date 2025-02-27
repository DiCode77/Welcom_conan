cmake_minimum_required(VERSION 3.31.5)
project(MyProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(EXISTS "${CMAKE_BINARY_DIR}/conan_toolchain.cmake")
    include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)
else()
    message(FATAL_ERROR "conan_toolchain.cmake не знайдено")
endif()

add_executable(${PROJECT_NAME} main.cpp)

set(CMAKE_OSX_SYSROOT "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk")

find_package(fmt REQUIRED)
include_directories(${fmt_INCLUDE_DIRS})

find_package(fmt REQUIRED)
set(FMT_LIBRARY ${CONAN_LIB_DIRS_FMT}/libfmt.a)

get_filename_component(FMT_BASE_DIR ${fmt_INCLUDE_DIRS} DIRECTORY)
target_link_libraries(${PROJECT_NAME} PRIVATE ${FMT_BASE_DIR}/lib${FMT_LIBRARY})

message(STATUS "FMT base dir: ${FMT_BASE_DIR}/lib${FMT_LIBRARY}")

