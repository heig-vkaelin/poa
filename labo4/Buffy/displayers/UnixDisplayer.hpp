#ifndef BUFFY_UNIXDISPLAYER_HPP
#define BUFFY_UNIXDISPLAYER_HPP

#include <string>
#include "Displayer.hpp"

/**
 * Classe UnixDisplayer permettant d'afficher la simulation dans la console avec
 * des couleurs sur les plateformes Unix
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class UnixDisplayer : public Displayer {
public:
	/**
	 * Crée un UnixDisplayer spécifique aux plateformes Unix
	 * @param width : largeur du Field à afficher
	 * @param height : hauteur du Field à afficher
	 */
	UnixDisplayer(unsigned width, unsigned height);

	void display(const Humanoid* humanoid) const override;

private:
	static std::string getColor(Color color);

	static void resetColor();
};

#endif // BUFFY_UNIXDISPLAYER_HPP
