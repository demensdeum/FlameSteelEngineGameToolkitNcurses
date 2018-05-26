#include "FSEGTIONcursesRenderer.h"
#include <ncurses.h>
#include <thread>
#include <chrono>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include <iostream>

FSEGTIONcursesRenderer::FSEGTIONcursesRenderer() {

}

void FSEGTIONcursesRenderer::initialize() {

}

void FSEGTIONcursesRenderer::render(shared_ptr<FSEGTGameData> gameData) {


	clear();

	int cameraRendererWidth = 41;
	int cameraRendererHeight = 21;

	auto gameMap = gameData->gameMap;

	if (objectsMap.get() == nullptr) {

		objectsMap = make_shared<ObjectsMap>(gameMap->width, gameMap->height);

	}

	if (camera.get() == nullptr)
	{
		cout << "Can't render - there is no camera... skip" << endl;
		return;
	}
	auto position = FSEGTUtils::getObjectPosition(camera);

	auto cameraX = position->x - cameraRendererWidth / 2;
	auto cameraY = position->z - cameraRendererHeight / 2;

	for (auto y = cameraY; y < cameraY + cameraRendererHeight; y++)
	{
		for (auto x = cameraX; x < cameraX + cameraRendererWidth; x++)
		{
			auto object = objectsMap->objectAtXY(x, y);

			if (object.get() != nullptr)
			{
				printw("^");
				continue;
			}

			auto tile = gameMap->getTileIndexAtXY(x,y);

			switch (tile) {

				case 0:
					printw(" ");
					break;

				case 1:
					printw("#");
					break;

				default:
					printw("?");
					break;

			}
		}
		printw("\n");
	}

	refresh();
	std::this_thread::sleep_for(0.001s);
}

void FSEGTIONcursesRenderer::objectsContextObjectAdded(shared_ptr<FSEGTObjectsContext> context, shared_ptr<FSCObject> object)
{
	if (object->getClassIdentifier()->compare("camera") == 0) {

		this->camera = object;

	}

	if (objectsMap.get() != nullptr) {
		objectsMap->handleObject(object);
	}
}

void FSEGTIONcursesRenderer::objectsContextObjectUpdate(shared_ptr<FSEGTObjectsContext> context, shared_ptr<FSCObject> object)
{
	if (objectsMap.get() != nullptr) {
		objectsMap->handleObject(object);
	}
}

void FSEGTIONcursesRenderer::objectsContextAllObjectsRemoved(shared_ptr<FSEGTObjectsContext> context)
{
	if (objectsMap.get() != nullptr) {
		objectsMap->removeAllObjects();
	}
}	