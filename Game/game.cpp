#include "stdafx.h"
#include "game.h"

void Game::Start(){

    if(_gameState != Uninitialized)
        return;

    _mainWindow.create(sf::VideoMode(1025,768,32), "Test Game");
    _gameState = Game::Playing;

    while(!IsExiting()){
        GameLoop();
    }

    _mainWindow.close();
}


bool Game::IsExiting(){
    if(_gameState == Game::Exiting)
        return true;
    else
        return false;
}

void Game::GameLoop(){
    sf::Event currentEvent;
    while(_mainWindow.pollEvent(currentEvent)){
        switch(_gameState){
            case Game::Playing:{
            _mainWindow.clear(sf::Color(255,0,0));
            _mainWindow.display();

            if(currentEvent.type == sf::Event::Closed){
                _gameState = Game::Exiting;
            }
            break;

            }

        }

    }
}

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;

