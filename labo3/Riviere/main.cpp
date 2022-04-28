#include "Controller.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
	Controller controller;
	controller.nextTurn();
	Controller::showMenu();
	controller.display();
	return EXIT_SUCCESS;
}
