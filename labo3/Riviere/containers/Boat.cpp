//
// Created by Valentin Kaelin on 14.04.22.
//

#include "Boat.hpp"

Boat::Boat(const std::string& name) : Container(name) {
}

std::ostream& Boat::toStream(std::ostream& os) const {
	return os << getName() << ": < " << personsToString() << " >";
}

const Bank* Boat::getBank() const {
	return bank;
}

void Boat::setBank(const Bank* newBank) {
	bank = newBank;
}
