/**
 * Point d'entrée du programme et différents tests
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include "Controller.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <list>

using namespace std;

/**
 *  Lance le test souhaité après avoir reçu une entrée utilisateur.
 *  Vérifie que les string souhaitées soient bien affichées
 * @param in : entrée utilisateur
 * @param needToBeDisplayed : liste des strings qui doivent s'afficher pour que le
 * test passe
 * @param debug : si vaut true, le déroulement du jeu est affiché
 * @return true si le test est passé, false sinon
*/
bool runTest(const istringstream& in, const list<string>& needToBeDisplayed,
				 bool debug = false) {
	cin.rdbuf(in.rdbuf());
	stringstream redirectStream;
	streambuf* oldBuffer = cout.rdbuf(redirectStream.rdbuf());

	Controller controller;
	Controller::showMenu();
	controller.display();
	while (!controller.hasEnded()) {
		controller.nextTurn();
	}

	cout.rdbuf(oldBuffer);

	if (debug)
		cout << redirectStream.str() << endl;

	for (const auto& toFind: needToBeDisplayed) {
		if (redirectStream.str().find(toFind) == string::npos)
			return false;
	}
	return true;
}

/**
 * Teste la bonne solution du jeu
 */
void correctSolution() {
	cout << "TEST: Solution complete du jeu : ";

	istringstream iss("e voleur\ne policier\nm\nd voleur\nm\ne jeanne\nm\n"
							"d policier\nd jeanne\ne voleur\ne policier\nm\nd policier\n"
							"d voleur\ne julie\ne mere\nm\nd julie\nm\ne pere\nm\n"
							"d mere\nm\nd pere\ne voleur\ne policier\nm\nd policier\n"
							"d voleur\ne mere\nm\ne pere\nm\nd mere\nm\ne paul\nm\n"
							"d pere\nd paul\ne voleur\ne policier\nm\nd policier\n"
							"d voleur\ne pierre\ne policier\nm\nd pierre\nm\ne voleur\n"
							"m\nd policier\nd voleur\nq");

	bool passed = runTest(iss, {
		"Bravo, vous avez termine la partie!"
	});
	cout << (passed ? "PASSED" : "FAILED") << endl;
}

void resetProgram() {
	cout << "TEST: Reset du jeu : ";

	istringstream iss("e voleur\ne policier\nm\nd voleur\nm\ne paul\nr\nq");

	bool passed = runTest(iss, {
		"<  >",
	});
	cout << (passed ? "PASSED" : "FAILED") << endl;
}

/**
 * Teste la règle qui dit que le garçon ne peut pas rester avec sa mère si son père
 * n'est pas là
 */
void boyWithMotherButWithoutFather() {
	cout << "TEST: Garcon avec sa mere mais sans son pere : ";

	istringstream iss("e pere\ne paul\ne pere\nq");

	bool passed = runTest(iss, {
		Controller::getErrorMessage(ErrorStatus::BOY_ERROR),
	});
	cout << (passed ? "PASSED" : "FAILED") << endl;
}

/**
 * Teste la règle qui dit que la fille ne peut pas rester avec son père si sa mère
 * n'est pas là
 */
void girlWithFatherButWithoutMother() {
	cout << "TEST: Fille avec son pere mais sans sa mere : ";

	istringstream iss("e mere\ne jeanne\ne mere\nq");

	bool passed = runTest(iss, {
		Controller::getErrorMessage(ErrorStatus::GIRL_ERROR),
	});
	cout << (passed ? "PASSED" : "FAILED") << endl;
}

/**
 * Teste qu'un bateau vide ne peut pas bouger de rive
 */
void emptyBoatCantMove() {
	cout << "TEST: Bateau vide ne peut pas bouger : ";
	istringstream iss("m\nq");

	bool passed = runTest(iss, {
		"Bateau sans conducteur",
	});
	cout << (passed ? "PASSED" : "FAILED") << endl;
}

/**
 * Teste qu'il puisse y avoir au maximum 2 personnes dans le bateau
 */
void onlyTwoPeopleOnTheBoat() {
	cout << "TEST: Bateau avec max 2 personnes : ";

	istringstream iss("e voleur\n e policier\n e paul\nq");

	bool passed = runTest(iss, {
		"Le bateau est plein",
	});
	cout << (passed ? "PASSED" : "FAILED") << endl;
}

/**
 * Teste que le voleur ne puisse pas être seul avec la famille sans le policier
 */
void thiefWithFamilyWithoutPoliceman() {
	cout << "TEST: voleur avec famille sans policier : ";

	istringstream iss("e policier\ne voleur\ne policier\nq");

	bool passed = runTest(iss, {
		Controller::getErrorMessage(ErrorStatus::THIEF_ERROR),
		"< voleur policier >",
	});
	cout << (passed ? "PASSED" : "FAILED") << endl;
}

/**
 * Teste que les enfants et le voleur ne puissent pas conduire le bateau
 */
void thiefAndChildrenCannotDriveTheBoat() {
	cout << "TEST: enfants et voleur ne peuvent pas conduire le bateau : ";

	istringstream iss1("e paul\nm\nq");
	istringstream iss2("e voleur\nm\nq");

	bool passed1 = runTest(iss1, {"Bateau sans conducteur"});
	bool passed2 = runTest(iss2, {"Bateau sans conducteur"});

	cout << (passed1 && passed2 ? "PASSED" : "FAILED") << endl;
}

/**
 * Lance tous les tests créés ci-dessus
 */
void testEverything() {
	correctSolution();
	resetProgram();
	boyWithMotherButWithoutFather();
	girlWithFatherButWithoutMother();
	emptyBoatCantMove();
	onlyTwoPeopleOnTheBoat();
	thiefWithFamilyWithoutPoliceman();
	thiefAndChildrenCannotDriveTheBoat();
}

int main() {
	testEverything();
	return EXIT_SUCCESS;

//	Controller controller;
//	Controller::showMenu();
//	controller.display();
//
//	while (!controller.hasEnded())
//		controller.nextTurn();
//
//	return EXIT_SUCCESS;
}
