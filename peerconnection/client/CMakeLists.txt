find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)
include_directories(${GTK_INCLUDE_DIRS})
add_executable(client main.cpp
    defaults.cc
    # main_wnd.cc
    # gtk_wnd.cc
    # conductor.cc
    # peer_connection_client.cc
)
target_link_libraries(client ${LIBWEBRTC_LIBRARIES} gtk-3)