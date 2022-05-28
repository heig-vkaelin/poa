//
// Created by valik on 27.05.2022.
//

#include "Move.hpp"
#include "../actors/Humanoid.hpp"
#include "../Field.hpp"
#include "../Utils/Random.hpp"

using namespace std;

void Move::execute(Field& field) {
	vector<const Position*> directions = getPossibleDirections(field);
	// TODO: remove these casts
	const Position* direction = directions.at(
		(unsigned long)(Random::randomPosition(0, (int)directions.size()))
	);

	humanoid->setPosition(
		direction->multiplyVal((int)_range).add(humanoid->getPosition())
	);
}

Move::Move(unsigned range, Humanoid& humanoid)
	: _range(range), humanoid(&humanoid) {
}

vector<const Position*> Move::getPossibleDirections(const Field& field) const {
	vector<const Position*> possibleDirections;

	int x = humanoid->getPosition().getX();
	int y = humanoid->getPosition().getY();
	int maxX = (int)field.getWidth();
	int maxY = (int)field.getHeight();
	int range = (int)_range;

	if (x >= range)
		possibleDirections.push_back(&Position::LEFT);
	if (x >= range && y >= range)
		possibleDirections.push_back(&Position::UP_LEFT);
	if (x >= range && y < maxY - range)
		possibleDirections.push_back(&Position::DOWN_LEFT);
	if (x < maxX - range)
		possibleDirections.push_back(&Position::RIGHT);
	if (x < maxX - range && y >= range)
		possibleDirections.push_back(&Position::UP_RIGHT);
	if (x < maxX - range && y < maxY - range)
		possibleDirections.push_back(&Position::DOWN_RIGHT);
	if (y >= range)
		possibleDirections.push_back(&Position::UP);
	if (y < maxY - range)
		possibleDirections.push_back(&Position::DOWN);

	return possibleDirections;
}
