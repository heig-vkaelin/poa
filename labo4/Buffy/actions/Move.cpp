//
// Created by valik on 27.05.2022.
//

#include "Move.hpp"
#include "../Utils/Random.hpp"
#include "../actors/Humanoid.hpp"
#include "../Field.hpp"

#include <iostream>

using namespace std;

Move::Move(unsigned int range, Humanoid& humanoid) {
	init(range, humanoid, nullptr);
}

Move::Move(unsigned range, Humanoid& humanoid, const Position& target) {
	init(range, humanoid, &target);
}

void Move::execute(Field& field) {
	Position direction;
	if (target) {
		direction = *Position::getDirection(humanoid->getPosition(), *target);
		cout << "direction: " << direction.getX() << " " << direction.getY() << endl;
	} else {
		vector<const Position*> directions = getPossibleDirections(field);
		// TODO: remove these casts
		direction = *directions.at(
			(unsigned long)(Random::randomPosition(0, (int)directions.size()))
		);
	}

	humanoid->setPosition(
		direction.multiplyVal((int)range).add(humanoid->getPosition())
	);
}

void Move::init(unsigned _range, Humanoid& _humanoid, const Position* _target) {
	range = _range;
	humanoid = &_humanoid;
	target = _target;
}

vector<const Position*> Move::getPossibleDirections(const Field& field) const {
	vector<const Position*> possibleDirections;

	int x = humanoid->getPosition().getX();
	int y = humanoid->getPosition().getY();
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
