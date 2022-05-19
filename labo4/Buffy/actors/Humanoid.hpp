//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_HUMANOID_HPP
#define BUFFY_HUMANOID_HPP

#include "../actions/Action.hpp"

class Field;

class Humanoid {
public:
	Humanoid(unsigned maxWidth, unsigned maxHeight);

	virtual void setAction(const Field& field);

	virtual void executeAction(Field& field);

	virtual bool isAlive() const;

	unsigned getXPos() const;

	unsigned getYPos() const;

	virtual ~Humanoid() = 0;

private:
	Action* action;
	unsigned x, y;
	bool alive;
};

#endif // BUFFY_HUMANOID_HPP
