import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 1280
    height: 720
    visible: true
    title: qsTr("Hello World")

    Text {
        id: name
        text: qsTr("Hello Word")
        font.family: "Helvetica"
        font.pointSize: 24
        color: "red"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
}


