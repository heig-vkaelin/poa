#include <iostream>
#include "Matrix.hpp"

int main() {
	std::cout << "Hello, World from Labo1!" << std::endl;


	Matrix m = Matrix(3, 4, 10);
	std::cout << m;

	Matrix m2 = Matrix(0, 0, 10);
	std::cout << m2;

	return 0;
}
