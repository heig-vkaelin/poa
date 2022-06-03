//
// Created by Alexandre Jaquier on 19.05.2022.
//

#ifndef BUFFY_RANDOM_HPP
#define BUFFY_RANDOM_HPP

#include <random>

class Random {
public:
	/**
	 * Génère un nombre aléatoire entre 0 et max non compris
	 * @param max : borne supérieure
	 * @return le nombre aléatoire
	 */
	static int generate(int max);

	/**
	 * Génère un nombre aléatoire dans l'intervalle [min, max[
	 * @param min : borne inférieure
	 * @param max : borne supérieure
	 * @return le nombre aléatoire
	 */
	static int generate(int min, int max);

private:
	static std::random_device rand_dev;
	static std::mt19937 generator;
};

#endif // BUFFY_RANDOM_HPP
