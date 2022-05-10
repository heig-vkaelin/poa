#ifndef RIVIERE_THIEF_HPP
#define RIVIERE_THIEF_HPP

#include <string>
#include "Person.hpp"
#include "IndependantPerson.hpp"
#include "ErrorStatus.hpp"

/**
 * Classe représentant un voleur
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Thief : public Person {
public:
	/**
	 * Crée un nouveau voleur
	 * @param name : nom du voleur
	 * @param policeman : policier qui s'occupe de ce voleur
	 */
	Thief(const std::string& name, const IndependantPerson& policeman);

	bool isStateValid(const Container& container) const override;

	ErrorStatus getErrorStatus() const override;

private:
	const IndependantPerson* policeman;
};

#endif // RIVIERE_THIEF_HPP
