//
// Created by Valentin Kaelin on 14.04.22.
//

#include "Boat.hpp"

using namespace std;

Boat::Boat(const string& name, size_t capacity)
	: Container(name), capacity(capacity) {
}

ostream& Boat::toStream(ostream& os) const {
	return os << getName() << ": < " << personsToString() << " >";
}

const Bank* Boat::getBank() const {
	return bank;
}

void Boat::setBank(const Bank* newBank) {
	bank = newBank;
}
