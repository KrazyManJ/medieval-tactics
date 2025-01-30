import QtQuick

Rectangle {
    id: shop
    color: "#AAA"
    width: 400
    height: 200
    signal buyingUnitSelected()
    signal readyButtonClicked()


    function redraw() {
        const unit = gameContext.getShopDetails().unit;
        [knightRectangle,priestRectangle,druidRectangle].forEach((shopItem) => {
            if (shopItem === unit)
                shopItem.border.color = "#f00"
            else
                shopItem.border.color = "#000"
        })
    }

    Row {
        anchors.centerIn: parent
        spacing: 20

        // First clickable image with label
        Column {
            spacing: 5
            Rectangle {
                id: knightRectangle
                property string unitName: "Knight"
                width: 100
                height: 100
                color: "#FFF"
                border.color: "#000"
                border.width: 2

                Image {
                    anchors.fill: parent
                    source: `qrc:/assets/warrior.png`
                    fillMode: Image.PreserveAspectFit
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        gameContext.selectButyingUnitInShop(knightRectangle.unitName)
                        shop.buyingUnitSelected()
                        redraw()
                    }
                }
            }
            Text {
                text: "100"
                anchors.horizontalCenter: parent.horizontalCenter
                color: "#000"
            }
        }

        // Second clickable image with label
        Column {
            spacing: 5
            Rectangle {
                id: priestRectangle
                property string unitName: "Priest"
                width: 100
                height: 100
                color: "#FFF"
                border.color: "#000"
                border.width: 2

                Image {
                    anchors.fill: parent
                    source: `qrc:/assets/priest.png`
                    fillMode: Image.PreserveAspectFit
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        gameContext.selectButyingUnitInShop(priestRectangle.unitName)
                        shop.buyingUnitSelected()
                        redraw()
                    }
                }
            }
            Text {
                text: "200"
                anchors.horizontalCenter: parent.horizontalCenter
                color: "#000"
            }
        }

        // Third clickable image with label
        Column {
            spacing: 5
            Rectangle {
                id: druidRectangle
                property string unitName: "Druid"
                width: 100
                height: 100
                color: "#FFF"
                border.color: "#000"
                border.width: 2

                Image {
                    anchors.fill: parent
                    source: `qrc:/assets/druid.png`
                    fillMode: Image.PreserveAspectFit
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        gameContext.selectButyingUnitInShop(druidRectangle.unitName)
                        shop.buyingUnitSelected()
                        redraw()
                    }
                }
            }
            Text {
                text: "500"
                anchors.horizontalCenter: parent.horizontalCenter
                color: "#000"
            }
        }

        // Ready Button
        Button {
            title: "Ready"
            onClicked: {
                gameContext.playerReady()
                shop.readyButtonClicked()
            }
        }

        Button {
            title: "Deselect"
            onClicked: {
                gameContext.deselect()
            }
        }
    }
}
