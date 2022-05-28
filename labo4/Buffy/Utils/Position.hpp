//
// Created by Valentin Kaelin on 28.05.22.
//

#ifndef BUFFY_POSITION_HPP
#define BUFFY_POSITION_HPP

class Position {
public:
	Position(int x, int y);

	int getX() const;

	int getY() const;

	Position& add(const Position& other);

	Position addVal(const Position& other) const;

	Position& multiply(int factor);

	Position multiplyVal(int factor) const;

	static double getDistance(const Position& from, const Position& to);

	static Position getRandomPosition(int maxX, int maxY);

	static const Position UP;
	static const Position UP_LEFT;
	static const Position LEFT;
	static const Position DOWN_LEFT;
	static const Position DOWN;
	static const Position DOWN_RIGHT;
	static const Position RIGHT;
	static const Position UP_RIGHT;
	static const Position NONE;

private:
	int x;
	int y;
};

#endif // BUFFY_POSITION_HPP
