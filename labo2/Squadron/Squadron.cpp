//
// Created by Valentin Kaelin on 17.03.22.
//
#include <iostream>
#include <sstream>

#include "Squadron.hpp"
#include <exception>

using namespace std;

ostream& operator<<(ostream& os, const Squadron& squadron) {
	stringstream header;
	stringstream ships;
	Squadron::Member* leader = squadron.leader;
	Squadron::Member* member = squadron.head;

	unsigned maxSpeed = UINT_MAX;
	double totalWeight = 0;

	header << "Squadron: " << squadron.name << endl;

	if (leader) {
		ships << "-- Leader:" << endl
				<< leader->ship << endl;
	} else {
		ships << "-- Leader:" << endl
				<< "No leader" << endl << endl;
	}
	ships << "-- Members:" << endl;

	while (member != nullptr) {
		if (member != leader) {
			ships << member->ship << endl;
		}
		totalWeight += member->ship.getWeight();
		maxSpeed = min(maxSpeed, member->ship.getMaxSpeed());
		member = member->next;
	}

	header << "  max speed: " << maxSpeed << " MGLT" << endl
			 << "  total weight: " << totalWeight << " tons" << endl;

	return os << header.str() << endl << ships.str();
}

Squadron::Squadron(const string& name) : name(name), size(0), leader(nullptr),
													  head(nullptr), tail(nullptr) {}

Squadron& Squadron::operator+=(const Ship& ship) {
	Member* member = new Member{const_cast<Ship&>(ship), nullptr};

	if (head != nullptr) {
		tail->next = member;
		tail = tail->next;
	} else {
		head = member;
		tail = member;
	}

	size++;
	return *this;
}

void Squadron::setName(const string& n) {
	name = n;
}

void Squadron::setLeader(const Ship& ship) {
	if (leader && &(leader->ship) == &ship)
		return;

	Member* iter = head;
	while (iter) {
		if (&(iter->ship) == &ship) {
			leader = iter;
			return;
		}
		iter = iter->next;
	}

	*this += ship;
	leader = tail;
}

void Squadron::removeLeader() {
	leader = nullptr;
}

Squadron& Squadron::operator-=(const Ship& ship) {
	if (!size)
		return *this;

	bool deleted = false;

	if (&(head->ship) == &ship) {
		if (head == leader)
			removeLeader();
		if (head->next != nullptr) {
			Member* tmp = head;
			head = head->next;
			delete tmp;
		} else {
			head = nullptr;
			delete head;
		}
		deleted = true;
	}

	Member* iter = head;
	while (!deleted && iter->next != nullptr) {
		if (&(iter->next->ship) == &ship) {
			if (iter->next == leader)
				removeLeader();
			if (iter->next->next != nullptr) {
				Member* tmp = iter->next;
				iter->next = iter->next->next;
				delete tmp;
			} else {
				iter->next = nullptr;
				delete iter->next;
			}
			deleted = true;
			break;
		}
		iter = iter->next;
	}
	if (deleted)
		size--;

	return *this;
}

Ship& Squadron::operator[](unsigned int index) {
   if (index >= size)
      throw runtime_error("Erreur: L'index demande n'est pas conforme.");

   Member* iter = head;
   unsigned i = 0;
   while (i != index) {
      iter = iter->next;
      ++i;
   }
   return iter->ship;
}
