//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_BUFFY_HPP
#define BUFFY_BUFFY_HPP

#include "Humanoid.hpp"

class Buffy : public Humanoid {
public:
	Buffy(unsigned x, unsigned y);

	ActorType getType() const override;

	void setAction(const Field& field) override;

	char getSymbol() const override;

	Color getColor() const override;
};

#endif // BUFFY_BUFFY_HPP
