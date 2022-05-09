//
// Created by Valentin Kaelin on 05.05.22.
//

#include "Boy.hpp"

using namespace std;

const string Boy::ERROR_MESSAGE = "garcon avec sa mere sans son pere";

Boy::Boy(const string& name, const IndependantPerson& dependsOn,
			const IndependantPerson& cannotStayWith)
	: Kid(name, dependsOn, cannotStayWith) {
}

string Boy::getErrorMessage() const {
	return ERROR_MESSAGE;
}
