import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import org.sample 1.0

ApplicationWindow {
    width: 700
    height: 500
    visible: true

    MessageDialog {
        id: aboutBox
        title: "About"
        text: "This is a basic syntax highlighter \nwritten with Qt Quick Controls"
        icon: StandardIcon.Information
    }

    FileDialog {
        id: fileDialog
        nameFilters: ["C++ files (*.cpp)", "Text files (*.txt)"]
        onAccepted: {
            documentHandler.openFile(fileUrl);
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

        Menu {
            title: "&Help"
            MenuItem { text: "About..." ; onTriggered: aboutBox.open() }
        }
    }

    TextArea {
        id: textArea
        anchors.fill: parent
        focus: true
        text: documentHandler.text
        Component.onCompleted: documentHandler.setDocument(textArea.textDocument)
    }
}
