//
// Created by Valentin Kaelin on 05.05.22.
//

#include "Kid.hpp"
#include "../containers/Container.hpp"

Kid::Kid(const std::string& name, const IndependantPerson& dependsOn,
			const IndependantPerson& cannotStayWith)
	: DependantPerson(name), dependsOn(&dependsOn), cannotStayWith(&cannotStayWith) {
}

bool Kid::isStateValid(const Container& container) const {
	// TODO: check si ya le cannotStayWith, si oui, il faut aussi qu'il y ait le
	//  dependsOn (avec 2 bool et une boucle ça doit etre ez)
	return false;
}
