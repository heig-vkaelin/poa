#include <iostream>
#include <stdexcept>
#include "Matrix.hpp"

using namespace std;

#define NUM_ARGS 6

int main(int argc, char* argv[]) {
   if (argc != NUM_ARGS)
      throw invalid_argument("Erreur: Il manque des arguments.");

   unsigned rows1, cols1, rows2, cols2, modulus;

   // TODO: Rendre tout clean
   try {
      for (int i = 1; i < argc; ++i) {
         if (stoi(argv[i]) < 0)
            throw exception();
      }
      rows1 = (unsigned) stoi(argv[1]);
      cols1 = (unsigned) stoi(argv[2]);
      rows2 = (unsigned) stoi(argv[3]);
      cols2 = (unsigned) stoi(argv[4]);
      modulus = (unsigned) stoi(argv[5]);
   } catch (exception& e) {
      throw invalid_argument("Erreur: Un argument n'est pas une valeur correcte.");
   }

   Matrix m1 = Matrix(rows1, cols1, modulus);
   Matrix m2 = Matrix(rows2, cols2, modulus);
   cout << m1 << endl;
   cout << m2 << endl;
   return 0;
}
