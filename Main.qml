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
        }
    }

    Map {
        id: map
        anchors {
            // bottom: unitControls.top
            horizontalCenter: parent.horizontalCenter
        }
        width: 600  
        height: 400
        visible: false
        rows: 5
        columns: 5
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
