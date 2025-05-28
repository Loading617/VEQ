#ifndef _VEQ_VEQ_h
#define _VEQ_VEQ_h

#include <CtrlLib/CtrlLib.h>

using namespace Upp;

#define LAYOUTFILE <VEQ/VEQ.lay>
#include <CtrlCore/lay.h>

class VEQ : public WithVEQLayout<TopWindow> {
public:
	VEQ();
};

#endif
