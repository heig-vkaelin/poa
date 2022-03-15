#ifndef MATRIXRELOADED_OPERATOR_HPP
#define MATRIXRELOADED_OPERATOR_HPP

/**
 * Classe représentant un opérateur arithmétique
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Operator {
public:
	Operator() = default;

	/**
     * Applique une opération sur deux entiers
     *
     * @param i1 un entier
     * @param i2 un entier
     * @return le résultat de l'opération
     */
	virtual int apply(int a, int b) const = 0;
};

#endif // MATRIXRELOADED_OPERATOR_HPP
