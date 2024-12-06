import QtQuick

Rectangle{
    id: button
    property string title: "title"
    anchors.centerIn: parent

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
