import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import fHours 1.0

Window {
    width: 1280
    height: 720
    visible: true
    title: qsTr("Restaurant Hours")
    color: '#ACE9E8'

    FilterHours {
        id: aHours
    }

    Item {
        id: rowl
        width: parent.width
        height: textinput.height + 20

        Text {
            id: digite
            text: "Digite o horário desejado:"
            anchors {
                right: textinput.left
                verticalCenter: textinput.verticalCenter
                rightMargin: 10
            }
            font.family: "Helvetica"
            font.pointSize: 20
        }

        TextField {
            id: textinput
            anchors {
                top: parent.top
                horizontalCenter: parent.horizontalCenter
                topMargin: 30
            }
            width: 120
            height: 50
            placeholderText: "HH:MM"
            font.family: "Helvetica"
            font.pointSize: 20
            validator: RegularExpressionValidator { regularExpression: /^(0[1-9]|1[0-9]|2[0-4]):[0-5][0-9]$/ }
            background: Rectangle {
                width: textinput.width
                height: textinput.height
                color: '#eafcfc'
                border.color: '#2E6968'
                border.width: 1
                radius: 10
            }
        }

        Button {
            id: but
            width: 200
            height: 50
            onClicked: aHours.setAvailableHours(textinput.text);//'../restaurant_hours/restaurant_hours.csv', textinput.text);
            anchors{
                left: textinput.right
                verticalCenter: textinput.verticalCenter
                leftMargin: 25
            }
            contentItem: Text {
                    text: "Filter"
                    font.pointSize: 12
                    color: "white"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }
            background: Rectangle {
                width: but.width
                height: but.height
                color: '#86B5B4'
                radius: 10
                border.color: '#2E6968'
                border.width: 2
            }
        }

    }

    Rectangle {
        width: 900
        height: 500
        color: '#eafcfc'
        border.color: '#2E6968'
        border.width: 1
        radius: 10
        anchors {
            bottom: parent.bottom
            horizontalCenter: rowl.horizontalCenter
            bottomMargin: 80
        }

        ScrollView {
            id: scroll
            width: parent.width - 50
            height: parent.height - 100
            anchors.centerIn: parent
            ScrollBar.vertical.policy: ScrollBar.AlwaysOn
            ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

            ListView {
                id: name
                model: aHours.availableHours;
                width: parent.width
                height: parent.height
                delegate: Rectangle {
                    id: rectext
                    width: name.width - 10
                    height: textolista.height + 20
                    color: '#eafcfc'
                    border.color: 'gray'
                    border.width: 0.5
                    Text {
                        id: textolista
                        text: modelData
                        font.family: "Helvetica"
                        font.pointSize: 16
                        anchors {
                            verticalCenter: rectext.verticalCenter
                        }
                        leftPadding: 10
                    }
                }
            }
        }
    }
}

