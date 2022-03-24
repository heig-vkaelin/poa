//
// Created by Valentin Kaelin on 17.03.22.
//

#include "CargoShip.hpp"

#include <iostream>

using namespace std;

CargoShip::CargoShip(unsigned maxSpeed, double weight, double cargo)
	: Ship(maxSpeed, weight), cargo(cargo) {
}

void CargoShip::setCargo(double newCargo) {
	cargo = newCargo;
}

ostream& CargoShip::toStream(ostream& os) const {
	// TODO: use maxCargo in static ? Instead of "MAX"
	return Ship::toStream(os) << "  cargo: " << cargo << " tons (max : "
									  << "MAX" << ")";
}

double CargoShip::getWeight() const {
	return Ship::getWeight() + cargo;
}
