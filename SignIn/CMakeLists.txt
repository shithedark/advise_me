cmake_minimum_required(VERSION 3.16)


add_library(SignIn STATIC)





find_package(Qt6 6.4 REQUIRED COMPONENTS Quick Network)

qt_add_qml_module(SignIn
        URI "SignIn"
        VERSION 1.0
        QML_FILES SignIn.qml ../UIComponents/ColoredTextField.qml
        SOURCES Logic/signinrepository.h Logic/signinrepository.cpp


    )

target_link_libraries(SignIn
    PRIVATE Qt6::Quick Qt6::Network
)
