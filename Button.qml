import QtQuick

// TODO: Make cursor to be point when hovered

Rectangle{
    id: button
    property string title: "title"

    color: "#666666"
    width: 200
    height: 60

    Text{
        text: button.title
        color: "white"
        font.bold: true
        font.pixelSize: 30
        anchors.centerIn: parent
    }

    states: [

        State {
            name: "pressed"
            PropertyChanges {
                target: button
            }
        },

        State {
            name: "hover"
            PropertyChanges {
                target: button
                color: "#505050"
            }
        }
    ]

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor

        onClicked: {
            button.state = "pressed"
        }

        onEntered: {
            button.state = "hover"
        }

        onExited: {
            button.state = ""
        }

    }
}
