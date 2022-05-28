//
// Created by Valentin Kaelin on 28.05.22.
//

#include <cmath>
#include "Position.hpp"
#include "Random.hpp"

const Position Position::UP(0, -1);
const Position Position::UP_LEFT(-1, -1);
const Position Position::UP_RIGHT(1, -1);
const Position Position::DOWN(0, 1);
const Position Position::DOWN_LEFT(-1, 1);
const Position Position::DOWN_RIGHT(1, 1);
const Position Position::LEFT(-1, 0);
const Position Position::RIGHT(1, 0);
const Position Position::NONE(0, 0);

Position::Position() : x(0), y(0) {}

Position::Position(int x, int y) : x(x), y(y) {
}

int Position::getX() const {
	return x;
}

int Position::getY() const {
	return y;
}

Position& Position::add(const Position& other) {
	x += other.x;
	y += other.y;
	return *this;
}

Position Position::addVal(const Position& other) const {
	return {x + other.x, y + other.y};
}

Position& Position::multiply(int factor) {
	x *= factor;
	y *= factor;
	return *this;
}

Position Position::multiplyVal(int factor) const {
	return {x * factor, y * factor};
}

double Position::getDistance(const Position& from, const Position& to) {
	return hypot(from.getX() - to.getX(), from.getY() - to.getY());
}

Position Position::getRandomPosition(int maxX, int maxY) {
	return {
		Random::randomPosition(0, maxX),
		Random::randomPosition(0, maxY)
	};
}

const Position* Position::getDirection(const Position& from, const Position& to) {
	int x = to.x - from.x;
	int y = to.y - from.y;

	if (x < 0 && y < 0)
		return &UP_LEFT;
	if (x < 0 && y == 0)
		return &LEFT;
	if (x < 0 && y > 0)
		return &DOWN_LEFT;
	if (x == 0 && y < 0)
		return &UP;
	if (x == 0 && y == 0)
		return &NONE;
	if (x == 0 && y > 0)
		return &DOWN;
	if (x > 0 && y < 0)
		return &UP_RIGHT;
	if (x > 0 && y == 0)
		return &RIGHT;
	if (x > 0 && y > 0)
		return &DOWN_RIGHT;

	return &NONE;
}
