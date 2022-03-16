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

int main(int argc, char* argv[]) {
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

   cout << "The modulus is " <<  modulus << endl;

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

int test_main(int argc, char* argv[]) {
	Matrix test = Matrix(4, 3, 100);
	Matrix test2 = Matrix(2, 2, 100);
//	test2 = test;

	cout << test << endl;
	cout << test2 << endl;
	test.subtract(test2);
	cout << "test - test2" << endl;
	cout << test << endl;

	return EXIT_SUCCESS;
}
