cmake_minimum_required(VERSION 2.8)
project(XonoVIEW)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/api
)
set(XONOVIEW_HEADERS
    ${CMAKE_SOURCE_DIR}/include/data_buffer.h
    ${CMAKE_SOURCE_DIR}/include/b_mode_frame.h
    ${CMAKE_SOURCE_DIR}/include/device_config.h
    ${CMAKE_SOURCE_DIR}/include/device_config_daemon.h
    ${CMAKE_SOURCE_DIR}/include/ulterius_singleton.h
    ${CMAKE_SOURCE_DIR}/include/callbacks.h
    ${CMAKE_SOURCE_DIR}/api/xonoview.h
)
set(XONOVIEW_SOURCES
    ${CMAKE_SOURCE_DIR}/src/data_buffer.cpp
    ${CMAKE_SOURCE_DIR}/src/b_mode_frame.cpp
    ${CMAKE_SOURCE_DIR}/src/device_config.cpp
    ${CMAKE_SOURCE_DIR}/src/device_config_daemon.cpp
    ${CMAKE_SOURCE_DIR}/src/ulterius_singleton.cpp
    ${CMAKE_SOURCE_DIR}/src/callbacks.cpp
    ${CMAKE_SOURCE_DIR}/api/xonoview.cpp
)
set(LIBRARY_NAME xonoview)
add_library(${LIBRARY_NAME}
    ${XONOVIEW_SOURCES} ${XONOVIEW_HEADERS}
)
