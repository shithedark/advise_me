cmake_minimum_required(VERSION 3.16)

add_library(PlatformStorage STATIC)


qt_add_qml_module(PlatformStorage
    URI PlatformStorage
    VERSION 1.0
    RESOURCES
    SOURCES ../androidsecurestorage.h androidsecurestorage.cpp
)
target_link_libraries(PlatformStorage
    PRIVATE Qt6::Quick Qt6::Network
)
