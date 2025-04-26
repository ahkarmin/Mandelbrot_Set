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

    while (window.isOpen())
    {
        ///Input
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        ///Update


        ///Draw
        window.clear();
        //window.draw(...);
        window.display();
    }




}
