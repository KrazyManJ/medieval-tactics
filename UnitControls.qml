import QtQuick

Rectangle {
    id: unitControl
    color: "#AAA"
    height: 150

    signal moveButtonClicked()

    function selectUnit(row, column) {
        const foundUnit = gameContext.getUnitByPos(row,column)
        if (!foundUnit) {
            noUnitSelected.visible = true;
            selectedUnit.visible = false;
        }

        noUnitSelected.visible = false;
        selectedUnit.visible = true;
        unitPreview.img = foundUnit.unit.name.toLowerCase();
    }

    Item {
        id: noUnitSelected
        visible: true
        anchors.fill: parent

        Text {
            text: "No unit selected"
            color: "#555"
            anchors.centerIn: parent
            font {
                italic: true
                pixelSize: 40
            }
        }
    }

    Item {
        id: selectedUnit
        visible: false
        anchors.fill: parent

        Image {
            id: unitPreview
            property string img: "druid";
            source: `qrc:/assets/${unitPreview.img}.png`
            width: 100
            height: 100

            anchors {
                left: parent.left
                top: parent.top
                leftMargin: 25
                topMargin: 25
            }
        }

        Row {
            id: btnContainer
            spacing: 10

            Button {
                title: "Move"

                MouseArea {
                    anchors.fill: parent

                    onClicked: unitControls.moveButtonClicked()
                }

            }
            Button {
                title: "Attack"
            }

            anchors {
                right: parent.right
                bottom: parent.bottom
                rightMargin: 10
                bottomMargin: 10
            }
        }

    }
}
