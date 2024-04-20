//
// Created by User on 20.04.2024.
//

#ifndef DEMOVIEW_H
#define DEMOVIEW_H
#include "CurvedIndicator.h"
#include "SeekBar.h"


class DemoView {
public:

    DemoView();

    CurvedIndicator* getIndicator() {
        return indicator;
    }

    SeekBar* getSeekBar() {
        return seekBar;
    }

    ~DemoView() {
        delete indicator;
        delete seekBar;
    }

private:
    CurvedIndicator* indicator;
    SeekBar* seekBar;

};



#endif //DEMOVIEW_H
