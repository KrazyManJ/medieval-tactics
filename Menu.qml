import QtQuick

Item {
    id: mainMenu
    signal gameCreated()

    Image {
        anchors.centerIn: parent

        opacity: 0.4
        source: "qrc:/assets/menu-background.png"
    }

    Column {
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -50
        spacing: 40
        width: parent.width

        Text {
            text: "Medieval-Tactics"
            font.pixelSize: 82
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Column {
            spacing: 20
            anchors.horizontalCenter: parent.horizontalCenter

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
}
