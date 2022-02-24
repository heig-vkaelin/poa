//
// Created by Valentin Kaelin on 24.02.22.
//

#ifndef MATRIXRELOADED_MATRIX_HPP
#define MATRIXRELOADED_MATRIX_HPP

#include <iostream>


class Matrix {
	friend std::ostream &operator<<(std::ostream &lhs, const Matrix &rhs);

public:
	Matrix(unsigned rows, unsigned columns, unsigned modulus);
	~Matrix();

private:
	unsigned rows;
	unsigned columns;
	unsigned modulus;
	unsigned** data;
};


#endif // MATRIXRELOADED_MATRIX_HPP
