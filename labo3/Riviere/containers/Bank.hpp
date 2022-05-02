//
// Created by Valentin Kaelin on 14.04.22.
//

#ifndef RIVIERE_BANK_HPP
#define RIVIERE_BANK_HPP

#include <string>
#include "Container.hpp"

/**
 * Conteneur représentant la rive d'une rivière
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Bank : public Container {
public:
	/**
	 * Crée une nouvelle rive
	 * @param name : nom de la rive
	 */
	explicit Bank(const std::string& name);

	std::ostream& toStream(std::ostream& os) const override;
};


#endif // RIVIERE_BANK_HPP
