#include <cstdlib>
#include <iostream>
#include "Squadron.hpp"
#include "ships/cargo/Shuttle.hpp"
#include "ships/TIEFighter.hpp"

using namespace std;

int main() {
	TIEFighter blackLeader;
	blackLeader.setNickname("Black leader");
	TIEFighter blackTwo;
	Shuttle shuttle(23.4); // 23.4 tonnes de marchandises

	Squadron squad("Black Squadron");
	squad += blackLeader;
	squad += blackTwo;
	squad += shuttle;

	squad.setLeader(blackLeader);

	cout << squad;

//	cout << squad[0] << endl << endl;

	cout << "Consommation: " << squad.computeConsumption(200, 40) << endl;

	return EXIT_SUCCESS;
}
