/**
 * Classe UnixDisplayer permettant d'afficher la simulation dans la console avec
 * des couleurs sur les plateformes Unix
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */

#include <iostream>
#include "UnixDisplayer.hpp"

using namespace std;

UnixDisplayer::UnixDisplayer(unsigned width, unsigned height)
	: Displayer(width, height) {
}

void UnixDisplayer::display(const Humanoid* humanoid) const {
	cout << getColor(humanoid->getColor());
	Displayer::display(humanoid);
	resetColor();
}

string UnixDisplayer::getColor(Color color) {
	switch (color) {
		case Color::BLUE:
			return "\033[1m\033[34m";
		case Color::YELLOW:
			return "\033[1m\033[33m";
		case Color::PINK:
			return "\033[1m\033[35m";
		default:
			return "";
	}
}

void UnixDisplayer::resetColor() {
	cout << "\033[0m";
}
