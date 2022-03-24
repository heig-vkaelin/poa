#include <cstdlib>
#include <iostream>
#include "Shuttle.hpp"
#include "Squadron.hpp"
#include "TIEFighter.hpp"

using namespace std;

int main() {
	cout << "Hello World from Labo2!" << endl;

	TIEFighter blackLeader;
	blackLeader.setNickname("Black leader");
	TIEFighter blackTwo;
	Shuttle shuttle(23.4); // 23.4 tonnes de marchandises

	Squadron squad("Black Squadron");
	squad += blackLeader;
	squad += blackTwo;
	squad += shuttle;

	squad.setLeader(blackLeader);

	cout << squad << endl;

	return EXIT_SUCCESS;
}
