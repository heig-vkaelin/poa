#include <algorithm>
#include "Matrix.hpp"
#include "Utils.hpp"
#include "Add.hpp"
#include "Subtract.hpp"
#include "Multiply.hpp"

using namespace std;

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

Matrix& Matrix::operator=(const Matrix& other) {
	if (&other != this) {
		replaceData(other.rows, other.columns, other);
	}
	return *this;
}

unsigned Matrix::get(unsigned row, unsigned column) const {
	if (row >= rows || column >= columns)
		return 0;
	return data[row][column];
}

Matrix Matrix::add(const Matrix& other) {
	Add op;
	applyOperator(other, op);
	return *this;
}

Matrix Matrix::subtract(const Matrix& other) {
	Subtract op;
	applyOperator(other, op);
	return *this;
}

Matrix Matrix::multiply(const Matrix& other) {
	Multiply op;
	applyOperator(other, op);
	return *this;
}

void Matrix::deleteData() {
	for (unsigned i = 0; i < rows; ++i) {
		delete[] data[i];
	}
	delete[] data;
}

void Matrix::replaceData(unsigned newRows, unsigned newCols, const Matrix& other) {
	unsigned** newData = new unsigned* [newRows];
	for (unsigned i = 0; i < newRows; i++) {
		newData[i] = new unsigned[newCols];
		for (unsigned j = 0; j < newCols; ++j) {
			newData[i][j] = other.get(i, j);
		}
	}

	deleteData();
	swap(data, newData);

	rows = newRows;
	columns = newCols;
}

void Matrix::applyOperator(const Matrix& other, const Operator& op) {
	if (other.modulus != modulus)
		throw std::invalid_argument("Les modulos ne sont pas compatibles.");

	unsigned maxRows = max(rows, other.rows);
	unsigned maxColumns = max(columns, other.columns);

	// Modification de la taille de la matrice nécessaire
	if (rows < maxRows || columns < maxColumns) {
		replaceData(maxRows, maxColumns, *this);
	}

	// Applique les opérations opérande par opérande
	for (unsigned row = 0; row < maxRows; ++row) {
		for (unsigned col = 0; col < maxColumns; ++col) {
			data[row][col] = Utils::floorMod(
				op.apply((int)data[row][col], (int)other.data[row][col]), (int)modulus
			);
		}
	}
}
