import QtQuick

Grid{
    id: grid
    columns: 5
    rows: 5
    spacing: 5

    Repeater{
        model: columns * rows
        MapObject {}
    }
}
