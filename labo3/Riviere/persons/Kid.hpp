#ifndef RIVIERE_KID_HPP
#define RIVIERE_KID_HPP

#include "DependantPerson.hpp"
#include "IndependantPerson.hpp"

/**
 * Classe représentant un enfant
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Kid : public DependantPerson {
public:
	Kid(const std::string& name, const IndependantPerson& dependsOn,
		 const IndependantPerson& cannotStayWith);

private:
	const IndependantPerson* dependsOn;
	const IndependantPerson* cannotStayWith;
};


#endif // RIVIERE_KID_HPP
