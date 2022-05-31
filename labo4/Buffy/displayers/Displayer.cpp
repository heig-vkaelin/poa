//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Displayer.hpp"
#include "../Field.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

Displayer::Displayer(unsigned width, unsigned height)
	: content(height, vector<ActorType>(width, ActorType::UNKNOWN)) {
}

void Displayer::display(const Field& field) {
	Position position;

	// Clear the content
	for (auto& v: content) {
		fill(v.begin(), v.end(), ActorType::UNKNOWN);
	}

	// Set content
	for (auto humanoid: field) {
		position = humanoid->getPosition();
		content.at((unsigned)position.getY()).at((unsigned)position.getX())
			= humanoid->getType();
	}

	displayHorizontalBorder(field);
	for (unsigned y = 0; y < field.getHeight(); y++) {
		cout << VERTICAL_BORDER;
		for (unsigned x = 0; x < field.getWidth(); x++)
			display(content.at(y).at(x));
		cout << VERTICAL_BORDER << endl;
	}
	displayHorizontalBorder(field);
}

void Displayer::display(ActorType actor) const {
	cout << getActorSymbol(actor);
}

void Displayer::displayBuffy() const {
	cout << BUFFY;
}

void Displayer::displayHuman() const {
	cout << HUMAN;
}

void Displayer::displayVampire() const {
	cout << VAMPIRE;
}

void Displayer::displayStats(unsigned wins, unsigned total) const {
	unsigned winrate = wins * 100 / total;
	cout << "\rBuffy's win rate: " << left << setw(6) << setprecision(2) << fixed <<
		  winrate << "% " << "(" << total << " iterations)" << endl;
}

void Displayer::displayPrompt(int turn, char quit, char stats, char next) {
	cout << "[" << turn << "] "
		  << quit << ")uit "
		  << stats << ")tatistics "
		  << next << ")ext: ";
}

void Displayer::clear() const {
	// TODO: surtout pour les couleurs par après
}

char Displayer::getActorSymbol(ActorType type) const {
	switch (type) {
		case ActorType::HUMAN:
			return HUMAN;
		case ActorType::VAMPIRE:
			return VAMPIRE;
		case ActorType::BUFFY:
			return BUFFY;
		case ActorType::UNKNOWN:
			return EMPTY;
	}
	return EMPTY;
}

void Displayer::displayHorizontalBorder(const Field& field) {
	cout << CORNER << setfill(HORIZONTAL_BORDER)
		  << setw((int)field.getWidth() + 1) << CORNER << endl;

	cout << setfill(EMPTY);
}
