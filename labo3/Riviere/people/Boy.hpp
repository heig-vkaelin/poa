#ifndef RIVIERE_BOY_HPP
#define RIVIERE_BOY_HPP

#include "Kid.hpp"
#include "IndependantPerson.hpp"

/**
 * Classe représentant un garçon
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Boy : public Kid {
public:
	Boy(const std::string& name, const IndependantPerson& mother,
		 const IndependantPerson& father);
};

#endif // RIVIERE_BOY_HPP
