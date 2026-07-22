#ifndef _DrinkForm_DrinkForm_h
#define _DrinkForm_DrinkForm_h

#include <CtrlLib/CtrlLib.h>

using namespace Upp;

#define LAYOUTFILE <DrinkForm/DrinkForm.lay>
#include <CtrlCore/lay.h>
#include <AutoScroller/AutoScroller.h>
#include "drink.h"

class DrinkForm : public WithMainAppWindow<TopWindow> {
public:
	DrinkForm();
private:
	AutoScroller scroller;
	WithDrinkFormLayout<ParentCtrl> scroller_view;
};

#endif
