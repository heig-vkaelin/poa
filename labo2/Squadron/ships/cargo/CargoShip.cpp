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

CargoShip::CargoShip(unsigned id, double cargo, double maxCargo) : Ship(id) {
	init(cargo, maxCargo);
}

double CargoShip::getCargo() const {
	return cargo;
}

void CargoShip::setCargo(double newCargo) {
	if (newCargo < 0)
		throw runtime_error("La cargaison est invalide.");

	if (newCargo > maxCargo)
		throw runtime_error("La cargaison est trop grosse pour le vaisseau.");

	cargo = newCargo;
}

ostream& CargoShip::toStream(ostream& os) const {
	return Ship::toStream(os) << setprecision(1)
									  << "  cargo: " << cargo << " tons (max : "
									  << maxCargo << ")" << endl;
}

void CargoShip::init(double carg, double maxCarg) {
	if (maxCarg < 0)
		throw runtime_error("La cargaison maximale est invalide.");

	maxCargo = maxCarg;
	setCargo(carg);
}
