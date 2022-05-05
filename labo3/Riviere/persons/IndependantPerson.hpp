#ifndef RIVIERE_INDEPENDANTPERSON_HPP
#define RIVIERE_INDEPENDANTPERSON_HPP

#include "Person.hpp"

/**
 * Classe abstraite représentant une personne indépendante
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class IndependantPerson : public Person {
public:
	bool canDrive() const override;
};


#endif // RIVIERE_INDEPENDANTPERSON_HPP
