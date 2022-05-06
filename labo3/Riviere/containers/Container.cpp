//
// Created by Valentin Kaelin on 14.04.22.
//

#include <algorithm>
#include "Container.hpp"
#include "../Controller.hpp"

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

void Container::removePerson(const Person& person) {
	people.remove(&person);
}

bool Container::empty() const {
	return people.empty();
}

size_t Container::size() const {
	return people.size();
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

const list<const Person*>& Container::getPeople() const {
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

bool Container::isValid() const {
	for (const Person* person: people) {
		if (!person->isStateValid(*this)) {
			Controller::displayError(person->getErrorMessage());
			return false;
		}
	}
	return true;
}

list<const Person*>::const_iterator Container::begin() const {
	return people.begin();
}

list<const Person*>::const_iterator Container::end() const {
	return people.end();
}
