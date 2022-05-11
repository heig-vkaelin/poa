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
	return Container::toStream(os) << "< " << peopleToString() << " >";
}

bool Boat::isDockedTo(const Bank& isOnBank) const {
	return bank == &isOnBank;
}

void Boat::setBank(const Bank& newBank) {
	bank = &newBank;
}

bool Boat::isFull() const {
	return size() >= capacity;
}

bool Boat::hasDriver() const {
	return any_of(begin(), end(), [](const Person* person) {
		return person->canDrive();
	});
}
