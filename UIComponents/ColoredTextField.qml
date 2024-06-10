import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ColumnLayout {
    required property string placeholderText
    property color mainColor : systemTheme.highlight
    property int inputType: TextInput.Normal
    property string  inputText
    Text{
        text: placeholderText
        color : mainColor
    }
    TextField{
        Layout.fillWidth: true
        Layout.preferredHeight: 40
        echoMode : inputType
        background: Rectangle{
            color : systemTheme.base
            radius: 5
            border.color : systemTheme.highlight
        }

        color : mainColor
        onTextChanged: {
            inputText = text
        }
    }
}
