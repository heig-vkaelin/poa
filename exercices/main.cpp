#include <iostream>
#include <string>
#include "Season/Season.hpp"
#include "Array/Array.hpp"

using namespace std;

int exSeason() {
	const Season& season = Season::Spring;
	for (int i = 0; i < Season::size(); i++)
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

int main() {
//	return exSeason();
	return exArray();
}
