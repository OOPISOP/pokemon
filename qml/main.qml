import QtQuick 2
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.3
import com.game 1.0

ApplicationWindow
{
    id: root
    title: qsTr("Chess")
    visible: true
    minimumWidth: 600
    minimumHeight: 600

    Component {
        id: mainScreen
        Item
        {
            Game
            {
                id:game
            }
            Button
            {
                x: 300
                y: 300
                id:blackSurrend
                text: "Bag"
                onClicked:
                {
                    game.executeCommand("Bag");
                    //console.log("Button clicked!")
                }
            }
        }
    }
    StackView
    {
        id: screen
        anchors.fill: parent
        initialItem: mainScreen
    }
}
