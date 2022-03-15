#ifndef MATRIXRELOADED_MULTIPLY_HPP
#define MATRIXRELOADED_MULTIPLY_HPP

#include "Operator.hpp"

/**
 * Classe représentant un opérateur de multiplication
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Multiply : public Operator {
public:
	int apply(int a, int b) const override;
};

#endif // MATRIXRELOADED_MULTIPLY_HPP
