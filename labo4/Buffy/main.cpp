#include <iostream>
#include "Controller.hpp"
#include "displayers/Displayer.hpp"
#include "displayers/UnixDisplayer.hpp"
#include "displayers/WindowsDisplayer.hpp"

using namespace std;

/**
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
int main(int argc, char* argv[]) {
	const int NB_ARGS = 5;

	if (argc != NB_ARGS)
		cout << "Usage: " << argv[0]
			  << " <width> <height> <nbHumans> <nbVampires>" << endl;

	unsigned width, height, nbHumans, nbVampires;
	try {
		for (int i = 1; i < argc; ++i) {
			if (stoi(argv[i]) < 0) {
				// Vérification que les différentes tailles ne sont pas négatives
				throw exception();
			}
		}
		width = (unsigned)stoi(argv[1]);
		height = (unsigned)stoi(argv[2]);
		nbHumans = (unsigned)stoi(argv[2]);
		nbVampires = (unsigned)stoi(argv[3]);
	} catch (exception& e) {
		throw invalid_argument("Erreur: Un argument n'a pas une valeur positive.");
	}

#if  defined(__linux__) || defined(__APPLE__)
	UnixDisplayer displayer(width, height);
#elif __WIN32
	WindowsDisplayer displayer(width, height);
#else
	Displayer displayer(width, height);
#endif

	Controller controller(width, height, nbHumans, nbVampires, &displayer);
	controller.run();

	return EXIT_SUCCESS;
}
