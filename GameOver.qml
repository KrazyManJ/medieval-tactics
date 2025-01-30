import QtQuick

Rectangle {
    id: gameOver
    property string winnerColor: gameContext.getWinner()

    color: gameOver.winnerColor

    signal menuButtonClicked()

    Column {
        anchors.centerIn: parent
        spacing: 50

        Text {
            text: "Game over"
            font.pixelSize: 80
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            font.pixelSize: 32
            text: gameOver.winnerColor + " wins!"
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            title: "Go to menu"
            onClicked: menuButtonClicked()
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
