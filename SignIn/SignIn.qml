import QtQuick
import QtQuick.Shapes
import QtQuick.Layouts
import QtQuick.Controls
import SignInRepository
import QtQuick.Dialogs
import "UIComponents"
Rectangle {
    id : base
    width : app.width
    height : app.height
    color: systemTheme.base
    property int samplesNumber: 16

    onWidthChanged: {
        animation.start() //re-apply the animation on width change.

    }

    SignInRepository{
        id : signIN
        onLoading: {
            popupText.text=qsTr("Validating Your Data")
            stack.currentIndex=1
        }

    }

    ColumnLayout{
        id: columnLayout
        width: base.width*0.3
        y : -height
        x: 20
        spacing : 20
        NumberAnimation on y {
            id : forumAnimation
            to :height*0.3;duration: 500
        }
        Text{
            text : qsTr("Sign In")
            color : systemTheme.highlight
            font.pixelSize: 21
            font.bold: true
        }

        ColoredTextField{
            id: email
            placeholderText: qsTr("Email")

        }
        ColoredTextField{
            id: password
            placeholderText: qsTr("Password")
            inputType: TextInput.Password

        }
        Rectangle{
            id : popUPDialogContainer
            Layout.alignment: Qt.AlignCenter

            Popup {
                id: popup
                parent : popUPDialogContainer
                anchors.centerIn: popUPDialogContainer
                modal: true
                focus: true
                closePolicy: Popup.NoAutoClose
                onActiveFocusChanged: {
                    if(activeFocus){
                        popUpTimer.start()
                    }

                }

                contentItem: Text{
                    id : popupText
                    text: qsTr("Incorrect Email or Password")
                    color : systemTheme.highlight
                }
                enter: Transition {
                       NumberAnimation { property: "opacity"; from: 0.0; to: 1.0 }
                   }
                exit: Transition {
                        NumberAnimation { property: "opacity"; from: 1.0; to: 0.0 }
                    }
                Timer {
                        id : popUpTimer
                        interval: 2000
                        onTriggered: popup.close()
                    }
                }



        }



        StackLayout{
            id : stack
            Layout.maximumWidth: 200
            Layout.preferredHeight: 40
            Layout.alignment: Qt.AlignCenter

            Button{
                id : signInButton

                Text{
                    text : qsTr("Sign in")
                    color: systemTheme.highlight
                    anchors.centerIn: parent
                }
                background: Rectangle{
                    color : systemTheme.base
                    border.color: systemTheme.highlight
                    radius: 2
                }
                onClicked: {
                    popup.open()

                    signIN.request({}, {"email":email.inputText, "password" : password.inputText})
                }
            }


        Item{
                ProgressBar{
                        width: parent.width
                        height : 10
                        indeterminate : true
                        anchors.centerIn: parent
                    }

            }







        }





    }


    Button {
        anchors.bottom: parent.bottom
        anchors.margins: 5
        width : buttonText.width
        height : buttonText.height
        x : 5
        flat : true
        highlighted: false
        hoverEnabled: false
        background:  Rectangle{
            color : systemTheme.base
        }
        Text {
            id : buttonText
            anchors.centerIn: parent
            text : qsTr("Don't have an account ? Sing Up")
            color : systemTheme.highlight
        }


    }




    Shape {
        id: shape
        width:  0
        height: parent.height
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        layer.enabled: true
        layer.samples: samplesNumber

        NumberAnimation on width {
            id : animation
            from:0;to :base.width/2;duration: 500
        }

        ShapePath {
            fillColor: systemTheme.highlight
            strokeWidth: 0
            strokeColor: systemTheme.highlight

            startX: shape.width / 2
            startY: 0
            PathCurve {
                x:  0
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
        ColumnLayout{
            anchors.centerIn: shape
            width : shape.width
            id : textColumn
            Text{
                text : qsTr("Advise Me")
                font.bold: true
                font.pixelSize: 21
                Layout.alignment: Qt.AlignCenter
            }
            ToolSeparator {
            orientation: Qt.Horizontal
            Layout.alignment: Qt.AlignCenter
            Layout.preferredWidth: parent.width*0.7

            }

            Text{
                text : qsTr("All Advise You Need")
                font.pixelSize: 16
                Layout.alignment: Qt.AlignCenter

            }
            Text{
                text : qsTr("In One Place")
                font.pixelSize: 16
                Layout.alignment: Qt.AlignCenter

            }
        }

    }



}
