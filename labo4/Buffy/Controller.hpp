#ifndef BUFFY_CONTROLLER_HPP
#define BUFFY_CONTROLLER_HPP

#include "Field.hpp"

class Displayer;

/**
 * Classe Controller gérant toute la logique globale du programme
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Controller {
public:
	/**
	 * Crée un nouveau contrôleur
	 * @param width : largeur du Field
	 * @param height : hauteur du Field
	 * @param nbHumans : nombre d'humains initial
	 * @param nbVampires : nombre de vampires initial
	 * @param displayer : potentiel afficheur
	 */
	Controller(unsigned width, unsigned height,
				  unsigned nbHumans, unsigned nbVampires,
				  Displayer* displayer = nullptr);

	/**
	 * Lance la simulation
	 */
	void run();

private:
	void nextTurn();

	void quit();

	void statistics();

	void handleCommand();

	Displayer* displayer;
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
