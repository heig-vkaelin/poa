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
	init(name);
}

// TODO : check avec Valgrind
Squadron::~Squadron() {
	Member* iter = head;
	while (iter) {
		Member* tmp = iter->next;
		delete iter;
		iter = tmp;
	}
}

Squadron::Squadron(const Squadron& squad) {
	setName(squad.name);
	if (squad.leader) {
		setLeader(*squad.leader);
	}

	Member* iter = squad.head;
	while (iter) {
		addShip(*iter->ship);
		iter = iter->next;
	}
}

Squadron& Squadron::addShip(Ship& ship) {
	if (head) {
		Member* previous = nullptr;
		Member* current = head;
		while (current) {
			if (current->ship == &ship)
				return *this;
			previous = current;
			current = current->next;
		}
		previous->next = new Member{&ship, nullptr};
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
	if (size && contains(ship)) {
		size--; // A partir de là on est sûr d'enlever un ship

		if (leader == &ship)
			removeLeader();

		Member* previous = nullptr;
		Member* current = head;
		while (current) {
			if (current->ship == &ship) {
				if (current->next) { // On raccorde le précédent au suivant
					Member* next = current->next;
					delete current;
					previous ? previous->next = next : head = next;
				} else { // On est en bout de liste
					delete current;
					previous ? previous->next = nullptr : head = nullptr;
				}
				return *this;
			} else {
				previous = current;
				current = current->next;
			}
		}
	}
	return *this;
}

Squadron Squadron::removeShipCopy(Ship& ship) const {
	return Squadron(*this).removeShip(ship);
}

Squadron& Squadron::operator+=(Ship& ship) {
	return addShip(ship);
}

void Squadron::setName(const string& newName) {
	name = newName;
}

void Squadron::setLeader(Ship& ship) {
	if (leader && leader == &ship)
		return;

	if (!contains(ship))
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
	return getByIndex(index);
}

Ship& Squadron::get(size_t index) {
	return getByIndex(index);
}

const Ship& Squadron::operator[](size_t index) const {
	return get(index);
}

//Ship& Squadron::operator[](size_t index) {
//	return get(index);
//}

double Squadron::computeConsumption(double distance, double speed) {
	if (!size)
		throw runtime_error(
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

	unsigned maxSpeed = head ? UINT_MAX : 0;
	double totalWeight = 0;

	header << "Squadron: " << name << endl;

	ships << "-- Leader:" << endl;
	if (leader)
		ships << *leader << endl;
	else
		ships << "No leader" << endl << endl;

	ships << "-- Members:" << endl;

	while (member != nullptr) {
		if (member->ship != leader) {
			ships << *member->ship << endl;
		}
		totalWeight += member->ship->getWeight();
		maxSpeed = min(maxSpeed, member->ship->getMaxSpeed());
		member = member->next;
	}

	header << fixed << setprecision(2)
			 << "  max speed: " << maxSpeed << " MGLT" << endl
			 << "  total weight: " << totalWeight << " tons" << endl;

	return os << header.str() << endl << ships.str();
}

void Squadron::init(const string& n) {
	name = n;
	size = 0;
	leader = nullptr;
	head = nullptr;
}

bool Squadron::contains(Ship& ship) {
	Member* iter = head;
	while (iter) {
		if (iter->ship == &ship) {
			return true;
		}
		iter = iter->next;
	}
	return false;
}

Ship& Squadron::getByIndex(size_t index) const {
	if (index >= size)
		throw runtime_error("Erreur: L'index demande n'est pas conforme.");

	Member* iter = head;
	for (size_t i = 0; i != index; ++i) {
		iter = iter->next;
	}

	return *iter->ship;
}
