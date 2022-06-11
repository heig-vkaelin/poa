#ifndef BUFFY_BUFFY_HPP
#define BUFFY_BUFFY_HPP

#include "Humanoid.hpp"

/**
 * Classe Buffy représentant un super-vampire qui peut tuer les autres vampires
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Buffy : public Humanoid {
public:
	/**
	 * Constructeur de la classe Buffy
	 * @param maxX : borne supérieure de la coordonnée x
	 * @param maxY : borne supérieure de la coordonnée y
	 */
	Buffy(unsigned maxX, unsigned maxY);

	char getSymbol() const override;

	Color getColor() const override;

protected:
	Action* getNextAction(const Field& field) override;

private:
	static constexpr int
		HUNT_RANGE = 1,
		MOVE_RANGE = 2;
};

#endif // BUFFY_BUFFY_HPP
