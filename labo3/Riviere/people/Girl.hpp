#ifndef RIVIERE_GIRL_HPP
#define RIVIERE_GIRL_HPP

#include "Kid.hpp"
#include "ErrorStatus.hpp"

/**
 * Classe représentant une fille
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Girl : public Kid {
public:
	/**
	 * Crée une nouvelle fille
	 * @param name : nom de la fille
	 * @param dependsOn : personne sur laquelle la fille dépend
	 * @param cannotStayWith : personne avec laquelle la fille ne peut pas rester
	 */
	Girl(const std::string& name, const IndependantPerson& dependsOn,
		  const IndependantPerson& cannotStayWith);

	ErrorStatus getErrorStatus() const override;
};

#endif // RIVIERE_GIRL_HPP
