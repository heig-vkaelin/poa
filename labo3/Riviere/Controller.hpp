#ifndef RIVIERE_CONTROLLER_HPP
#define RIVIERE_CONTROLLER_HPP

#include "containers/Bank.hpp"
#include "containers/Boat.hpp"
#include "persons/Person.hpp"
#include <list>

/**
 * Classe gérant toute la logique globale du programme
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Controller {
public:
	/**
	 * Crée un nouveau contrôleur qui gère le déroulement du programme
	 */
	Controller();

	/**
	 * Affiche l'état du bateau et des rives de la rivière
	 */
	void display() const;

	/**
	 * Passe au tour suivant
	 */
	void nextTurn();

	/**
	 * Affiche le menu d'aide du programme
	 */
	static void showMenu();

	/**
	 * @return true si le programme doit être arrêté
	 */
	bool hasEnded() const;

private:
	void init();

	void reset();

	void handleCommand(char command);

	void moveBoat();

	static void displayError(const std::string& error) ;

	std::list<const Person*> persons;
	Boat boat;
	Bank leftBank;
	Bank rightBank;
	int turn;
	bool ended;

	static const char
		DISPLAY = 'p',
		EMBARK = 'e',
		DISEMBARK = 'd',
		MOVE = 'm',
		RESET = 'r',
		QUIT = 'q',
		MENU = 'h';
};

#endif // RIVIERE_CONTROLLER_HPP
