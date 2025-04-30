#include <SFML/Graphics.hpp>
#include "ComplexPlane.h"
#include <iostream>
using namespace sf;
using namespace std;

int main() {
    VideoMode desktop = VideoMode::getDesktopMode();
    unsigned int width = desktop.width / 2;
    unsigned int height = desktop.height / 2;

    RenderWindow window(VideoMode(width, height), "Mandelbrot Viewer");
    ComplexPlane plane(width, height);

    Font font;
    if (!font.loadFromFile("font/KOMIKAP_.ttf"))
    {
        cerr << "Font file not working." << endl;
        return 0;
    }

    Text infoText("", font, 14);
    infoText.setFillColor(Color::White);
    infoText.setPosition(10, 10);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed) {
                plane.setCenter(Mouse::getPosition(window));
                if (event.mouseButton.button == Mouse::Left)
                    plane.zoomIn();
                else if (event.mouseButton.button == Mouse::Right)
                    plane.zoomOut();
            }

            if (event.type == Event::MouseMoved) {
                Vector2i mousePos = Mouse::getPosition(window);
                plane.setMouseLocation(mousePos);
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
            window.close();

        // Update
        plane.updateRender();
        plane.loadText(infoText);

        // Draw
        window.clear();
        window.draw(plane);
        window.draw(infoText);
        window.display();
    }

    return 0;
}
