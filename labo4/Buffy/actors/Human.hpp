//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_HUMAN_HPP
#define BUFFY_HUMAN_HPP

#include "Humanoid.hpp"

class Human : public Humanoid {
public:
	Human(unsigned x, unsigned y);

	void setAction(const Field& field) override;

	void kill(Field& field) override;

	char getSymbol() const override;

	Color getColor() const override;
};

#endif // BUFFY_HUMAN_HPP
