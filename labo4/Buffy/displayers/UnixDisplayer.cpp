//
// Created by Valentin Kaelin on 19.05.22.
//

#include <iostream>
#include "UnixDisplayer.hpp"

using namespace std;

const string UnixDisplayer::BUFFY_COLOR("\033[1m\033[33m");
const string UnixDisplayer::HUMAN_COLOR("\033[35m");
const string UnixDisplayer::VAMPIRE_COLOR("\033[34m");

void UnixDisplayer::displayBuffy() const {
	cout << BUFFY_COLOR;
	Displayer::displayBuffy();
	resetColor();
}

void UnixDisplayer::displayHuman() const {
	cout << HUMAN_COLOR;
	Displayer::displayHuman();
	resetColor();
}

void UnixDisplayer::displayVampire() const {
	cout << VAMPIRE_COLOR;
	Displayer::displayVampire();
	resetColor();
}

void UnixDisplayer::resetColor() {
	cout << "\033[0m";
}
