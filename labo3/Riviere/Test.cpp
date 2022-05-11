/**
 * Classe testant les différentes fonctionnalités et cas limites du programme
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include <iostream>
#include "Test.hpp"
#include "Controller.hpp"

using namespace std;

void Test::correctSolution(bool debug) {
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
	}, debug);
	cout << (passed ? "PASSED" : "FAILED") << endl;
}

void Test::resetProgram(bool debug) {
	cout << "TEST: Reset du jeu : ";

	istringstream iss("e voleur\ne policier\nm\nd voleur\nm\ne paul\nr\nq");

	bool passed = runTest(iss, {
		"<  >",
	}, debug);
	cout << (passed ? "PASSED" : "FAILED") << endl;
}

void Test::boyWithMotherButWithoutFather(bool debug) {
	cout << "TEST: Garcon avec sa mere mais sans son pere : ";

	istringstream iss("e pere\ne paul\ne pere\nq");

	bool passed = runTest(iss, {
		Controller::getErrorMessage(ErrorStatus::BOY_ERROR),
	}, debug);
	cout << (passed ? "PASSED" : "FAILED") << endl;
}

void Test::girlWithFatherButWithoutMother(bool debug) {
	cout << "TEST: Fille avec son pere mais sans sa mere : ";

	istringstream iss("e mere\ne jeanne\ne mere\nq");

	bool passed = runTest(iss, {
		Controller::getErrorMessage(ErrorStatus::GIRL_ERROR),
	}, debug);
	cout << (passed ? "PASSED" : "FAILED") << endl;
}

void Test::emptyBoatCantMove(bool debug) {
	cout << "TEST: Bateau vide ne peut pas bouger : ";
	istringstream iss("m\nq");

	bool passed = runTest(iss, {
		"Bateau sans conducteur",
	}, debug);
	cout << (passed ? "PASSED" : "FAILED") << endl;
}

void Test::onlyTwoPeopleOnTheBoat(bool debug) {
	cout << "TEST: Bateau avec max 2 personnes : ";

	istringstream iss("e voleur\n e policier\n e paul\nq");

	bool passed = runTest(iss, {
		"Le bateau est plein",
	}, debug);
	cout << (passed ? "PASSED" : "FAILED") << endl;
}

void Test::thiefWithFamilyWithoutPoliceman(bool debug) {
	cout << "TEST: voleur avec famille sans policier : ";

	istringstream iss("e policier\ne voleur\ne policier\nq");

	bool passed = runTest(iss, {
		Controller::getErrorMessage(ErrorStatus::THIEF_ERROR),
		"< voleur policier >",
	}, debug);
	cout << (passed ? "PASSED" : "FAILED") << endl;
}

void Test::thiefAndChildrenCannotDriveTheBoat(bool debug) {
	cout << "TEST: enfants et voleur ne peuvent pas conduire le bateau : ";

	istringstream iss1("e paul\nm\nq");
	istringstream iss2("e voleur\nm\nq");

	bool passed1 = runTest(iss1, {"Bateau sans conducteur"}, debug);
	bool passed2 = runTest(iss2, {"Bateau sans conducteur"}, debug);

	cout << (passed1 && passed2 ? "PASSED" : "FAILED") << endl;
}

void Test::testEverything(bool debug) {
	correctSolution(debug);
	resetProgram(debug);
	boyWithMotherButWithoutFather(debug);
	girlWithFatherButWithoutMother(debug);
	emptyBoatCantMove(debug);
	onlyTwoPeopleOnTheBoat(debug);
	thiefWithFamilyWithoutPoliceman(debug);
	thiefAndChildrenCannotDriveTheBoat(debug);
}

bool Test::runTest(const istringstream& in, const list<string>& needToBeDisplayed,
						 bool debug) {
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
