#ifndef MATRIXRELOADED_ADD_HPP
#define MATRIXRELOADED_ADD_HPP

#include "Operator.hpp"

/**
 * Classe représentant un opérateur d'addition
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Add : public Operator {
public:
	int apply(int a, int b) const override;
};

#endif // MATRIXRELOADED_ADD_HPP
