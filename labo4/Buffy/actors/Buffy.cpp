/**
 * Classe Buffy représentant un super-vampire qui peut tuer les autres vampires
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */

#include "Buffy.hpp"
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
	// TODO: constantes pas en dur
	if (!field.hasVampires())
		return new Move(1, *this);

	Vampire* target = field.findClosestHumanoid<Vampire>(*this);
	if (getPosition().getDistance(target->getPosition()) <= 1)
		return new Kill(*target);

	return new Move(2, *this, target);
}
