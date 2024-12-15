import QtQuick
Item{
    id: map
    property int columns: 5
    property int rows: 5
    property int fieldSize: 70
    width: columns * fieldSize + (columns-1) * grid.spacing
    height: rows * fieldSize + (rows-1) * grid.spacing
    state: "display"

    signal unitSelected()


    function redraw(){
        for (let i = 0; i < grid.children.length; i++) {
            let child = grid.children[i];

            if(!child.redraw)
                continue

            if(map.state == "display"){
                child.state = "display"
                child.redraw();
            }else if(map.state == "move"){
                if(gameContext.isUnitOfCurrentPlayerInWalkingRange(child.row, child.column)){
                    child.state = "inRange"
                }
                else{
                    child.state = "move"
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
                required property int index
                row: Math.floor(index / grid.rows)
                column: (index % grid.rows)

                width: map.fieldSize
                height: map.fieldSize
            }
        }
    }
}

