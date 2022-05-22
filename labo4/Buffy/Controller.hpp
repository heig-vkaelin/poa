//
// Created by Valentin Kaelin on 22.05.22.
//

#ifndef BUFFY_CONTROLLER_HPP
#define BUFFY_CONTROLLER_HPP

#include "Field.hpp"

class Displayer;

class Controller {
public:
	Controller(unsigned width, unsigned height,
				  unsigned nbHumans, unsigned nbVampires,
				  const Displayer* displayer = nullptr);

	void run();

private:
	void nextTurn();

	void quit();

	void statistics();

	void handleCommand();

	const Displayer* displayer;
	Field field;
	int turn;
	bool finished;

	unsigned width, height;
	unsigned nbHumans, nbVampires;

	static constexpr unsigned NB_SIMULATIONS = 10000;

	static constexpr char
		QUIT = 'q',
		STATS = 's',
		NEXT = 'n';
};

#endif // BUFFY_CONTROLLER_HPP
