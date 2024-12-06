import QtQuick

Rectangle{
    id: mapObject
    width: 50
    height: 50
    property int row: 0
    property int column: 0
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