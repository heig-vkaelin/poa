/**
 * Point d'entrée du programme
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include <iostream>
#include <stdexcept>
#include "Matrix.hpp"

using namespace std;

#define NUM_ARGS 6

/**
 * Teste qu'une exception est levée en cas d'opération entre deux matrices avec
 * des modules différents
 */
void testDifferentModulus() {
	cout << "TEST : Opération avec modulos différents" << endl;
	unsigned rows = 3;
	unsigned cols = 3;
	unsigned modulus1 = 4;
	unsigned modulus2 = 5;
	Matrix m1 = Matrix(rows, cols, modulus1);
	Matrix m2 = Matrix(rows, cols, modulus2);
	try {
		m1.add(m2);
	} catch (const exception& e) {
		cout << "Erreur levée lorsque les modulos ne correspondent pas: " << endl;
		cout << e.what() << endl;
		cout << "TEST PASSÉ" << endl;
	}
}

/**
 * Teste que la création et les opérations avec une matrice vide se passent
 * sans soucis
 */
void testEmptyMatrix() {
	cout << "TEST : Matrice vide" << endl;
	unsigned modulus = 4;

	Matrix m3 = Matrix(0, 0, modulus);
	cout << "Matrice vide multiplie une autre matrice :" << endl;
	try {
		Matrix m4 = Matrix(3, 3, modulus);
		m3.multiply(m4);
		cout << m3;
		cout << "TEST PASSÉ" << endl;
	} catch (const exception& e) {
		cout << "ERREUR: une addition avec une matrice vide ne devrait pas lever "
				  "d'exception" << endl;
	}
}

/**
 * Teste qu'une exception est levée à la création d'une matrice avec un modulo nul
 */
void testModulusZero() {
	cout << "TEST : Valeurs illégales" << endl;
	unsigned modulus = 0;
	try {
		Matrix m1 = Matrix(3, 4, modulus);
	} catch (const exception& e) {
		cout << "Erreur levée lors de la création d'une matrice avec des valeurs plus "
				  "grandes que le modulo - 1 : " << endl;
		cout << e.what() << endl;
		cout << "TEST PASSÉ" << endl;
	}
}

/**
 * Teste les opérations rendant une nouvelle matrice, retournée par valeur
 */
void testStaticOperations() {
	unsigned modulus = 10;
	cout << "TEST : Opérations statiques - modulo " << modulus << endl;
	Matrix m1(3, 4, modulus);
	Matrix m2(3, 4, modulus);

	cout << "Valeurs initiales m1" << endl;
	cout << m1 << endl;
	cout << "Valeurs initiales m2" << endl;
	cout << m2 << endl;

	cout << "m1 + m2" << endl;
	Matrix result = m1.addStatic(m2);
	cout << result << endl;

	cout << "Valeurs inchangées m1" << endl;
	cout << m1 << endl;
	cout << "Valeurs inchangées m2" << endl;
	cout << m2 << endl;
}

/**
 * Teste les opérations rendant une nouvelle matrice, retournée par pointeur
 */
void testDynamicOperations() {
	unsigned modulus = 10;

	cout << "TEST : Opérations dynamiques - modulo " << modulus << endl;
	Matrix m1(3, 4, modulus);
	Matrix m2(3, 4, modulus);

	cout << "Valeurs initiales m1" << endl;
	cout << m1 << endl;
	cout << "Valeurs initiales m2" << endl;
	cout << m2 << endl;

	cout << "m1 - m2" << endl;
	Matrix* result = m1.subtractDynamic(m2);
	cout << *result << endl;

	cout << "Valeurs inchangées m1" << endl;
	cout << m1 << endl;
	cout << "Valeurs inchangées m2" << endl;
	cout << m2 << endl;

	delete result;
}

/**
 * Teste les opérations qui modifient directement la matrice
 */
void testSelfOperations() {
	unsigned modulus = 10;

	cout << "TEST : Opérations dynamiques - modulo " << modulus << endl;
	Matrix m1(3, 4, modulus);
	Matrix m2(3, 4, modulus);

	cout << "Valeurs initiales m1" << endl;
	cout << m1 << endl;
	cout << "Valeurs initiales m2" << endl;
	cout << m2 << endl;

	cout << "m1 * m2" << endl;
	Matrix& result = m1.multiply(m2);
	cout << result << endl;

	cout << "Vérification que la matrice retournée est bien la même: ";
	cout << (&result == &m1 ? "OK!" : "ERREUR!!") << endl;

	cout << "Valeurs changées m1" << endl;
	cout << m1 << endl;
	cout << "Valeurs inchangées m2" << endl;
	cout << m2 << endl;
}

/**
 * Lance tous les tests
 */
void testEverything() {
	testDifferentModulus();
	cout << endl;
	testEmptyMatrix();
	cout << endl;
	testModulusZero();
	cout << endl;
	testStaticOperations();
	cout << endl;
	testDynamicOperations();
	cout << endl;
	testSelfOperations();
}

int main(int argc, char* argv[]) {
//	testEverything();
//	return EXIT_SUCCESS;

	if (argc != NUM_ARGS)
		throw invalid_argument("Erreur: Il manque des arguments.");

	unsigned rows1, cols1, rows2, cols2, modulus;

	try {
		for (int i = 1; i < argc; ++i) {
			if (stoi(argv[i]) < 0) {
				// Vérification que les différentes tailles ne sont pas négatives
				throw exception();
			}
		}
		rows1 = (unsigned)stoi(argv[1]);
		cols1 = (unsigned)stoi(argv[2]);
		rows2 = (unsigned)stoi(argv[3]);
		cols2 = (unsigned)stoi(argv[4]);
		modulus = (unsigned)stoi(argv[5]);
	} catch (exception& e) {
		throw invalid_argument("Erreur: Un argument n'a pas une valeur correcte.");
	}

	Matrix m1 = Matrix(rows1, cols1, modulus);
	Matrix m2 = Matrix(rows2, cols2, modulus);

	cout << "The modulus is " << modulus << endl;

	cout << "\none" << endl;
	cout << m1 << endl;

	cout << "two" << endl;
	cout << m2 << endl;

	cout << "one + two" << endl;
	cout << m1.addStatic(m2) << endl;

	cout << "one - two" << endl;
	cout << m1.subtractStatic(m2) << endl;

	cout << "one x two" << endl;
	cout << m1.multiplyStatic(m2) << endl;

	return EXIT_SUCCESS;
}
