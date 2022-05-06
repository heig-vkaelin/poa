//
// Created by Valentin Kaelin on 14.04.22.
//

#include <algorithm>
#include "Boat.hpp"

using namespace std;

Boat::Boat(const string& name, size_t capacity)
	: Container(name), bank(nullptr), capacity(capacity) {
}

ostream& Boat::toStream(ostream& os) const {
	return os << getName() << ": < " << peopleToString() << " >";
}

bool Boat::isDockedTo(const Bank& isOnBank) const {
	return bank == &isOnBank;
}

void Boat::setBank(const Bank& newBank) {
	bank = &newBank;
}

bool Boat::hasDriver() {
	return any_of(getPeople().begin(), getPeople().end(),
					  [](const Person* person) {
						  return person->canDrive();
					  });
}

bool Boat::addPerson(const Person& person) {
	return getPeople().size() < capacity && Container::addPerson(person);
}
