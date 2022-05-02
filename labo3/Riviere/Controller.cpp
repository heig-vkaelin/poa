//
// Created by Valentin Kaelin on 14.04.22.
//

#include <iostream>
#include <iomanip>
#include "Controller.hpp"

using namespace std;

Controller::Controller() : boat("Bateau"), leftBank("Gauche"), rightBank("Droite"),
									turn(0) {
	// Personnes
	Person* father = new Person{"pere"};
	Person* mother = new Person{"mere"};
	Person* paul = new Person{"paul"};
	Person* pierre = new Person{"pierre"};
	Person* julie = new Person{"julie"};
	Person* jeanne = new Person{"jeanne"};
	Person* policeman = new Person{"policier"};
	Person* thief = new Person{"voleur"};

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

void Controller::display() {
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
}

void Controller::nextTurn() {
	++turn;
	// TODO: attendre input utilisateur
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
