#ifndef BUFFY_HUMAN_HPP
#define BUFFY_HUMAN_HPP

#include "Humanoid.hpp"

/**
 * Classe Humain représentant un acteur se déplaçant aléatoirement dans la
 * simulation et pouvant être transformé en vampire
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Human : public Humanoid {
public:
	/**
	 * Constructeur de la classe Human
	 * @param maxX : borne supérieure de la coordonnée x
	 * @param maxY : borne supérieure de la coordonnée x
	 */
	Human(unsigned maxX, unsigned maxY);

	void kill(Field& field) override;

	char getSymbol() const override;

	Color getColor() const override;

	/**
	 * Portée de déplacement des humains
	 */
	static constexpr int MOVE_RANGE = 1;

protected:
	Action* getNextAction(const Field& field) override;
};

#endif // BUFFY_HUMAN_HPP
