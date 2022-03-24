//
// Created by Valentin Kaelin on 17.03.22.
//

#include "Ship.hpp"

using namespace std;

ostream& operator<<(ostream& os, const Ship& ship) {
	return ship.toStream(os);
}

void Ship::setNickname(const string& nick) {
	nickname = nick;
}

Ship::~Ship() {
	// TODO
}

ostream& Ship::toStream(ostream& os) const {
	return os << nickname << (nickname.empty() ? "" : " ")
				 << "[" << getModelName() << " #1]" << endl
				 << "  weight : " << getWeight() << " tons" << endl
				 << "  max speed : " << getMaxSpeed() << " MGLT" << endl;
}
