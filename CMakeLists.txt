cmake_minimum_required(VERSION 3.16)

project(base VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick Network)

qt_standard_project_setup()

qt_add_executable(appbase
    main.cpp
)

add_subdirectory(android_cpp/)
add_subdirectory(SignIn/)


qt_add_qml_module(appbase
        URI base
        VERSION 1.0
        QML_FILES
        Main.qml UIComponents/ColoredTextField.qml
        RESOURCES android/src/org/qtproject/example/TestClass.java
        RESOURCES android/src/org/qtproject/example/SecureStorage.java
        SOURCES securestorage.h securestorage.cpp
        SOURCES securestoragefactory.h securestoragefactory.cpp
        SOURCES networkmanageraccessor.h networkmanageraccessor.cpp
        SOURCES androidsecurestorage.h
        SOURCES
        SOURCES
        SOURCES SignIn/Logic/signinrepository.h SignIn/Logic/signinrepository.cpp
        QML_FILES
        SOURCES
        SOURCES webrequest.h webrequest.cpp
    )



# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appbase PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appbase
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

set_property(TARGET appbase APPEND PROPERTY
    QT_ANDROID_PACKAGE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/android
)

target_link_libraries(appbase
    PRIVATE Qt6::Quick Qt6::Network PlatformStorageplugin SignInplugin
)

include(GNUInstallDirs)
install(TARGETS appbase
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
