//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_HUMAN_HPP
#define BUFFY_HUMAN_HPP

#include "Humanoid.hpp"

/**
 * Classe Human
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Human : public Humanoid {
public:
	/**
	 * Constructeur de la classe Human
	 * @param x Largeur du Field
	 * @param y Hauteur du Field
	 */
	Human(unsigned x, unsigned y);

	/**
	 * Méthode permettant de tuer l'Human
	 * @param field Field sur lequel l'Human se trouve
	 */
	void kill(Field& field) override;

	/**
	 * Méthode permettant de récupérer le symbole des Human
	 * @return Symbole des Human
	 */
	char getSymbol() const override;

	/**
	 * Méthode permettant de récupérer la couleur des Human
	 * @return Couleur des Human
	 */
	Color getColor() const override;

protected:
	/**
	 * Méthode permettant de choisir une action à effectuer
	 * @param field Field sur lequel l'action doit être effectuée
	 */
	Action* getNextAction(const Field& field) override;
};

#endif // BUFFY_HUMAN_HPP
