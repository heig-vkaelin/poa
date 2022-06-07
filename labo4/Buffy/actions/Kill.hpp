//
// Created by Alexandre Jaquier on 27.05.2022.
//

#ifndef BUFFY_KILL_HPP
#define BUFFY_KILL_HPP

#include "Action.hpp"
/**
 * Classe Kill
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Kill : public Action {
public:
	/**
	 * Constructeur de la classe Kill
	 * @param humanoid Humanoid associé à l'action
	 */
	explicit Kill(Humanoid& humanoid);

	/**
	 * Méthode permettant d'executer l'action Kill
	 * @param field Field sur lequel l'action doit être effectuée
	 */
	void execute(Field& field) override;
};

#endif // BUFFY_KILL_HPP
