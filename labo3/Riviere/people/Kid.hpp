#ifndef RIVIERE_KID_HPP
#define RIVIERE_KID_HPP

#include "Person.hpp"
#include "IndependantPerson.hpp"

/**
 * Classe représentant un enfant
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Kid : public Person {
public:
	Kid(const std::string& name, const IndependantPerson& dependsOn,
		 const IndependantPerson& cannotStayWith);

	bool isStateValid(const Container& container) const override;

private:
	const IndependantPerson* dependsOn;
	const IndependantPerson* cannotStayWith;
};


#endif // RIVIERE_KID_HPP
