#include <SFML/Graphics.hpp>
#include <iostream>

#include "ComplexPlane.h"

using namespace sf;
using namespace std;

int main()
{
    int pixelWidth = VideoMode::getDesktopMode().width / 2;
    int pixelHeight = VideoMode::getDesktopMode().height / 2;
    VideoMode vm(pixelWidth, pixelHeight);
    RenderWindow window(vm, "Rainbow Screen", Style::Default);
    ComplexPlane plane(pixelWidth, pixelHeight);
    
    Font font;
    if (!font.loadFromFile("font/KOMIKAP_.ttf"))
    {
        cerr << "File did not load. \n";
		return 1;
    }

    Text messageText;
    messageText.setFont(font);
    messageText.setCharacterSize(25);
	messageText.setFillColor(Color::Red);
	messageText.setPosition(10.f, 10.f);

    messageText.setString("Zoom In OR Zoom Out. YOUR CHOICE!!");

    while (window.isOpen())
    {
        ///Input
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                // Quit the game when the window is closed.
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    //plane.zoomOut();
                    //plane.setCenter(Vector2i(event.mouseButton.x, event.mouseButton.y));
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                }
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    //plane.zoomIn();
                    //plane.setCenter(Vector2i(event.mouseButton.x, event.mouseButton.y));
                    std::cout << "the left button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                }
            }
            if (event.type == sf::Event::MouseMoved)
            {
                //plane.setMouseLocation(Vector2i(event.mouseButton.x, event.mouseButton.y));
                std::cout << "Moused Moved!!" << std::endl;
                std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                std::cout << "mouse y: " << event.mouseButton.y << std::endl;
            }
        }
        
        //  NOT WORKING (Sunday)
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        /*
		****************************************
		Update the scene
		****************************************
        */
        //plane.updateRender();
        //plane.loadText(messageText);

        /*
		****************************************
		Draw the scene
		****************************************
		*/
        window.clear();
        window.draw(plane);
        window.draw(messageText);
        window.display();
    }
}
