//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Field.hpp"
#include "displayers/Displayer.hpp"
#include "Utils/Utils.hpp"
#include "actors/Human.hpp"
#include "actors/Vampire.hpp"

using namespace std;

Field::Field(unsigned width, unsigned height, unsigned nbHumans,
				 unsigned nbVampires, const Displayer* displayer)
	: width(width), height(height), turn(0), displayer(displayer), humanoids() {

	for (unsigned i = 0; i < nbHumans; ++i) {
		humanoids.emplace_back(new Human(width, height));
	}
	for (unsigned i = 0; i < nbVampires; ++i) {
		humanoids.emplace_back(new Vampire(width, height));
	}
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
	unsigned minDist = UINT_MAX;
	T** closest = nullptr;

	for (auto humanoid: humanoids) {
		unsigned dist = Utils::getDistance(
			humanoid->getXPos(), humanoid->getYPos(),
			closeTo.getXPos(), closeTo.getYPos()
		);
		if (dist < minDist && dynamic_cast<T*>(humanoid) != nullptr) {
			minDist = dist;
			closest = humanoid;
		}
	}
	return closest ? *closest : nullptr;
}

unsigned Field::getWidth() const {
	return width;
}

unsigned Field::getHeight() const {
	return height;
}

Field::~Field() {
	for (auto humanoid: humanoids)
		delete humanoid;
}
