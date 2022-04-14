//
// Created by Valentin Kaelin on 14.04.22.
//

#ifndef RIVIERE_CONTAINER_HPP
#define RIVIERE_CONTAINER_HPP

#include <string>
#include <list>
#include "../persons/Person.hpp"

class Container {
public:
	explicit Container(const std::string& name);

	const std::string& getName() const;

private:
	std::string name;
	std::list<Person*> persons;
};


#endif // RIVIERE_CONTAINER_HPP
