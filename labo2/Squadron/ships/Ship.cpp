/**
 * Classe représentant un vaisseau de tout type
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include "Ship.hpp"

using namespace std;

ostream& operator<<(ostream& os, const Ship& ship) {
	return ship.toStream(os);
}

Ship::Ship(unsigned id) : id(id) {
}

void Ship::setNickname(const string& nick) {
	nickname = nick;
}

Ship::~Ship() {
	// TODO
}

ostream& Ship::toStream(ostream& os) const {
	return os << nickname << (nickname.empty() ? "" : " ")
				 << "[" << getModelName() << " #" << id << "]" << endl
				 << "  weight : " << getWeight() << " tons" << endl
				 << "  max speed : " << getMaxSpeed() << " MGLT" << endl;
}
