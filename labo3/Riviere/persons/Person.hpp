//
// Created by Valentin Kaelin on 14.04.22.
//

#ifndef RIVIERE_PERSON_HPP
#define RIVIERE_PERSON_HPP

#include <string>

/**
 * Classe abstraite représentant une personne
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Person {
public:
	// TODO: TMP, go bouger après
	explicit Person(const std::string& name) { this->name = name; }

	// TODO: abstract (= 0)
	virtual bool canDrive() const { return false; };

	/**
	 * @return le nom de la personne
	 */
	std::string getName() const;

private:
	std::string name;
};

#endif // RIVIERE_PERSON_HPP
