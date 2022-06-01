//
// Created by Alexandre Jaquier on 27.05.2022.
//

#include "Transform.hpp"
#include "../actors/Humanoid.hpp"
#include "../actors/Vampire.hpp"
#include "../Field.hpp"

Transform::Transform(Humanoid& humanoid) {
	this->humanoid = &humanoid;
}

void Transform::execute(Field& field) {
	// TODO: fix crash
    humanoid->kill();
    field.addCharacter(new Vampire(*humanoid));
}
