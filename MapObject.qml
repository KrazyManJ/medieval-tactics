import QtQuick

Rectangle{
    id: mapObject
    property int row: 0
    property int column: 0

    function init(){
        const foundUnit = gameContext.getUnitByPos(mapObject.row,mapObject.column)
        if(foundUnit != null){
            unit.visible = true;
            unit.color = foundUnit.color;
            unit.img = foundUnit.unit.name.toLowerCase()
        }
    }

    color: "green"

    border {
        color: "#000000"
        width: 1

    }

    Unit{
        id: unit
        visible: false;

        anchors {
            fill: parent
        }
    }

}
