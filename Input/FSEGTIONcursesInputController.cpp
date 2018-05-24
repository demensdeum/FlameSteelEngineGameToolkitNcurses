#include "FSEGTIONcursesInputController.h"
#include <ncurses.h>
#include <iostream>

FSEGTIONcursesInputController::FSEGTIONcursesInputController() {

}

void FSEGTIONcursesInputController::pollKey() {

	FSEGTInputController::clearKeys();

	auto key = getch();

	switch (key) {

		case KEY_RIGHT:
			rightKeyPressed = true;
			break;

		case KEY_LEFT:
			leftKeyPressed = true;
			break;

		case KEY_UP:
			upKeyPressed = true;
			break;

		case KEY_DOWN:
			downKeyPressed = true;
			break;

		default:
			break;

	}
}