import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    width: 700
    height: 500
    visible: true


    FileDialog {
        id: fileDialog
        nameFilters: ["C++ files (*.cpp)", "Text files (*.txt)"]
        onAccepted: {
        }
    }

    Action {
        id: fileOpenAction
        iconSource: "images/fileopen.png"
        iconName: "document-open"
        text: "Open"
        onTriggered: fileDialog.open()
    }

    menuBar: MenuBar {
        Menu {
            title: "&File"
            MenuItem { action: fileOpenAction }
            MenuItem { text: "Quit"; onTriggered: Qt.quit() }
        }
    }

    TextArea {
        id: textArea
        anchors.fill: parent
    }
}
