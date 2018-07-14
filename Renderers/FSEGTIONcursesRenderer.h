#ifndef FSEGTIONCURSESRENDERER_DEFINED
#define FSEGTIONCURSESRENDERER_DEFINED 1

#include <FlameSteelEngineGameToolkit/IO/Renderers/FSEGTRenderer.h>
#include <FlameSteelEngineGameToolkit/Data/ObjectsMap/ObjectsMap.h>
#include <memory>

using namespace std;
using namespace FlameSteelEngine::GameToolkit;

class FSEGTIONcursesRenderer: public FSEGTRenderer {

public:
	FSEGTIONcursesRenderer();

	virtual void initialize();

	virtual void render(shared_ptr<FSEGTGameData> gameData);

	virtual void objectsContextObjectAdded(shared_ptr<FSEGTObjectsContext> context, shared_ptr<Object> object);
 	virtual void objectsContextObjectUpdate(shared_ptr<FSEGTObjectsContext> context, shared_ptr<Object> object);
	virtual void objectsContextAllObjectsRemoved(shared_ptr<FSEGTObjectsContext> context);	

static const char *printSymbolFromObject(shared_ptr<Object>object);

private:
	shared_ptr<Object> camera;
	shared_ptr<ObjectsMap> objectsMap;
	shared_ptr<Objects> userInterfaceObjects;
	

};

#endif