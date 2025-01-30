import QtQuick
Rectangle {
    id: unit
    property string color
    property string img: "druid"

    border {
        color: color
        width: 1
    }

    Image{
        anchors.fill: parent
        source: "qrc:/assets/"+ unit.img +".png"
        mipmap: true
        mirror: true
        anchors.margins: 1
    }

    Rectangle {
        visible: false
        border {
            color: black
            width: 2
        }

        width: 60
        height: 10
        anchors {
            bottom: unit.top
            bottomMargin: 1
            horizontalCenter: unit.horizontalCenter
        }
        color: "red"
    }
}
