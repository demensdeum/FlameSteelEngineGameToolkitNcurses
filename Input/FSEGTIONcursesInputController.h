#ifndef FSEGTIONCURSESINPUTCONTROLLER_DEFINED
#define FSEGTIONCURSESINPUTCONTROLLER_DEFINED

#include <FlameSteelEngineGameToolkit/IO/Input/FSEGTInputController.h>

class FSEGTIONcursesInputController : public FSEGTInputController {

public:

	 FSEGTIONcursesInputController();

	virtual void pollKey(); 

};

#endif