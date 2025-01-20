import QtQuick

Window {
    id: app
    width: 1280
    height: 720
    title: qsTr("Medieval Tactics")
    minimumWidth: 720
    minimumHeight: 480
    color: "#f6ebd5"


    visibility: Window.FullScreen

    function showGame() {
        game.visible = true;
        menu.visible = false;
    }

    function showMenu() {
        game.visible = false;
        menu.visible = true;
    }

    function createNewGame() {
        gameContext.createNewGame()
        app.showGame()
        game.redraw()
    }


    Menu {
        id: menu
        anchors.fill: parent

        onCreateGameButtonClicked: app.createNewGame()
        onQuitButtonClicked: Qt.quit()
    }

    Game {
        id: game
        anchors.fill: parent
        visible: false

        onQuitButtonClicked: app.showMenu()
    }
}
