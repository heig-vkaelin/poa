//
// Created by Valentin Kaelin on 05.05.22.
//

#include <iostream>
#include <utility>
#include <sstream>
#include <memory>
#include "Band.hpp"

using namespace std;

Band::Band(string name) : name(move(name)), musicians() {}

void Band::setMembers(initializer_list<shared_ptr<Musician>> _musicians) {
	// Suppression de tous les membres de l'ancien groupe
	for (auto it = musicians.begin(); it != musicians.end();) {
		(*it)->removeBand();
		it = musicians.erase(it);
	}

	for (const auto& musician: _musicians) {
		// TODO: weak_from_this() ici
		if (musician->setBand(shared_from_this()))
			musicians.push_back(musician);
	}
}

string Band::getName() const {
	return name;
}

string Band::toString() const {
	stringstream ss;
	ss << name << ": ";
	for (const auto& m: musicians) {
		ss << m->getName() << " ";
	}
	return ss.str();
}

Band::~Band() {
	cout << "~Band(): " << name << endl;
}
