#include <SFML/Graphics.hpp>
#include <iostream>

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


    while (window.isOpen())
    {
        ///Input
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event.Closed)
            {
                // Quit the game when the window is closed.
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    plane.zoomOut();
                    plane.setCenter(Vector2f(event.mouseButton.x, event.mouseButton.y));
                }
                if (event.mouseButton.button == sf::Mouse::Right)
                {

                }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        ///Update


        ///Draw
        window.clear();
        messageText.setString("Here!!!!");
        window.draw(messageText);
        window.display();
    }
}
