import QtQuick

Rectangle {
    id: unitControls
    color: "#AAA"
    height: 150
    focus: true

    signal moveButtonClicked()
    signal useButtonClicked()

    function updateSelectedUnitState() {
        const foundUnit = gameContext.getSelectedUnitOfCurrentPlayer()
        if (!foundUnit){
            noUnitSelected.visible = true;
            selectedUnit.visible = false;
            return;
        }
        noUnitSelected.visible = false;
        selectedUnit.visible = true;
        unitPreview.img = foundUnit.name.toLowerCase();
        unitLabel.text = foundUnit.name;
        hpLabel.text = foundUnit.hp;
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
        Text {
            id: unitLabel
            anchors {
                left: unitPreview.right
                top: unitPreview.top
                leftMargin: 10
            }
            font.pixelSize: 36
        }

        Text {
            id: hpLabel
            anchors {
                left: unitPreview.right
                top: unitLabel.bottom
                leftMargin: 10
                topMargin: 20
            }
        }

        Row {
            id: btnContainer
            spacing: 10

            Button {
                title: "Move"
                onClicked: unitControls.moveButtonClicked()
            }

            Button {
                title: "Attack"
                onClicked: unitControls.useButtonClicked()
            }

            anchors {
                right: parent.right
                bottom: parent.bottom
                rightMargin: 10
                bottomMargin: 10
            }
        }

    }

    Keys.onPressed: (e) => {
        if (e.key === Qt.Key_W && selectedUnit.visible) unitControls.moveButtonClicked()
    }
}
