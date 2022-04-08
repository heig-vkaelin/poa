/**
 * Classe représentant un vaisseau de type Star Destroyer
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include "StarDreadnought.hpp"

CargoShipSpecs StarDreadnought::specs = CargoShipSpecs("Super-class Star Destroyer",
																		 40,
																		 9000000000, 250000);

StarDreadnought::StarDreadnought(double cargo)
	: CargoShip(&specs, cargo) {
}
