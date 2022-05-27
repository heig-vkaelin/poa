//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Buffy.hpp"
#include "Vampire.hpp"
#include "Human.hpp"
#include "../Field.hpp"

#include "../actions/Kill.hpp"

Buffy::Buffy(unsigned x, unsigned y) : Humanoid(x, y) {}

ActorType Buffy::getType() const {
	return ActorType::BUFFY;
}

void Buffy::display(const Displayer& displayer) const {
	displayer.displayBuffy();
}

void Buffy::setAction(const Field &field) {
    if(action != nullptr) {
        delete action;
    }
    action = new Kill(*field.findClosestHumanoid<Vampire>(*this));
}

void Buffy::executeAction(Field &field) {
    action->execute(field);
}