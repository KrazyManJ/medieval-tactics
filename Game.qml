import QtQuick

Item {
    id: game
    signal quitButtonClicked()

    Button {
        id: quitGame
        title: "Quit"
        width: 140
        height: 40

        MouseArea {
            anchors.fill: parent
            onClicked: game.quitButtonClicked()
        }
    }

    Item {
        id: mapContainer

        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
            bottom: unitControls.top
        }

        Map {
            id: map

            anchors.centerIn: parent

            property var mapData: gameContext.getMapDetails()

            rows: mapData.height
            columns: mapData.width
        }
    }

    UnitControls {
        id: unitControls
        anchors {
            left: parent.left
            bottom: parent.bottom
            right: parent.right
        }
    }
}
