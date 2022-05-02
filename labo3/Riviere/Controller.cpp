//
// Created by Valentin Kaelin on 14.04.22.
//

#include <iostream>
#include "Controller.hpp"


using namespace std;

Controller::Controller() : boat("Bateau"), leftBank("Gauche"), rightBank("Droite"),
									turn(0) {
}

void Controller::showMenu() {
	cout
		<< "p      : afficher" << endl
		<< "e <nom>: embarquer <nom>" << endl
		<< "d <nom>: debarquer <nom>" << endl
		<< "m      : deplacer bateau" << endl
		<< "r      : reinitialiser" << endl
		<< "q      : quitter" << endl
		<< "h      : menu" << endl << endl;
}

void Controller::display() {
	cout
		<< "----------------------------------------------------------" << endl
		// << "Gauche: " << leftBank << endl
		<< "----------------------------------------------------------" << endl
		<< displayBoat(true) << endl
		<< "==========================================================" << endl
		<< displayBoat(false) << endl
		<< "----------------------------------------------------------" << endl
		// << "Droite:" << rightBank << endl
		<< "----------------------------------------------------------" << endl;
}

void Controller::nextTurn() {
	++turn;
	// TODO: attendre input utilisateur
}

void Controller::init() {
	// TODO: ptr + init ou ref et constructeur
}

std::string Controller::displayBoat(bool isOnLeftBank = true) {
	return isOnLeftBank ? "Bateau: <TODO>" : "";
}
