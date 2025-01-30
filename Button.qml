import QtQuick

Rectangle{
    id: button
    property string title: "title"
    property int fontSize: 30
    width: label.width + 20 * 2
    height: label.height + 10 * 2
    color: "#AA5500"
    state: "normal"
    radius: 4

    signal clicked()

    Text{
        id: label
        text: button.title
        color: "white"
        font.bold: true
        font.pixelSize: button.fontSize
        anchors.centerIn: parent
    }

    states: [
        State {
            name: "normal"
            PropertyChanges {
                target: button
                color: "#AA5500"
            }
        },

        State {
            name: "pressed"
            PropertyChanges {
                target: button
                color: "#883300"
            }
        },

        State {
            name: "hover"
            PropertyChanges {
                target: button
                color: "#CC5500"
            }
        }
    ]

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor

        onClicked: {
            button.state = "pressed"
            button.clicked()
            resetTimer.start()
        }

        onEntered: {
            button.state = "hover"
        }

        onExited: {
            button.state = "normal"
        }
    }

    Timer {
        id: resetTimer
        interval: 100  // Doba, po které se tlačítko vrátí do normálu (ms)
        onTriggered: button.state = "normal"
    }

    transitions: [
        Transition {
            from: "hover"
            to: "normal"
            ColorAnimation { target: button; duration: 100}
        },
        Transition {
            from: "normal"
            to: "hover"
            ColorAnimation { target: button; duration: 100}
        },
        Transition {
            from: "pressed"
            to: "normal"
            ColorAnimation { target: button; duration: 100 }
        }
    ]
}
