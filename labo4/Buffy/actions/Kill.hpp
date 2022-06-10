#ifndef BUFFY_KILL_HPP
#define BUFFY_KILL_HPP

#include "Action.hpp"

/**
 * Classe Kill représentant la mort de l'humanoïde souhaité
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Kill : public Action {
public:
	/**
	 * Crée une nouvelle action d'homicide
	 * @param humanoid : humanoïde à tuer
	 */
	explicit Kill(Humanoid& humanoid);
	
	void execute(Field& field) override;
};

#endif // BUFFY_KILL_HPP
