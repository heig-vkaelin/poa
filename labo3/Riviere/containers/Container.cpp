//
// Created by Valentin Kaelin on 14.04.22.
//

#include "Container.hpp"

using namespace std;

Container::Container(const string& name) {
	this->name = name;
}

const string& Container::getName() const {
	return name;
}
