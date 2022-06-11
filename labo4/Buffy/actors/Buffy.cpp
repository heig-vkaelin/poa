/**
 * Classe Buffy représentant un super-vampire qui peut tuer les autres vampires
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */

#include "Buffy.hpp"
#include "Human.hpp"
#include "Vampire.hpp"
#include "../Field.hpp"
#include "../actions/Kill.hpp"
#include "../actions/Move.hpp"

using namespace std;

Buffy::Buffy(unsigned maxX, unsigned maxY) : Humanoid(maxX, maxY) {}

char Buffy::getSymbol() const {
	return 'B';
}

Color Buffy::getColor() const {
	return Color::YELLOW;
}

Action* Buffy::getNextAction(const Field& field) {
	if (!field.hasVampires())
		return new Move(Human::MOVE_RANGE, *this);

	Vampire* target = field.findClosestHumanoid<Vampire>(*this);
	if (getPosition().getDistance(target->getPosition()) <= HUNT_RANGE)
		return new Kill(*target);

	return new Move(MOVE_RANGE, *this, target);
}
