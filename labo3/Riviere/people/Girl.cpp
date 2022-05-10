/**
 * Classe représentant une fille
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include "Girl.hpp"

using namespace std;

Girl::Girl(const string& name, const IndependantPerson& dependsOn,
			  const IndependantPerson& cannotStayWith)
	: Kid(name, dependsOn, cannotStayWith) {
}

ErrorStatus Girl::getErrorStatus() const {
	return GIRL_ERROR;
}
