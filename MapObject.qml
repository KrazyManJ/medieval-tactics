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
            unit.hp = foundUnit.hp
        }
        else {
            unit.visible = false;
        }
        const type = gameContext.getMapObjectAt(row, column).type;
        const MAP = {
            water: "blue",
            grass: "green",
            sand: "yellow",
            mud: "brown",
            hill: "gray",
            tree: "#55ff55",
        }
        mapObject.color = MAP[type]

    }

    color: "transparent"

    Image {
        source: (() => {
            if (!gameContext)
                    return "qrc:/assets/grass.png";
            const type = gameContext.getMapObjectAt(row, column).type
            return "qrc:/assets/"+ type +".png"
        })()
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
            name: "place"
            PropertyChanges {
                target: mapObject
                border.color: "red"
            }
        },

        State {
            name: "use"
            PropertyChanges {
                target: abilityIndicator
                visible: true
            }
            PropertyChanges {
                target: mapObject
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

            else if(mapObject.state === "place") {
                gameContext.buyUnitForPlayer(row,column)
                mapObject.unitBought()
            }

            else if(mapObject.state === "use"){
                gameContext.useUnitOfCurrentPlayer(mapObject.row, mapObject.column)
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
                else if (mapObject.state === "use") {
                    gameContext.useUnitOfCurrentPlayer(mapObject.row, mapObject.column)

                    mapObject.unitSelected()
                }
            }
        }
    }

    Rectangle {
        id: abilityIndicator
        color: "red"
        opacity: 0.2
        anchors.fill: parent
        visible: false

    }
}
