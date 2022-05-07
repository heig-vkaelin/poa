//
// Created by Valentin Kaelin on 05.05.22.
//

#ifndef EXERCICES_BAND_HPP
#define EXERCICES_BAND_HPP

#include <string>
#include <list>
#include <memory>
#include "Musician.hpp"

class Band : public std::enable_shared_from_this<Band> {
public:
	explicit Band(std::string name);

	void setMembers(std::initializer_list<std::shared_ptr<Musician>> musicians);

	std::string getName() const;

	std::string toString() const;

	~Band();

private:
	std::string name;
	std::list<std::shared_ptr<Musician>> musicians;
};

#endif // EXERCICES_BAND_HPP
