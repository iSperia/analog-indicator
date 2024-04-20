//
// Created by iSperia on 20.04.2024.
//

#include "../headers/SFMLEngine.h"

const sf::Time SFMLEngine::TimePerFrame = seconds(1.f / 60.f);

SFMLEngine::SFMLEngine() {
    resolution = Vector2i(640, 480);
    ContextSettings settings;
    settings.antialiasingLevel = 8.0;
    window->create(VideoMode(resolution.x, resolution.y), "Indicator Sample", Style::Default, settings);
    window->setFramerateLimit(FPS);
}

void SFMLEngine::run() {
    while (window->isOpen()) {
        handleEvents();
        act();
        draw();
    }
}

void SFMLEngine::draw() {
    window->clear(Color::White);

    for (auto component : components) {
        component->draw(*window);
    }

    window->display();
}

void SFMLEngine::add(UiComponent* component) {
    components.push_back(component);
}


void SFMLEngine::handleEvents() {
    Event event{};

    while (window->pollEvent(event)) {
        //Handle window closed
        if (event.type == Event::Closed) {
            window->close();
        }

        //simple mouse click, no dragging support for simplicity reasons
        if (event.type == Event::MouseButtonPressed) {
            for (auto component : components) {
                Vector2f mouseCoords(event.mouseButton.x, event.mouseButton.y);
                if (component->bounds.contains(mouseCoords)) {
                    component->onMousePressed(mouseCoords);
                }
            }
        }

        //simple mouse click, no dragging support for simplicity reasons
        if (event.type == Event::MouseButtonReleased) {
            for (auto component : components) {
                Vector2f mouseCoords(event.mouseButton.x, event.mouseButton.y);
                component->onMouseReleased(mouseCoords);
            }
        }

        if (event.type == Event::MouseMoved) {
            for (auto component : components) {
                Vector2f mouseCoords(event.mouseMove.x, event.mouseMove.y);
                component->onMouseMoved(mouseCoords);
            }
        }
    }
}

void SFMLEngine::act() {
    for (auto component : components) {
        component->act();
    }
}


