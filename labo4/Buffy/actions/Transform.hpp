//
// Created by Alexandre Jaquier on 27.05.2022.
//

#ifndef BUFFY_TRANSFORM_HPP
#define BUFFY_TRANSFORM_HPP

#include "Action.hpp"
//Déclaration de la classe Humanoid
class Humanoid;

/**
 * Classe Transform
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Transform : public Action {
public:
	/**
	 * Constructeur de la classe Transform
	 * @param humanoid Humanoid associé à l'action
	 */
	explicit Transform(Humanoid& humanoid);

	/**
	 * Méthode permettant d'executer l'action Transform
	 * @param field Field sur lequel l'action doit être effectuée
	 */
	void execute(Field& field) override;
};

#endif // BUFFY_TRANSFORM_HPP
