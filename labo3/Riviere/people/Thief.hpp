#ifndef RIVIERE_THIEF_HPP
#define RIVIERE_THIEF_HPP

#include <string>
#include "DependantPerson.hpp"
#include "IndependantPerson.hpp"

/**
 * Classe représentant un voleur
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Thief : public DependantPerson {
public:
	Thief(const std::string& name, const IndependantPerson& policeman);

	bool isStateValid(const Container& container) const override;

	std::string getErrorMessage() const override;

private:
	const IndependantPerson* policeman;
};

#endif // RIVIERE_THIEF_HPP
