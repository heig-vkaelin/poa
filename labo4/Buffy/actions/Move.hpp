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

	Move(unsigned range, Humanoid& humanoid, const Position& target);

	void execute(Field& f) override;

private:
	void init(unsigned range, Humanoid& humanoid, const Position* target);

	std::vector<const Position*> getPossibleDirections(const Field& field) const;

	unsigned range;
	Humanoid* humanoid;
	const Position* target;
};

#endif // BUFFY_MOVE_HPP
