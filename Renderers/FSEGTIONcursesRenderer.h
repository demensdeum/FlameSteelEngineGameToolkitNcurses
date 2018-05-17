#ifndef FSEGTIONCURSESRENDERER_DEFINED
#define FSEGTIONCURSESRENDERER_DEFINED 1

#include <FlameSteelEngineGameToolkit/IO/Renderers/FSEGTRenderer.h>

#include <memory>

using namespace std;

class FSEGTIONcursesRenderer: public FSEGTRenderer {

public:
	FSEGTIONcursesRenderer();

	virtual void initialize();

	virtual void render(shared_ptr<FSEGTGameData> gameData);

	virtual void objectsContextObjectAdded(shared_ptr<FSEGTObjectsContext> context, shared_ptr<FSCObject> object);
 	virtual void objectsContextObjectUpdate(shared_ptr<FSEGTObjectsContext> context, shared_ptr<FSCObject> object);
	virtual void objectsContextAllObjectsRemoved(shared_ptr<FSEGTObjectsContext> context);	

};

#endif