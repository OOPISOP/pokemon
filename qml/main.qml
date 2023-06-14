import QtQuick 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.3
import com.game 1.0

ApplicationWindow
{
    id: root
    title: qsTr("Pokemon Init")
    visible: true
    minimumWidth: 300
    minimumHeight: 500
    Game
    {
        id:game
    }
    Component {
        id: mainScreen
        Item
        {
            Button
            {
                x: 100
                y: 0
                id:loadTestCase
                text: "Load TestCase"
                onClicked:
                {
                    game.loadTestCase();
                }
            }
            Button
            {
                x:100
                y:100
                id:loadPokemonData
                text:"Load PokemonData"
                onClicked:
                {
                    game.loadPokemonData()
                }
            }
            Button
            {
                x:100
                y:200
                id:loadMoveData
                text:"Load MoveData"
                onClicked:
                {
                    game.loadMoveData()
                }
            }
            Button
            {
                x:100
                y:300
                id:loadGameData
                text:"Load GameData"
                onClicked:
                {
                    game.loadGameData()
                }
            }
            Button
            {
                x:100
                y:400
                id:startGame
                text:"Start Game"
                onClicked:
                {
                    if(game.checkAllDataLoaded())
                    {
                        battleWindow.show()
                        root.hide()
                        playerOne.text =  game.getCurrentStatus(0)
                        playerTwo.text =  game.getCurrentStatus(1)
                    }
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

    Window
    {
        id:battleWindow
        width:600
        height:600
        title:qsTr("secondWindow")
        StackView
        {
            id: stackView
            anchors.fill: parent

            initialItem: buttonPage1
            Component
            {
                id: buttonPage1
                Item
                {
                    Button
                    {
                        x: 400
                        y: 100
                        id: battle
                        text: "Battle"
                        onClicked:
                        {
                            stackView.push(moveButtons)

                        }
                    }
                    Button
                    {
                        x:400
                        y:200
                        id:pokemon
                        text:"Pokemon"
                        onClicked:
                        {
                            game.executeCommand("Pokemon")
                            stackView.push(swap)
                        }
                    }
                    Button
                    {
                        x:400
                        y:300
                        id:bag
                        text:"Bag"
                        onClicked:
                        {
                            game.executeCommand("Bag")
                        }
                    }
                }
            }
        }
        Item
        {
            Text
            {
                x:100
                y:400
                id: playerOne
                text: game.getCurrentStatus(0)
            }
            Text
            {
                x:300
                y:100
                id: playerTwo
                text: game.getCurrentStatus(1)
            }
        }

    }
    Component
    {
        id:swap
        Item {
            width: 200
            height: 200
            Column {
                Repeater {
                    model: game.stringList.length
                    Button {
                        text: game.stringList[index]
                        onClicked: {
                            console.log("Button clicked: " + text)
                        }
                    }
                }
            }
            Button
            {
                x:250
                y:300
                id:blackSwap
                text:"back"
                onClicked:
                {
                    stackView.pop()
                }
            }
        }
    }

    Component
    {
        id: moveButtons
        Item
        {
            Button
            {
                x: 400
                y: 100
                id: moveOne
                text: game.getMoveName(0)
                onClicked:
                {
                    game.executeCommand("Battle")
                     game.executeCommand(game.getMoveName(0))
                    stackView.pop()
                }
            }
            Button
            {
                x:400
                y:250
                id:moveTwo
                text: game.getMoveName(1)
                onClicked:
                {
                    game.executeCommand("Battle")
                    game.executeCommand(game.getMoveName(1))
                    stackView.pop()
                }
            }
            Button
            {
                x:400
                y:350
                id: moveThree
                text:game.getMoveName(2)
                onClicked:
                {
                    game.executeCommand("Battle")
                     game.executeCommand(game.getMoveName(2))
                    stackView.pop()
                }
            }
            Button
            {
                x:400
                y:450
                id:moveFour
                text:game.getMoveName(3)
                onClicked:
                {
                    game.executeCommand("Battle")
                     game.executeCommand(game.getMoveName(3))
                    stackView.pop()
                }
            }
            Button
            {
                x:250
                y:300
                id:blackMove
                text:"back"
                onClicked:
                {
                    stackView.pop()
                }
            }
        }
    }

    Connections
    {
        target:game
        function onUpdatePokemonInfo()
        {
            playerOne.text =  game.getCurrentStatus(0)
           playerTwo.text =  game.getCurrentStatus(1)
        }
    }
}



