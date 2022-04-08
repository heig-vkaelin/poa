#ifndef SQUADRON_SHIPSPECS_HPP
#define SQUADRON_SHIPSPECS_HPP

#include <string>

/**
 * Classe représentant les spécifications d'un modèle de vaisseau
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class ShipSpecs {
public:
	/**
	 * Construit des spécifications d'un modèle de vaisseau
	 * @param modelName : nom du modèle
	 * @param maxSpeed : vitesse maximale en [MGLT]
	 * @param weight : poids en [tonnes]
	 * @throws runtime_error si un des paramètres numériques est < 0
	 */
	ShipSpecs(const std::string& modelName, double maxSpeed, double weight);

	/**
	 * @return le nom du modèle
	 */
	const std::string& getModelName() const;

	/**
	 * @return la vitesse maximale en [MGLT]
	 */
	double getMaxSpeed() const;

	/**
	 * @return le poids du modèle en [tonnes]
	 */
	double getWeight() const;

	/**
	 * @return le prochain id du modèle du vaisseau
	 */
	unsigned getNextId();

private:
	void init(const std::string& modelName, double maxSpeed, double weight);

	std::string modelName;
	double maxSpeed; // en [MGLT]
	double weight; // en [tonnes]
	unsigned counter;
};

#endif // SQUADRON_SHIPSPECS_HPP
