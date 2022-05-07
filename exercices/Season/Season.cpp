//
// Created by Valentin Kaelin on 31.03.22.
//

#include "Season.hpp"

#include <cstring>
#include <stdexcept>

using namespace std;

const Season Season::Spring("Spring");
const Season Season::Summer("Summer");
const Season Season::Autumn("Autumn");
const Season Season::Winter("Winter");

const Season* Season::seasons[]{
	&Spring,
	&Summer,
	&Autumn,
	&Winter
};

size_t Season::counter = 0;

Season::Season(const char* n) {
	char* tmp = new char[strlen(n) + 1];
	strcpy(tmp, n);
	_name = tmp;
	ord = counter++;
}

const char* Season::name() const {
	return _name;
}

size_t Season::index() const {
	return ord;
}

const Season& Season::next() const {
	return *seasons[(ord + 1) % counter];
}

size_t Season::size() {
	return counter;
}

const Season& Season::get(size_t index) {
	if (index >= counter)
		throw out_of_range("Index invalide");

	return *seasons[index];
}

const Season** Season::values() {
	return seasons;
}

Season::~Season() {
	delete[] _name;
}
