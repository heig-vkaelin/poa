//
// Created by valik on 27.05.2022.
//

#include "Move.hpp"
#include "../Utils/Random.hpp"
#include "../actors/Humanoid.hpp"
#include "../Field.hpp"

using namespace std;

Move::Move(unsigned range, Humanoid& humanoid, const Humanoid* target)
	: Action(humanoid), range(range), target(target) {
}

void Move::execute(Field& field) {
	Position direction;
	Position newPosition = getHumanoid()->getPosition();

	for (unsigned i = 0; i < range; ++i) {
		if (target) {
			direction = *Position::getDirection(newPosition, target->getPosition());
		} else {
			vector<const Position*> directions = getPossibleDirections(newPosition,
																						  field);
			// TODO: remove these casts
			direction = *directions.at(
				(unsigned long)(Random::randomPosition(0, (int)directions.size()))
			);
		}
		newPosition.add(direction);
	}

	getHumanoid()->setPosition(newPosition);
}

vector<const Position*> Move::getPossibleDirections(const Position& position,
																	 const Field& field) const {
	vector<const Position*> possibleDirections;

	int x = position.getX();
	int y = position.getY();
	int maxX = (int)field.getWidth();
	int maxY = (int)field.getHeight();
	int reach = (int)range;

	if (x >= reach)
		possibleDirections.push_back(&Position::LEFT);
	if (x >= reach && y >= reach)
		possibleDirections.push_back(&Position::UP_LEFT);
	if (x >= reach && y < maxY - reach)
		possibleDirections.push_back(&Position::DOWN_LEFT);
	if (x < maxX - reach)
		possibleDirections.push_back(&Position::RIGHT);
	if (x < maxX - reach && y >= reach)
		possibleDirections.push_back(&Position::UP_RIGHT);
	if (x < maxX - reach && y < maxY - reach)
		possibleDirections.push_back(&Position::DOWN_RIGHT);
	if (y >= reach)
		possibleDirections.push_back(&Position::UP);
	if (y < maxY - reach)
		possibleDirections.push_back(&Position::DOWN);

	return possibleDirections;
}
