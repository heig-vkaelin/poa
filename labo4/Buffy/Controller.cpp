//
// Created by Valentin Kaelin on 22.05.22.
//

#include "Controller.hpp"
#include "displayers/Displayer.hpp"
#include "Field.hpp"
#include "EndStatus.hpp"
#include <iostream>

using namespace std;

Controller::Controller(unsigned width, unsigned height,
							  unsigned nbHumans, unsigned nbVampires,
							  Displayer* displayer)
	: displayer(displayer), field(width, height, nbHumans, nbVampires),
	  turn(0), finished(false), width(width), height(height),
	  nbHumans(nbHumans), nbVampires(nbVampires) {
}

void Controller::run() {
	turn = 0;
	displayer->display(field);

	while (!finished) {
		handleCommand();
	}
}

void Controller::nextTurn() {
	turn = field.nextTurn();
	displayer->clear();
	displayer->display(field);
}

void Controller::handleCommand() {
	do {
		Displayer::displayPrompt(turn, QUIT, STATS, NEXT);

		string line;
		getline(cin, line);
		char input = (line.empty() ? NEXT : line[0]);

		switch ((char)tolower(input)) {
			case QUIT:
				quit();
				return;
			case STATS:
				statistics();
				return;
			case NEXT:
				nextTurn();
				return;
			default:
				break;
		}
	} while (true);
}

void Controller::quit() {
	finished = true;
}

void Controller::statistics() {
	displayer->displayStarting();
	unsigned wins = 0;
	for (unsigned i = 0; i < NB_SIMULATIONS; ++i) {
		Field simulation(width, height, nbHumans, nbVampires);

		while (simulation.isFinished() == EndStatus::RUNNING) {
			simulation.nextTurn();
		}

		if (simulation.isFinished() == EndStatus::WIN)
			++wins;
	}
	displayer->displayStats(wins * 100.0 / NB_SIMULATIONS, NB_SIMULATIONS);
}
