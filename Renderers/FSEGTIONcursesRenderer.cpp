#include "FSEGTIONcursesRenderer.h"
#include <ncurses.h>
#include <thread>
#include <chrono>

FSEGTIONcursesRenderer::FSEGTIONcursesRenderer() {

}

void FSEGTIONcursesRenderer::initialize() {

}

void FSEGTIONcursesRenderer::render(shared_ptr<FSEGTGameData> gameData) {

	//clear();
	//printw("NCurses IO System render");
	//refresh();
	std::this_thread::sleep_for(0.01s);
}

void FSEGTIONcursesRenderer::objectsContextObjectAdded(shared_ptr<FSEGTObjectsContext> context, shared_ptr<FSCObject> object)
{
}

void FSEGTIONcursesRenderer::objectsContextObjectUpdate(shared_ptr<FSEGTObjectsContext> context, shared_ptr<FSCObject> object)
{
}

void FSEGTIONcursesRenderer::objectsContextAllObjectsRemoved(shared_ptr<FSEGTObjectsContext> context)
{
}	