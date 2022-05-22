//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Displayer.hpp"
#include "../Field.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

void Displayer::clear() const {
	// TODO: surtout pour les couleurs par après
}

void Displayer::display(const Field& field) const {
	displayHorizontalBorder(field);
	for (size_t y = 0; y < field.getHeight(); y++) {
		cout << VERTICAL_BORDER;
		for (size_t x = 0; x < field.getWidth(); x++) {
			char content = EMPTY;
			for (Humanoid* humanoid: field) {
				if (humanoid->getXPos() == x && humanoid->getYPos() == y) {
					content = humanoid->getSymbol();
				}
			}
			cout << content;
		}
		cout << VERTICAL_BORDER << endl;
	}
	displayHorizontalBorder(field);
}

void Displayer::displayStats() const {
	// TODO: add real values
	int win = 50;
	int iterations = 10000;
	cout << "\rBuffy's win rate: " << left << setw(6) << setprecision(2) << fixed <<
		  win * 100 << "%s " << "(" << iterations << " iterations )" << endl;
}

void Displayer::displayPrompt(int turn, char quit, char stats, char next) {
	cout << '[' << turn << ']'
		  << quit << ")uit "
		  << stats << ")tatistics "
		  << next << ")ext: ";
}

void Displayer::displayHorizontalBorder(const Field& field) {
	cout << CORNER << setfill(HORIZONTAL_BORDER)
		  << setw((int)field.getWidth() + 1) << CORNER << endl;

	cout << setfill(EMPTY);
}
