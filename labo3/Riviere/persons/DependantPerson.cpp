//
// Created by Valentin Kaelin on 05.05.22.
//

#include "DependantPerson.hpp"

DependantPerson::DependantPerson(const std::string& name) : Person(name) {
}

bool DependantPerson::canDrive() const {
	return false;
}
