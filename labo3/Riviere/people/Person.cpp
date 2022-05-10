/**
 * Classe abstraite représentant une personne
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include "Person.hpp"

using namespace std;

Person::Person(const string& name) : name(name) {
}

bool Person::canDrive() const {
	return false;
}

string Person::getName() const {
	return name;
}
