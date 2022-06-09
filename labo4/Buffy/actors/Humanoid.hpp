//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_HUMANOID_HPP
#define BUFFY_HUMANOID_HPP

#include "../actions/Action.hpp"
#include "../utils/Position.hpp"
#include "../displayers/Color.hpp"

//Déclaration de la classe Field
class Field;

/**
 * Classe Humanoid
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Humanoid {
public:
	/**
	 * Constructeur de la classe Humanoid
	 * @param maxWidth Largeur du Field
	 * @param maxHeight Hauteur du Field
	 */
	Humanoid(unsigned maxWidth, unsigned maxHeight);

	/**
	 * Constructeur de copie de la classe Humanoid
	 * @param humanoid Humanoid à copier
	 */
	Humanoid(const Humanoid& humanoid);

	/**
	 * Destructeur par défaut, virtuel pur de la classe Humanoid
	 */
	virtual ~Humanoid() = default;

	/**
	 * Méthode permettant d'assigner une action à effectuer
	 * @param field Field sur lequel l'action doit être effectuée
	 */
	void setAction(const Field& field);

	/**
	 * Méthode permettant d'executer l'action choisie
	 * @param field
	 */
	void executeAction(Field& field);

	/**
	 * Méthode permettant de savoir si le Humanoid est vivant
	 * @return true si le Humanoid est vivant, false sinon
	 */
	virtual bool isAlive() const;

	/**
	 * Méthode permettant de tuer l'Humanoid
	 * @param field Field sur lequel l'Humanoid se trouve
	 */
	virtual void kill(Field& field);

	/**
	 * Méthode permettant de récupérer la position de l'Humanoid
	 * @return Position de l'Humanoid
	 */
	Position getPosition() const;

	/**
	 * Méthode permettant de définir la position de l'humanoid
	 * @param position Nouvelle position de l'Humanoid
	 */
	void setPosition(Position position);

	/**
	 * Méthode permettant de récupérer le symbole de l'Humanoid
	 * @return Symbole de l'Humanoid
	 */
	virtual char getSymbol() const = 0;

	/**
	 * Méthode permettant de récupérer la couleur de l'Humanoid
	 * @return Couleur de l'Humanoid
	 */
	virtual Color getColor() const = 0;

protected:
	/**
	 * Méthode permettant de choisir une action à effectuer
	 * @param field Field sur lequel l'action doit être effectuée
	 */
	virtual Action* getNextAction(const Field& field) = 0;

private:
	/**
	 * Méthode permettant d'initialiser les attributs de l'Humanoid
	 * @param position Position de l'Humanoid
	 */
	void init(const Position& position);

	bool alive;
	Position position;
	Action* action;
};

#endif // BUFFY_HUMANOID_HPP
