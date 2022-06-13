/**
 * Classe Windows permettant d'afficher la simulation dans la console avec
 * des couleurs sur Windows
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */

#include "WindowsDisplayer.hpp"

#ifdef __WIN32

using namespace std;

WindowsDisplayer::WindowsDisplayer(unsigned width, unsigned height)
	: Displayer(width, height), defaultColor(getCurrentColor()) {
}

void WindowsDisplayer::display(const Humanoid* humanoid) const {
	changeColor(getColor(humanoid->getColor()));
	Displayer::display(humanoid);
	changeColor(defaultColor);
}

WORD WindowsDisplayer::getColor(Color color) const {
	switch (color) {
		case Color::BLUE:
			return 0x0D;
		case Color::YELLOW:
			return 0x0E;
		case Color::PINK:
			return 0x01;
		default:
			return defaultColor;
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

#endif // __WIN32
