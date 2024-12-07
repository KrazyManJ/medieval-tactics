import QtQuick

Window {
    width: 1280
    height: 720
    visible: true
    title: qsTr("Medieval tactics")
    color: "#EEE"

    Menu {
        id: menu
        anchors.centerIn: parent
        onGameCreated: {
            map.visible = true
            unitControls.visible = true
            menu.visible = false
            quitGame.visible = true
        }
    }
    Button {
        id: quitGame
        visible: false
        title: "Quit"
        width: 140
        height: 40
        MouseArea {
            anchors.fill: parent
            onClicked: {
                Qt.quit()
            }
        }
    }

    Item {
        id: mapContainer

        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
            bottom: unitControls.top
        }

        Map {
            id: map

            anchors.centerIn: parent
            visible: false

            property var mapData: gameContext.getMapDetails()

            rows: mapData.height
            columns: mapData.width
        }
    }


    UnitControls {
        id: unitControls
        visible: false
        anchors {
            left: parent.left
            bottom: parent.bottom
            right: parent.right
        }
    }
}
