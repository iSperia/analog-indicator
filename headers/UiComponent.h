//
// Created by User on 20.04.2024.
//

#ifndef ICOMPONENT_H
#define ICOMPONENT_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace sf;

class UiComponent {
public:
    UiComponent(FloatRect bounds) : bounds(bounds) {}

    virtual ~UiComponent() {}
    virtual void draw(RenderWindow& window) = 0;

    virtual void onMousePressed(Vector2f coords) = 0;
    virtual void onMouseReleased(Vector2f coords) = 0;
    virtual void onMouseMoved(Vector2f coords) = 0;
    virtual void act() = 0;

    FloatRect bounds;

private:

};



#endif //ICOMPONENT_H
