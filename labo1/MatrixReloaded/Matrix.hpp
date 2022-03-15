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

	/**
	 * Constructeur de copie
	 * @param other : référence de la matrice à copier
	 */
	Matrix(const Matrix& other);

	/**
	 * Détruit les allocations dynamiques de la Matrice
	 */
	~Matrix();

	/**
	 * Opérateur d'affectation prenant la référence d'une autre matrice
	 *
	 * @param other : référence de la matrice
	 * @return la référence de la matrice dupliquée
	 */
	Matrix& operator=(const Matrix& other);

	/**
	 * Donne une valeur de la matrice à la position spécifiée
	 *
	 * @param row : ligne de la matrice
	 * @param column : colonne de la matrice
	 * @return la valeur cherchée de la matrice
	 */
	unsigned get(unsigned row, unsigned column) const;

	/**
	 * Effectue une addition composante par composante sur la matrice et retourne sa référence
	 *
	 * @param other : la matrice utilisée comme opérande
	 * @return la référence de la matrice appelant la méthode
	 */
	Matrix& add(const Matrix& other);

	/**
	 * Effectue une addition composante par composante sur une matrice locale et la retourne
	 *
	 * @param other : la matrice utilisée comme opérande
	 * @return la matrice résultante de l'opération
	 */
	Matrix addStatic(const Matrix& other) const;

	/**
	 * Effectue une addition composante par composante sur une matrice allouée dynamiquement et
	 * retourne son pointeur
	 *
	 * @param other : la matrice utilisée comme opérande
	 * @return le pointeur de la matrice résultante de l'opération
	 */
	Matrix* addDynamic(const Matrix& other) const;

	/**
	 * Effectue une soustraction composante par composante sur la matrice et retourne sa référence
	 *
	 * @param other : la matrice utilisée comme opérande
	 * @return la référence de la matrice appelant la méthode
	 */
	Matrix& subtract(const Matrix& other);

	/**
	 * Effectue une soustraction composante par composante sur une matrice locale et la retourne
	 *
	 * @param other : la matrice utilisée comme opérande
	 * @return la matrice résultante de l'opération
	 */
	Matrix subtractStatic(const Matrix& other) const;

	/**
	 * Effectue une soustraction composante par composante sur une matrice allouée dynamiquement et
	 * retourne son pointeur
	 *
	 * @param other : la matrice utilisée comme opérande
	 * @return le pointeur de la matrice résultante de l'opération
	 */
	Matrix* subtractDynamic(const Matrix& other) const;

	/**
	 * Effectue une multiplication composante par composante sur la matrice et retourne sa référence
	 *
	 * @param other : la matrice utilisée comme opérande
	 * @return la référence de la matrice appelant la méthode
	 */
	Matrix& multiply(const Matrix& other);

	/**
	 * Effectue une multiplication composante par composante sur une matrice locale et la retourne
	 *
	 * @param other : la matrice utilisée comme opérande
	 * @return la matrice résultante de l'opération
	 */
	Matrix multiplyStatic(const Matrix& other) const;

	/**
	 * Effectue une multiplication composante par composante sur une matrice allouée dynamiquement et
	 * retourne son pointeur
	 *
	 * @param other : la matrice utilisée comme opérande
	 * @return le pointeur de la matrice résultante de l'opération
	 */
	Matrix* multiplyDynamic(const Matrix& other) const;

private:
	unsigned rows;
	unsigned columns;
	unsigned modulus;
	unsigned** data;

	/**
	 * initialise tous les attributs de la matrice
	 *
	 * @param rows : nombre de lignes de la matrice
	 * @param columns : nombre de colonnes de la matrice
	 * @param modulus : modulo de la matrice
	 */
	void init(unsigned rows, unsigned columns, unsigned modulus);

	/**
	 * Détruit les tableaux alloués dynamiquement
	 */
	void deleteData();

	/**
	 * Initialise des valeurs aléatoires ou remplace les valeurs d'une matrice par celles d'une
	 * autre
	 *
	 * @param newRows : nouveau nombre de lignes de la matrice
	 * @param newCols : nouveau nombre de colonnes de la matrice
	 * @param other : pointeur sur une matrice à copier
	 */
	void replaceData(unsigned newRows, unsigned newCols, const Matrix* other);

	/**
	 * applique une opération avec l'opérateur et la matrice opérande passés en paramètre
	 *
	 * @param other : la matrice utilisée comme opérande
	 * @param op : la référence sur l'opérateur voulu
	 */
	void applyOperator(const Matrix& other, const Operator& op);
};

#endif // MATRIXRELOADED_MATRIX_HPP
