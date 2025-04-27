#ifndef COMPLEX_PLANE_H
#define COMPLEX_PLANE_H
#include <SFML/Graphics.hpp>
#include <sstream>
#include namespace sf;
#include namespace std;

const unsigned int MAX_ITER = 64;
const float BASE_WIDTH = 4.0f;
const float BASE_HEIGHT = 4.0f;
const float BASE_ZOOM = 0.5f;

enum class State {CALCULATING, DISPLAYING};

Class ComplexPlane : public Drawable
{
    public:
        int ComplexPlane(int pixelWidth, int pixelHeight);
        void draw(traget:RenderTarget&, states: RenderStates) const;
        void zoonIn();
        void zoomOut();
        void setCenter(mousePixel: Vector2i);
        void setMouseLocation(mousePixel: Vector2i);
        void loadText(text: Text&);
        void updateRender();
    private:
        void iterationsToRgb(size_t count, Uint8& r, Uint8& g, Uint8& b);
        size_t countIterations(Vector2f coord);
        Vector2f mapPixelToCoords(Vector2i mousePixel);

        VertexArray m_vArray;
        State m_state;
        Vector2f m_mouseLocation;
        Vector2i m_pixel_size;
        Vector2f m_plane_size;
        int m_zoomCount;
        float m_aspectRatio;
};

#endif