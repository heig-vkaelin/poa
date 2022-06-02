//
// Created by Valentin Kaelin on 19.05.22.
//

#include "WindowsDisplayer.hpp"

#ifdef __WIN32

using namespace std;

WindowsDisplayer::WindowsDisplayer(unsigned width, unsigned height)
	: Displayer(width, height) {
}

void WindowsDisplayer::display(ActorType actor) const {
	WORD savedColor = getCurrentColor();
	changeColor(getColor(actor));
	Displayer::display(actor);
	changeColor(savedColor);
}

WORD WindowsDisplayer::getColor(ActorType actor) {
	switch (actor) {
		case ActorType::BUFFY:
			return BUFFY_COLOR;
		case ActorType::HUMAN:
			return HUMAN_COLOR;
		case ActorType::VAMPIRE:
			return VAMPIRE_COLOR;
		default:
			return getCurrentColor(); // TODO: comment dire ne rien mettre
	}
}

WORD WindowsDisplayer::getCurrentColor() {
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

#endif // __WIN32
