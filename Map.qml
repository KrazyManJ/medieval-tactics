import QtQuick
Item{
    id: map
    property int columns: 5
    property int rows: 5
    property int fieldSize: 70
    width: columns * fieldSize + (columns-1) * grid.spacing
    height: rows * fieldSize + (rows-1) * grid.spacing
    Grid{
        id: grid
        columns: map.columns
        rows: map.rows

        Repeater{
            id: model
            model: map.rows * map.columns

            MapObject {

                required property int index
                property int row: Math.floor(index / grid.rows)
                property int column: (index % grid.rows)

                width: map.fieldSize
                height: map.fieldSize
            }
        }
    }
}

