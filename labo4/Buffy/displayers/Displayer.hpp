//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_DISPLAYER_HPP
#define BUFFY_DISPLAYER_HPP

#include <string>
#include <vector>
#include "../actors/Humanoid.hpp"

class Field;

/**
 * Classe Displayer
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Displayer {
public:
	/**
	 * Constructeur de la classe Displayer
	 * @param width Largeur du Field à afficher
	 * @param height Hauteur du Field à afficher
	 */
	Displayer(unsigned width, unsigned height);

	/**
	 * Méthode permettant d'afficher le Field
	 * @param field Field à afficher
	 */
	virtual void display(const Field& field);

	/**
	 * Méthode permettant d'afficher un Humanoid
	 * @param humanoid Humanoid à afficher
	 */
	virtual void display(const Humanoid* humanoid) const;

	/**
	 * Méthode permettant d'afficher les statistiques
	 * @param wins Nombre de victoires
	 * @param total Nombre total de parties
	 */
	virtual void displayStats(unsigned wins, unsigned total) const;

	/**
	 * Méthode permettant d'afficher le menu
	 * @param turn Numéro du tour
	 * @param quit Caractère représentant l'option quitter
	 * @param stats Caractère représentant l'option statistiques
	 * @param next Caractère représentant l'option tour suivant
	 */
	static void displayPrompt(int turn, char quit, char stats, char next);

	/**
	 * Méthode permettant de nettoyer la console
	 */
	virtual void clear() const;

private:
	/**
	 * Méthode permettant d'afficher les bordure horizontale du Field
	 * @param field Field à afficher
	 */
	static void displayHorizontalBorder(const Field& field);

	//TODO commenter ça
	static constexpr char
		CORNER = '+',
		HORIZONTAL_BORDER = '-',
		VERTICAL_BORDER = '|',
		EMPTY = ' ';

	std::vector<std::vector<const Humanoid*>> content;
};

#endif // BUFFY_DISPLAYER_HPP
