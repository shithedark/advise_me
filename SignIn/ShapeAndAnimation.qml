import QtQuick
import QtQuick.Shapes
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Dialogs
import SignIn 1.0
import "UIComponents"

Shape {
    id: shape
    function startAnimation() {
        animation.start()
    }

    signal animationDone

    NumberAnimation {
        id: animation
        targets: [shape]
        properties: "width"
        duration: 200
        from: 0
        to: parent.width / 2
        onFinished: {
            animationDone()
        }
    }

    ShapePath {
        fillColor: systemTheme.highlight
        strokeWidth: 0
        strokeColor: systemTheme.highlight

        startX: shape.width / 2
        startY: 0
        PathCurve {
            x: 0
            y: shape.height * 0.5
        }
        PathCurve {
            x: shape.width / 2
            y: shape.height
        }
        PathLine {
            x: shape.width
            y: shape.height
        }
        PathLine {
            x: shape.width
        }
    }
    ColumnLayout {
        anchors.centerIn: shape
        width: shape.width
        id: textColumn
        Text {
            text: qsTr("Advise Me")
            color: systemTheme.light
            font.bold: true
            font.pixelSize: 21
            Layout.alignment: Qt.AlignCenter
        }
        ToolSeparator {
            orientation: Qt.Horizontal
            Layout.alignment: Qt.AlignCenter
            Layout.preferredWidth: parent.width * 0.7
        }

        Text {
            text: qsTr("All Advise You Need")
            color: systemTheme.light

            font.pixelSize: 16
            Layout.alignment: Qt.AlignCenter
        }
        Text {
            text: qsTr("In One Place")
            color: systemTheme.light

            font.pixelSize: 16
            Layout.alignment: Qt.AlignCenter
        }
    }
}
