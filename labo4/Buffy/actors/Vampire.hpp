#ifndef BUFFY_VAMPIRE_HPP
#define BUFFY_VAMPIRE_HPP

#include "Humanoid.hpp"

/**
 * Classe Vampire représentant un acteur chassant les humains et pouvant transformer
 * les transformer en vampires
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Vampire : public Humanoid {
public:
	/**
	 * Crée un nouveau Vampire à un position aléatoire
	 * @param maxX : borne supérieure de la coordonnée x
	 * @param maxY : borne supérieure de la coordonnée y
	 */
	Vampire(unsigned maxX, unsigned maxY);

	/**
	 * Crée par copie un Vampire à la même position
	 * @param other : vampire à copier
	 */
	explicit Vampire(const Humanoid& other);

	void kill(Field& field) override;

	char getSymbol() const override;

	Color getColor() const override;

protected:
	Action* getNextAction(const Field& field) override;

private:
	static constexpr int
		HUNT_RANGE = 1,
		MOVE_RANGE = 1;
};

#endif // BUFFY_VAMPIRE_HPP
