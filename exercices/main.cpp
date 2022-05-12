#include <iostream>
#include <string>
#include <memory>

#include "Season/Season.hpp"
#include "Array/Array.hpp"
#include "SharedPointer/SharedPointer.hpp"
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

template<typename Iterator, typename Fn>
Fn foreach(Iterator begin, Iterator end, Fn fn) {
	for (; begin != end; ++begin) {
		fn(*begin);
	}
	return fn;
}

int exArray() {
	Array<int> a(5);
	a[0] = 2;
	a[1] = 4;

	for (auto& i: a)
		cout << i << " ";

	cout << endl;

	Array<string> b{"Ceci", "est", "un", "tableau", "de", "chaines"};
	for (auto& i: b)
		cout << i << " ";

	cout << endl;

	foreach(a.begin(), a.end(), [](int i) {
		cout << i << " ";
	});

	return EXIT_SUCCESS;
}

int exSharedPointer() {
	SharedPointer<int> sp1(new int(1));
	SharedPointer<int> sp2(sp1);
	*sp2 = 2;
	cout << *sp1 << endl;
	SharedPointer<int> sp3(new int(3));
	sp2 = sp3;
	sp1 = SharedPointer<int>(new int(4));
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
//	return exSeason();
//	return exArray();
//	return exSharedPointer();
	return exMusician();
}
