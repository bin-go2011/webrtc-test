cmake_minimum_required(VERSION 3.3)
project(sample)

# set(CMAKE_VERBOSE_MAKEFILE ON)
add_definitions(-g -fno-rtti)

add_subdirectory(lib)

find_package(LibWebRTC REQUIRED)
include(${LIBWEBRTC_USE_FILE})

add_subdirectory(sample)
add_subdirectory(logging)
add_subdirectory(peerconnection/server)
add_subdirectory(peerconnection/client)
