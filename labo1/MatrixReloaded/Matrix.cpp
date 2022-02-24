//
// Created by Valentin Kaelin on 24.02.22.
//

#include "Matrix.h"

std::ostream& operator<<(std::ostream& lhs, const Matrix& rhs) {
	// TODO: afficher la matrice
	return lhs;
}

Matrix::Matrix(unsigned width, unsigned height, unsigned modulus) {
	data = static_cast<unsigned int**>(calloc(height, sizeof(int*)));

	for (unsigned i = 0; i < height; i++)
		data[i] = static_cast<unsigned int*>(calloc(width, sizeof(int)));

	// TODO: TMP: hard-coded value
	unsigned counter = 1;
	for (unsigned i = 0; i < height; ++i) {
		for (unsigned j = 0; j < width; ++j) {
			data[i][j] = counter++;
		}
	}
}


