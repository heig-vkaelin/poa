//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Field.hpp"
#include "Utils/Utils.hpp"
#include "actors/Buffy.hpp"
#include "actors/Human.hpp"
#include "actors/Vampire.hpp"

using namespace std;

Field::Field(unsigned width, unsigned height, unsigned nbHumans, unsigned nbVampires)
	: width(width), height(height), turn(0), humanoids() {

	for (unsigned i = 0; i < nbHumans; ++i)
		humanoids.emplace_back(new Human(width, height));
	for (unsigned i = 0; i < nbVampires; ++i)
		humanoids.emplace_back(new Vampire(width, height));
	
	humanoids.emplace_back(new Buffy(width, height));
}

Field::~Field() {
	for (Humanoid* humanoid: humanoids)
		delete humanoid;
}

int Field::nextTurn() {
	// Déterminer les prochaines actions
	for (auto& humanoid: humanoids)
		humanoid->setAction(*this);

	// Exécuter les actions
	for (auto& humanoid: humanoids)
		humanoid->executeAction(*this);

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

	for (Humanoid* humanoid: humanoids) {
		unsigned dist = Utils::getDistance(
			humanoid->getXPos(), humanoid->getYPos(),
			closeTo.getXPos(), closeTo.getYPos()
		);
		// && dynamic_cast<T*>(humanoid) != nullptr
		if (dist < minDist) {
			minDist = dist;
			closest = humanoid;
		}
	}
	return closest ? *closest : nullptr;
}

const Humanoid* Field::getHumanoidAt(unsigned x, unsigned y) const {
	for (Humanoid* humanoid: humanoids) {
		if (humanoid->getXPos() == x && humanoid->getYPos() == y)
			return humanoid;
	}
	return nullptr;
}

unsigned Field::getWidth() const {
	return width;
}

unsigned Field::getHeight() const {
	return height;
}

list<Humanoid*>::const_iterator Field::begin() const {
	return humanoids.begin();
}

list<Humanoid*>::const_iterator Field::end() const {
	return humanoids.end();
}

EndStatus Field::isFinished() const {
	bool vampireAlive = false;
	bool humanAlive = false;

	// TODO cast ou alors getter du nbr de vivants sur le field ≤?
	for (Humanoid* humanoid: humanoids) {
		if (dynamic_cast<Vampire*>(humanoid) != nullptr) {
			vampireAlive = true;
		} else if (dynamic_cast<Human*>(humanoid) != nullptr) {
			humanAlive = true;
		}
	}

	if (humanAlive)
		return vampireAlive ? EndStatus::RUNNING : EndStatus::WIN;
	return EndStatus::LOSE;
}
