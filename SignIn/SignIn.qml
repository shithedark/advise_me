import QtQuick
import QtQuick.Shapes
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Dialogs
import SignIn 1.0
import "UIComponents"

Rectangle {
    id: base
    width: app.width
    height: app.height
    color: systemTheme.light
    property int samplesNumber: 16
    onWidthChanged: {
        shape.startAnimation() //re-apply the animation on width change.
    }

    SigninForm {
        id: signinForm
        x: 20
    }

    Button {
        anchors.bottom: parent.bottom
        anchors.margins: 5
        width: buttonText.width
        height: buttonText.height
        x: 5
        flat: true
        highlighted: false
        hoverEnabled: false
        background: Rectangle {
            color: systemTheme.light
        }
        Text {
            id: buttonText
            anchors.centerIn: parent
            text: qsTr("Don't have an account ? Sing Up")
            color: systemTheme.highlight
        }
    }

    ShapeAndAnimation {
        id: shape
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        height: parent.height
        layer.enabled: true
        layer.samples: samplesNumber
        onAnimationDone: signinForm.startAnimation()
    }
}
