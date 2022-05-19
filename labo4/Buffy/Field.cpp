//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Field.hpp"

using namespace std;

Field::Field(unsigned width, unsigned height)
	: width(width), height(height), turn(0), humanoids() {
}

int Field::nextTurn() {
	// Déterminer les prochaines actions
	for (auto it = humanoids.begin(); it != humanoids.end();)
		(*it)->setAction(*this);

	// Exécuter les actions
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

template<typename T>
T* Field::findClosestHumanoid(const Humanoid& closeTo) const {
	for (auto it = humanoids.begin(); it != humanoids.end();) {
		// TODO
//		if ((*it)->getPosition() == closeTo.getPosition())
//			return *it;
//		++it;
	}
}

unsigned Field::getWidth() const {
	return width;
}

unsigned Field::getHeight() const {
	return height;
}