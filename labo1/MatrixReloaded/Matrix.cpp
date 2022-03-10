#include <algorithm>
#include "Matrix.hpp"
#include "Utils.hpp"
#include "operators/Add.hpp"
#include "operators/Subtract.hpp"
#include "operators/Multiply.hpp"

using namespace std;

ostream& operator<<(ostream& lhs, const Matrix& rhs) {
	for (unsigned row = 0; row < rhs.rows; ++row) {
		for (unsigned col = 0; col < rhs.columns; ++col) {
			lhs << rhs.data[row][col];
			if (col != rhs.columns)
				lhs << " ";
		}
		if (row != rhs.rows)
			lhs << endl;
	}
	return lhs;
}

Matrix::Matrix(unsigned rows, unsigned columns, unsigned modulus) {
	init(rows, columns, modulus);
	replaceData(rows, columns, nullptr);
}

Matrix::Matrix(const Matrix& other) {
	if (this != &other) {
		init(rows, columns, modulus);
		replaceData(rows, columns, &other);
	}
}

Matrix::~Matrix() {
	deleteData();
}

Matrix& Matrix::operator=(const Matrix& other) {
	if (this != &other) {
		replaceData(other.rows, other.columns, &other);
	}
	return *this;
}

unsigned Matrix::get(unsigned row, unsigned column) const {
	if (row >= rows || column >= columns)
		return 0;
	return data[row][column];
}

void Matrix::add(const Matrix& other) {
	static Add op;
	applyOperator(other, op);
//	return *this;
}

void Matrix::subtract(const Matrix& other) {
	static Subtract op;
	applyOperator(other, op);
//	return *this;
}

void Matrix::multiply(const Matrix& other) {
	static Multiply op;
	applyOperator(other, op);
//	return *this;
}

Matrix Matrix::addStatic(const Matrix& other) const {
	Matrix result(*this);
	result.add(other);
	return result;
}

Matrix* Matrix::addDynamic(const Matrix& other) const {
	Matrix* result = new Matrix(*this);
	result->add(other);
	return result;
}

Matrix Matrix::subtractStatic(const Matrix& other) const {
	Matrix result(*this);
	result.subtract(other);
	return result;
}

Matrix* Matrix::subtractDynamic(const Matrix& other) const {
	Matrix* result = new Matrix(*this);
	result->subtract(other);
	return result;
}

Matrix Matrix::multiplyStatic(const Matrix& other) const {
	Matrix result(*this);
	result.multiply(other);
	return result;
}

Matrix* Matrix::multiplyDynamic(const Matrix& other) const {
	Matrix* result = new Matrix(*this);
	result->multiply(other);
	return result;
}

void Matrix::init(unsigned rows, unsigned columns, unsigned modulus) {
	if (modulus == 0) {
		throw runtime_error("Le modulo ne peut pas être nul.");
	}

	this->rows = rows;
	this->columns = columns;
	this->modulus = modulus;
	this->data = nullptr;
}

void Matrix::deleteData() {
	if (data != nullptr) {
		for (unsigned i = 0; i < rows; ++i) {
			delete[] data[i];
		}
		delete[] data;
	}
}

void Matrix::replaceData(unsigned newRows, unsigned newCols, const Matrix* other) {
	unsigned** newData = new unsigned* [newRows];
	for (unsigned i = 0; i < newRows; i++) {
		newData[i] = new unsigned[newCols];
		for (unsigned j = 0; j < newCols; ++j) {
			newData[i][j] = other == nullptr ?
								 Utils::getRandom(modulus) :
								 other->get(i, j);
		}
	}

	deleteData();
	swap(data, newData);

	rows = newRows;
	columns = newCols;
}

void Matrix::applyOperator(const Matrix& other, const Operator& op) {
	if (other.modulus != modulus)
		throw invalid_argument("Les modulos ne sont pas compatibles.");

	unsigned maxRows = max(rows, other.rows);
	unsigned maxColumns = max(columns, other.columns);

	// Modification de la taille de la matrice si nécessaire
	if (rows < maxRows || columns < maxColumns) {
		replaceData(maxRows, maxColumns, this);
	}

	// Applique les opérations opérande par opérande
	for (unsigned row = 0; row < maxRows; ++row) {
		for (unsigned col = 0; col < maxColumns; ++col) {
			data[row][col] = Utils::floorMod(
				op.apply((int)get(row, col), (int)other.get(row, col)), (int)modulus
			);
		}
	}
}
