//
// Created by Valentin Kaelin on 14.04.22.
//

#include "Controller.hpp"

using namespace std;

Controller::Controller() : boat("Bateau"), leftBank("Gauche"), rightBank("Droite"),
									turn(0) {
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
