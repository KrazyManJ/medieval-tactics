import QtQuick
import QtQuick.Controls

Rectangle {
    id: shop
    color: "#AAA"
    width: 400
    height: 150

    signal readyButtonClicked()

    Row {
        anchors.centerIn: parent
        spacing: 20

        // First clickable image
        Rectangle {
            width: 100
            height: 100
            color: "#FFF"
            border.color: "#000"
            radius: 5

            Image {
                anchors.fill: parent
                source: `qrc:/assets/warrior.png`
                fillMode: Image.PreserveAspectFit
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("Image 1 clicked!")
                }
            }
        }

        // Second clickable image
        Rectangle {
            width: 100
            height: 100
            color: "#FFF"
            border.color: "#000"
            radius: 5

            Image {
                anchors.fill: parent
                source: `qrc:/assets/priest.png`
                fillMode: Image.PreserveAspectFit
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("Image 2 clicked!")
                }
            }
        }

        // Third clickable image
        Rectangle {
            width: 100
            height: 100
            color: "#FFF"
            border.color: "#000"
            radius: 5

            Image {
                anchors.fill: parent
                source: `qrc:/assets/druid.png`
                fillMode: Image.PreserveAspectFit
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("Image 3 clicked!")
                }
            }
        }


        // Ready Button
        Button {
            text: "Ready"
            onClicked: {
                shop.readyButtonClicked(); // Emit the signal
                console.log("Ready button clicked in Shop!");
            }
        }


    }
}
