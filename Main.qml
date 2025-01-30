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

    // Automatické přehrání hudby při spuštění aplikace


    function showGame() {
        fadingScene.perform(() => {
            game.visible = true;
            menu.visible = false;
        })
    }

    function showMenu() {
        fadingScene.perform(() => {
            game.visible = false;
            menu.visible = true;
        })
    }

    function createNewGame() {
        gameContext.createNewGame()
        app.showGame()
        game.init()
        game.redraw()
    }

    Menu {
        id: menu
        anchors.fill: parent

        onCreateGameButtonClicked: app.createNewGame()
        onQuitButtonClicked: fadingScene.perform(() => Qt.quit(),1000)
    }

    Game {
        id: game
        anchors.fill: parent
        visible: false

        onQuitButtonClicked: app.showMenu();

        onGameOver: {
            gameOver.visible = true;
            game.visible = false;
        }
    }

    GameOver {
        id: gameOver

        visible: false
        anchors.fill: parent

        onMenuButtonClicked: {
            gameOver.visible = false;
            menu.visible = true;
        }
    }

    Rectangle {
        id: fadingScene
        anchors.fill: parent
        color: "black"
        opacity: 0

        function perform(fct, duration = 200) {
            timer.interval = duration
            fade.duration = duration

            fadingScene.fct = fct
            fadingScene.opacity = 1
            timer.start()
        }

        property var fct;

        Timer {
            id: timer
            interval: fadingScene.duration
            onTriggered: {
                fadingScene.fct()
                fadingScene.opacity = 0
            }
        }

        Behavior on opacity {
            NumberAnimation {
                id: fade
                duration: 200
            }
        }
    }
}
