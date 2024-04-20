//
// Created by User on 20.04.2024.
//

#include "../headers/DemoView.h"

DemoView::DemoView() {
    seekBar = new SeekBar(FloatRect(40.f, 400.f, 560.f, 40.f), 0.5f);
    indicator = new CurvedIndicator(FloatRect(40.f, 40.f, 560.f, 320.f), 0.5f, 15);
}
