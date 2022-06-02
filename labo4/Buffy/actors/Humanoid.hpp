//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_HUMANOID_HPP
#define BUFFY_HUMANOID_HPP

#include "../actions/Action.hpp"
#include "ActorType.hpp"
#include "../Utils/Position.hpp"
#include "../displayers/Color.hpp"

class Field;

class Humanoid {
public:
	Humanoid(unsigned maxWidth, unsigned maxHeight);

	Humanoid(const Humanoid& humanoid) noexcept;

	virtual ~Humanoid() = 0;

	virtual ActorType getType() const = 0;

	virtual void setAction(const Field& field) = 0;

	virtual void executeAction(Field& field);

	virtual bool isAlive() const;

	virtual void kill(Field& field);

	Position getPosition() const;

	void setPosition(Position position);

	virtual char getSymbol() const = 0;

	virtual Color getColor() const = 0;

protected:
	Action* action;

private:
	bool alive;
	Position position;
};

#endif // BUFFY_HUMANOID_HPP
