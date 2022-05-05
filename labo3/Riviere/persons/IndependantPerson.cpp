//
// Created by Valentin Kaelin on 05.05.22.
//

#include "IndependantPerson.hpp"

IndependantPerson::IndependantPerson(const std::string& name) : Person(name) {
}

bool IndependantPerson::canDrive() const {
	return true;
}
