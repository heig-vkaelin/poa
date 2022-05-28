//
// Created by valik on 27.05.2022.
//

#ifndef BUFFY_MOVE_HPP
#define BUFFY_MOVE_HPP

#include <vector>
#include "Action.hpp"
#include "../Utils/Position.hpp"

class Humanoid;

class Move : public Action {
public:
	Move(unsigned range, Humanoid& humanoid);

	void execute(Field& f) override;

private:
	std::vector<const Position*> getPossibleDirections(const Field& field) const;

	unsigned _range;
	Humanoid* humanoid;
};

#endif // BUFFY_MOVE_HPP
