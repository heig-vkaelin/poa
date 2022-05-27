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

	static double getDistance(const Position& from, const Position& to);

	static Position getRandomPosition(int maxX, int maxY);

private:
	int x;
	int y;
};

#endif // BUFFY_POSITION_HPP
