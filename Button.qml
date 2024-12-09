import QtQuick

// TODO: Make button hover effect (change color when hovered instead of pressed
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
                color: "#A9A9A9"
            }
        }

    ]

    MouseArea {
        anchors.fill: parent

        onClicked:
            button.state = "pressed"

    }



}
