//
// Created by Valentin Kaelin on 28.05.22.
//

#ifndef BUFFY_POSITION_HPP
#define BUFFY_POSITION_HPP

class Position {
public:
	Position();

	Position(int x, int y);

	int getX() const;

	int getY() const;

	Position& add(const Position& other);

	Position addVal(const Position& other) const;

	Position& multiply(int factor);

	Position multiplyVal(int factor) const;

	Position getDirection(const Position& to) const;

	int getDistance(const Position& to) const;

	static Position getRandomPosition(int maxX, int maxY);

	static const Position
		UP,
		UP_LEFT,
		LEFT,
		DOWN_LEFT,
		DOWN,
		DOWN_RIGHT,
		RIGHT,
		UP_RIGHT;

private:
	int x;
	int y;
};

#endif // BUFFY_POSITION_HPP
