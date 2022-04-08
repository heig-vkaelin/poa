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

Ship::Ship(ShipSpecs* specifications) {
	if (specifications == nullptr)
		throw runtime_error("Specifications du vaisseau invalide.");

	specs = specifications;
	id = specs->getNextId();
}

void Ship::setNickname(const string& nick) {
	nickname = nick;
}

double Ship::computeConsumption(double distance, double speed) const {
	if (speed > getMaxSpeed())
		throw runtime_error("La vitesse est trop rapide pour le vaisseau.");

	return cbrt(getWeight()) / 2 * log10(getWeight() * speed) * log10(distance + 1);
}

string Ship::getModelName() const {
	return specs->getModelName();
}

double Ship::getMaxSpeed() const {
	return specs->getMaxSpeed();
}

double Ship::getWeight() const {
	return specs->getWeight();
}

ostream& Ship::toStream(ostream& os) const {
	return os << fixed << setprecision(2)
				 << (nickname.empty() ? "" : nickname + " ")
				 << "[" << getModelName() << " #" << id << "]" << endl
				 << "  weight : " << getWeight() << " tons" << endl
				 << setprecision(0)
				 << "  max speed : " << getMaxSpeed() << " MGLT" << endl;
}
