find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-3.0)
include_directories(${GTK_INCLUDE_DIRS} 
        ${CMAKE_SOURCE_DIR}/lib/libyuv/include
        ${CMAKE_SOURCE_DIR}/lib/jsoncpp/include)

link_directories(${CMAKE_SOURCE_DIR}/build/lib/jsoncpp/src/lib_json
    /usr/local/opt/gettext/lib
)
add_executable(client main.cpp
    defaults.cc
    main_wnd.cc
    conductor.cc
    peer_connection_client.cc
)
target_link_libraries(client ${LIBWEBRTC_LIBRARIES} yuv jsoncpp
    gtk-3 gdk-3 pangocairo-1.0 pango-1.0 atk-1.0 cairo-gobject cairo gdk_pixbuf-2.0 gio-2.0 gobject-2.0 glib-2.0 intl
    "-framework AVFoundation" "-framework CoreVideo"  "-framework CoreMedia")