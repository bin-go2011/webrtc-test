cmake_minimum_required(VERSION 3.3)
project(sample)

add_definitions(-g)

find_package(LibWebRTC REQUIRED)
include(${LIBWEBRTC_USE_FILE})

add_subdirectory(sample)
add_subdirectory(logging)
add_subdirectory(peerconnection)