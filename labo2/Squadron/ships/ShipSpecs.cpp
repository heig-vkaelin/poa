/**
 * Classe représentant les spécifications d'un modèle de vaisseau avec une cargaison
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include <stdexcept>
#include "ShipSpecs.hpp"

using namespace std;

ShipSpecs::ShipSpecs(const string& name, double speed, double weight) {
	init(name, speed, weight);
}

const string& ShipSpecs::getModelName() const {
	return modelName;
}

double ShipSpecs::getMaxSpeed() const {
	return maxSpeed;
}

double ShipSpecs::getWeight() const {
	return weight;
}

unsigned ShipSpecs::getNextId() {
	return ++counter;
}

void ShipSpecs::init(const string& name, double speed, double mass) {
	if (speed < 0)
		throw invalid_argument("Vitesse invalide");

	if (mass <= 0)
		throw invalid_argument("Poids invalide");

	modelName = name;
	maxSpeed = speed;
	weight = mass;
	counter = 0;
}
