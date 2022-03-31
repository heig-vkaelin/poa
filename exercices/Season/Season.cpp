//
// Created by Valentin Kaelin on 31.03.22.
//

#include "Season.hpp"

#include <cstring>
#include <stdexcept>

using namespace std;

const Season& Season::Spring = Season("Spring");
const Season& Season::Summer = Season("Summer");
const Season& Season::Autumn = Season("Autumn");
const Season& Season::Winter = Season("Winter");

const Season* Season::seasons[]{
	&Season::Spring,
	&Season::Summer,
	&Season::Autumn,
	&Season::Winter
};

int Season::counter = 0;

Season::Season(const char* n) {
	size_t len = strlen(n);
	char* tmp = new char[len + 1];
	strcpy(tmp, n);
	_name = tmp;
	ord = counter++;
}

const char* Season::name() const {
	return _name;
}

int Season::index() const {
	return ord;
}

const Season& Season::next() const {
	return *seasons[(ord + 1) % counter];
}

int Season::size() {
	return counter;
}

const Season& Season::get(int index) {
	if (index >= counter)
		throw runtime_error("Index invalide");

	return *seasons[index];
}

const Season** Season::values() {
	return seasons;
}

Season::~Season() {
	delete[] _name;
}
