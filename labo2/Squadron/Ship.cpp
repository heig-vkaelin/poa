//
// Created by Valentin Kaelin on 17.03.22.
//

#include "Ship.hpp"

using namespace std;

ostream& operator<<(ostream& os, const Ship& ship) {
	return ship.toStream(os);
}

Ship::Ship(unsigned maxSpeed, double weight) : maxSpeed(maxSpeed), weight(weight) {
	// TODO: make a method to compute consumption
	consumption = 66;
}

void Ship::setNickname(const string& nick) {
	nickname = nick;
}

Ship::~Ship() {
	// TODO
}

ostream& Ship::toStream(ostream& os) const {
	// TODO, remove space before [
	// TODO: moddeName en static: CRASH
	return os << nickname << " [" << "MODELNAME" << " #1]" << endl
				 << "  weight : " << weight << " tons" << endl
				 << "  max speed : " << maxSpeed << " MGLT" << endl;
}

