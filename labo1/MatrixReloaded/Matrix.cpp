#include <algorithm>
#include "Matrix.hpp"
#include "Utils.hpp"
#include "Add.hpp"

using namespace std;

int floor_mod(int a, int b) {
	int res = a % b;
	return res < 0 ? res + b : res;
}

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

		// Insertion des valeurs aléatoires
		for (unsigned j = 0; j < columns; ++j) {
			data[i][j] = Utils::getRandom(modulus);
		}
	}
}

Matrix::~Matrix() {
	deleteData();
}

Matrix Matrix::add(const Matrix& other) {
	Add op;
	applyOperator(other, op);
	return *this;
}

void Matrix::deleteData() {
	for (unsigned i = 0; i < rows; ++i) {
		delete[] data[i];
	}
	delete[] data;
}


Matrix& Matrix::operator=(const Matrix& other) {
	if (&other != this) {
		replaceData(other);
	}
	return *this;
}

void Matrix::replaceData(const Matrix& other) {
	deleteData();

	rows = other.rows;
	columns = other.columns;
	modulus = other.modulus;

	data = new unsigned* [rows];
	for (unsigned i = 0; i < rows; i++) {
		data[i] = new unsigned[columns];
		for (unsigned j = 0; j < columns; ++j) {
			// Ou 0
			data[i][j] = other.data[i][j];
		}
	}
}

void Matrix::applyOperator(const Matrix& other, const Operator& op) {
	if (other.modulus != modulus)
		throw std::invalid_argument("Les modulos ne sont pas compatibles.");

	unsigned maxRows = max(rows, other.rows);
	unsigned maxColumns = max(columns, other.columns);

	if (rows < maxRows || columns < maxColumns) {
		rows = maxRows;
		columns = maxColumns;
		replaceData(*this);
	}

	for (unsigned row = 0; row < maxRows; ++row) {
		for (unsigned col = 0; col < maxColumns; ++col) {
			unsigned op1 = row >= rows || col >= columns ? 0 : data[row][col];
			unsigned op2 = row >= other.rows || col >= other.columns ? 0 :
								other.data[row][col];
			// TODO: test if mod ok
			data[row][col] = (unsigned)floor_mod(op.apply((int)op1, (int)op2),
															 (int)modulus);
		}
	}
}


