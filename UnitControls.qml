import QtQuick

Rectangle {
    id: unitControl
    color: "#AAA"
    height: 150

    signal moveButtonClicked()

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

    Item {
        anchors.fill: parent

        Image {
            source: "qrc:/assets/druid.png"
            width: 100
            height: 100

            anchors {
                left: parent.left
                top: parent.top
                leftMargin: 25
                topMargin: 25
            }
        }

        Row {
            id: btnContainer
            spacing: 10

            Button {
                title: "Move"
                onClicked: unitControls.moveButtonClicked()
            }
            Button {
                title: "Attack"
            }

            anchors {
                right: parent.right
                bottom: parent.bottom
                rightMargin: 10
                bottomMargin: 10
            }
        }

    }
}
