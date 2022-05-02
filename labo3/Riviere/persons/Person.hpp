//
// Created by Valentin Kaelin on 14.04.22.
//

#ifndef RIVIERE_PERSON_HPP
#define RIVIERE_PERSON_HPP

#include <string>

class Person {
public:
	// TODO: TMP, go bouger après
	explicit Person(const std::string& name) { this->name = name; }

	// TODO: abstract (= 0)
	virtual bool canDrive() const { return false; };

	std::string getName() const;

private:
	std::string name;
};


#endif // RIVIERE_PERSON_HPP
