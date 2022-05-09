/**
 * Conteneur représentant un bateau avec un capacité fixe
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

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

bool Boat::isFull() const {
	return getPeople().size() >= capacity;
}

bool Boat::hasDriver() {
	return any_of(getPeople().begin(), getPeople().end(),
					  [](const Person* person) {
						  return person->canDrive();
					  });
}
