import QtQuick
import QtQuick.Controls as QC

Rectangle {
    id: shop
    color: "#AAA"
    width: 400
    height: 200
    signal buyingUnitSelected()
    signal readyButtonClicked()

    function redraw() {
        const unit = gameContext.getShopDetails().unit;
        for (let i = 0; i < shopItems.children.length; i++) {
            let child = shopItems.children[i]
            if (!child.unitName) continue;
            console.log(child.unitName, child)
            if (child.unitName === unit)
                child.children[0].color = "#f00"
            else
                child.children[0].color = "#000"

        }
    }


    Row {
        id: shopItems
        anchors.centerIn: parent
        spacing: 20

        Repeater {

            model: gameContext.getShopDetails().availableUnits

            Column {
                property string unitName: modelData.name
                spacing: 5
                Rectangle {
                    id: unit
                    width: 100
                    height: 100
                    color: "#000"

                    Image {
                        anchors {
                            fill: parent
                            margins: 4
                        }
                        source: `qrc:/assets/${modelData.name.toLowerCase()}.png`

                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            console.log(gameContext.getShopDetails().unit,modelData.name)
                            if (gameContext.getShopDetails().unit === modelData.name) {
                                gameContext.deselectShopUnit();
                            }
                            else {
                                gameContext.selectButyingUnitInShop(modelData.name)
                            }
                            shop.buyingUnitSelected()
                            shop.redraw()
                        }
                    }

                }
                Text {
                    text: modelData.cost
                    anchors.horizontalCenter: parent.horizontalCenter
                    color: "#000"
                }
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
    }
}
