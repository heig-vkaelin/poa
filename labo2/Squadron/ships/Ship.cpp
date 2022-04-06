/**
 * Classe représentant un vaisseau de tout type
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include <iomanip>
#include <stdexcept>
#include <cmath>
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

double Ship::computeConsumption(double distance, double speed) const {
	if (speed > getMaxSpeed())
		throw runtime_error("La vitesse est trop rapide pour le vaisseau.");

	return cbrt(getWeight()) / 2 * log10(getWeight() * speed) * log10(distance + 1);
}

ostream& Ship::toStream(ostream& os) const {
	return os << fixed << setprecision(2)
				 << (nickname.empty() ? "" : nickname + " ")
				 << "[" << getModelName() << " #" << id << "]" << endl
				 << "  weight : " << getWeight() << " tons" << endl
				 << "  max speed : " << getMaxSpeed() << " MGLT" << endl;
}
