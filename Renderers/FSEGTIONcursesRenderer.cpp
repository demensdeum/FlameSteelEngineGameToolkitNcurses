#include "FSEGTIONcursesRenderer.h"
#include <ncurses.h>
#include <thread>
#include <chrono>
#include <FlameSteelEngineGameToolkit/Utils/FSEGTUtils.h>
#include <iostream>
#include <FlameSteelEngineGameToolkit/Const/FSEGTConst.h>
#include <FlameSteelEngineGameToolkitAlgorithms/Const/Const.h>
#include <FlameSteelCore/FSCObjects.h>

using namespace FlameSteelEngine::GameToolkit::Algorithms;

FSEGTIONcursesRenderer::FSEGTIONcursesRenderer() {

	objectsMap = make_shared<ObjectsMap>();
	userInterfaceObjects = make_shared<FSCObjects>();
}

const char *FSEGTIONcursesRenderer::printSymbolFromObject(shared_ptr<FSCObject>object) {

	auto instanceIdentifier = object->getInstanceIdentifier().get();

	if (instanceIdentifier->compare("camera") == 0)
	{
		return "C";
	}
	else if (instanceIdentifier->compare(ConstMapEntityStartPoint) == 0)
	{
		return "S";
	}
	else if (instanceIdentifier->compare(ConstMapEntityEndPoint) == 0)
	{
		return "E";
	}

	return "^";

}

void FSEGTIONcursesRenderer::initialize() {

}

void FSEGTIONcursesRenderer::render(shared_ptr<FSEGTGameData> gameData) {

	clear();

	int cameraRendererWidth = 41;
	int cameraRendererHeight = 21;

	auto gameMap = gameData->gameMap;

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
			auto objects = objectsMap->objectsAtXY(x, y);

			if (objects.get() != nullptr && objects->size() > 0)
			{
				auto object = objects->objectAtIndex(0);
				auto printSymbol = FSEGTIONcursesRenderer::printSymbolFromObject(object);

				printw(printSymbol);
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

	for (auto i = 0; i < userInterfaceObjects->size(); i++)
	{
		auto object = userInterfaceObjects->objectAtIndex(i);
		auto text = FSEGTUtils::getText(object);
		printw("\n");
		printw(text->c_str());
	}

	refresh();
	std::this_thread::sleep_for(0.001s);
}

void FSEGTIONcursesRenderer::objectsContextObjectAdded(shared_ptr<FSEGTObjectsContext> context, shared_ptr<FSCObject> object)
{
	cout << object->getInstanceIdentifier()->c_str() << endl;

	if (object->getClassIdentifier()->compare("camera") == 0) {

		this->camera = object;

	}
	else if (object->getClassIdentifier()->compare(FSEGTConstObjectClassIdentifierOnScreenText) == 0) {

		userInterfaceObjects->addObject(object);

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