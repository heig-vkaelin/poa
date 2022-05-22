//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_ACTION_HPP
#define BUFFY_ACTION_HPP

class Field;

class Action {
public:
	virtual void execute(Field& f) = 0;
};

#endif // BUFFY_ACTION_HPP
