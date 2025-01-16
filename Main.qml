import QtQuick

Window {
    width: 1280
    height: 720
    visible: true
    title: qsTr("Medieval Tactics")
    color: "#EEE"
    minimumWidth: 720
    minimumHeight: 480

    visibility: Window.FullScreen

    Menu {
        id: menu
        anchors.centerIn: parent

        onGameCreated: {
            menu.visible = false
            game.visible = true
            game.redraw()
        }
    }

    Game {
        id: game
        anchors.fill: parent
        visible: false

        onQuitButtonClicked: {
            menu.visible = true
            game.visible = false
        }
    }
}
