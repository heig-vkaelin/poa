//
// Created by Valentin Kaelin on 05.05.22.
//

#ifndef EXERCICES_MUSICIAN_HPP
#define EXERCICES_MUSICIAN_HPP

#include <string>
#include <memory>

class Band;

class Musician {
public:
	explicit Musician(const std::string& name);

	std::string toString() const;

	std::string getName() const;

	void setBand(std::shared_ptr<Band> band);

	~Musician();

private:
	std::string name;
	std::weak_ptr<Band> band;
};


#endif // EXERCICES_MUSICIAN_HPP
