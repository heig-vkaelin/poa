//
// Created by valik on 27.05.2022.
//

#include "Direction.hpp"

const Direction Direction::UP(0, -1);
const Direction Direction::UP_LEFT(-1, -1);
const Direction Direction::UP_RIGHT(1, -1);
const Direction Direction::DOWN(0, 1);
const Direction Direction::DOWN_LEFT(-1, 1);
const Direction Direction::DOWN_RIGHT(1, 1);
const Direction Direction::LEFT(-1, 0);
const Direction Direction::RIGHT(1, 0);
const Direction Direction::NONE(0, 0);

const Direction* Direction::getDirection(int fromX, int fromY, int toX, int toY) {
	int tmpX = toX - fromX;
	int tmpY = toY - fromY;

	if (tmpX < 0 && tmpY < 0)
		return &UP_LEFT;
	if (tmpX < 0 && tmpY == 0)
		return &LEFT;
	if (tmpX < 0 && tmpY > 0)
		return &DOWN_LEFT;
	if (tmpX == 0 && tmpY < 0)
		return &UP;
	if (tmpX == 0 && tmpY == 0)
		return &NONE;
	if (tmpX == 0 && tmpY > 0)
		return &DOWN;
	if (tmpX > 0 && tmpY < 0)
		return &UP_RIGHT;
	if (tmpX > 0 && tmpY == 0)
		return &RIGHT;
	if (tmpX > 0 && tmpY > 0)
		return &DOWN_RIGHT;

	return &NONE;
}

int Direction::getX() const {
	return x;
}

int Direction::getY() const {
	return y;
}

Direction::Direction(int x, int y) : x(x), y(y) {
}
