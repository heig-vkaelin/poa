/**
 * Classe abstraite représentant une personne
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include <string>
#include "Person.hpp"

using namespace std;

const string Person::ERROR_MESSAGE;

Person::Person(const string& name) : name(name) {
}

bool Person::canDrive() const {
	return false;
}

string Person::getName() const {
	return name;
}

string Person::getErrorMessage() const {
	return ERROR_MESSAGE;
}
