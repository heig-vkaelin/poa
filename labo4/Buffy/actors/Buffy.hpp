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
	 * Crée une nouvelle Buffy à une position donnée
	 * @param position : position de Buffy
	 */
	explicit Buffy(const Position& position);

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
