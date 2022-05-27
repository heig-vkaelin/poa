//
// Created by Alexandre Jaquier on 19.05.2022.
//

#ifndef BUFFY_UTILS_HPP
#define BUFFY_UTILS_HPP

#include <random>

class Utils {
public:
	static int randomPosition(int min, int max);

	static double getDistance(int x1, int y1, int x2, int y2);
};

#endif // BUFFY_UTILS_HPP
