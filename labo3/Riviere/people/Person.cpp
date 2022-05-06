//
// Created by Valentin Kaelin on 14.04.22.
//

#include "Person.hpp"

using namespace std;

Person::Person(const string& name) : name(name) {
}

string Person::getName() const {
	return name;
}
