#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

//standard includes
#include <iostream>
#include <memory>

//sfml includes
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Engine {
    sf::RenderWindow    window;         //window object that everything will be drawn to
    sf::Clock           framerateClock; //clock used to keep track of framerate
    sf::Clock           logicClock;     //clock used to keep track of logic cycles / ticks
    sf::Font            defaultFont;    //default font to be used for text
    uint32_t            ticksPerSecond; //how many logic ticks should happen every second
    double              lastFPS;        //last framerate calculated by calculateFPS()
    double              lastLC;         //last logic cycles calculated by calculateLC()
    

    double calculateFPS(); //calculates the FPS
    double calculateLC();  //calculates how many logic cycles have elapsed
public:
    //states that the game can be in
    typedef enum {
        mainMenu,
        optionsMenu,
        playing
    } State;
    
    State currentState;

    //constructor
    Engine(const sf::VideoMode& videoMode = sf::VideoMode(1280, 720),
            const std::string& title = "Title",
            const uint32_t style = sf::Style::Default,
            const uint32_t TPS = 60);
            

    //functions for drawing
    bool windowIsOpen();
    bool pollEvent(sf::Event& event);

    void clear();
    void draw(const sf::Drawable& drawable, const sf::RenderStates& states = sf::RenderStates::Default);
    void display();
    
    void close();

    //getters
    sf::Vector2u getResolution();       //returns the resolution of window
    double getLogicCycles();            //returns how many ticks have passed since the last display() statement
    double getFramerate();              //returns the current framerate  
    
    //setters
    void setResolution(uint32_t x, uint32_t y); //changes the resolution of window
    void setTitle(const std::string& title);    //changes the title of window
    void setTPS(uint32_t tps);                  //sets how many ticks per second logic should be
};

#endif
