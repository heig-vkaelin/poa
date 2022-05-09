//
// Created by Valentin Kaelin on 05.05.22.
//

#include <algorithm>
#include "Thief.hpp"
#include "../containers/Container.hpp"

using namespace std;

const string Thief::ERROR_MESSAGE = "voleur avec membre de la famille sans policier";

Thief::Thief(const string& name, const IndependantPerson& policeman) :
	Person(name), policeman(&policeman) {
}

bool Thief::isStateValid(const Container& container) const {
	return container.size() == 1 ||
			 find(container.begin(), container.end(),
					policeman) != container.end();
}

string Thief::getErrorMessage() const {
	return ERROR_MESSAGE;
}
