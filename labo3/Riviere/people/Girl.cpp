/**
 * Classe représentant une fille
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

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
