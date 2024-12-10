import QtQuick

// TODO: Make cursor to be point when hovered

Rectangle{
    id: button
    property string title: "title"

    color: "grey"
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
                color: "#696969"
            }
        }
    ]

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true

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
