//
// Created by User on 20.04.2024.
//

#include "../headers/DemoPresenter.h"

DemoPresenter::DemoPresenter(SFMLEngine* engine, DemoView* view) : engine(engine), view(view) {
    engine->add(view->getIndicator());
    engine->add(view->getSeekBar());

    view->getSeekBar()->setCallbacks(this);
}

void DemoPresenter::onProgressChanged(float progress) {
    view->getIndicator()->setProgress(progress);
}

