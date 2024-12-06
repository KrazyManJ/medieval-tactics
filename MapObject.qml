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

}