//
// Created by valik on 27.05.2022.
//

#ifndef BUFFY_DIRECTION_HPP
#define BUFFY_DIRECTION_HPP

class Direction {
public:
	Direction(const Direction& other) = delete;

	Direction& operator=(const Direction& other) = delete;

	static const Direction UP;
	static const Direction UP_LEFT;
	static const Direction LEFT;
	static const Direction DOWN_LEFT;
	static const Direction DOWN;
	static const Direction DOWN_RIGHT;
	static const Direction RIGHT;
	static const Direction UP_RIGHT;
	static const Direction NONE;

	static const Direction* getDirection(int fromX, int fromY, int toX, int toY);

	int getX() const;

	int getY() const;

private:
	int x;
	int y;

	Direction(int x, int y);
};

#endif // BUFFY_DIRECTION_HPP
