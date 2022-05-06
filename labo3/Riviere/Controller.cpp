//
// Created by Valentin Kaelin on 14.04.22.
//

#include <iostream>
#include <iomanip>
#include <limits>
#include "Controller.hpp"
#include "people/IndependantPerson.hpp"
#include "people/Thief.hpp"
#include "people/Boy.hpp"
#include "people/Girl.hpp"

using namespace std;

Controller::Controller() : boat("Bateau", 2), leftBank("Gauche"),
									rightBank("Droite"),
									turn(0), ended(false) {
	// Personnes
	IndependantPerson* father = new IndependantPerson{"pere"};
	IndependantPerson* mother = new IndependantPerson{"mere"};
	Boy* paul = new Boy{"paul", *father, *mother};
	Boy* pierre = new Boy{"pierre", *father, *mother};
	Girl* julie = new Girl{"julie", *mother, *father};
	Girl* jeanne = new Girl{"jeanne", *mother, *father};
	IndependantPerson* policeman = new IndependantPerson{"policier"};
	Thief* thief = new Thief{"voleur", *policeman};

	people.emplace_back(father);
	people.emplace_back(mother);
	people.emplace_back(paul);
	people.emplace_back(pierre);
	people.emplace_back(julie);
	people.emplace_back(jeanne);
	people.emplace_back(policeman);
	people.emplace_back(thief);

	// Situation initiale
	leftBank.addPeople(people);
	boat.setBank(leftBank);
}

void Controller::display() const {
	const unsigned WIDTH = 59;
	cout
		<< setw(WIDTH) << setfill('-') << "" << endl
		<< leftBank << endl
		<< setw(WIDTH) << setfill('-') << "" << endl;

	if (boat.isDockedTo(leftBank))
		cout << boat;

	cout << endl << setw(WIDTH) << setfill('=') << "" << endl;

	if (boat.isDockedTo(rightBank))
		cout << boat;

	cout << endl
		  << setw(WIDTH) << setfill('-') << "" << endl
		  << rightBank << endl
		  << setw(WIDTH) << setfill('-') << "" << endl;

	// Remise à 0 du fill sur le stream
	cout.fill(0);
}

void Controller::nextTurn() {
	cout << turn << ">";
	char command;
	cin >> command;
	handleCommand(command);
	turn++;
	if (hasWon()) {
		// TODO: essayer de trouver mieux que cette dingz
		display();
		cout << "Bravo, vous avez termine la partie!" << endl;
		ended = true;
	}
	if (!hasEnded())
		display();
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

bool Controller::hasWon() const {
	return leftBank.empty() && boat.empty();
}

bool Controller::hasEnded() const {
	return ended;
}

Controller::~Controller() {
	for (const Person* person: people)
		delete person;
}

void Controller::init() {
	// TODO: ptr + init ou ref et constructeur
}

void Controller::reset() {
	boat.clear();
	leftBank.clear();
	rightBank.clear();
	leftBank.addPeople(people);
	boat.setBank(leftBank);
}

void Controller::handleCommand(char command) {
	switch (command) {
		case DISPLAY:
			display();
			break;
		case EMBARK: {
			if (boat.isFull()) {
				displayError("Le bateau est plein.");
				break;
			}
			movePerson(getCurrentBank(), boat);
			break;
		}
		case DISEMBARK: {
			movePerson(boat, getCurrentBank());
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
			displayError("Commande inconnue");
			break;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Controller::moveBoat() {
	if (boat.hasDriver())
		boat.setBank(boat.isDockedTo(leftBank) ? rightBank : leftBank);
	else
		displayError("Bateau sans conducteur");
}

void Controller::movePerson(Container& from, Container& to) {
	string name;
	cin >> name;
	const Person* person = from.findByName(name);
	if (!person) {
		displayError(name + " ne se trouve pas dans la rive.");
		return;
	}

	to.addPerson(*person);
	from.removePerson(*person);

	// On annule le déplacement de la personne s'il n'est pas valide
	if (!isGameStateValid()) {
		from.addPerson(*person);
		to.removePerson(*person);
	}
}

Bank& Controller::getCurrentBank() {
	return boat.isDockedTo(leftBank) ? leftBank : rightBank;
}

bool Controller::isGameStateValid() {
	for (const Person* person: getCurrentBank()) {
		if (!person->isStateValid(getCurrentBank())) {
			displayError(person->getErrorMessage());
			return false;
		}
	}

	for (const Person* person: boat) {
		if (!person->isStateValid(boat)) {
			displayError(person->getErrorMessage());
			return false;
		}
	}
	return true;
}

void Controller::displayError(const string& error) {
	cout << "### " << error << endl;
}
