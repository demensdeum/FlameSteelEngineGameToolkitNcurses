#ifndef FSEGTIONCURSES_DEFINED
#define FSEGTIONCURSES_DEFINED

#include <ncurses.h>
#include <FlameSteelEngineGameToolkit/IO/IOSystems/FSEGTIOSystem.h>

class FSEGTIONcursesSystem: public FSEGTIOSystem {

public:
 	virtual void initialize(shared_ptr<FSEGTIOSystemParams> params);
    
	virtual void objectsContextObjectAdded(shared_ptr<FSEGTObjectsContext> context, shared_ptr<FSCObject> object);
	virtual void objectsContextObjectUpdate(shared_ptr<FSEGTObjectsContext> context, shared_ptr<FSCObject> object);
	virtual void objectsContextAllObjectsRemoved(shared_ptr<FSEGTObjectsContext> context); 

	virtual void stop();

private:
	WINDOW *window;

};

#endif