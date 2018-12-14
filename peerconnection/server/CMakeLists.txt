add_executable(server main.cpp 
    data_socket.cc 
    utils.cc 
    peer_channel.cc
    simple_command_line_parser.cc)
target_link_libraries(server ${LIBWEBRTC_LIBRARIES})