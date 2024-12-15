import QtQuick

Item {
    id: game
    signal quitButtonClicked()

    function init() {
        map.redraw()
    }

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

    Text {
        id: currentPlayer
        property string playerColor: gameContext.getCurrentPlayerOnTurn().color
        text: currentPlayer.playerColor;
        color: currentPlayer.playerColor;
        anchors {
            top: parent.top
            right: parent.right
        }
        font.pixelSize: 20
    }

    Text {
        id: currentPlayerLabel
        text: `On turn: `
        anchors {
            top: parent.top
            right: currentPlayer.left
        }
        font.pixelSize: 20
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

            onUnitSelected: {
                unitControls.selectUnit()
                //map.redraw()
            }
        }
    }

    UnitControls {
        id: unitControls
        anchors {
            left: parent.left
            bottom: parent.bottom
            right: parent.right
        }

        onMoveButtonClicked: {
            map.state = "move"
            map.redraw()
        }
    }
}
