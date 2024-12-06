import QtQuick

Rectangle{
    id: MapObject
    property string title: "MapObject"
    width: 200
    height: 50
    color: "green"

    states: [
        State {
            
        },
        State {
            
        }


    ]

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true

        onClicked:
            if (button.state === "pressed"){
                button.state = "hover"
            }
            else {
                button.state = "pressed"
            }

        onEntered:
            if (button.state !== "pressed"){
                button.state = "hover"
            }
        onExited:
            if (button.state !== "pressed"){
                button.state = ""
            }


    }

}