#include <iostream>

using namespace std;

#include "Controller.hpp"
#include "actors/Human.hpp"
#include "actors/Vampire.hpp"
#include "displayers/Displayer.hpp"
#include "displayers/UnixDisplayer.hpp"
#include "displayers/WindowsDisplayer.hpp"

int main(int argc, char* argv[]) {
	const unsigned SIZE = 30;
	const unsigned NB_HUMANS = 20;
	const unsigned NB_VAMPIRES = 10;

#if  defined(__linux__) || defined(__APPLE__)
	UnixDisplayer displayer;
#elif __WIN32
	WindowsDisplayer displayer;
#else
	Displayer displayer;
#endif

//	size_t size = strtoul(argv[1], nullptr, 0);
//	size_t nbHumans = strtoul(argv[2], nullptr, 0);
//	size_t nbVampires = strtoul(argv[3], nullptr, 0);

	Controller controller(SIZE, SIZE, NB_HUMANS, NB_VAMPIRES, &displayer);
	controller.run();

	// TODO: le générique ne marche pas
//	const Humanoid* first = *field.begin();
//	Humanoid* closest = field.findClosestHumanoid<Human>(*first);

	return EXIT_SUCCESS;
}
