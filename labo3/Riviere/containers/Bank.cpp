/**
 * Conteneur représentant la rive d'une rivière
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include "Bank.hpp"

using namespace std;

Bank::Bank(const string& name) : Container(name) {
}

ostream& Bank::toStream(ostream& os) const {
	return Container::toStream(os) << peopleToString();
}
