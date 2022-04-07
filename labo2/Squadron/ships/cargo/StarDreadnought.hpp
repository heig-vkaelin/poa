#ifndef SQUADRON_STARDREADNOUGHT_HPP
#define SQUADRON_STARDREADNOUGHT_HPP

#include "CargoShip.hpp"

/**
 * Classe représentant un vaisseau de type Star Destroyer
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class StarDreadnought : public CargoShip {
public:
	/**
	 * Crée un nouveau Star Destroyer
	 * @param cargo : cargaison actuelle en [tonnes]
	 */
	explicit StarDreadnought(double cargo);

	double getMaxSpeed() const override;

	std::string getModelName() const override;

	double getWeight() const override;

private:
	static unsigned counter;
	const static std::string MODEL_NAME;
	const static double MAX_SPEED; // en [MGLT]
	const static double WEIGHT; // en [tonnes]
	const static double MAX_CARGO; // en [tonnes]
};


#endif // SQUADRON_STARDREADNOUGHT_HPP
