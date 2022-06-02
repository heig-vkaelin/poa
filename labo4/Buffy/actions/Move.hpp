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
	Move(unsigned range, Humanoid& humanoid, const Humanoid* target = nullptr);

	void execute(Field& f) override;

private:
	std::vector<const Position*> getPossibleDirections(const Position& position,
																		const Field& field) const;

	unsigned range;
	const Humanoid* target;
};

#endif // BUFFY_MOVE_HPP
