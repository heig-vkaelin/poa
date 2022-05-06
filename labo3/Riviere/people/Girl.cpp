//
// Created by Valentin Kaelin on 05.05.22.
//

#include "Girl.hpp"

using namespace std;

Girl::Girl(const string& name, const IndependantPerson& dependsOn,
			  const IndependantPerson& cannotStayWith)
	: Kid(name, dependsOn, cannotStayWith) {
}

string Girl::getErrorMessage() const {
	return "fille avec son pere sans sa mere";
}
