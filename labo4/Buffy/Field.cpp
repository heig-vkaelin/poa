//
// Created by Valentin Kaelin on 19.05.22.
//

#include "Field.hpp"
#include "utils/Random.hpp"
#include "actors/Buffy.hpp"
#include "actors/Human.hpp"
#include "actors/Vampire.hpp"

using namespace std;

Field::Field(unsigned width, unsigned height, unsigned nbHumans, unsigned nbVampires)
	: width(width), height(height), turn(0),
	  nbHumans(nbHumans), nbVampires(nbVampires), humanoids() {

	for (unsigned i = 0; i < nbVampires; ++i)
		humanoids.emplace_back(new Vampire(width, height));
	for (unsigned i = 0; i < nbHumans; ++i)
		humanoids.emplace_back(new Human(width, height));


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
	for (auto it = humanoids.begin(); it != humanoids.end();) {
		if (!(*it)->isAlive()) {
			delete *it;
			it = humanoids.erase(it);
		} else
			++it;
	}
	return turn++;
}

void Field::addCharacter(Humanoid* humanoid) {
	auto end = this->end();
	for (auto i = this->begin(); i != end; ++i) {
		if (*i == humanoid)
			return;
	}
	humanoids.emplace_back(humanoid);
}

void Field::humanDied() {
	if (nbHumans)
		--nbHumans;
}

void Field::vampireDied() {
	if (nbVampires)
		--nbVampires;
}

void Field::vampireBorn() {
	++nbVampires;
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
	if (nbHumans > 0)
		return nbVampires > 0 ? EndStatus::RUNNING : EndStatus::WIN;
	return EndStatus::LOSE;
}
