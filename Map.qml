import QtQuick
Item{
    id: map
    property int columns: 5
    property int rows: 5
    width: column * mapObject.width
    Grid{
        id: grid
        columns: map.columns
        rows: map.rows
        spacing: 5

        Repeater{
            id: model
            model: map.rows * map.columns
            MapObject {
                property int row: Math.floor(index / grid.rows)
                property int column: (index % grid.rows)
            }
            
        }
    }
}

