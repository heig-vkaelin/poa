/**
 * Classe gérant toute la logique globale du programme
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include <iostream>
#include <iomanip>
#include <limits>
#include "Controller.hpp"
#include "people/IndependantPerson.hpp"
#include "people/Thief.hpp"
#include "people/Boy.hpp"
#include "people/Girl.hpp"

using namespace std;

const string Controller::WIN_MESSAGE = "Bravo, vous avez termine la partie!";
const string Controller::INVALID_COMMAND = "Commande invalide";
const string Controller::UNKNOWN_COMMAND = "Commande inconnue";
const string Controller::BOAT_FULL = "Le bateau est plein";
const string Controller::BOAT_WITHOUT_DRIVER = "Bateau sans conducteur";
const string Controller::PERSON_CANT_BE_MOVED = " ne peut pas etre deplace.";

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

	people = {father, mother, paul, pierre, julie, jeanne, policeman, thief};

	// Situation initiale
	leftBank.addPeople(people);
	boat.setBank(leftBank);
}

void Controller::display() const {
	const int WIDTH = 59;
	displayBank(leftBank, WIDTH);

	if (boat.isDockedTo(leftBank))
		cout << boat;

	cout << endl << setw(WIDTH) << setfill('=') << "" << endl;

	if (boat.isDockedTo(rightBank))
		cout << boat;

	cout << endl;
	displayBank(rightBank, WIDTH);

	// Remise à 0 du fill sur le stream
	cout.fill(' ');
}

void Controller::nextTurn() {
	cout << turn << ">";
	string command;
	cin >> command;
	handleCommand(command);
	turn++;
	if (hasWon()) {
		display();
		cout << WIN_MESSAGE << endl;
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

void Controller::displayError(const string& error) {
	cout << "### " << error << endl;
}

string Controller::getErrorMessage(ErrorStatus status) {
	switch (status) {
		case ErrorStatus::BOY_ERROR:
			return "garcon avec sa mere sans son pere";
		case ErrorStatus::GIRL_ERROR:
			return "fille avec son pere sans sa mere";
		case ErrorStatus::THIEF_ERROR:
			return "voleur avec membre de la famille sans policier";
		default:
			return "";
	}
}

void Controller::displayBank(const Bank& bank, int width) {
	cout
		<< setw(width) << setfill('-') << "" << endl
		<< bank << endl
		<< setw(width) << setfill('-') << "" << endl;

	// Remise à 0 du fill sur le stream
	cout.fill(' ');
}

void Controller::reset() {
	boat.clear();
	leftBank.clear();
	rightBank.clear();
	leftBank.addPeople(people);
	boat.setBank(leftBank);
	turn = 0;
}

void Controller::handleCommand(const string& command) {
	if (command.length() != 1) {
		displayError(INVALID_COMMAND);
		return;
	}
	switch (command[0]) {
		case DISPLAY:
			display();
			break;
		case EMBARK:
			if (boat.isFull()) {
				displayError(BOAT_FULL);
				break;
			}
			movePerson(getCurrentBank(), boat);
			break;
		case DISEMBARK:
			movePerson(boat, getCurrentBank());
			break;
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
			displayError(UNKNOWN_COMMAND);
			break;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Controller::moveBoat() {
	if (boat.hasDriver())
		boat.setBank(boat.isDockedTo(leftBank) ? rightBank : leftBank);
	else
		displayError(BOAT_WITHOUT_DRIVER);
}

void Controller::movePerson(Container& from, Container& to) {
	string name;
	cin >> name;
	const Person* person = from.findByName(name);
	if (!person) {
		displayError(name + PERSON_CANT_BE_MOVED);
		return;
	}

	to.addPerson(*person);
	from.removePerson(*person);

	// On annule le déplacement de la personne s'il n'est pas valide
	ErrorStatus status;
	if ((status = getCurrentBank().isValid()) != OK ||
		 (status = boat.isValid()) != OK) {
		displayError(getErrorMessage(status));
		from.addPerson(*person);
		to.removePerson(*person);
	}
}

Bank& Controller::getCurrentBank() {
	return boat.isDockedTo(leftBank) ? leftBank : rightBank;
}
