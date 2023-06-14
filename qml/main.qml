import QtQuick 2.0
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
                x: 100
                y: 300
                id:bag
                text: "Bag"
                onClicked:
                {
                    game.executeCommand("Bag");
                }
            }
            Button
            {
                x: 300
                y: 300
                id:loadTestCase
                text: "Load TestCase"
                onClicked:
                {
                    game.loadTestCase();
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
