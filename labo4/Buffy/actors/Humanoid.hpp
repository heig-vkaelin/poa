//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_HUMANOID_HPP
#define BUFFY_HUMANOID_HPP

#include "../actions/Action.hpp"
#include "../displayers/Displayer.hpp"
#include "ActorType.hpp"

class Field;

class Humanoid {
public:
	Humanoid(unsigned maxWidth, unsigned maxHeight);

	virtual ~Humanoid() = 0;

	virtual void display(const Displayer& displayer) const = 0;

	virtual ActorType getType() const = 0;

	virtual void setAction(const Field& field); // TODO: = 0

	virtual void executeAction(Field& field);

	virtual bool isAlive() const;

    void kill();

	unsigned getXPos() const;

	unsigned getYPos() const;

	void setPosition(unsigned x, unsigned y);

protected:
	Action* action;

private:
	unsigned x, y;
	bool alive;
};

#endif // BUFFY_HUMANOID_HPP
