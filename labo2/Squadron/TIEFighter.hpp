//
// Created by Valentin Kaelin on 17.03.22.
//

#ifndef SQUADRON_TIEFIGHTER_HPP
#define SQUADRON_TIEFIGHTER_HPP

#include "Ship.hpp"

class TIEFighter : public Ship {
public:
	TIEFighter() = default;

	unsigned getMaxSpeed() const override;

	std::string getModelName() const override;

	double getWeight() const override;

private:
	const static std::string MODEL_NAME;
	const static unsigned MAX_SPEED;
	const static double WEIGHT;
};


#endif //SQUADRON_TIEFIGHTER_HPP
