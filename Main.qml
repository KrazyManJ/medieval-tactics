import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Medieval tactics")
    color: "#EEE"

    UnitControls {
        visible: false
        anchors {
            left: parent.left
            bottom: parent.bottom
            right: parent.right
        }
    }
}
