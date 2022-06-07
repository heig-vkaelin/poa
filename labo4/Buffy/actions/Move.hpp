//
// Created by valik on 27.05.2022.
//

#ifndef BUFFY_MOVE_HPP
#define BUFFY_MOVE_HPP

#include <vector>
#include "Action.hpp"
#include "../utils/Position.hpp"

//Declaration de la classe Humanoid
class Humanoid;

/**
 * Classe Move
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Move : public Action {
public:
	 /**
	  * Constructeur de la classe Move
	  * @param range Longueur du déplacement
	  * @param humanoid Humanoid associé à l'action
	  * @param target Cible à atteindre (déplacement aléatoire si nullptr)
	  */
	Move(unsigned range, Humanoid& humanoid, const Humanoid* target = nullptr);

	/**
	 * Méthode permettant d'executer l'action Move
	 * @param f Field sur lequel l'action doit être effectuée
	 */
	void execute(Field& f) override;

private:
	/**
	 * Méthode permettant de générer une direction aléatoire
	 * @param position Position de départ
	 * @param field Field sur lequel l'action doit être effectuée
	 * @return Positions possible
	 */
	std::vector<const Position*> getPossibleDirections(const Position& position,
																		const Field& field) const;

	unsigned range;
	const Humanoid* target;
};

#endif // BUFFY_MOVE_HPP
