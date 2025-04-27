#ifndef COMPLEX_PLANE_H
#define COMPLEX_PLANE_H

#include <SFML/Graphics.hpp>
#include <sstream>
using namespace sf;
using namespace std;

const unsigned int MAX_ITER = 64;
const float BASE_WIDTH = 4.0f;
const float BASE_HEIGHT = 4.0f;
const float BASE_ZOOM = 0.5f;

enum class State {CALCULATING, DISPLAYING};

class ComplexPlane : public Drawable
{
    public:
        ComplexPlane(int pixelWidth, int pixelHeight);
        void draw(RenderTarget& target, RenderStates states) const;
        // void zoonIn();
        // void zoomOut();
        // void setCenter(Vector2i mousePixel);
        // void setMouseLocation(Vector2i mousePixel);
        // void loadText(Text& text);
        // void updateRender();
        
    private:
        // void iterationsToRgb(size_t count, Uint8& r, Uint8& g, Uint8& b);
        // size_t countIterations(Vector2f coord);
        // Vector2f mapPixelToCoords(Vector2i mousePixel);

        VertexArray m_vArray;
        State m_state;
        Vector2f m_mouseLocation;
        Vector2i m_pixel_size;
        Vector2f m_plane_center;
        Vector2f m_plane_size;
        int m_zoomCount;
        float m_aspectRatio;
};

#endif