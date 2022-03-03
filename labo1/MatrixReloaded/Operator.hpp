//
// Created by Valentin Kaelin on 03.03.22.
//

#ifndef MATRIXRELOADED_OPERATOR_HPP
#define MATRIXRELOADED_OPERATOR_HPP

class Operator {
public:
	Operator() = default;

	/**
     * @brief Applique une opération sur deux entiers
     *
     * @param i1 un entier
     * @param i2 un entier
     * @return le résultat de l'opération
     */
	virtual int apply(int a, int b) const = 0;
};

#endif // MATRIXRELOADED_OPERATOR_HPP
