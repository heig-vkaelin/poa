#include "Controller.hpp"
#include <cstdlib>

int main() {
	Controller controller;
	Controller::showMenu();
	controller.display();
	while (!controller.hasEnded()) {
		controller.nextTurn();
	}
	return EXIT_SUCCESS;
}
