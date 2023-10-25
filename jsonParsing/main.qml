import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import readInfo 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Item{
        id :root
        width: parent.width
        height: parent.height

        Button{
            id: parsing_bt
            width: parent.width/4
            height: parent.height/4
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter:parent.verticalCenter
            text:"parsing"

            onClicked:{
                ReadInfo.loadJson();

            }
        }
    }
}
