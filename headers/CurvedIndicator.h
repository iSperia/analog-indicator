//
// Created by User on 20.04.2024.
//

#ifndef CURVEDINDICATOR_H
#define CURVEDINDICATOR_H
#include "UiComponent.h"


class CurvedIndicator : public UiComponent {
public:
    CurvedIndicator(
        FloatRect bounds,
        float progress = 0.f,
        int detalization = 100
    ) : UiComponent(bounds) {
        this->progress = progress;
        this->displayedProgress = progress;
        this->detalization = detalization;
        init();
    }

    void draw(RenderWindow& window) override;
    void onMousePressed(Vector2f coords) override;
    void onMouseReleased(Vector2f coords) override;
    void onMouseMoved(Vector2f coords) override;
    void act() override;

    void setProgress(float progress);

private:
    void init();
    void onProgressUpdated();
    void createConvexes(float centerX, float centerY, float angleFrom, float angleTo, Color color);
    void updateIndicatorRotation();

    Texture indicatorTexture;
    Sprite indicatorSprite;

    int detalization;
    float progress;
    float innerRadius;
    float outerRadius;
    float sectorShift;
    float centerX;
    float centerY;

    int animationState = ANIMATION_STATE_NONE;
    float displayedProgress = progress;
    float indicatorForce = 0.f;

    FloatRect innerBounds;
    std::vector<ConvexShape> indicatorConvexes;

    Color colorStart = Color(252, 199, 21);
    Color colorMiddle = Color(164, 203, 60);
    Color colorEnd = Color(254, 69, 66);

    const float FRAME_ACCELERATION = 0.0005f;
    const float THRESHOLD_ACCELERATION = 0.005f;
    const float THRESHOLD_PROGRESS = 0.005f;

    const int ANIMATION_STATE_NONE = 0;
    const int ANIMATION_STATE_ACCELERATE = 1;
    const int ANIMATION_STATE_DECELERATE = 2;
};



#endif //CURVEDINDICATOR_H
