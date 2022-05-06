//
// Created by Valentin Kaelin on 05.05.22.
//

#include "Kid.hpp"

Kid::Kid(const std::string& name, const IndependantPerson& dependsOn,
			const IndependantPerson& cannotStayWith)
	: DependantPerson(name), dependsOn(&dependsOn), cannotStayWith(&cannotStayWith) {
}
