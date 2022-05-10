#ifndef RIVIERE_INDEPENDANTPERSON_HPP
#define RIVIERE_INDEPENDANTPERSON_HPP

#include "Person.hpp"

/**
 * Classe représentant une personne indépendante qui peut conduire et qui n'a
 * besoin de personne
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class IndependantPerson : public Person {
public:
	/**
	 * Crée une personne indépendante qui peut conduire et qui n'a besoin de personne
	 * @param name : nom de la personne
	 */
	explicit IndependantPerson(const std::string& name);

	bool canDrive() const override;

	bool isStateValid(const Container& container) const override;

	ErrorStatus getErrorStatus() const override;
};

#endif // RIVIERE_INDEPENDANTPERSON_HPP
