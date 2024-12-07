import QtQuick
Rectangle {
    id: unit
    property color color

    border {
        color: color
        width: 1
    }

    Image{
        anchors.fill: parent
        source: "qrc:/assets/druid.png"
        mipmap: true
        mirror: true
        anchors.margins: 1
    }
}
