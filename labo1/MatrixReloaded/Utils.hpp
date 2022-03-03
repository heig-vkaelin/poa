#ifndef MATRIXRELOADED_UTILS_HPP
#define MATRIXRELOADED_UTILS_HPP

/**
 * Classe mettant à dispositions diverses fonctions utilitaires
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Utils {
public:
	/**
	 * Retourne un entier non signé aléatoire dans l'intervalle [0, max - 1]
	 * @param max : valeur maximale + 1
	 * @return le nombre aléatoire
	 */
	static unsigned getRandom(unsigned max);

	/**
	 * Une version du modulo sans résultat négatif
	 * @param a : opérande de gauche du modulo
	 * @param b : opérande de droite du modulo
	 * @return a modulo b
	 */
	static unsigned floorMod(int a, int b);
};


#endif // MATRIXRELOADED_UTILS_HPP
