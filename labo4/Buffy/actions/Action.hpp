#ifndef BUFFY_ACTION_HPP
#define BUFFY_ACTION_HPP


//Déclaration de la classe Field
class Field;

//Déclaration de la classe Humanoid
class Humanoid;

/**
 * Classe abstraite Action
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Action {
public:
	 /**
	  * Constructeur de la classe Action
	  */
	explicit Action(Humanoid& humanoid);

	/**
	 * Destructeur par défaut de la classe Action
	 */

	virtual ~Action() = default;
	/**
	 * Méthode permettant d'executer une action
	 * @param f Field sur lequel l'action doit être effectuée
	 */
	virtual void execute(Field& f) = 0;

protected:

	/**
	 * Méthode permettant de récupérer l'Humanoid associé à l'action
	 * @return Humanoid associé à l'action
	 */
	Humanoid* getHumanoid();

private:
	Humanoid* humanoid;
};

#endif // BUFFY_ACTION_HPP
