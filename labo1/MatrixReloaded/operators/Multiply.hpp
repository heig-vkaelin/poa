//
// Created by Valentin Kaelin on 03.03.22.
//

#ifndef MATRIXRELOADED_MULTIPLY_HPP
#define MATRIXRELOADED_MULTIPLY_HPP

#include "Operator.hpp"

class Multiply : public Operator {
public:
	int apply(int a, int b) const override;
};

#endif // MATRIXRELOADED_MULTIPLY_HPP
