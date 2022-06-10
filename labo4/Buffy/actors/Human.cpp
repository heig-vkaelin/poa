/**
 * Classe Humain représentant un acteur se déplaçant aléatoirement dans la
 * simulation et pouvant être transformé en vampire
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */

#include "Human.hpp"
#include "../actions/Move.hpp"
#include "../Field.hpp"

using namespace std;

Human::Human(unsigned maxX, unsigned maxY) : Humanoid(maxX, maxY) {}

void Human::kill(Field& field) {
	Humanoid::kill(field);
	field.humanDied();
}

char Human::getSymbol() const {
	return 'h';
}

Color Human::getColor() const {
	return Color::PINK;
}

Action* Human::getNextAction(const Field&) {
	// TODO: constante pas en dur
	return new Move(1, *this);
}
