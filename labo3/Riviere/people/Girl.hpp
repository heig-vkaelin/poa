#ifndef RIVIERE_GIRL_HPP
#define RIVIERE_GIRL_HPP

#include "Kid.hpp"

/**
 * Classe représentant une fille
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Girl : public Kid {
public:
	Girl(const std::string& name, const IndependantPerson& dependsOn,
		  const IndependantPerson& cannotStayWith);

	std::string getErrorMessage() const override;
};

#endif // RIVIERE_GIRL_HPP
