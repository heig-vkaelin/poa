//
// Created by Valentin Kaelin on 24.02.22.
//

#ifndef MATRIXRELOADED_MATRIX_H
#define MATRIXRELOADED_MATRIX_H

#include <iostream>


class Matrix {
	friend std::ostream &operator<<(std::ostream &lhs, const Matrix &rhs);

public:
	Matrix(unsigned width, unsigned height, unsigned modulus);

private:
	unsigned modulus;
	unsigned** data;
};


#endif // MATRIXRELOADED_MATRIX_H
