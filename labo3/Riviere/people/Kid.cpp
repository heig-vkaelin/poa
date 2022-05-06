//
// Created by Valentin Kaelin on 05.05.22.
//

#include <algorithm>
#include "Kid.hpp"
#include "../containers/Container.hpp"

using namespace std;

Kid::Kid(const string& name, const IndependantPerson& dependsOn,
			const IndependantPerson& cannotStayWith)
	: DependantPerson(name), dependsOn(&dependsOn), cannotStayWith(&cannotStayWith) {
}

bool Kid::isStateValid(const Container& container) const {
	bool isWithCannotStayWith =
		find(container.begin(), container.end(), cannotStayWith) != container.end();
	bool isWithDependsOn =
		find(container.begin(), container.end(), dependsOn) != container.end();

	return !isWithCannotStayWith || isWithDependsOn;;
}
