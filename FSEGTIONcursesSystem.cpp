#include "FSEGTIONcursesSystem.h"
#include "Renderers/FSEGTIONcursesRenderer.h"
#include "Input/FSEGTIONcursesInputController.h"

void FSEGTIONcursesSystem::initialize(shared_ptr<FSEGTIOSystemParams> params) {

	initscr();

	renderer = make_shared<FSEGTIONcursesRenderer>();
	renderer->initialize();

	inputController = make_shared<FSEGTIONcursesInputController>();

}
    
void FSEGTIONcursesSystem::objectsContextObjectAdded(shared_ptr<FSEGTObjectsContext> context, shared_ptr<FSCObject> object) {
}

void FSEGTIONcursesSystem::objectsContextObjectUpdate(shared_ptr<FSEGTObjectsContext> context, shared_ptr<FSCObject> object) {
}

void FSEGTIONcursesSystem::objectsContextAllObjectsRemoved(shared_ptr<FSEGTObjectsContext> context) {
}