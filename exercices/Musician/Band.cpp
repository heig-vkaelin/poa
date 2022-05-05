//
// Created by Valentin Kaelin on 05.05.22.
//

#include "Band.hpp"

#include <iostream>
#include <utility>

using namespace std;

Band::Band(const std::string& name) {
	this->name = name;
}

void Band::setMembers(list<shared_ptr<Musician>> _musicians) {
	this->musicians = std::move(_musicians);

	for (auto& musician: this->musicians) {
		musician->setBand(shared_from_this());
	}
}

std::string Band::getName() const {
	return name;
}

std::string Band::toString() const {
	string result = name + ": ";
	for (auto& musician: musicians) {
		result += musician->getName() + " ";
	}
	return result;
}

Band::~Band() {
	cout << "~Band(): " << name << endl;
}
