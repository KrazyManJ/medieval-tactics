import QtQuick
Item{
    id: map

    property var mapData: (() => {
        if (!gameContext) return {width: 0, height: 0};
                               return gameContext.getMapDetails()
    })()

    property int columns: mapData.width
    property int rows: mapData.height
    property int fieldSize: 50
    width: columns * fieldSize + (columns-1) * grid.spacing
    height: rows * fieldSize + (rows-1) * grid.spacing

    state: "display"

    signal unitSelected()
    signal unitBought()

    function enterPlacementMode() {

        for (let i = 0; i < grid.children.length; i++) {
            let child = grid.children[i];

            if (!child.redraw) {
                continue;
            }

            //console.log("Child at row:", child.row, "column:", child.column, "unit visible:", child.unit.visible);
            if(gameContext.getCurrentPlayerOnTurn().color === "orange") {
                if(child.column < columns/2) {
                    if (!child.unit.visible && gameContext.getMapObjectAt(child.row, child.column).type === "grass") {
                        child.state = "Place";
                    } else if (child.unit.visible) {
                        child.state = "display";
                    }

                    child.redraw();
                }
            } else {
                if(child.column > columns/2) {
                    if (!child.unit.visible && gameContext.getMapObjectAt(child.row, child.column).type === "grass") {
                        child.state = "Place";
                    } else if (child.unit.visible) {
                        child.state = "display";
                    }

                    child.redraw();
                }
            }


        }
    }



    function redraw(){
        for (let i = 0; i < grid.children.length; i++) {
            let child = grid.children[i];

            if(!child.redraw)
                continue

            if(map.state == "display"){
                child.state = "display"
                child.redraw();
            }else if(map.state == "move"){
                if(gameContext.canUnitOfCurrentPlayerWalkToDest(child.row, child.column)){
                    child.state = "inRange"
                }
                else{
                    child.state = "display"
                }
                child.redraw();
            }

        }
    }

    Grid{
        id: grid
        columns: map.columns
        rows: map.rows

        Repeater{
            id: model
            model: map.rows * map.columns

            MapObject {
                onUnitSelected:{
                    map.unitSelected()
                }

                onUnitBought: {
                    map.state = "display"
                    map.redraw()
                }
                required property int index
                row: Math.floor(index / grid.columns)
                column: (index % grid.columns)

                width: map.fieldSize
                height: map.fieldSize
            }
        }
    }
}

