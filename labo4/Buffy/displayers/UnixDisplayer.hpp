//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_UNIXDISPLAYER_HPP
#define BUFFY_UNIXDISPLAYER_HPP

#include <string>
#include "Displayer.hpp"

/**
 * Classe UnixDisplayer
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class UnixDisplayer : public Displayer {
public:
/**
	 * Constructeur de la classe UnixDisplayer
	 * @param x Largeur du Field
	 * @param y Hauteur du Field
	 */
	UnixDisplayer(unsigned width, unsigned height);

	/**
	 * Méthode permettant d'afficher le Field
	 * @param field Field à afficher
	 */
	void display(const Humanoid* humanoid) const override;

private:
	/**
	 * Méthode permettant de récupérer la couleur dans un format affichable par Unix
	 * @param color Couleur à récupérer
	 * @return Couleur dans un format affichable par Unix
	 */
	static std::string getColor(Color color);

	/**
	 * Méthode permettant de mettre la couleur par défaut
	 */
	static void resetColor();
};

#endif // BUFFY_UNIXDISPLAYER_HPP
