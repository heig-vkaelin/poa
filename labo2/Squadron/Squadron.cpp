//
// Created by Valentin Kaelin on 17.03.22.
//
#include <iostream>
#include <sstream>

#include "Squadron.hpp"

using namespace std;

ostream& operator<<(ostream& os, const Squadron& squadron) {
	stringstream header;
	stringstream ships;
	Squadron::Member* leader = squadron.leader;
	Squadron::Member* member = squadron.first;

	unsigned maxSpeed = UINT_MAX;
	double totalWeight = 0;

	header << "Squadron: " << squadron.name << endl;
	ships << "-- Leader:" << endl
			<< leader->ship << endl
			<< "-- Members:" << endl;

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
													  first(nullptr),
													  last(nullptr) {}

Squadron& Squadron::operator+=(const Ship& ship) {
	Member* member = new Member{ship, nullptr};

	if (first != nullptr) {
		last->next = member;
		last = last->next;
	} else {
		first = member;
		last = member;
	}

	size++;
	return *this;
}

void Squadron::setName(const string& name) {
	this->name = name;
}

void Squadron::setLeader(const Ship& ship) {
	if (leader && &(leader->ship) == &ship)
		return;

	Member* iter = first;
	while (iter) {
		if (&(iter->ship) == &ship) {
			leader = iter;
			return;
		}
		iter = iter->next;
	}

	*this += ship;
	leader = last;
}
