#ifndef RIVIERE_KID_HPP
#define RIVIERE_KID_HPP

#include "Person.hpp"
#include "IndependantPerson.hpp"

/**
 * Classe abstraite représentant un enfant
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Kid : public Person {
public:
	/**
	 * Crée un nouvel enfant
	 * @param name : nom de l'enfant
	 * @param dependsOn : personne sur laquelle l'enfant dépend
	 * @param cannotStayWith : personne avec laquelle l'enfant ne peut pas rester
	 */
	Kid(const std::string& name, const IndependantPerson& dependsOn,
		 const IndependantPerson& cannotStayWith);

	bool isStateValid(const Container& container) const override;

	/*
	 * Destructeur abstrait afin de rendre la classe abstraite
	 */
	virtual ~Kid() = 0;

private:
	const IndependantPerson* dependsOn;
	const IndependantPerson* cannotStayWith;
};

#endif // RIVIERE_KID_HPP
