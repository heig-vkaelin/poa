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
	/**
	 * Crée un nouveau garçon
	 * @param name : nom du garçon
	 * @param dependsOn : personne sur laquelle le garçon dépend
	 * @param cannotStayWith : personne avec laquelle le garçon ne peut pas rester
	 */
	Boy(const std::string& name, const IndependantPerson& dependsOn,
		 const IndependantPerson& cannotStayWith);

	std::string getErrorMessage() const override;

private:
	const static std::string ERROR_MESSAGE;
};

#endif // RIVIERE_BOY_HPP
