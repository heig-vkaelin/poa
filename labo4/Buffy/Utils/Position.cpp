//
// Created by Valentin Kaelin on 28.05.22.
//

#include <cmath>
#include "Position.hpp"
#include "Random.hpp"

Position::Position(int x, int y) : x(x), y(y) {
}

int Position::getX() const {
	return x;
}

int Position::getY() const {
	return y;
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
