#include "ComplexPlane.h"
#include <cmath>

ComplexPlane::ComplexPlane(int pixelWidth, int pixelHeight)
    : m_pixel_size(pixelWidth, pixelHeight),
      m_aspectRatio((float)pixelHeight / pixelWidth),
      m_plane_center(0.f, 0.f),
      m_plane_size(BASE_WIDTH, BASE_HEIGHT * m_aspectRatio),
      m_zoomCount(0),
      m_State(State::CALCULATING),
      m_vArray(sf::Points, pixelWidth * pixelHeight) {}

void ComplexPlane::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_vArray);
}

void ComplexPlane::updateRender() {
    if (m_State != State::CALCULATING) return;

    for (unsigned int i = 0; i < m_pixel_size.y; ++i) {
        for (unsigned int j = 0; j < m_pixel_size.x; ++j) {
            size_t index = j + i * m_pixel_size.x;
            m_vArray[index].position = sf::Vector2f((float)j, (float)i);
            sf::Vector2f coord = mapPixelToCoords({ (int)j, (int)i });
            size_t iter = countIterations(coord);

            sf::Uint8 r = 0, g = 0, b = 0;
            iterationsToRGB(iter, r, g, b);
            m_vArray[index].color = sf::Color(r, g, b);
        }
    }
    m_State = State::DISPLAYING;
}

void ComplexPlane::zoomIn() {
    m_zoomCount++;
    m_plane_size = sf::Vector2f(
        BASE_WIDTH * std::pow(BASE_ZOOM, m_zoomCount),
        BASE_HEIGHT * m_aspectRatio * std::pow(BASE_ZOOM, m_zoomCount));
    m_State = State::CALCULATING;
}

void ComplexPlane::zoomOut() {
    m_zoomCount--;
    m_plane_size = sf::Vector2f(
        BASE_WIDTH * std::pow(BASE_ZOOM, m_zoomCount),
        BASE_HEIGHT * m_aspectRatio * std::pow(BASE_ZOOM, m_zoomCount));
    m_State = State::CALCULATING;
}

void ComplexPlane::setCenter(sf::Vector2i mousePixel) {
    m_plane_center = mapPixelToCoords(mousePixel);
    m_State = State::CALCULATING;
}

void ComplexPlane::setMouseLocation(sf::Vector2i mousePixel) {
    m_mouseLocation = mapPixelToCoords(mousePixel);
}

void ComplexPlane::loadText(sf::Text& text) {
    std::stringstream ss;
    ss.precision(5);
    ss << "Cursor: (" << m_mouseLocation.x << ", " << m_mouseLocation.y << ")\n"
       << "Center: (" << m_plane_center.x << ", " << m_plane_center.y << ")\n"
       << "Zoom Level: " << m_zoomCount << std::endl
       << "Left-click to Zoom-in" << std::endl
       << "Right-click to Zoom-out" << std::endl;

    text.setString(ss.str());
}

size_t ComplexPlane::countIterations(sf::Vector2f coord) {
    std::complex<float> c(coord.x, coord.y);
    std::complex<float> z = 0;
    size_t i = 0;
    while (abs(z) < 2.0f && i < MAX_ITER) {
        z = z * z + c;
        ++i;
    }
    return i;
}

void ComplexPlane::iterationsToRGB(size_t count, sf::Uint8& r, sf::Uint8& g, sf::Uint8& b) {
    if (count == MAX_ITER) 
    {
        r = g = b = 0;
    } 
    else 
    {
        float t = static_cast<float>(count) / MAX_ITER;
        r = static_cast<sf::Uint8>(9 * (1 - t) * t * t * t * 255);
        g = static_cast<sf::Uint8>(15 * (1 - t) * (1 - t) * t * t * 255);
        b = static_cast<sf::Uint8>(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    }
}

sf::Vector2f ComplexPlane::mapPixelToCoords(sf::Vector2i mousePixel) {
    float x = ((float)mousePixel.x / m_pixel_size.x) * m_plane_size.x + (m_plane_center.x - m_plane_size.x / 2.0f);
    float y = ((float)(m_pixel_size.y - mousePixel.y) / m_pixel_size.y) * m_plane_size.y + (m_plane_center.y - m_plane_size.y / 2.0f);
    return { x, y };
}
