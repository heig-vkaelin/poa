/**
 * Classe représentant une personne indépendante qui peut conduire et qui n'a
 * besoin de personne
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include "IndependantPerson.hpp"

IndependantPerson::IndependantPerson(const std::string& name) : Person(name) {
}

bool IndependantPerson::canDrive() const {
	return true;
}

bool IndependantPerson::isStateValid(const Container&) const {
	return true;
}

ErrorStatus IndependantPerson::getErrorStatus() const {
	return OK;
}
