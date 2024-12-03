import QtQuick

Rectangle {
    id: unitControl
    color: "#AAA"
    height: 150

    Item {
        id: noUnitSelected

        anchors.fill: parent

        Text {
            text: "No unit selected"
            color: "#555"
            anchors.centerIn: parent
            font {
                italic: true
                pixelSize: 20
            }
        }
    }
}
