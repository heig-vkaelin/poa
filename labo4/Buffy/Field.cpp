/**
 * Classe Field représentant le terrain de la simulation sur lequel évolue les
 * acteurs
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */

#include "Field.hpp"
#include "utils/Random.hpp"


using namespace std;

Field::Field(unsigned width, unsigned height, unsigned nbHumans, unsigned nbVampires)
	: width(width), height(height), turn(0),
	  nbHumans(nbHumans), nbVampires(nbVampires), humanoids() {

	int maxX = (int)width;
	int maxY = (int)height;

	for (unsigned i = 0; i < nbVampires; ++i)
		humanoids.emplace_back(new Vampire(Position::getRandomPosition(maxX, maxY)));
	for (unsigned i = 0; i < nbHumans; ++i)
		humanoids.emplace_back(new Human(Position::getRandomPosition(maxX, maxY)));

	humanoids.emplace_back(new Buffy(Position::getRandomPosition(maxX, maxY)));
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

bool Field::hasHumans() const {
	return nbHumans > 0;
}

bool Field::hasVampires() const {
	return nbVampires > 0;
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
