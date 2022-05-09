//
// Created by Valentin Kaelin on 05.05.22.
//

#include "Girl.hpp"

using namespace std;

const string Girl::ERROR_MESSAGE = "fille avec son pere sans sa mere";

Girl::Girl(const string& name, const IndependantPerson& dependsOn,
			  const IndependantPerson& cannotStayWith)
	: Kid(name, dependsOn, cannotStayWith) {
}

string Girl::getErrorMessage() const {
	return ERROR_MESSAGE;
}
