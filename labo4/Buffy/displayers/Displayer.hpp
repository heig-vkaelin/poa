#ifndef BUFFY_DISPLAYER_HPP
#define BUFFY_DISPLAYER_HPP

#include <string>
#include <vector>
#include "../actors/Humanoid.hpp"

class Field;

/**
 * Classe Displayer permettant d'afficher la simulation dans la console
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Displayer {
public:
	/**
	 * Crée un Displayer
	 * @param width : largeur du Field à afficher
	 * @param height : hauteur du Field à afficher
	 */
	Displayer(unsigned width, unsigned height);

	/**
	 * Affiche le Field ainsi que son contenu
	 * @param field : field à afficher
	 */
	virtual void display(const Field& field);

	/**
	 * Affiche l'humanoïde
	 * @param humanoid : humanoïde à afficher
	 */
	virtual void display(const Humanoid* humanoid) const;

	/**
	 * Affiche une message indiquant que le calcul des statistiques est en cours
	 */
	virtual void displayStarting() const;

	/**
	 * Affiche le résultat des statistiques
	 * @param winrate : pourcentage de victoire
	 * @param total : nombre total de parties
	 */
	virtual void displayStats(double winrate, unsigned total) const;

	/**
	 * Afficher le menu du programme
	 * @param turn : tour actuel
	 * @param quit : caractère représentant l'option quitter
	 * @param stats : caractère représentant l'option statistiques
	 * @param next : caractère représentant l'option tour suivant
	 */
	static void displayPrompt(int turn, char quit, char stats, char next);

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
