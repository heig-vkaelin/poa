#include "Controller.hpp"
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
	Controller controller;
	Controller::showMenu();
	controller.display();
	while (!controller.hasEnded()) {
		controller.nextTurn();
	}
	return EXIT_SUCCESS;
}
