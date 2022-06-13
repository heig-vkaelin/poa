#ifndef BUFFY_ACTION_HPP
#define BUFFY_ACTION_HPP

class Field;

class Humanoid;

/**
 * Classe abstraite représentant une action réalisée par un humanoïde de la
 * simulation
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Action {
public:
	/**
	 * Crée une nouvelle action
	 * @param humanoid : humanoïde qui effectue/subit l'action
	 */
	explicit Action(Humanoid& humanoid);

	/**
	 * Destructeur par défaut de la classe Action
	 */
	virtual ~Action() = default;

	/**
	 * Empêche la copie d'une Action
	 */
	Action(const Action&) = delete;

	/**
	 * Empêche re-affectation d'une Action
	 */
	Action& operator=(const Action&) = delete;

	/**
	 * Execute l'action
	 * @param field : Field sur lequel l'action doit être effectuée
	 */
	virtual void execute(Field& field) = 0;

protected:
	/**
	 * @return l'humanoïde associé à l'action
	 */
	Humanoid* getHumanoid();

private:
	Humanoid* humanoid;
};

#endif // BUFFY_ACTION_HPP
