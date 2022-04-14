/**
 * Classe représentant les spécifications d'un modèle de vaisseau avec une cargaison
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include <stdexcept>
#include "CargoShipSpecs.hpp"

using namespace std;

CargoShipSpecs::CargoShipSpecs(const string& modelName, double maxSpeed,
										 double weight, double maxCargo)
	: ShipSpecs(modelName, maxSpeed, weight), maxCargo(maxCargo) {
	if (maxCargo < 0)
		throw invalid_argument("Cargaison maximale du vaisseau invalide.");
}

double CargoShipSpecs::getMaxCargo() const {
	return maxCargo;
}
