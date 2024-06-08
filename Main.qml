import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import SignIn
Window {
    id : app
    minimumHeight: 768
    maximumHeight: 768
    minimumWidth: 1024
    maximumWidth:1024
    visible: true
    title: qsTr("Hello World")
    SystemPalette {
        id : systemTheme
        colorGroup: SystemPalette.Active
    }

    SignIn{
        anchors.fill : parent
    }


}
