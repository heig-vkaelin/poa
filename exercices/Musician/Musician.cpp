//
// Created by Valentin Kaelin on 05.05.22.
//

#include <iostream>
#include <utility>
#include "Musician.hpp"
#include "Band.hpp"

using namespace std;

Musician::Musician(const string& name) {
	this->name = name;
}

string Musician::toString() const {
	string bandStr = "<none>";
	shared_ptr<Band> spBand = band.lock();
	if (spBand)
		bandStr = spBand->getName();
	return name + ", band: " + bandStr;
}

string Musician::getName() const {
	return name;
}

void Musician::setBand(std::shared_ptr<Band> _band) {
	band = std::move(_band);
}

Musician::~Musician() {
	cout << "~Musician(): " << name << endl;
}
