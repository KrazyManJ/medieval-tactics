import QtQuick
Item{
    id: map
    property int columns: 5
    property int rows: 5
    Grid{
    id: grid
    columns: map.columns
    rows: map.rows
    spacing: 5

    Repeater{
        id: Model
        model: map.rows * map.columns
        MapObject {
            property int row: Math.floor(index / g.rows)
            property int column: index
        }
        
    }
    }
}

