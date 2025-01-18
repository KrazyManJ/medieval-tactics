import QtQuick

Item {
    id: game
    signal quitButtonClicked()

    function redraw() {
        map.redraw()
        currentPlayer.updateText()
        remainingTurns.updateText()
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

        function updateText() {
            const color = gameContext.getCurrentPlayerOnTurn().color;
            currentPlayer.color = color;
            currentPlayer.text = color;
        }

        property string playerColor: gameContext.getCurrentPlayerOnTurn().color
        text: currentPlayer.playerColor;
        color: currentPlayer.playerColor;
        anchors {
            top: parent.top
            right: parent.right
            rightMargin: 10
        }
        font.pixelSize: 30
    }

    Text {
        id: currentPlayerLabel
        text: `On turn: `
        anchors {
            top: parent.top
            right: currentPlayer.left
        }
        font.pixelSize: 30
    }

    Text {
        id: remainingTurns

        function updateText() {
            remainingTurns.text = `Remaining turns: ${gameContext.getRemainingTurns()}`
        }

        anchors {
            right: parent.right
            top: currentPlayerLabel.bottom
            rightMargin: 10
        }
        font.pixelSize: 15
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

            onUnitSelected: {
                unitControls.selectUnit()
                map.state = "display"
                game.redraw()
            }
        }
    }

    UnitControls {
        id: unitControls
        visible: false
        anchors {
            left: parent.left
            bottom: parent.bottom
            right: parent.right
        }

        onMoveButtonClicked: {
            map.state = map.state == "display" ? "move" : "display"
            game.redraw()
        }
    }

    Shop {
        id: shop
        visible: true
        anchors {
            left: parent.left
            bottom: parent.bottom
            right: parent.right
        }
        onBuyingUnitSelected: {

        }
    }


}
