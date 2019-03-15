cmake_minimum_required(VERSION 2.8)
project(Xono2L)

# Guard against 64-bit builds
if(NOT WIN32)
    message(FATAL_ERROR "Xono2L is supported on Windows only")
endif()
if(${CMAKE_GENERATOR} MATCHES "Win64")
    message(FATAL_ERROR "Xono2L is supported in 32-bit only")
endif()

# Activate CMake find scripts
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/cmake)

# User options
option(USE_ULTERIUS "Link against Ulterius, and activate functionality" OFF)

list(APPEND XONO2L_INCLUDE_DIRS
    ${CMAKE_SOURCE_DIR}/api
    ${Ulterius_INCLUDE_DIR}
)

# Suffix indicating what the built library supports
set(${FILE_SUFFIX} "")

# Activate source code based on user options
if(${USE_ULTERIUS})
    add_definitions(-DUSE_ULTERIUS)

    # Try to locale Ulterius library
    find_package(Ulterius REQUIRED)

    list(APPEND XONO2L_INCLUDE_DIRS
        ${Ulterius_INCLUDE_DIR}
    )

    string(CONCAT FILE_SUFFIX ${FILE_SUFFIX} "-usx")
endif()

# Set build parts
include_directories(${XONO2L_INCLUDE_DIRS})

set(XONO2L_HEADERS
    ${CMAKE_SOURCE_DIR}/include/data_buffer.h
    ${CMAKE_SOURCE_DIR}/include/b_mode_frame.h
    ${CMAKE_SOURCE_DIR}/include/device_config.h
    ${CMAKE_SOURCE_DIR}/include/device_config_daemon.h
    ${CMAKE_SOURCE_DIR}/include/ulterius_singleton.h
    ${CMAKE_SOURCE_DIR}/include/callbacks.h
    ${CMAKE_SOURCE_DIR}/api/xono2l.h
)
set(XONO2L_SOURCES
    ${CMAKE_SOURCE_DIR}/src/data_buffer.cpp
    ${CMAKE_SOURCE_DIR}/src/b_mode_frame.cpp
    ${CMAKE_SOURCE_DIR}/src/device_config.cpp
    ${CMAKE_SOURCE_DIR}/src/device_config_daemon.cpp
    ${CMAKE_SOURCE_DIR}/src/ulterius_singleton.cpp
    ${CMAKE_SOURCE_DIR}/src/callbacks.cpp
    ${CMAKE_SOURCE_DIR}/api/xono2l.cpp
)

# Build DLL
set(LIBRARY_NAME xono2l${FILE_SUFFIX})

add_library(${LIBRARY_NAME} SHARED
    ${XONO2L_SOURCES} ${XONO2L_HEADERS}
)
target_link_libraries(${LIBRARY_NAME}
    ${Ulterius_LIBRARY}
)
