import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ColumnLayout {
    required property string placeholderText
    property color mainColor : systemTheme.highlight
    Text{
        text: placeholderText
        color : mainColor
    }
    TextField{
        Layout.fillWidth: true
        Layout.preferredHeight: 40

        background: Rectangle{
            color : systemTheme.base
            radius: 5
            border.color : systemTheme.highlight
        }

        color : mainColor
    }
}
