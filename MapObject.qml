import QtQuick

Rectangle{
    id: mapObject
    property int row: 0
    property int column: 0

    color: "green"

    border {
        color: "#000000"
        width: 1

    }

    Unit{
        visible: true;
        color: "orange"

        anchors {
            fill: parent
        }
    }

}
