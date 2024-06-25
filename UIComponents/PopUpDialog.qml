import QtQuick
import QtQuick.Shapes
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Dialogs
import SignIn 1.0

Item {
    property string popUpText
    height: popup.height

    function openPopUp(text) {
        popUpText = text
        popup.open()
    }

    Popup {
        id: popup
        background: Rectangle {
            color: systemTheme.light
        }

        width: parent.width
        focus: true
        closePolicy: Popup.NoAutoClose
        onActiveFocusChanged: {
            if (activeFocus) {
                popUpTimer.start()
            }
        }

        contentItem: Text {
            id: textElement
            horizontalAlignment: Text.AlignHCenter
            text: popUpText
            color: systemTheme.highlight
        }
        enter: Transition {
            NumberAnimation {
                property: "opacity"
                from: 0.0
                to: 1.0
            }
        }
        exit: Transition {
            NumberAnimation {
                property: "opacity"
                from: 1.0
                to: 0.0
            }
        }
        Timer {
            id: popUpTimer
            interval: 2000
            onTriggered: popup.close()
        }
    }
}
