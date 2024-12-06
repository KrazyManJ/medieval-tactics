import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Medieval tactics")
    color: "#EEE"

    function changeLayout() {

    }

    Menu {
        anchors.fill: parent
        onGameCreated:{
            console.log("created game")
        }
        onGameQuit: {
            Qt.quit()
        }
    }



    UnitControls {
        visible: false
        anchors {
            left: parent.left
            bottom: parent.bottom
            right: parent.right
        }
    }
}
