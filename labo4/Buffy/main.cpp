#include <iostream>

using namespace std;

#include "Field.hpp"
#include "actors/Human.hpp"
#include "actors/Vampire.hpp"

int main() {
	cout << "Hello, World from Labo4!" << endl;
	const unsigned SIZE = 50;
	const unsigned NB_HUMANS = 20;
	const unsigned NB_VAMPIRES = 10;
	Field field(SIZE, SIZE, NB_HUMANS, NB_VAMPIRES);

	const Humanoid* first = *field.begin();
	// TODO: le générique ne marche pas
//	Humanoid* closest = field.findClosestHumanoid<Human>(*first);


//	while (true)
//		field.nextTurn();

	return EXIT_SUCCESS;
}
