//
// Created by User on 20.04.2024.
//

#include "../headers/CurvedIndicator.h"

#include <cmath>
#include <complex>
#include <iostream>
#include <math.h>

void CurvedIndicator::init() {
    float innerWidth = std::min(bounds.getSize().x, bounds.getSize().y * 2.f);
    float innerHeight = std::min(bounds.getSize().y, innerWidth / 2.f);

    float paddingHor = (bounds.getSize().x - innerWidth) / 2.f;

    innerBounds = FloatRect(
        bounds.getPosition().x + paddingHor,
        bounds.getPosition().y + bounds.getSize().y - innerHeight,
        innerWidth,
        innerHeight);

    indicatorTexture.loadFromFile("assets/indicator_arrow.png");
    float indicatorScale = innerWidth * 0.08f / indicatorTexture.getSize().x;
    indicatorSprite.setTexture(indicatorTexture);
    indicatorSprite.setOrigin(Vector2f(34.f, 170.f));
    indicatorSprite.setScale(Vector2f(indicatorScale, indicatorScale));
    indicatorSprite.setPosition(innerBounds.getPosition().x + innerBounds.getSize().x / 2.f, innerBounds.getPosition().y + innerBounds.getSize().y);
    updateIndicatorRotation();

    innerRadius = 0.57f * innerHeight;
    outerRadius = innerHeight;
    sectorShift = innerBounds.getSize().y * 0.03f;
    centerX = innerBounds.getPosition().x + innerWidth / 2.f;
    centerY = innerBounds.getPosition().y + innerBounds.getSize().y;

    float shiftAngleStart = 30.f * M_PI / 180.f;
    float shiftAngleMiddle = 90.f * M_PI / 180.f;
    float shiftAngleEnd = 150.f * M_PI / 180.f;

    createConvexes(
        centerX - sectorShift * cos(shiftAngleStart),
        centerY - sectorShift * sin(shiftAngleStart),
        0.f * M_PI / 180.f,
        60.f * M_PI / 180.f,
        colorStart);
    createConvexes(
        centerX - sectorShift * cos(shiftAngleMiddle),
        centerY - sectorShift * sin(shiftAngleMiddle),
        60.f * M_PI / 180.f,
        120.f * M_PI / 180.f,
        colorMiddle);
    createConvexes(
        centerX - sectorShift * cos(shiftAngleEnd),
        centerY - sectorShift * sin(shiftAngleEnd),
        120.f * M_PI / 180.f,
        180.f * M_PI / 180.f,
        colorEnd);

    onProgressUpdated();
}

void CurvedIndicator::draw(RenderWindow &window) {
    for (auto convex : indicatorConvexes) {
        window.draw(convex);
    }
    window.draw(indicatorSprite);
}

void CurvedIndicator::createConvexes(float centerX, float centerY, float angleFrom, float angleTo, Color color) {
    float angleStep = (angleTo - angleFrom) / detalization;
    for (int i = 0; i < detalization; i++) {
        float as = angleFrom + angleStep * i;
        float ae = as + angleStep;

        ConvexShape convex;
        convex.setPointCount(4);
        convex.setPoint(0, Vector2f(centerX - innerRadius * cos(as), centerY - innerRadius * sin(as)));
        convex.setPoint(1, Vector2f(centerX - outerRadius * cos(as), centerY - outerRadius * sin(as)));
        convex.setPoint(2, Vector2f(centerX - outerRadius * cos(ae), centerY - outerRadius * sin(ae)));
        convex.setPoint(3, Vector2f(centerX - innerRadius * cos(ae), centerY - innerRadius * sin(ae)));

        convex.setFillColor(color);

        indicatorConvexes.push_back(convex);
    }
}

void CurvedIndicator::onMousePressed(Vector2f coords) {}
void CurvedIndicator::onMouseMoved(Vector2f coords) {}
void CurvedIndicator::onMouseReleased(Vector2f coords) {}


void CurvedIndicator::setProgress(float progress) {
    this->progress = progress;
    onProgressUpdated();
}

void CurvedIndicator::onProgressUpdated() {
    if (abs(displayedProgress - progress) > THRESHOLD_ACCELERATION) {
        animationState = ANIMATION_STATE_ACCELERATE;
    }
}

void CurvedIndicator::act() {
    if (animationState == ANIMATION_STATE_ACCELERATE) {
        float op = displayedProgress;
        float np = displayedProgress + indicatorForce;
        displayedProgress = np;

        if ((progress > op) != (progress > np)) {
            animationState = ANIMATION_STATE_DECELERATE;
        } else {
            indicatorForce += (progress > np) ? FRAME_ACCELERATION : -FRAME_ACCELERATION;
        }

        updateIndicatorRotation();
    } else if (animationState == ANIMATION_STATE_DECELERATE) {
        indicatorForce /= 1.2f;
        displayedProgress += indicatorForce;
        if (abs(indicatorForce) < THRESHOLD_ACCELERATION) {
            indicatorForce = 0.f;
            if (abs(progress - displayedProgress) < THRESHOLD_PROGRESS) {
                animationState = ANIMATION_STATE_NONE;
                displayedProgress = progress;
                indicatorForce = 0.f;
            } else {
                animationState = ANIMATION_STATE_ACCELERATE;

            }
        }
        updateIndicatorRotation();
    }
}

void CurvedIndicator::updateIndicatorRotation() {
    float rotation = -90.f + 180.f * displayedProgress;
    indicatorSprite.setRotation(rotation);
}




