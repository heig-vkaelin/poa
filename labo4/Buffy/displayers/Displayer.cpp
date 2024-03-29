/**
 * Classe Displayer permettant d'afficher la simulation dans la console
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */

#include "Displayer.hpp"
#include "../Field.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Displayer::Displayer(unsigned width, unsigned height)
	: content(height, vector<const Humanoid*>(width, nullptr)) {
}

void Displayer::display(const Field& field) {
	Position position;
	const Humanoid** toDisplay;

	// Ajoute les acteurs à leur position
	for (auto humanoid: field) {
		position = humanoid->getPosition();
		content.at((unsigned)position.getY()).at((unsigned)position.getX())
			= humanoid;
	}

	displayHorizontalBorder(field);
	for (unsigned y = 0; y < field.getHeight(); y++) {
		cout << VERTICAL_BORDER;
		for (unsigned x = 0; x < field.getWidth(); x++) {
			toDisplay = &content.at(y).at(x);
			if (*toDisplay) {
				display(*toDisplay);
				*toDisplay = nullptr;
			} else
				cout << EMPTY;
		}
		cout << VERTICAL_BORDER << endl;
	}
	displayHorizontalBorder(field);
}

void Displayer::display(const Humanoid* humanoid) const {
	cout << humanoid->getSymbol();
}

void Displayer::displayStarting() const {
	cout << "Statistics are beeing calculated..." << endl;
}

void Displayer::displayStats(double winrate, unsigned total) const {
	cout << "\rBuffy's win rate: " << left << setw(6) << setprecision(2) << fixed <<
		  winrate << "% " << "(" << total << " iterations)" << endl;
}

void Displayer::displayPrompt(int turn, char quit, char stats, char next) {
	cout << "[" << turn << "] "
		  << quit << ")uit "
		  << stats << ")tatistics "
		  << next << ")ext: ";
}

void Displayer::displayHorizontalBorder(const Field& field) {
	cout << CORNER << setfill(HORIZONTAL_BORDER)
		  << setw((int)field.getWidth() + 1) << CORNER << endl;

	cout << setfill(EMPTY);
}
