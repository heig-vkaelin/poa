#ifndef BUFFY_MOVE_HPP
#define BUFFY_MOVE_HPP

#include <vector>
#include "Action.hpp"
#include "../utils/Position.hpp"

class Humanoid;

/**
 * Classe Move représentant le déplacement d'un humanoïde
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Move : public Action {
public:
	/**
	 * Crée un nouveau déplacement (aléatoire si aucun cible n'est spécifiée)
	 * @param range : longueur du déplacement
	 * @param humanoid : Humanoid à déplacer
	 * @param target : potentielle cible à atteindre
	 */
	Move(unsigned range, Humanoid& humanoid, const Humanoid* target = nullptr);

	void execute(Field& f) override;

private:
	std::vector<const Position*> getPossibleDirections(const Position& position,
																		const Field& field) const;

	unsigned range;
	const Humanoid* target;
};

#endif // BUFFY_MOVE_HPP
