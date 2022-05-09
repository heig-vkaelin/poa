#ifndef RIVIERE_CONTROLLER_HPP
#define RIVIERE_CONTROLLER_HPP

#include "containers/Bank.hpp"
#include "containers/Boat.hpp"
#include "people/Person.hpp"
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
	 * On bloque la copie de la classe Controller
	 */
	Controller(const Controller&) = delete;

	/**
	 * On bloque la copie de la classe Controller
	 */
	Controller& operator=(const Controller&) = delete;

	/**
	 * Affiche l'état du bateau et des rives de la rivière
	 */
	void display() const;

	/**
	 * Affiche une erreur dans la console
	 * @param error : l'erreur à afficher
	 */
	static void displayError(const std::string& error);

	/**
	 * Passe au tour suivant
	 */
	void nextTurn();

	/**
	 * Affiche le menu d'aide du programme
	 */
	static void showMenu();

	/**
	 * @return true si le joueur a gagné le jeu
	 */
	bool hasWon() const;

	/**
	 * @return true si le programme doit être arrêté (demandé par l'utilisateur ou
	 * fin du jeu)
	 */
	bool hasEnded() const;

	/**
	 * Destructeur du controller, désalloue toute la mémoire
	 */
	~Controller();

private:
	void reset();

	void handleCommand(char command);

	void moveBoat();

	void movePerson(Container& from, Container& to);

	Bank& getCurrentBank();

	std::list<const Person*> people;
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
