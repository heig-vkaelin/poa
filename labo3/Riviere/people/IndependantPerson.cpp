/**
 * Classe représentant une personne indépendante
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
