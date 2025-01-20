import QtQuick

Rectangle{
    id: mapObject
    property alias unit: unit
    property int row: -1
    property int column: -1
    signal unitSelected()
    signal unitBought()
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

    color: (()=> {
        const type = gameContext.getMapObjectAt(row, column).type;
        const MAP = {
            water: "blue",
            grass: "green",
            sand: "yellow",
            mud: "brown",
            hill: "gray",
        }
        return MAP[type];
    })()

    Image {
        source: "qrc:/assets/"+ gameContext.getMapObjectAt(row, column).type +".png"
        anchors.fill: parent
        anchors.margins: 1
    }

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
        },

        State {
            name: "Place"
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

            if(mabObject.state === "Place") {
                gameContext.buyUnitForPlayer(row,column)
                mapObject.unitBought()
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
