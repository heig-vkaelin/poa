//
// Created by Alexandre Jaquier on 19.05.2022.
//

#ifndef BUFFY_RANDOM_HPP
#define BUFFY_RANDOM_HPP

#include <random>

class Random {
public:
	static int randomPosition(int min, int max);

private:
   static std::random_device rand_dev;
	static std::mt19937 generator;
};

#endif // BUFFY_RANDOM_HPP
