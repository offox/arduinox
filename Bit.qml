import QtQuick 2.0

Rectangle {
    property int value;

    width: 25
    height: 25
    color: ListView.isCurrentItem ? "black" : "red"
    Rectangle {
        width: parent.width - 4
        height: parent.height - 4
        anchors.centerIn: parent
        Text {
            text: value.toString()
            anchors.centerIn: parent
        }
    }
}
