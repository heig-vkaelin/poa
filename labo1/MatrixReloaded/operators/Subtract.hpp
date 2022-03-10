//
// Created by Valentin Kaelin on 03.03.22.
//

#ifndef MATRIXRELOADED_SUBTRACT_HPP
#define MATRIXRELOADED_SUBTRACT_HPP

#include "Operator.hpp"

class Subtract : public Operator {
public:
	int apply(int a, int b) const override;
};


#endif // MATRIXRELOADED_SUBTRACT_HPP
