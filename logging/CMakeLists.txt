set(SOURCE_FILES main.cpp)
add_executable(logging ${SOURCE_FILES})
target_link_libraries(logging ${LIBWEBRTC_LIBRARIES})