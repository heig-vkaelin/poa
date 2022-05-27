//
// Created by Valentin Kaelin on 19.05.22.
//

#include "WindowsDisplayer.hpp"

using namespace std;

void WindowsDisplayer::displayBuffy() const {
	WORD savedColor = getColor();
	changeColor(BUFFY_COLOR);
	Displayer::displayBuffy();
	changeColor(savedColor);
}

void WindowsDisplayer::displayHuman() const {
	WORD savedColor = getColor();
	changeColor(HUMAN_COLOR);
	Displayer::displayHuman();
	changeColor(savedColor);
}

void WindowsDisplayer::displayVampire() const {
	WORD savedColor = getColor();
	changeColor(VAMPIRE_COLOR);
	Displayer::displayVampire();
	changeColor(savedColor);
}

WORD WindowsDisplayer::getColor() {
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	return info.wAttributes;
}

void WindowsDisplayer::changeColor(WORD color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void WindowsDisplayer::clear() const {
	// TODO: voir si utile
	system("cls");
}
