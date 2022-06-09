//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_WINDOWSDISPLAYER_HPP
#define BUFFY_WINDOWSDISPLAYER_HPP

#ifdef __WIN32

#include "Displayer.hpp"
#include <windows.h>

/**
 * Classe WindowsDisplayer
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class WindowsDisplayer : public Displayer {
public:
	/**
	 * Constructeur de la classe WindowsDisplayer
	 * @param x Largeur du Field
	 * @param y Hauteur du Field
	 */
	WindowsDisplayer(unsigned width, unsigned height);

	/**
	 * Méthode permettant d'afficher le Field
	 * @param field Field à afficher
	 */
	void display(const Humanoid* humanoid) const override;

private:
	/**
	 * Méthode permettant de récupérer la couleur actuelle d'écriture
	 * @return Couleur d'écriture actuelle
	 */
	static WORD getCurrentColor();

	/**
	 * Méthode permettant de récupérer la couleur dans un format affichable par Windows
	 * @param color Couleur à récupérer
	 * @return Couleur dans un format affichable par Windows
	 */
	static WORD getColor(Color color);

	/**
	 * Méthode permettant de changer la couleur d'écriture
	 * @param color Couleur à appliquer
	 */
	static void changeColor(WORD color);
};

#endif // __WIN32

#endif // BUFFY_WINDOWSDISPLAYER_HPP
