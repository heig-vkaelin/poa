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

	if (boat.isDockedTo(leftBank))
		cout << boat;

	cout << endl << setw(WIDTH) << setfill('=') << "" << endl;

	if (boat.isDockedTo(rightBank))
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
	leftBank.addPeople(people);
	boat.setBank(leftBank);
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
			string name;
			cin >> name;
			const Person* person = getCurrentBank().findByName(name);
			if (!person) {
				displayError(name + " ne se trouve pas dans la rive.");
				return;
			}

			getCurrentBank().removePerson(*person);
			bool successfullyAddedToBoat = boat.addPerson(*person);
			if (!successfullyAddedToBoat)
				displayError("Le bateau est plein!");

			// On annule le déplacement de la personne
			if (!isGameStateValid()) {
				boat.removePerson(*person);
				getCurrentBank().addPerson(*person);
				// TODO: afficher msg erreur en faisant:
//				displayError(person.getErrorMessage());
			}
			break;
		}
		case DISEMBARK: {
			string name;
			cin >> name;
			const Person* person = boat.findByName(name);
			if (!person) {
				displayError(name + " ne se trouve pas dans la rive.");
				return;
			}

			getCurrentBank().addPerson(*person);
			boat.removePerson(*person);
			if (!isGameStateValid()) {
				boat.addPerson(*person);
				getCurrentBank().removePerson(*person);
				// TODO: afficher msg erreur en faisant:
//				displayError(person.getErrorMessage());
			}
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
		boat.setBank(boat.isDockedTo(leftBank) ? rightBank : leftBank);
	else
		displayError("Bateau sans conducteur");
}

Bank& Controller::getCurrentBank() {
	return boat.isDockedTo(leftBank) ? leftBank : rightBank;
}

bool Controller::isGameStateValid() {
	bool valid = true;
	for (const Person* person: getCurrentBank().getPeople()) {
		if (!person->isStateValid(getCurrentBank()))
			return false;
	}
	for (const Person* person: boat.getPeople()) {
		if (!person->isStateValid(boat))
			return false;
	}
	return valid;
}

void Controller::displayError(const string& error) {
	cout << "### " << error << endl;
}
