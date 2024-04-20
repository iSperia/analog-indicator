//
// Created by User on 20.04.2024.
//

#ifndef DEMOPRESENTER_H
#define DEMOPRESENTER_H
#include "DemoView.h"
#include "ISeekBarCallbacks.h"
#include "SFMLEngine.h"


class DemoPresenter : public ISeekBarCallbacks {
public:
    DemoPresenter(
        SFMLEngine* engine,
        DemoView* view
    );

    void onProgressChanged(float progress) override;

    ~DemoPresenter() override = default;

private:
    SFMLEngine* engine;
    DemoView* view;
};



#endif //DEMOPRESENTER_H
