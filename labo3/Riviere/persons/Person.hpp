//
// Created by Valentin Kaelin on 14.04.22.
//

#ifndef RIVIERE_PERSON_HPP
#define RIVIERE_PERSON_HPP

#include <string>

class Person {
public:

	virtual bool canDrive() const = 0;

private:
	std::string name;
};


#endif // RIVIERE_PERSON_HPP
