#ifndef SQUADRON_TIEINTERCEPTOR_HPP
#define SQUADRON_TIEINTERCEPTOR_HPP

#include "Ship.hpp"

/**
 * Classe représentant un vaisseau de type Intercepteur TIE
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class TIEInterceptor : public Ship {
public:
	TIEInterceptor();

	double getMaxSpeed() const override;

	std::string getModelName() const override;

	double getWeight() const override;

private:
	static unsigned counter;
	const static std::string MODEL_NAME;
	const static double MAX_SPEED; // en [MGLT]
	const static double WEIGHT; // en [tonnes]
};


#endif // SQUADRON_TIEINTERCEPTOR_HPP
