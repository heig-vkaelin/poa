/**
 * Classe Position représentant une position dans la simulation en 2 dimensions
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */

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

Position Position::getDirection(const Position& to) const {
	int _x = to.x - x;
	int _y = to.y - y;

	return {
		_x == 0 ? 0 : _x / abs(_x),
		_y == 0 ? 0 : _y / abs(_y)
	};
}

int Position::getDistance(const Position& to) const {
	double first = abs((x - to.x));
	double second = abs((y - to.y));
	return (int)round(hypot(first, second));
}

Position Position::getRandomPosition(int maxX, int maxY) {
	return {
		Random::generate(maxX),
		Random::generate(maxY)
	};
}
