import QtQuick
import QtQuick.Controls

Rectangle {
    id: shop
    color: "#AAA"
    width: 400
    height: 150
    signal buyingUnitSelected()

    signal readyButtonClicked()

    Row {
        anchors.centerIn: parent
        spacing: 20

        // First clickable image
        Rectangle {
            id: knightRectangle
            property string unitName: "Knight" //which string is passed to gamecontext
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
                    gameContext.selectButyingUnitInShop(knightRectangle.unitName)
                    shop.buyingUnitSelected()
                }
            }
        }

        // Second clickable image
        Rectangle {
            id: priestRectangle
            property string unitName: "Priest"
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
                    gameContext.selectButyingUnitInShop(priestRectangle.unitName)
                    shop.buyingUnitSelected()
                }
            }
        }

        // Third clickable image
        Rectangle {
            id: druidRectangle
            property string unitName: "Druid"
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
                    gameContext.selectButyingUnitInShop(druidRectangle.unitName)
                    shop.buyingUnitSelected()
                }
            }
        }


        // Ready Button
        Button {
            text: "Ready"
            onClicked: {
                gameContext.playerReady()
                shop.readyButtonClicked();
            }
        }


    }
}
