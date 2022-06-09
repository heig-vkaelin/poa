//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_BUFFY_HPP
#define BUFFY_BUFFY_HPP

#include "Humanoid.hpp"

/**
 * Classe Buffy
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Buffy : public Humanoid {
public:
	/**
	 * Constructeur de la classe Buffy
	 * @param x Largeur du Field
	 * @param y Hauteur du Field
	 */
	Buffy(unsigned x, unsigned y);

	/**
	 * Méthode permettant de récupérer le symbole de Buffy
	 * @return Symbole de Buffy
	 */
	char getSymbol() const override;

	/**
	 * Méthode permettant de récupérer la couleur de Buffy
	 * @return Couleur de Buffy
	 */
	Color getColor() const override;

protected:
	/**
	 * Méthode permettant de choisir une action à effectuer
	 * @param field Field sur lequel l'action doit être effectuée
	 */
	Action* getNextAction(const Field& field) override;
};

#endif // BUFFY_BUFFY_HPP
