import QtQuick

Window {
    width: 1280
    height: 720
    visible: true
    title: qsTr("Medieval tactics")
    color: "#EEE"
    minimumWidth: 720
    minimumHeight: 480

    Menu {
        id: menu
        anchors.centerIn: parent
        onGameCreated: {
            menu.visible = false
            game.visible = true
        }
    }

    Game {
        anchors.fill: parent

        id: game
        visible: false
    }
}
