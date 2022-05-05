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
	Kid(const std::string& name, const IndependantPerson* mother,
		 const IndependantPerson* father);

private:
	const IndependantPerson* mother;
	const IndependantPerson* father;
};


#endif // RIVIERE_KID_HPP
