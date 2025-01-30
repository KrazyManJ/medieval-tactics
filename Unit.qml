import QtQuick
Rectangle {
    id: unit
    property string color
    property string img: "druid"
    property real hp
    property real maxhp

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
            color: "black"
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

    Rectangle {
        anchors {
            bottom: unit.top
            horizontalCenter: unit.horizontalCenter
            bottomMargin: 5
        }
        width: 40
        height: 10
        color: "red"
        border {
            width: 1
            color: "black"
        }

        Rectangle {
            anchors {
                left: parent.left
                top: parent.top
                bottom: parent.bottom
                margins: 1
            }
            width: unit.hp / unit.maxhp * 40
            color: "green"
        }
    }
}
