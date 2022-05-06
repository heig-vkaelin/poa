//
// Created by Valentin Kaelin on 05.05.22.
//

#include "Thief.hpp"

Thief::Thief(const std::string& name, const IndependantPerson& policeman) :
	DependantPerson(name), policeman(&policeman) {
}
