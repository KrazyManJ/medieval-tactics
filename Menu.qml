import QtQuick


Item  {
    id: mainMenu
    signal gameCreated()
    signal gameQuit()

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
                mainMenu.gameQuit()
            }
        }
    }


}
