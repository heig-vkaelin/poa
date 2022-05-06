//
// Created by Valentin Kaelin on 05.05.22.
//

#include <algorithm>
#include "Kid.hpp"
#include "../containers/Container.hpp"

Kid::Kid(const std::string& name, const IndependantPerson& dependsOn,
			const IndependantPerson& cannotStayWith)
	: DependantPerson(name), dependsOn(&dependsOn), cannotStayWith(&cannotStayWith) {
}

bool Kid::isStateValid(const Container& container) const {

   bool isWithCannotStayWith = find(container.getPeople().begin(), container.getPeople().end(),
                                    cannotStayWith) != container.getPeople().end();
   bool isWithDependsOn = find(container.getPeople().begin(), container.getPeople().end(),
                               dependsOn) != container.getPeople().end();

   return !isWithCannotStayWith || isWithDependsOn;
}
