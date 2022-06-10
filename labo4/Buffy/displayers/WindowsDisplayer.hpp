#ifndef BUFFY_WINDOWSDISPLAYER_HPP
#define BUFFY_WINDOWSDISPLAYER_HPP

#ifdef __WIN32

#include "Displayer.hpp"
#include <windows.h>

/**
 * Classe Windows permettant d'afficher la simulation dans la console avec
 * des couleurs sur Windows
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class WindowsDisplayer : public Displayer {
public:
	/**
	 * Crée un WindowsDisplayer spécifique à Windows
	 * @param width : largeur du Field à afficher
	 * @param height : hauteur du Field à afficher
	 */
	WindowsDisplayer(unsigned width, unsigned height);

	void display(const Humanoid* humanoid) const override;

private:
	static WORD getCurrentColor();

	static WORD getColor(Color color);

	static void changeColor(WORD color);
};

#endif // __WIN32

#endif // BUFFY_WINDOWSDISPLAYER_HPP
