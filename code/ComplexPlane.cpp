#include "ComplexPlane.h"

ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight)
{
    m_pixel_size = Vector2i(pixelWidth, pixelHeight);
    m_aspectRatio = pixelHeight / static_cast<float>(pixelWidth);
    m_plane_center = Vector2f(0, 0);
    m_plane_size = Vector2f(BASE_WIDTH, BASE_HEIGHT * m_aspectRatio);
    m_zoomCount = 0;
    m_state = State::CALCULATING;
    m_vArray.setPrimitiveType(Points);
	m_vArray.resize(pixelWidth * pixelHeight);
}
void ComplexPlane::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(m_vArray);
}
// void ComplexPlane::zoonIn() 
// {

// }
// void ComplexPlane::zoomOut()
// {

// }
// void ComplexPlane::setCenter(Vector2i mousPixel)
// {

// }
// void ComplexPlane::setMouseLocation(Vector2i mousPixel)
// {

// }
// void ComplexPlane::loadText(Text& text)
// {

// }

// FIX-ME
void ComplexPlane::updateRender()
{
    if (m_state == CALCULATING)
    {
        int pixelHeight = m_pixel_size.y;
        int pixelWidth = m_pixel_size.x;
        for (int i = 0; i < pixelHeight; i++)
        {
            for (int j = 0; j < pixelWidth; j++)
            {
                Vertex m_position
                Vector2f m_position = m_vArray[i * pixelWidth + j].position
                m_position = { (float)j, (float)i };
                Vector2f coord = mapPixelToCoords(m_position);
                size_t iter = countIterations(coord);
                Uint8 r, g, b;

            }
        }
    }
}
// void ComplexPlane::iterationsToRgb(size_t count, Uint8& r, Uint8& g, Uint8& b)
// {

// }
// size_t ComplexPlane::countIterations(Vector2f coord)
// {

// }
// Vector2f ComplexPlane::mapPixelToCoords(Vector2i mousPixel)
// {

// }

//