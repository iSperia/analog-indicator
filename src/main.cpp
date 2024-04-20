#include "DemoPresenter.h"
#include "DemoView.h"
#include "SFMLEngine.h"

int main() {
    auto* engine = new SFMLEngine();
    auto* view = new DemoView();
    auto* presenter = new DemoPresenter(engine, view);

    engine->run();

    delete engine;
    delete view;
    delete presenter;

    return 0;
}
