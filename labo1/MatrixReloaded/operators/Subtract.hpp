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
	long apply(long a, long b) const override;
};


#endif // MATRIXRELOADED_SUBTRACT_HPP
