#include <iostream>
#include <string>
#include <memory>

#include "Season/Season.hpp"
#include "Array/Array.hpp"
#include "Musician/Band.hpp"
#include "Musician/Musician.hpp"

using namespace std;

int exSeason() {
	const Season& season = Season::Spring;
	for (size_t i = 0; i < Season::size(); i++)
		cout << Season::get(i).name() << endl;
	for (const Season* s = *Season::values();
		  s <= Season::values()[Season::size() - 1]; s++)
		cout << s->name() << " " << s->index() << " "
			  << s->next().name() << endl;

	return EXIT_SUCCESS;
}

int exArray() {
	Array<string> a(10);

	a[0] = "Hello";
	a[1] = "World";

	for (auto i = a.begin(); i != a.end(); ++i)
		cout << *i << endl;

	return EXIT_SUCCESS;
}

int exMusician() {
	shared_ptr<Musician>
		john = make_shared<Musician>("John"),
		paul = make_shared<Musician>("Paul"),
		george = make_shared<Musician>("George"),
		ringo = make_shared<Musician>("Ringo");

	shared_ptr<Band> beatles = make_shared<Band>("The Beatles");
	beatles->setMembers({john, paul, george, ringo});
	cout << beatles->toString() << endl;
	cout << john->toString() << endl;

	shared_ptr<Band> wings = make_shared<Band>("Wings");
	wings->setMembers({paul});
	beatles.reset();
	cout << paul->toString() << endl;

	wings->setMembers({paul});
	cout << paul->toString() << endl;
	return EXIT_SUCCESS;
}

int main() {
	return exSeason();
//	return exArray();
//	return exMusician();
}
