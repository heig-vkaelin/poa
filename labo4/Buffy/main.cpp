#include <iostream>

using namespace std;

#include "Controller.hpp"
#include "displayers/Displayer.hpp"
#include "displayers/UnixDisplayer.hpp"
#include "displayers/WindowsDisplayer.hpp"

int main(int argc, char* argv[]) {
	const unsigned SIZE = 15;
	const unsigned NB_HUMANS = 2;
	const unsigned NB_VAMPIRES = 1;

#if  defined(__linux__) || defined(__APPLE__)
	UnixDisplayer displayer(SIZE, SIZE);
#elif __WIN32
	WindowsDisplayer displayer(SIZE, SIZE);
#else
	Displayer displayer(SIZE, SIZE);
#endif

//	size_t size = strtoul(argv[1], nullptr, 0);
//	size_t nbHumans = strtoul(argv[2], nullptr, 0);
//	size_t nbVampires = strtoul(argv[3], nullptr, 0);

	Controller controller(SIZE, SIZE, NB_HUMANS, NB_VAMPIRES, &displayer);
	controller.run();

	return EXIT_SUCCESS;
}
