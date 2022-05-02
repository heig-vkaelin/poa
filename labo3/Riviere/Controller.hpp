//
// Created by Valentin Kaelin on 14.04.22.
//

#ifndef RIVIERE_CONTROLLER_HPP
#define RIVIERE_CONTROLLER_HPP

#include "containers/Bank.hpp"
#include "containers/Boat.hpp"
#include "persons/Person.hpp"
#include <list>

class Controller {
public:
	Controller();

	void display();

	void nextTurn();

	static void showMenu();

	/**
	 * @return true si le programme doit être arrêté
	 */
	bool hasEnded();

private:
	void init();

	void reset();

	std::list<const Person*> persons;
	Boat boat;
	Bank leftBank;
	Bank rightBank;
	int turn;
	bool ended;

	static const char
		DISPLAY = 'p',
		EMBARK = 'e',
		DISEMBARK = 'd',
		MOVE = 'm',
		RESET = 'r',
		QUIT = 'q',
		MENU = 'h';
};


#endif // RIVIERE_CONTROLLER_HPP
