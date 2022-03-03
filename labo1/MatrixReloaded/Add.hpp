//
// Created by Valentin Kaelin on 03.03.22.
//

#ifndef MATRIXRELOADED_ADD_HPP
#define MATRIXRELOADED_ADD_HPP

#include "Operator.hpp"

class Add : public Operator {
public:
	int apply(int a, int b) const override;
};

#endif // MATRIXRELOADED_ADD_HPP
