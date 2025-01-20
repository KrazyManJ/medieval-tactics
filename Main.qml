import QtQuick

Window {
    id: app
    width: 1280
    height: 720
    title: qsTr("Medieval Tactics")
    minimumWidth: 720
    minimumHeight: 480

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

    FontLoader {
        source: "qrc:/assets/fonts/InknutAntiqua-Bold.ttf"
    }
    FontLoader {
        source: "qrc:/assets/fonts/Macondo-Regular.ttf"
    }


    Menu {
        id: menu
        anchors.centerIn: parent

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
