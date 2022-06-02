//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_ACTION_HPP
#define BUFFY_ACTION_HPP

class Field;

class Humanoid;

class Action {
public:
	explicit Action(Humanoid& humanoid);

	virtual void execute(Field& f) = 0;

	virtual ~Action() = default;

protected:
	Humanoid* getHumanoid();

private:
	Humanoid* humanoid;
};

#endif // BUFFY_ACTION_HPP
