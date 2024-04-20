//
// Created by User on 20.04.2024.
//

#include "../headers/SeekBar.h"

#include <iostream>

void SeekBar::init() {

    focusPadding = 0.2f * bounds.height;
    focusSize = bounds.height - 2.f * focusPadding;

    backgroundRect.setSize(bounds.getSize());
    backgroundRect.setPosition(bounds.getPosition());

    backgroundRect.setFillColor(backgroundColor);
    foregroundRect.setFillColor(foregroundColor);
    focusRect.setFillColor(focusColor);

    onProgressUpdated();
}

void SeekBar::setProgress(float progress) {
    this->progress = progress;

    onProgressUpdated();
}

void SeekBar::onProgressUpdated() {
    float progressWidth = progress * bounds.getSize().x;
    Vector2f posBounds = bounds.getPosition();

    foregroundRect.setSize(Vector2f(progressWidth, bounds.getSize().y));
    foregroundRect.setPosition(bounds.getPosition());

    focusRect.setSize(Vector2f(focusSize, focusSize));
    focusRect.setPosition(Vector2f(posBounds.x + progressWidth - focusPadding - focusSize, posBounds.y + focusPadding));

    if (callbacks != nullptr) {
        callbacks->onProgressChanged(progress);
    }
}

void SeekBar::onMousePressed(Vector2f coords) {
    progress = std::max(0.f, std::min(1.f, (coords.x - bounds.getPosition().x) / bounds.getSize().x));
    isDragging = true;
    onProgressUpdated();
}

void SeekBar::onMouseMoved(Vector2f coords) {
    if (isDragging) {
        progress = std::max(0.f, std::min(1.f, (coords.x - bounds.getPosition().x) / bounds.getSize().x));
        onProgressUpdated();
    }
}

void SeekBar::onMouseReleased(Vector2f coords) {
    isDragging = false;
}



void SeekBar::draw(RenderWindow &window) {
    window.draw(backgroundRect);
    window.draw(foregroundRect);
    if (focusRect.getPosition().x >= bounds.getPosition().x) { //don't show focus rect if does not fit component (too small progress)
        window.draw(focusRect);
    }
}

void SeekBar::setCallbacks(ISeekBarCallbacks* callbacks) {
    this->callbacks = callbacks;
}

void SeekBar::act() {}

