/**
 * Classe abstraite représentant une action réalisée par un humanoïde de la
 * simulation
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */

#include "Action.hpp"
#include "../Field.hpp"

Action::Action(Humanoid& humanoid) : humanoid(&humanoid) {
}

Humanoid* Action::getHumanoid() {
	return humanoid;
}
