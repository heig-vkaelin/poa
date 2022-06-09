//
// Created by Valentin Kaelin on 19.05.22.
//

#include "WindowsDisplayer.hpp"

#ifdef __WIN32

using namespace std;

WindowsDisplayer::WindowsDisplayer(unsigned width, unsigned height)
	: Displayer(width, height) {
}

void WindowsDisplayer::display(const Humanoid* humanoid) const {
	WORD savedColor = getCurrentColor();
	changeColor(getColor(humanoid->getColor()));
	Displayer::display(humanoid);
	changeColor(savedColor);
}

WORD WindowsDisplayer::getColor(Color color) {
	switch (color) {
		case Color::BLUE:
			return 0x0D;
		case Color::YELLOW:
			return 0x0E;
		case Color::PINK:
			return  0x01;
		default:
			return getCurrentColor();
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
