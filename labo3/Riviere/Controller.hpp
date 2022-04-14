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

	void showMenu();

private:
	void init();

	std::list<Person> persons;
	Boat boat;
	Bank leftBank;
	Bank rightBank;
	int turn;
};


#endif //RIVIERE_CONTROLLER_HPP
