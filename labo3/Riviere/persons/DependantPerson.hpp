#ifndef RIVIERE_DEPENDANTPERSON_HPP
#define RIVIERE_DEPENDANTPERSON_HPP

#include "Person.hpp"

/**
 * Classe abstraite représentant une personne dépendante d'une ou plusieurs autre(s)
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class DependantPerson : public Person {
public:
	explicit DependantPerson(const std::string& name);

	bool canDrive() const override;
};


#endif // RIVIERE_DEPENDANTPERSON_HPP
