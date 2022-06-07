//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_VAMPIRE_HPP
#define BUFFY_VAMPIRE_HPP

#include "Humanoid.hpp"

/**
 * Classe Vampire
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Vampire : public Humanoid {
public:
	/**
	 * Constructeur de la classe Vampire
	 * @param x Largeur du Field
	 * @param y Hauteur du Field
	 */
	Vampire(unsigned x, unsigned y);

	/**
	 * Constructeur de copie de la classe Vampire
	 * @param other Vampire à copier
	 */
	explicit Vampire(const Humanoid& other);

	/**
	 * Méthode permettant de choisir une action à effectuer
	 * @param field Field sur lequel l'action doit être effectuée
	 */
	void setAction(const Field& field) override;

	/**
	 * Méthode permettant de tuer le Vampire
	 * @param field Field sur lequel le Vampire se trouve
	 */
	void kill(Field& field) override;

	/**
	 * Méthode permettant de récupérer le symbole des Vampire
	 * @return Symbole des Vampire
	 */
	char getSymbol() const override;

	/**
	 * Méthode permettant de récupérer la couleur des Vampire
	 * @return Couleur des Vampire
	 */
	Color getColor() const override;
};

#endif // BUFFY_VAMPIRE_HPP
