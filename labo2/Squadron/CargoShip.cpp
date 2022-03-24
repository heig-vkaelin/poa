//
// Created by Valentin Kaelin on 17.03.22.
//

#include "CargoShip.hpp"

using namespace std;

CargoShip::CargoShip(unsigned id, double cargo) : Ship(id), cargo(cargo) {
}

double CargoShip::getCargo() const {
	return cargo;
}

void CargoShip::setCargo(double newCargo) {
	cargo = newCargo;
}

ostream& CargoShip::toStream(ostream& os) const {
	return Ship::toStream(os) << "  cargo: " << cargo << " tons (max : "
									  << getMaxCargo() << ")";
}
