//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_HUMANOID_HPP
#define BUFFY_HUMANOID_HPP

#include "../actions/Action.hpp"

class Field;

class Humanoid {
public:
	virtual void setAction(const Field& field) = 0;

	virtual void executeAction(Field& field) = 0;

	virtual bool isAlive() const = 0;

	virtual ~Humanoid() = 0;

private:
	Action* action;
};

#endif // BUFFY_HUMANOID_HPP
