/**
 * Classe Vampire représentant un acteur chassant les humains et pouvant transformer
 * les transformer en vampires
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */

#include "Vampire.hpp"
#include "Human.hpp"
#include "../Field.hpp"
#include "../actions/Kill.hpp"
#include "../actions/Move.hpp"
#include "../actions/Transform.hpp"
#include "../utils/Random.hpp"

Vampire::Vampire(const Position& position) : Humanoid(position) {}

void Vampire::kill(Field& field) {
	Humanoid::kill(field);
	field.vampireDied();
}

char Vampire::getSymbol() const {
	return 'V';
}

Color Vampire::getColor() const {
	return Color::BLUE;
}

Action* Vampire::getNextAction(const Field& field) {
	if (!field.hasHumans())
		return nullptr;

	Human* target = field.findClosestHumanoid<Human>(*this);
	if (getPosition().getDistance(target->getPosition()) <= HUNT_RANGE) {
		// 50% de chance de tuer, 50% de chance de transformer
		if (Random::generateBool())
			return new Kill(*target);
		else
			return new Transform(*target);
	}

	return new Move(MOVE_RANGE, *this, target);
}
