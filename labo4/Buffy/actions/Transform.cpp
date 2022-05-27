//
// Created by Alexandre Jaquier on 27.05.2022.
//

#include "Transform.hpp"
#include "../actors/Humanoid.hpp"
#include "../actors/Vampire.hpp"

Transform::Transform(Humanoid& humanoid) {
	this->humanoid = &humanoid;
}

void Transform::execute(Field& f) {
	Humanoid* tmp = humanoid;
	humanoid = new Vampire(tmp->getXPos(), tmp->getYPos());
	delete tmp;
}