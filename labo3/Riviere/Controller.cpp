//
// Created by Valentin Kaelin on 14.04.22.
//

#include "Controller.hpp"

using namespace std;

Controller::Controller() {
	turn = 0;
	leftBank = Bank("Gauche");
	rightBank = Bank("Droite");
	boat = Boat("Bateau");
	persons = list<Person>();
}

void Controller::showMenu() {

}

void Controller::display() {

}

void Controller::nextTurn() {
	++turn;
	// TODO: attendre input utilisateur
}

void Controller::init() {
	// TODO: ptr + init ou ref et constructeur
}
