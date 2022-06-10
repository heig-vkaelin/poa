#ifndef BUFFY_TRANSFORM_HPP
#define BUFFY_TRANSFORM_HPP

#include "Action.hpp"

class Humanoid;

/**
 * Classe Transform représentant la transformation d'un humain en vampire
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Transform : public Action {
public:
	/**
	 * Crée une nouvelle action de transformation
	 * @param humanoid : humanoïde à transformer
	 */
	explicit Transform(Humanoid& humanoid);

	void execute(Field& field) override;
};

#endif // BUFFY_TRANSFORM_HPP
