#include "FSEGTIONcursesSystem.h"
#include "Renderers/FSEGTIONcursesRenderer.h"
#include "Input/FSEGTIONcursesInputController.h"

void FSEGTIONcursesSystem::initialize(shared_ptr<FSEGTIOSystemParams> params) {

	initscr();
	keypad(stdscr, true);
	printw("NCurses IO System initialized\n");
	refresh();

	renderer = make_shared<FSEGTIONcursesRenderer>();
	renderer->initialize();

	inputController = make_shared<FSEGTIONcursesInputController>();

}
    
void FSEGTIONcursesSystem::objectsContextObjectAdded(shared_ptr<FSEGTObjectsContext> context, shared_ptr<Object> object) {

    renderer->objectsContextObjectAdded(context, object);

}

void FSEGTIONcursesSystem::objectsContextObjectUpdate(shared_ptr<FSEGTObjectsContext> context, shared_ptr<Object> object) {
    
    renderer->objectsContextObjectUpdate(context, object);
    
}

void FSEGTIONcursesSystem::objectsContextAllObjectsRemoved(shared_ptr<FSEGTObjectsContext> context) {
    
    renderer->objectsContextAllObjectsRemoved(context);

}

void FSEGTIONcursesSystem::stop() {

	endwin();

}