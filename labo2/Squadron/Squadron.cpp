/**
 * Classe représentant une escadrille de divers vaisseaux pouvant être mise à jour
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <limits>

#include "Squadron.hpp"

using namespace std;

struct Squadron::Member {
	Ship* ship;
	Member* next;
};

ostream& operator<<(ostream& os, const Squadron& squadron) {
	return squadron.toStream(os);
}

Squadron operator+(const Squadron& squadron, Ship& ship) {
	return squadron.addShipCopy(ship);
}

Squadron operator-(const Squadron& squadron, Ship& ship) {
	return squadron.removeShipCopy(ship);
}

Squadron::Squadron(const string& name) {
	init(name, nullptr);
}

Squadron::~Squadron() {
	freeSquadron();
}

Squadron::Squadron(const Squadron& squad) {
	init(squad.name, squad.leader);
	copyShips(squad);
}

Squadron& Squadron::operator=(const Squadron& squad) {
	if (this != &squad) {
		freeSquadron();
		init(squad.name, squad.leader);
		copyShips(squad);
	}
	return *this;
}

Squadron& Squadron::addShip(Ship& ship) {
	if (head) {
		Member* current = head;
		while (current->next) {
			if (current->ship == &ship || current->next->ship == &ship)
				return *this;
			current = current->next;
		}
		current->next = new Member{&ship, nullptr};
	} else {
		head = new Member{&ship, nullptr};
	}
	size++;
	return *this;
}

Squadron Squadron::addShipCopy(Ship& ship) const {
	return Squadron(*this).addShip(ship);
}

Squadron& Squadron::removeShip(Ship& ship) {
	Member* previous = nullptr;
	Member* current = head;
	while (current) {
		if (current->ship == &ship) {
			if (previous)
				previous->next = current->next;
			else
				head = current->next;

			if (current->ship == leader)
				removeLeader();
			size--;
			delete current;
			break;
		}
		previous = current;
		current = current->next;
	}
	return *this;
}

Squadron Squadron::removeShipCopy(Ship& ship) const {
	return Squadron(*this).removeShip(ship);
}

Squadron& Squadron::operator+=(Ship& ship) {
	return addShip(ship);
}

const string& Squadron::getName() const {
	return name;
}

void Squadron::setName(const string& newName) {
	name = newName;
}

void Squadron::setLeader(Ship& ship) {
	if (leader && leader == &ship)
		return;

	addShip(ship);
	leader = &ship;
}

void Squadron::removeLeader() {
	leader = nullptr;
}

Squadron& Squadron::operator-=(Ship& ship) {
	return removeShip(ship);
}

const Ship& Squadron::get(size_t index) const {
	if (index >= size)
		throw out_of_range("Erreur: L'index demande n'est pas conforme.");

	Member* iter = head;
	for (size_t i = 0; i != index; ++i) {
		iter = iter->next;
	}

	return *iter->ship;
}

const Ship& Squadron::operator[](size_t index) const {
	return get(index);
}

double Squadron::computeConsumption(double distance, double speed) const {
	if (!size)
		throw invalid_argument(
			"Il n'est pas possible de calculer la consommation car l'escadrille est"
			" vide.");

	double totalConsumption = 0;
	Squadron::Member* member = head;
	while (member != nullptr) {
		totalConsumption += member->ship->computeConsumption(distance, speed);
		member = member->next;
	}
	return totalConsumption;
}

ostream& Squadron::toStream(ostream& os) const {
	stringstream header;
	stringstream ships;
	Squadron::Member* member = head;

	double maxSpeed = head ? numeric_limits<double>::max() : 0;
	double totalWeight = 0;

	header << "Squadron: " << name << endl;

	ships << "-- Leader:" << endl;
	if (leader)
		ships << *leader << endl;
	else
		ships << "No leader" << endl << endl;

	ships << "-- Members:" << endl;

	if (size) {
		while (member != nullptr) {
			if (member->ship != leader) {
				ships << *member->ship << endl;
			}
			totalWeight += member->ship->getWeight();
			maxSpeed = min(maxSpeed, member->ship->getMaxSpeed());
			member = member->next;
		}
	} else {
		ships << "No member" << endl;
	}

	header << fixed << setprecision(0)
			 << "  max speed: " << maxSpeed << " MGLT" << endl
			 << setprecision(2)
			 << "  total weight: " << totalWeight << " tons" << endl;

	return os << header.str() << endl << ships.str();
}

void Squadron::init(const string& newName, Ship* newLeader) {
	name = newName;
	size = 0;
	leader = newLeader;
	head = nullptr;
}

void Squadron::copyShips(const Squadron& squad) {
	Member* iter = squad.head;
	while (iter) {
		addShip(*iter->ship);
		iter = iter->next;
	}
}

void Squadron::freeSquadron() {
	// TODO : check avec Valgrind
	Member* iter = head;
	while (iter) {
		Member* tmp = iter->next;
		delete iter;
		iter = tmp;
	}
}
