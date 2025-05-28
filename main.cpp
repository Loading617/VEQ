#include <CtrlLib/CtrlLib.h>

using namespace Upp;

#define LAYOUTFILE <VEq/VEq.lay>
#include <CtrlCore/lay.h>

class VEqApp : public WithVEqLayout<TopWindow> {
public:
    VEqApp() {
        CtrlLayout(*this, "VEQ");

        ApplyBtn <<= THISBACK(ApplySettings);

        for (int i = 0; i < 10; i++) {
            sliders[i] = &*this->GetChild(i);
            sliders[i]->MinMax(0, 100).SetData(50);
        }
    }

private:
    SliderCtrl* sliders[10];

    void ApplySettings() {
        String settings;
        for (int i = 0; i < 10; i++) {
            settings << Format("Band %d: %d\n", i + 1, (int)sliders[i]->GetData());
        }
        PromptOK(settings);
    }
};

GUI_APP_MAIN {
    VEqApp().Run();
}
