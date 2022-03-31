#ifndef SQUADRON_TIEFIGHTER_HPP
#define SQUADRON_TIEFIGHTER_HPP

#include "Ship.hpp"

/**
 * Classe représentant un vaisseau de type Chasseur TIE
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class TIEFighter : public Ship {
public:
	TIEFighter();

	unsigned getMaxSpeed() const override;

	std::string getModelName() const override;

	double getWeight() const override;

private:
	static unsigned counter;
	const static std::string MODEL_NAME;
	const static unsigned MAX_SPEED; // en [MGLT]
	const static double WEIGHT; // en [tonnes]
};


#endif // SQUADRON_TIEFIGHTER_HPP
