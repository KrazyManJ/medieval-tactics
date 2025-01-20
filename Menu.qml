import QtQuick

Item {
    id: mainMenu
    signal createGameButtonClicked()
    signal quitButtonClicked()

    // color: "#f6ebd5"

    Text {
        text: "Copyright 2024-2025 © Created by Jaroslav Korčák, Daniel Němec & Miloslav Švábenský"
        anchors {
            bottom: parent.bottom
            right: parent.right
            bottomMargin: 10
            rightMargin: 10
        }
        font.pointSize: 12
    }

    Text {
        text: "Version 0.1.0"
        anchors {
            bottom: parent.bottom
            left: parent.left
            bottomMargin: 10
            leftMargin: 10
        }
        font.pointSize: 16
    }

    Column {
        anchors.centerIn: parent
        anchors.verticalCenterOffset: -50
        spacing: 50
        width: parent.width

        Column {
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: -40

            Image {
                height: 450

                source: "qrc:/assets/icon.png"
                fillMode: Image.PreserveAspectFit
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                text: "Medieval-Tactics"
                font.pixelSize: 82
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }


        Column {
            spacing: 20
            anchors.horizontalCenter: parent.horizontalCenter

            Button {
                title: "Start game"
                anchors.horizontalCenter: parent.horizontalCenter

                MouseArea {
                    anchors.fill: parent
                    onClicked: mainMenu.createGameButtonClicked()
                }
            }

            Button {
                title: "Quit"
                anchors.horizontalCenter: parent.horizontalCenter

                MouseArea {
                    anchors.fill: parent
                    onClicked: mainMenu.quitButtonClicked()
                }
            }
        }
    }
}
