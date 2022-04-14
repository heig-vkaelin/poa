/**
 * Classe représentant un vaisseau avec une cargaison
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include <stdexcept>
#include <iomanip>
#include "CargoShip.hpp"

using namespace std;

CargoShip::CargoShip(CargoShipSpecs* specifications, double cargo)
	: Ship(specifications) {
	specs = specifications;
	setCargo(cargo);
}

void CargoShip::setCargo(double newCargo) {
	if (newCargo < 0)
		throw invalid_argument("La cargaison est invalide.");

	if (newCargo > specs->getMaxCargo())
		throw invalid_argument("La cargaison est trop grosse pour le vaisseau.");

	cargo = newCargo;
}

double CargoShip::getCargo() const {
	return cargo;
}

double CargoShip::getWeight() const {
	return Ship::getWeight() + cargo;
}

ostream& CargoShip::toStream(ostream& os) const {
	return Ship::toStream(os) << setprecision(1)
									  << "  cargo: " << cargo << " tons (max : "
									  << specs->getMaxCargo() << ")" << endl;
}
