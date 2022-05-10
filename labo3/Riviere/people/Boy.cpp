/**
 * Classe représentant un garçon
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include "Boy.hpp"

using namespace std;

Boy::Boy(const string& name, const IndependantPerson& dependsOn,
			const IndependantPerson& cannotStayWith)
	: Kid(name, dependsOn, cannotStayWith) {
}

ErrorStatus Boy::getErrorStatus() const {
	return BOY_ERROR;
}
