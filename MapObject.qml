import QtQuick

Rectangle{
    id: MapObject
    width: 200
    height: 50
    color: "green"
    border.color: "black"
    border.width: 5

    Unit{
        visible: false; 
        anchors{
            fill: parent
        }
    }
    states: [
        State {
            name: "hover"
            border.color: "black"
            border.width: 10
        },
        State {
            name: "pressed"
            border.color: "red"
            border.width: 10          

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