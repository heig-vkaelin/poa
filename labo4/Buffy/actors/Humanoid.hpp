#ifndef BUFFY_HUMANOID_HPP
#define BUFFY_HUMANOID_HPP

#include "../actions/Action.hpp"
#include "../utils/Position.hpp"
#include "../displayers/Color.hpp"

class Field;

/**
 * Classe Humanoid représentant tous les acteurs de la simulation
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Humanoid {
public:
	/**
	 * Crée un nouvel humanoïde à une donnée
	 * @param position : position de l'humanoïde
	 */
	explicit Humanoid(const Position& position);

	/**
	 * Empêche la copie d'un humanoïde
	 */
	Humanoid(const Humanoid&) = delete;

	/**
	 * Empêche re-affectation d'un humanoïde
	 */
	Humanoid& operator=(const Humanoid&) = delete;

	/**
	 * Destructeur supprimant l'allocation dynamique de l'action
	 */
	virtual ~Humanoid();

	/**
	 * Assigne une action à effectuer lors du prochain tour
	 * @param field : Field sur lequel l'action doit être effectuée
	 */
	void setAction(const Field& field);

	/**
	 * Execute l'action associée à l'humanoïde
	 * @param field
	 */
	void executeAction(Field& field);

	/**
	 * @return true si l'humanoïde est vivant, false sinon
	 */
	virtual bool isAlive() const;

	/**
	 * Tue l'humanoïde
	 * @param field : field sur lequel l'humanoïde se trouve
	 */
	virtual void kill(Field& field);

	/**
	 * @return la position courante de l'humanoïde
	 */
	const Position& getPosition() const;

	/**
	 * Définit la nouvelle position de l'humanoïde
	 * @param position : nouvelle position de l'humanoïde
	 */
	void setPosition(const Position& position);

	/**
	 * @return le symbole associé à l'humanoïde
	 */
	virtual char getSymbol() const = 0;

	/**
	 * @return la couleur associée à l'humanoïde
	 */
	virtual Color getColor() const = 0;

protected:
	/**
	 * @param field : field sur lequel l'action doit être effectuée
	 * @return la prochaine action à effectuer
	 */
	virtual Action* getNextAction(const Field& field) = 0;

private:
	bool alive;
	Position position;
	Action* action;
};

#endif // BUFFY_HUMANOID_HPP
