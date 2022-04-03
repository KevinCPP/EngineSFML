#include "Game.h"

Game::Game(){
    engine = std::make_unique<Engine>(sf::VideoMode(1280, 720), "title");
    currentState = mainMenu;
}


void Game::handleEvents(){
    sf::Event event;
    while(engine->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            engine->close();
        }
    }     
}

void Game::runMainLoop(){
    while(engine->windowIsOpen()){
        handleEvents();
        
        engine->clear();  
      
        switch(currentState){
            case mainMenu:
                displayMainMenu();
                break;
            case optionsMenu:
                displayOptionsMenu();
                break;
            case inGame:
                displayGame();
                break;
        }

        engine->display();
    }
}

void Game::displayMainMenu(){
    
}

void Game::displayOptionsMenu(){

}

void Game::displayGame(){

}
