//
// Created by iSperia on 20.04.2024.
//

#ifndef SFMLENGINE_H
#define SFMLENGINE_H

#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include <UiComponent.h>

using namespace sf;
using namespace std;

class SFMLEngine {
private:
    Vector2i resolution;
    RenderWindow* window = new RenderWindow();
    const unsigned int FPS = 60;
    static const Time TimePerFrame;

    vector<UiComponent*> components;

public:
    SFMLEngine();

    void draw();

    void run();

    void handleEvents();
    void act();

    void add(UiComponent* component);

    ~SFMLEngine() {
        components.clear();
        delete window;
    }
};



#endif //SFMLENGINE_H
