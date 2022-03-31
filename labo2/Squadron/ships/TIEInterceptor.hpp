//
// Created by Valentin Kaelin on 24.03.22.
//

#ifndef SQUADRON_TIEINTERCEPTOR_HPP
#define SQUADRON_TIEINTERCEPTOR_HPP

#include "Ship.hpp"

class TIEInterceptor : public Ship {
public:
	TIEInterceptor();

	unsigned getMaxSpeed() const override;

	std::string getModelName() const override;

	double getWeight() const override;

private:
	static unsigned counter;
	const static std::string MODEL_NAME;
	const static unsigned MAX_SPEED; // en [MGLT]
	const static double WEIGHT; // en [tonnes]
};


#endif // SQUADRON_TIEINTERCEPTOR_HPP
