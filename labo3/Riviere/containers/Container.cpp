//
// Created by Valentin Kaelin on 14.04.22.
//

#include <algorithm>
#include "Container.hpp"

using namespace std;

ostream& operator<<(ostream& os, const Container& container) {
	return container.toStream(os);
}

Container::Container(const string& name) {
	this->name = name;
}

bool Container::addPerson(const Person& person) {
	if (contains(person))
		return false;

	people.push_back(&person);
	return true;
}

void Container::addPeople(const list<const Person*>& list) {
	for (const Person* person: list)
		addPerson(*person);
}

bool Container::empty() const {
	return people.empty();
}

void Container::clear() {
	people.clear();
}

const string& Container::getName() const {
	return name;
}

std::string Container::peopleToString() const {
	string result;
	for (const Person* person: people)
		result += person->getName() + " ";
	return result;
}

list<const Person*>& Container::getPeople() {
	return people;
}

bool Container::contains(const Person& person) const {
	return find(people.begin(), people.end(), &person) != people.end();
}

const Person* Container::findByName(const string& nameToFind) const {
	for (const Person* person: people)
		if (person->getName() == nameToFind)
			return person;
	return nullptr;
}




