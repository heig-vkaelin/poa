//
// Created by valik on 27.05.2022.
//

#include "Move.hpp"
#include "../actors/Humanoid.hpp"
#include "../Field.hpp"
#include "../Utils/Utils.hpp"

using namespace std;

void Move::execute(Field& field) {
	vector<const Direction*> directions = getPossibleDirections(field);
	const Direction* direction = directions.at(
		Utils::randomPosition(0, (unsigned)directions.size())
	);
	// TODO: clean these conversions
	humanoid->setPosition(
		(unsigned)((int)humanoid->getXPos() + direction->getX() * (int)range),
		(unsigned)((int)humanoid->getYPos() + direction->getY() * (int)range)
	);
}

Move::Move(unsigned range, Humanoid& humanoid)
	: range(range), humanoid(&humanoid) {
}

vector<const Direction*> Move::getPossibleDirections(const Field& field) const {
	vector<const Direction*> possibleDirections;

	unsigned x = humanoid->getXPos();
	unsigned y = humanoid->getYPos();
	unsigned maxX = field.getWidth();
	unsigned maxY = field.getHeight();

	if (x >= range) {
		possibleDirections.push_back(&Direction::LEFT);
	}

	if (x >= range && y >= range) {
		possibleDirections.push_back(&Direction::UP_LEFT);
	}

	if (x >= range && y < maxY - range) {
		possibleDirections.push_back(&Direction::DOWN_LEFT);
	}

	if (x < maxX - range) {
		possibleDirections.push_back(&Direction::RIGHT);
	}

	if (x < maxX - range && y >= range) {
		possibleDirections.push_back(&Direction::UP_RIGHT);
	}

	if (x < maxX - range && y < maxY - range) {
		possibleDirections.push_back(&Direction::DOWN_RIGHT);
	}

	if (y >= range) {
		possibleDirections.push_back(&Direction::UP);
	}

	if (y < maxY - range) {
		possibleDirections.push_back(&Direction::DOWN);
	}

	return possibleDirections;
}
