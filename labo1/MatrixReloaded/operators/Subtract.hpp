#ifndef MATRIXRELOADED_SUBTRACT_HPP
#define MATRIXRELOADED_SUBTRACT_HPP

#include "Operator.hpp"

/**
 * Classe représentant un opérateur de soustraction
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Subtract : public Operator {
public:
	int apply(int a, int b) const override;
};


#endif // MATRIXRELOADED_SUBTRACT_HPP
