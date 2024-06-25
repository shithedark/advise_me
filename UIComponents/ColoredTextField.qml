import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ColumnLayout {
    id: root
    required property string placeholderText
    property color mainColor: systemTheme.highlight
    property int inputType: TextInput.Normal
    property string inputText

    state: "Filled"
    onStateChanged: {
        console.log("state changes")
    }

    states: [
        State {
            name: "Filled"
            PropertyChanges {
                target: root
                mainColor: systemTheme.highlight
            }
        },
        State {
            name: "UnFilled"
            PropertyChanges {
                target: root
                mainColor: "red"
            }
        }
    ]
    Text {
        text: placeholderText
        color: mainColor
    }
    TextField {

        Layout.fillWidth: true
        Layout.preferredHeight: 40
        echoMode: inputType
        background: Rectangle {
            color: systemTheme.base
            radius: 5
            border.color: mainColor
        }

        color: mainColor
        onTextChanged: {
            inputText = text
        }
    }
}
