#include <iostream>

using namespace std;

#include "Controller.hpp"
#include "actors/Human.hpp"
#include "actors/Vampire.hpp"
#include "displayers/Displayer.hpp"

int main(int argc, char* argv[]) {
	const unsigned SIZE = 50;
	const unsigned NB_HUMANS = 20;
	const unsigned NB_VAMPIRES = 10;
	Displayer displayer;

//	size_t size = strtoul(argv[1], nullptr, 0);
//	size_t nbHumans = strtoul(argv[2], nullptr, 0);
//	size_t nbVampires = strtoul(argv[3], nullptr, 0);


	Controller controller(SIZE, SIZE, NB_HUMANS, NB_VAMPIRES, &displayer);
	controller.run();

	// TODO: le générique ne marche pas
//	const Humanoid* first = *field.begin();
//	Humanoid* closest = field.findClosestHumanoid<Human>(*first);


//	while (true)
//		field.nextTurn();

	return EXIT_SUCCESS;
}
