import QtQuick
import QtQuick.Controls
import CounterCustomType

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Counter custom Type")

    Counter {
        id: counterId
    }

    Column {
        anchors.centerIn: parent
        spacing: 10

        Rectangle {
            width: 200
            height: 200
            radius: 10
            color: (counterId.count >= 0) ? "green" : "red"

            Text {
                id: textId
                text: counterId.count
                anchors.centerIn: parent
                font.pointSize: 40
                color: "white"
            }
        }

        Button {
            id: btnStartId
            text: "Start"
            width: 200
            onClicked: {
                counterId.start()
            }
        }

        Button {
            id: btnStopId
            text: "Stop"
            width: 200
            onClicked: {
                counterId.stop()
            }
        }

        Button {
            id: btnCountUpwardId
            text: "Upward"
            width: 200
            onClicked: {
                counterId.up = true
            }
        }

        Button {
            id: btnCountDownwardId
            text: "Downward"
            width: 200
            onClicked: {
                counterId.up = false
            }
        }
    }
}
