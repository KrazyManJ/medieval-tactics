import QtQuick

Item {
    id: game
    signal quitButtonClicked()
    signal gameOver()

    function showShop() {
        shop.visible = true;
        unitControls.visible = false;
        unitControls.focus = false;
        moneyDisplay.visible = true;
        remainingTurns.visible = false;
    }
    function showUnitControls() {
        unitControls.visible = true;
        shop.visible = false;
        unitControls.focus = true;
        moneyDisplay.visible = false;
        remainingTurns.visible = true;
    }

    function redraw() {
        unitControls.updateSelectedUnitState()
        map.redraw()
        currentPlayer.updateText()
        remainingTurns.updateText()
        moneyDisplay.updateMoney()
        if (!gameContext) return;
        if (gameContext.isGameOver()) {
            game.gameOver()
            return;
        }
        if (gameContext.isShopReady())
            showUnitControls()
        else
            showShop()
        unitControls.state = map.state
    }

    function init() {
        map.state = "display"
    }

    Button {
        title: "Quit"
        width: 140
        height: 40
        onClicked: game.quitButtonClicked()
        anchors {
            left: parent.left
            top: parent.top
            margins: 2
        }
    }

    Text {
        id: currentPlayer

        function updateText() {
            const color = gameContext.getCurrentPlayerOnTurn().color;
            currentPlayer.color = color;
            currentPlayer.text = color;
        }

        property string playerColor: (() => {
            if (!gameContext) return null;
            return gameContext.getCurrentPlayerOnTurn().color
        })()

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
            if(gameContext.isShopReady()) {
                remainingTurns.text = `Remaining turns: ${gameContext.getRemainingTurns()}`
            }

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
                unitControls.updateSelectedUnitState()
                map.state = "display"
                game.redraw()
            }

            onUnitBought: {
                map.state = "display"
                gameContext.deselectShopUnit()
                shop.redraw()
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
            map.state = map.state === "move" ? "display" : "move"
            game.redraw()
        }

        onUseButtonClicked: {
            map.state = map.state === "use" ? "display" : "use"
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
            map.state = gameContext.getShopDetails().unit !== "" ? "place" : "display"
            shop.redraw()
            map.enterPlacementMode();
        }

        onReadyButtonClicked: {
            map.state = "display"
            game.redraw()
        }
    }

    Text {
        id: moneyDisplay
        function updateMoney() {
            const money = gameContext.getPlayerMoney();
            moneyDisplay.text = "Money: " + money;
        }

        text: "Money: " + gameContext.getPlayerMoney()
        anchors.top: currentPlayerLabel.bottom
        anchors.right: parent.right
        anchors.margins: 10
        anchors.topMargin: -4
        color: "#000"
        font.pixelSize: 18
    }
}
