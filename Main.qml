import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ColumnLayout{
        anchors.fill: parent
        TextField{
            placeholderText: qsTr("Email")
        }
        TextField{
            placeholderText: qsTr("Email")
        }
        TextField{
            placeholderText: qsTr("Email")
        }
        TextField{
            placeholderText: qsTr("Email")
        }

    }
}
