//
// Created by Valentin Kaelin on 17.03.22.
//
#include "Squadron.hpp"

using namespace std;

Squadron::Squadron(const string& name) : name(name), size(0), leader(nullptr), head(nullptr) {}

Squadron& Squadron::operator+=(const Ship& ship) {
	auto member = new Member{ship, nullptr};
	if (head) {
		// TODO avec un itérateur
	} else {
		head = member;
	}
	return *this;
}

void Squadron::setName(const string& name) {
	this->name = name;
}
