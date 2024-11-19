cmake_minimum_required(VERSION 3.4.1)
project(UnstooOnlyTurbo)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 14)

add_library(react-native-unstoo-only-turbo            SHARED
            ../cpp/react-native-unstoo-only-turbo.cpp
            cpp-adapter.cpp
)

# Specifies a path to native header files.
include_directories(
            ../cpp
)
