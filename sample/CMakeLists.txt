set(SOURCE_FILES main.cpp)
add_executable(sample ${SOURCE_FILES})
target_link_libraries(sample ${LIBWEBRTC_LIBRARIES})