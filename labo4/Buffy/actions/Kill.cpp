/**
 * Classe Kill représentant la mort de l'humanoïde souhaité
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */

#include "Kill.hpp"
#include "../actors/Humanoid.hpp"

Kill::Kill(Humanoid& humanoid) : Action(humanoid) {
}

void Kill::execute(Field& field) {
	if (getHumanoid()->isAlive()) {
		getHumanoid()->kill(field);
	}
}
