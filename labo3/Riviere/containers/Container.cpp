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

bool Container::addPerson(const Person* person) {
	if (person == nullptr || contains(person))
		return false;

	persons.push_back(person);
	return true;
}

void Container::addPersons(const list<const Person*>& list) {
	for (const Person* person: list)
		addPerson(person);
}

bool Container::empty() const {
	return persons.empty();
}

void Container::clear() {
	persons.clear();
}

const string& Container::getName() const {
	return name;
}

std::string Container::personsToString() const {
	string result;
	for (const Person* person: persons)
		result += person->getName() + " ";
	return result;
}

list<const Person*>& Container::getPersons() {
	return persons;
}

bool Container::contains(const Person* person) const {
	return find(persons.begin(), persons.end(), person) != persons.end();
}

const Person* Container::findByName(const string& nameToFind) const {
	for (const Person* person: persons)
		if (person->getName() == nameToFind)
			return person;
	return nullptr;
}




