//
// Created by Valentin Kaelin on 05.05.22.
//

#include <algorithm>
#include "Thief.hpp"
#include "../containers/Container.hpp"

using namespace std;

Thief::Thief(const string& name, const IndependantPerson& policeman) :
	DependantPerson(name), policeman(&policeman) {
}

bool Thief::isStateValid(const Container& container) const {
	return find(container.getPeople().begin(), container.getPeople().end(),
					policeman) == container.getPeople().end();
}
