/**
 * Classe abstraite représentant une conteneur de tout type
 * Ce conteneur peut contenir un nombre indéterminé de personnes
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */

#include <algorithm>
#include <sstream>
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
	stringstream ss;
	for (auto it = people.begin(); it != people.end(); ++it) {
		ss << (*it)->getName();
		if (it != prev(people.end()))
			ss << " ";
	}
	return ss.str();
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

ErrorStatus Container::isValid() const {
	for (const Person* person: people) {
		if (!person->isStateValid(*this))
			return person->getErrorStatus();
	}
	return OK;
}

list<const Person*>::const_iterator Container::begin() const {
	return people.begin();
}

list<const Person*>::const_iterator Container::end() const {
	return people.end();
}

std::ostream& Container::toStream(ostream& os) const {
	return os << getName() << ": ";
}

Container::~Container() = default;
