import QtQuick
import QtQuick.Shapes
import QtQuick.Layouts
import QtQuick.Controls
import QtQuick.Dialogs
import SignIn 1.0
import "UIComponents"

ColumnLayout {
    id: columnLayout
    width: parent.width * 0.3
    y: -height
    spacing: 20

    SignInRepository {
        id: signInBackend
        onLoading: {
            stack.currentIndex = 1
        }

        onWrongCreds: {
            stack.currentIndex = 0
            app.popUPDialogContainer.openPopUp("Wrong email or password")
        }
        onInvalidData: {
            stack.currentIndex = 0
            app.popUPDialogContainer.openPopUp(
                        "Invalid Data, make sure this is the right format")
        }
    }

    function startAnimation() {
        forumAnimation.start()
    }

    NumberAnimation on y {
        id: forumAnimation
        to: parent.height * 0.25
        duration: 500
        onFinished: {

        }
    }
    Text {
        text: qsTr("Sign In")
        color: systemTheme.highlight
        font.pixelSize: 21
        font.bold: true
    }

    ColoredTextField {
        id: email
        placeholderText: qsTr("Email")
    }
    ColoredTextField {
        id: password
        placeholderText: qsTr("Password")
        inputType: TextInput.Password
    }
    Button {
        Layout.preferredWidth: buttonText.width
        Layout.preferredHeight: buttonText.height
        x: 5
        flat: true
        highlighted: false
        hoverEnabled: false
        background: Rectangle {
            color: systemTheme.light
        }
        Text {
            text: qsTr("Forgot password ? Reset.")
            color: systemTheme.highlight
        }
    }

    StackLayout {
        id: stack
        Layout.maximumWidth: 200
        Layout.preferredHeight: 40
        Layout.alignment: Qt.AlignCenter

        Button {
            id: signInButton

            Text {
                text: qsTr("Sign in")
                color: systemTheme.highlight
                anchors.centerIn: parent
            }
            background: Rectangle {
                color: systemTheme.base
                border.color: systemTheme.highlight
                radius: 2
            }
            onClicked: {
                if (email.inputText === "") {
                    email.state = "UnFilled"
                    popUPDialogContainer.openPopUp("Please fill all the fields")
                } else {
                    email.state = "Filled"
                }

                if (password.inputText === "") {
                    password.state = "UnFilled"
                    popUPDialogContainer.openPopUp("Please fill all the fields")
                } else {
                    password.state = "Filled"
                }
                if (email.inputText != "" && password.inputText != "") {
                    email.state = "Filled"
                    password.state = "Filled"
                    signInBackend.request({}, {
                                              "email": email.inputText,
                                              "password": password.inputText
                                          })
                }
            }
        }

        Item {
            ProgressBar {
                width: parent.width
                height: 10
                indeterminate: true
                anchors.centerIn: parent
            }
        }
    }
}
