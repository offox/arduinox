import QtQuick 2.0

Rectangle {
    width: 180
    height: 300

    Component {
        id: registerDelegate

        Rectangle {
            height: register.height + 4
            width: register.width + 4
            color: "green"

            Row {
                id: register
                height: 25
                anchors.centerIn: parent
                Text {
                    id: label
                    width: 40
                    text: name
                }
                Bit {
                    id: b0
                    value: bit0
                }
                Bit {
                    id: b1
                    value: bit1
                }
                Bit {
                    id: b2
                    value: bit2
                }
                Bit {
                    id: b3
                    value: bit3
                }
                Bit {
                    id: b4
                    value: bit4
                }
                Bit {
                    id: b5
                    value: bit5
                }
                Bit {
                    id: b6
                    value: bit6
                }
                Bit {
                    id: b7
                    value: bit7
                }
            }
        }
    }

    ListView {
        id: registerList
        anchors.fill: parent
        delegate: registerDelegate
        model: registerModel
        focus: true
    }
}
