/**
 * Classe représentant un vaisseau de type navette impériale
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include "Shuttle.hpp"

CargoShipSpecs Shuttle::specs = CargoShipSpecs("Lamda-class shuttle", 54, 360, 80);

Shuttle::Shuttle(double cargo) : CargoShip(&specs, cargo) {
}
