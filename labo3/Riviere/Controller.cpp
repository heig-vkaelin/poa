//
// Created by Valentin Kaelin on 14.04.22.
//

#include <iostream>
#include <iomanip>
#include <limits>
#include "Controller.hpp"
#include "persons/IndependantPerson.hpp"
#include "persons/Thief.hpp"
#include "persons/Boy.hpp"
#include "persons/Girl.hpp"

using namespace std;

Controller::Controller() : boat("Bateau", 2), leftBank("Gauche"),
									rightBank("Droite"),
									turn(0), ended(false) {
	// Personnes
	IndependantPerson* father = new IndependantPerson{"pere"};
	IndependantPerson* mother = new IndependantPerson{"mere"};
	Boy* paul = new Boy{"paul", mother, father};
	Boy* pierre = new Boy{"pierre", mother, father};
	Girl* julie = new Girl{"julie", mother, father};
	Girl* jeanne = new Girl{"jeanne", mother, father};
	IndependantPerson* policeman = new IndependantPerson{"policier"};
	Thief* thief = new Thief{"voleur", policeman};

	persons.emplace_back(father);
	persons.emplace_back(mother);
	persons.emplace_back(paul);
	persons.emplace_back(pierre);
	persons.emplace_back(julie);
	persons.emplace_back(jeanne);
	persons.emplace_back(policeman);
	persons.emplace_back(thief);

	// Situation initiale
	leftBank.addPersons(persons);
	boat.setBank(&leftBank);

	// TMP
	boat.addPerson(father);
}

void Controller::showMenu() {
	const int PADDING = 6;
	const char SPACE = ' ';
	cout << DISPLAY << setw(PADDING) << SPACE << ": afficher" << endl
		  << EMBARK << setw(PADDING) << "<nom>" << ": embarquer <nom>" << endl
		  << DISEMBARK << setw(PADDING) << "<nom>" << ": debarquer <nom>" << endl
		  << MOVE << setw(PADDING) << SPACE << ": deplacer bateau" << endl
		  << RESET << setw(PADDING) << SPACE << ": reinitialiser" << endl
		  << QUIT << setw(PADDING) << SPACE << ": quitter" << endl
		  << MENU << setw(PADDING) << SPACE << ": menu" << endl;
}

void Controller::display() const {
	const unsigned WIDTH = 59;
	cout
		<< setw(WIDTH) << setfill('-') << "" << endl
		<< leftBank << endl
		<< setw(WIDTH) << setfill('-') << "" << endl;

	if (boat.getBank() == &leftBank)
		cout << boat;

	cout << endl << setw(WIDTH) << setfill('=') << "" << endl;

	if (boat.getBank() == &rightBank)
		cout << boat;

	cout << endl
		  << setw(WIDTH) << setfill('-') << "" << endl
		  << rightBank << endl
		  << setw(WIDTH) << setfill('-') << "" << endl;

	cout.fill(0);
}

void Controller::nextTurn() {
	cout << turn << ">";
	char command;
	cin >> command;
	handleCommand(command);

	// TODO: seulement augmenter le tour s'il le faut
	turn++;
	display();
}

void Controller::init() {
	// TODO: ptr + init ou ref et constructeur
}

void Controller::reset() {
	boat.clear();
	leftBank.clear();
	rightBank.clear();
	leftBank.addPersons(persons);
	boat.setBank(&leftBank);
}

bool Controller::hasEnded() const {
	return ended;
}

void Controller::handleCommand(char command) {
	switch (command) {
		case DISPLAY:
			display();
			break;
		case EMBARK: {
			// TODO
			string name;
			cin >> name;
			break;
		}
		case DISEMBARK: {
			// TODO
			string name;
			cin >> name;
			break;
		}
		case MOVE:
			moveBoat();
			break;
		case RESET:
			reset();
			break;
		case QUIT:
			ended = true;
			break;
		case MENU:
			showMenu();
			break;
		default:
			cout << "Commande inconnue" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
	}
}

void Controller::moveBoat() {
	if (boat.hasDriver())
		boat.setBank(boat.getBank() == &leftBank ? &rightBank : &leftBank);
	else
		displayError("Bateau sans conducteur");
}

void Controller::displayError(const string& error) {
	cout << "### " << error << endl;
}
