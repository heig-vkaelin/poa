/**
 * Classe représentant un voleur
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include <algorithm>
#include "Thief.hpp"
#include "../containers/Container.hpp"

using namespace std;

Thief::Thief(const string& name, const IndependantPerson& policeman) :
	Person(name), policeman(&policeman) {
}

bool Thief::isStateValid(const Container& container) const {
	// Voleur seul ou accompagné du policier
	return container.size() == 1 ||
			 find(container.begin(), container.end(),
					policeman) != container.end();
}

ErrorStatus Thief::getErrorStatus() const {
	return THIEF_ERROR;
}
