//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Displayer.hpp"
#include "../Field.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

void Displayer::display(const Field& field) const {
	const Humanoid* humanoid;
	displayHorizontalBorder(field);
	for (unsigned y = 0; y < field.getHeight(); y++) {
		cout << VERTICAL_BORDER;
		for (unsigned x = 0; x < field.getWidth(); x++) {
			if ((humanoid = field.getHumanoidAt(x, y)) != nullptr) {
				humanoid->display(*this);
			} else {
				cout << EMPTY;
			}
		}
		cout << VERTICAL_BORDER << endl;
	}
	displayHorizontalBorder(field);
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

string Displayer::getActorSymbol(ActorType type) const {
	switch (type) {
		case ActorType::HUMAN:
			return "H";
		case ActorType::VAMPIRE:
			return "V";
		case ActorType::BUFFY:
			return "B";
	}
	return {};
}

void Displayer::displayHorizontalBorder(const Field& field) {
	cout << CORNER << setfill(HORIZONTAL_BORDER)
		  << setw((int)field.getWidth() + 1) << CORNER << endl;

	cout << setfill(EMPTY);
}
