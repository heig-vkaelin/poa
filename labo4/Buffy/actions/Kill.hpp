//
// Created by Alexandre Jaquier on 27.05.2022.
//

#ifndef BUFFY_KILL_HPP
#define BUFFY_KILL_HPP

#include "Action.hpp"

class Kill : public Action {
public:
	explicit Kill(Humanoid& humanoid);

	void execute(Field& field) override;
};

#endif // BUFFY_KILL_HPP
