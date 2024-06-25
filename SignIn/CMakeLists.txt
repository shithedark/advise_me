cmake_minimum_required(VERSION 3.16)


add_library(SignIn STATIC)





find_package(Qt6 6.4 REQUIRED COMPONENTS Quick Network  )
set( cur_path ${CMAKE_CURRENT_SOURCE_DIR} )
cmake_path(GET cur_path PARENT_PATH parent_path)
set( includes ${parent_path}/ )

include_directories( ${includes} )
qt_add_qml_module(SignIn
        URI "SignIn"
        VERSION 1.0
        QML_FILES SignIn.qml ../UIComponents/ColoredTextField.qml
        SOURCES signinrepository.h signinrepository.cpp
        QML_FILES
        QML_FILES
        QML_FILES
        QML_FILES ShapeAndAnimation.qml
        QML_FILES SigninForm.qml
        QML_FILES PopUpDialog.qml
        SOURCES signinrequest.h signinrequest.cpp
    )

target_link_libraries(SignIn
    PRIVATE Qt6::Quick Qt6::Network
)

