//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Field.hpp"

using namespace std;

int Field::nextTurn() {
	// Déterminer les prochaines actions
	for (auto it = humanoids.begin(); it != humanoids.end();)
		(*it)->setAction(*this);

	// Executer les actions
	for (auto it = humanoids.begin(); it != humanoids.end();)
		(*it)->executeAction(*this);

	// Enlever les humanoides tués
	for (auto it = humanoids.begin(); it != humanoids.end();)
		if (!(*it)->isAlive()) {
			it = humanoids.erase(it);  // suppression de l’élément dans la liste
			delete *it;
		} else
			++it;
	return turn++;
}
