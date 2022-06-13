#ifndef BUFFY_FIELD_HPP
#define BUFFY_FIELD_HPP

#include <list>
#include "actors/Humanoid.hpp"
#include "actors/Buffy.hpp"
#include "actors/Human.hpp"
#include "actors/Vampire.hpp"
#include "EndStatus.hpp"

class Controller;

/**
 * Classe Field représentant le terrain de la simulation sur lequel évolue les
 * acteurs
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Field {
public:
	/**
	 * Constructeur de la classe Field
	 * @param width : largeur du Field
	 * @param height : hauteur du Field
	 * @param nbHumans : nombre d'humains dans le Field
	 * @param nbVampires : nombre de vampires dans le Field
	 */
	Field(unsigned width, unsigned height,
			unsigned nbHumans, unsigned nbVampires);

	/**
	 * Destructeur de la classe Field supprimant les allocations dynamiques
	 */
	~Field();

	/**
	 * Empêche la copie d'un Field
	 */
	Field(const Field&) = delete;

	/**
	 * Empêche re-affectation d'un Field
	 */
	Field& operator=(const Field&) = delete;

	/**
	 * Augmente d'un tour le nombre de tours passés dans la simulation
	 * @return le numéro du tour actuel
	 */
	int nextTurn();

	/**
	 * Méthode permettant de trouver l'humanoïde le plus proche d'un autre
	 * @tparam T : type de l'humanoïde à rechercher
	 * @param closeTo : humanoïde à comparer
	 * @return l'humanoïde le plus proche du type souhaité (nullptr si aucun)
	 */
	template<typename T>
	T* findClosestHumanoid(const Humanoid& closeTo) const;

	/**
	 * Ajoute un humanoïde à la liste des humanoïdes en jeu
	 * @param humanoid : humanoïde à ajouter
	 */
	void addCharacter(Humanoid* humanoid);

	/**
	 * @return true s'il reste des humains vivants, false sinon
	 */
	bool hasHumans() const;

	/**
	 * @return true s'il reste des vampires vivants, false sinon
	 */
	bool hasVampires() const;

	/**
	 * Indique à la simulation qu'un humain est mort
	 */
	void humanDied();

	/**
	 * Indique à la simulation qu'un vampire est mort
	 */
	void vampireDied();

	/**
	 * Indique à la simulation qu'un nouveau vampire est né
	 */
	void vampireBorn();

	/**
	 * @return la largeur du Field
	 */
	unsigned getWidth() const;

	/**
	 * @return la hauteur du Field
	 */
	unsigned getHeight() const;

	/**
	 * @return un itérateur constant sur le premier acteur du Field
	 */
	std::list<Humanoid*>::const_iterator begin() const;

	/**
	 * @return un itérateur constant après le dernier acteur du Field
	 */
	std::list<Humanoid*>::const_iterator end() const;

	/**
	 * @return un status concernant la fin potentielle de la simulation
	 */
	EndStatus isFinished() const;

private:
	unsigned width, height;
	int turn;
	unsigned nbHumans, nbVampires;
	std::list<Humanoid*> humanoids;
};

#include "Field_Impl.hpp"

#endif // BUFFY_FIELD_HPP
