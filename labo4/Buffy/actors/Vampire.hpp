//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_VAMPIRE_HPP
#define BUFFY_VAMPIRE_HPP

#include "Humanoid.hpp"

class Vampire : public Humanoid {
public:
	Vampire(unsigned x, unsigned y);

	explicit Vampire(const Humanoid& other) noexcept;

	ActorType getType() const override;

	void setAction(const Field& field) override;

	void kill(Field& field) override;

	char getSymbol() const override;

	Color getColor() const override;
};

#endif // BUFFY_VAMPIRE_HPP
