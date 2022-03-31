//
// Created by Valentin Kaelin on 17.03.22.
//

#ifndef SQUADRON_SHUTTLE_HPP
#define SQUADRON_SHUTTLE_HPP

#include "CargoShip.hpp"

class Shuttle : public CargoShip {
public:
	explicit Shuttle(double cargo);

	unsigned getMaxSpeed() const override;

	std::string getModelName() const override;

	double getWeight() const override;

	double getMaxCargo() const override;

private:
	static unsigned counter;
	const static std::string MODEL_NAME;
	const static unsigned MAX_SPEED; // en [MGLT]
	const static double WEIGHT; // en [tonnes]
	const static double MAX_CARGO; // en [tonnes]
};

#endif // SQUADRON_SHUTTLE_HPP
