/**
 * Classe représentant un vaisseau avec une cargaison
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

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
									  << getMaxCargo() << ")" << endl;
}
