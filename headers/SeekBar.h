//
// Created by User on 20.04.2024.
//

#ifndef SEEKBAR_H
#define SEEKBAR_H
#include "ISeekBarCallbacks.h"
#include "UiComponent.h"


class SeekBar : public UiComponent {
public:
    SeekBar(FloatRect bounds, float progress = 0.f) : UiComponent(bounds) {
        this->progress = progress;
        init();
    }

    void draw(RenderWindow& window) override;
    void onMousePressed(Vector2f coords) override;
    void onMouseReleased(Vector2f coords) override;
    void onMouseMoved(Vector2f coords) override;
    void act() override;

    void setProgress(float progress);

    void setCallbacks(ISeekBarCallbacks* callbacks);

private:
    void init();
    void onProgressUpdated();

    float progress;
    bool isDragging = false;
    bool isDraggingInterrupted = false;
    float focusPadding;
    float focusSize;

    ISeekBarCallbacks* callbacks = nullptr;

    Color backgroundColor = Color(173, 216, 233);
    Color foregroundColor = Color(67, 105, 228);
    Color focusColor = Color(27, 24, 105);

    RectangleShape backgroundRect;
    RectangleShape foregroundRect;
    RectangleShape focusRect;
};



#endif //SEEKBAR_H
