import QtQuick

Rectangle{
    id: mapObject
    property int row: -1
    property int column: -1
    signal unitSelected()
    state: "display"

    function redraw(){
        const foundUnit = gameContext.getUnitByPos(mapObject.row,mapObject.column)
        if(foundUnit != null){
            unit.visible = true;
            unit.color = foundUnit.color;
            unit.img = foundUnit.unit.name.toLowerCase()
        }
        else {
            unit.visible = false;
        }

    }

    color: "green"

    border {
        color: "#000000"
        width: 1

    }

    states: [

        State {
            name: "display"
            PropertyChanges {
                target: mapObject
            }
        },

        State {
            name: "inRange"
            PropertyChanges {
                target: mapObject
                border.color: "red"
            }
        }
    ]

    MouseArea{
        anchors.fill: parent

        onClicked: {
            if(mapObject.state === "inRange" && !unit.visible){
                gameContext.moveUnitOfCurrentPlayer(mapObject.row, mapObject.column)
                mapObject.unitSelected()
            }
        }

    }


    Unit{
        id: unit
        visible: false;

        anchors {
            fill: parent
        }
        MouseArea{
            anchors.fill: parent

            onClicked: {
                if(gameContext.getCurrentPlayerOnTurn().color == unit.color && mapObject.state === "display"){
                    gameContext.selectUnitOfCurrentPlayer(mapObject.row, mapObject.column)
                    mapObject.unitSelected()
                }
            }
        }
    }


}
