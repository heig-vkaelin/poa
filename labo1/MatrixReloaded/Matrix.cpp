#include "Matrix.hpp"
#include "Utils.hpp"

std::ostream& operator<<(std::ostream& lhs, const Matrix& rhs) {
	for (unsigned row = 0; row < rhs.rows; ++row) {
		for (unsigned col = 0; col < rhs.columns; ++col) {
			lhs << rhs.data[row][col];
			if (col != rhs.columns)
				lhs << " ";
		}
		if (row != rhs.rows)
			lhs << std::endl;
	}
	return lhs;
}

Matrix::Matrix(unsigned rows, unsigned columns, unsigned modulus) {
	if (modulus == 0) {
		throw std::runtime_error("Le modulo ne peut pas être nul.");
	}

	this->rows = rows;
	this->columns = columns;
	this->modulus = modulus;

	// Création du contenu
	data = new unsigned* [rows];
	for (unsigned i = 0; i < rows; i++) {
		data[i] = new unsigned[columns];
	}

	// Insertion des valeurs aléatoires
	for (unsigned i = 0; i < rows; ++i) {
		for (unsigned j = 0; j < columns; ++j) {
			data[i][j] = Utils::getRandom(modulus);
		}
	}
}

Matrix::~Matrix() {
	for (unsigned i = 0; i < rows; ++i) {
		delete[] data[i];
	}
	delete[] data;
}


