//
// Created by Valentin Kaelin on 14.04.22.
//

#include "Bank.hpp"

using namespace std;

Bank::Bank(const string& name) : Container(name) {
}

ostream& Bank::toStream(ostream& os) const {
	return os << getName() << ": " << personsToString();
}
