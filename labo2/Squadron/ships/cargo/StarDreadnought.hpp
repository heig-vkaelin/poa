//
// Created by Valentin Kaelin on 17.03.22.
//

#ifndef SQUADRON_STARDREADNOUGHT_HPP
#define SQUADRON_STARDREADNOUGHT_HPP

#include "CargoShip.hpp"

class StarDreadnought : public CargoShip {
public:
	explicit StarDreadnought(double cargo);

	unsigned getMaxSpeed() const override;

	std::string getModelName() const override;

	double getWeight() const override;

	double getMaxCargo() const override;

private:
	static unsigned counter;
	const static std::string MODEL_NAME;
	const static unsigned MAX_SPEED;
	const static double WEIGHT;
	const static double MAX_CARGO;
};


#endif //SQUADRON_STARDREADNOUGHT_HPP
