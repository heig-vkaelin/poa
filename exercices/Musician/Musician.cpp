//
// Created by Valentin Kaelin on 05.05.22.
//

#include <iostream>
#include <sstream>
#include "Musician.hpp"
#include "Band.hpp"

using namespace std;

Musician::Musician(const string& name) {
	this->name = name;
}

string Musician::toString() const {
	stringstream ss;
	auto b = band.lock();

	ss << name << ", band: " << (b ? b->getName() : "<none>");
	return ss.str();
}

string Musician::getName() const {
	return name;
}

bool Musician::setBand(const weak_ptr<Band>& _band) {
	shared_ptr<Band> b = band.lock();
	if (!b) {
		band = _band;
		return true;
	}
	cout << name << " is already in " << b->getName() << endl;
	return false;
}

void Musician::removeBand() {
	band.reset();
}

Musician::~Musician() {
	cout << "~Musician(): " << name << endl;
}
