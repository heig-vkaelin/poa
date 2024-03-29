/**
 * Point d'entrée du programme et différents tests
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include "Test.hpp"
#include "Controller.hpp"
#include <cstdlib>

using namespace std;

int main() {
//	Test::testEverything();
//	return EXIT_SUCCESS;

	Controller controller;
	Controller::showMenu();
	controller.display();

	while (!controller.hasEnded())
		controller.nextTurn();

	return EXIT_SUCCESS;
}
