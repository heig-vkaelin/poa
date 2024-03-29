#ifndef RIVIERE_CONTROLLER_HPP
#define RIVIERE_CONTROLLER_HPP

#include "containers/Bank.hpp"
#include "containers/Boat.hpp"
#include "people/Person.hpp"
#include "Test.hpp"
#include <list>

/**
 * Classe gérant toute la logique globale du programme
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Controller {
	// Classe Test friend pour qu'elle puisse avoir accès aux messages d'erreur
	// privés
	friend class Test;

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
	static void displayError(const std::string& error);

	static std::string getErrorMessage(ErrorStatus status);

	static void displayBank(const Bank& bank, int width);

	void reset();

	void handleCommand(const std::string& command);

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

	static const std::string
		WIN_MESSAGE,
		INVALID_COMMAND,
		UNKNOWN_COMMAND,
		BOAT_FULL,
		BOAT_WITHOUT_DRIVER,
		PERSON_CANT_BE_MOVED;
};

#endif // RIVIERE_CONTROLLER_HPP
