/**
 * Classe Transform représentant la transformation d'un humain en vampire
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */

#include "Transform.hpp"
#include "../actors/Humanoid.hpp"
#include "../actors/Vampire.hpp"
#include "../Field.hpp"

Transform::Transform(Humanoid& humanoid) : Action(humanoid) {
}

void Transform::execute(Field& field) {
	if (getHumanoid()->isAlive()) {
		getHumanoid()->kill(field);
		field.addCharacter(new Vampire(getHumanoid()->getPosition()));
		field.vampireBorn();
	}
}
