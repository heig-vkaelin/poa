//
// Created by Valentin Kaelin on 17.03.22.
//

#include "CargoShip.hpp"

CargoShip::CargoShip(unsigned maxSpeed, double weight, double cargo)
	: Ship(maxSpeed, weight), cargo(cargo) {
}

void CargoShip::setCargo(double newCargo) {
	cargo = newCargo;
}
