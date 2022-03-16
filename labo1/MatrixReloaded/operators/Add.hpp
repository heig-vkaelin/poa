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
	long apply(long a, long b) const override;
};

#endif // MATRIXRELOADED_ADD_HPP
