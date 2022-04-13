#ifndef SQUADRON_CARGOSHIPSPECS_HPP
#define SQUADRON_CARGOSHIPSPECS_HPP

#include <string>
#include "../ShipSpecs.hpp"

/**
 * Classe représentant les spécifications d'un modèle de vaisseau avec une cargaison
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class CargoShipSpecs : public ShipSpecs {
public:
	/**
	 * Construit des spécifications d'un modèle de vaisseau avec cargaison
	 * @param modelName : nom du modèle
	 * @param maxSpeed : vitesse maximale en [MGLT]
	 * @param weight : poids en [tonnes]
	 * @param maxCargo : cargaison maximale en [tonnes]
	 * @throws invalid_argument si un des paramètres numériques est < 0
	 */
	CargoShipSpecs(const std::string& modelName, double maxSpeed, double weight,
						double maxCargo);

	/**
	 * @return la cargaison maximale du vaisseau
	 */
	double getMaxCargo() const;

private:
	double maxCargo; // en [tonnes]
};

#endif // SQUADRON_CARGOSHIPSPECS_HPP
