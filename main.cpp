//header includes
#include "Engine.h"

//std includes
#include <iostream>

int main(){
    Engine engine;
   
    //main loop
    while(engine.windowIsOpen())
    {
        
        //event handling
        sf::Event event;
        while (engine.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                engine.close();
        }
                

        engine.clear();
        //begin rendering
        
        
        //end rendering
        engine.display();
    }

    return 0;
}

