import QtQuick


Item  {
    id: mainMenu
    signal gameCreated()

Column {
    anchors.centerIn: parent
    spacing: 20
    Button {
        title: "Start game"
        MouseArea {
            anchors.fill: parent
            onClicked: {
                gameContext.createNewGame()
                mainMenu.gameCreated()
            }
        }
    }

    Button {
        title: "Quit"
        MouseArea {
            anchors.fill: parent
            onClicked: {
                Qt.quit()
            }
        }
    }
}



}
