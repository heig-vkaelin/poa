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

	virtual void setAction(const Field& field) = 0;

	virtual void executeAction(Field& field) = 0;

	virtual bool isAlive() const = 0;

	virtual ~Humanoid() = 0;

    unsigned getXPos() const;

    unsigned getYPos() const;

private:
	Action* action;
    unsigned x, y;
};

#endif // BUFFY_HUMANOID_HPP
