//
// Created by Alexandre Jaquier on 27.05.2022.
//

#ifndef BUFFY_KILL_HPP
#define BUFFY_KILL_HPP

#include "Action.hpp"

class Humanoid;

class Kill : public Action {
public:
	Kill(Humanoid& humanoid);

	void execute(Field& field) override;

private:
	Humanoid* humanoid;
};

#endif // BUFFY_KILL_HPP
