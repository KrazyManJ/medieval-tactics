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
}
