#ifndef MATRIXRELOADED_MATRIX_HPP
#define MATRIXRELOADED_MATRIX_HPP

#include <iostream>
#include "operators/Operator.hpp"

/**
 * Classe permettant de modéliser une Matrice. Il est également possible de réaliser
 * diverses opérations arithmétiques sur deux Matrices.
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Matrix {
	/**
	 * Affiche la représentation de la Matrice
	 *
	 * @param lhs : flux sur lequel afficher la Matrice
	 * @param rhs : Matrice à afficher
	 * @return le flux d'affichage
	 */
	friend std::ostream& operator<<(std::ostream& lhs, const Matrix& rhs);

public:
	/**
	 * Constructeur de Matrice remplie de valeurs aléatoires selon le modulo choisi.
	 *
	 * @param rows : nombre de lignes de la matrice
	 * @param columns : nombre de colonnes de la matrice
	 * @param modulus : modulo de la matrice
	 */
	Matrix(unsigned rows, unsigned columns, unsigned modulus);

	Matrix(const Matrix& other);

	/**
	 * Détruit les allocations dynamiques de la Matrice
	 */
	~Matrix();

	Matrix& operator=(const Matrix& other);

	unsigned get(unsigned row, unsigned column) const;

	void add(const Matrix& other);

	Matrix addStatic(const Matrix& other) const;

	Matrix* addDynamic(const Matrix& other) const;

	void subtract(const Matrix& other);

	Matrix subtractStatic(const Matrix& other) const;

	Matrix* subtractDynamic(const Matrix& other) const;

	void multiply(const Matrix& other);

	Matrix multiplyStatic(const Matrix& other) const;

	Matrix* multiplyDynamic(const Matrix& other) const;

private:
	unsigned rows;
	unsigned columns;
	unsigned modulus;
	unsigned** data;

	void init(unsigned rows, unsigned columns, unsigned modulus);

	void deleteData();

	void replaceData(unsigned newRows, unsigned newCols, const Matrix* other);

	void applyOperator(const Matrix& other, const Operator& op);
};


#endif // MATRIXRELOADED_MATRIX_HPP
