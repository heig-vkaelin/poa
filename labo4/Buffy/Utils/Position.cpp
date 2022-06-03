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

Position Position::getDirection(const Position& to) const {
	int _x = to.x - x;
	int _y = to.y - y;

	return {
		_x == 0 ? 0 : _x / abs(_x),
		_y == 0 ? 0 : _y / abs(_y)
	};
}

double Position::getDistance(const Position& to) const {
	return hypot(x - to.x, x - to.y);
}

Position Position::getRandomPosition(int maxX, int maxY) {
	return {
		Random::generate(maxX),
		Random::generate(maxY)
	};
}
