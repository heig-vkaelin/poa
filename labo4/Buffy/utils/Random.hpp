#ifndef BUFFY_RANDOM_HPP
#define BUFFY_RANDOM_HPP

#include <random>

/**
 * Classe permettant de générer facilement des nombres aléatoires
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Random {
public:
	/**
	 * Génère un nombre aléatoire entre 0 et max non compris
	 * @param max : borne supérieure
	 * @return le nombre aléatoire
	 * @throws invalid_argument si max <= 0
	 */
	static int generate(int max);

	/**
	 * Génère un nombre aléatoire dans l'intervalle [min, max[
	 * @param min : borne inférieure
	 * @param max : borne supérieure
	 * @return le nombre aléatoire
	 * @throws invalid_argument si max <= min
	 */
	static int generate(int min, int max);

	/**
	 * Génère un boolean true ou false
	 * @return le boolean aléatoire
	 */
	static bool generateBool();

private:
	static std::mt19937 generator;
};

#endif // BUFFY_RANDOM_HPP
