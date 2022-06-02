//
// Created by Alexandre Jaquier on 27.05.2022.
//

#include "Kill.hpp"
#include "../actors/Humanoid.hpp"

Kill::Kill(Humanoid& humanoid) : Action(humanoid) {
}

void Kill::execute(Field& field) {
	getHumanoid()->kill(field);
}
