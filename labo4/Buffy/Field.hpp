//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_FIELD_HPP
#define BUFFY_FIELD_HPP

#include "actors/Humanoid.hpp"
#include "actors/Buffy.hpp"
#include "actors/Human.hpp"
#include "actors/Vampire.hpp"
#include "EndStatus.hpp"
#include "utils/Random.hpp"
#include <cstdlib>
#include "list"

//Déclaration de la classe Controller
class Controller;

/**
 * Classe Field
 * @author Alexandre Jaquier
 * @author Valentin Kaelin
 */
class Field {
public:
	/**
	 * Constructeur de la classe Field
	 * @param width Largeur du Field
	 * @param height Hauteur du Field
	 * @param nbHumans Nombre d'humains dans le Field
	 * @param nbVampires Nombre de vampires dans le Field
	 */
	Field(unsigned width, unsigned height,
			unsigned nbHumans, unsigned nbVampires);

	/**
	 * Déstructeur de la classe Field
	 */
	~Field();

	/**
	 * Méthode gérant un tour de jeu
	 * @return Numéro du tour
	 */
	int nextTurn();

	/**
	 * Méthode permettant de connaitre l'humanoid le plus proche d'un autre
	 * @tparam T Type de l'humanoid à rechercher
	 * @param closeTo Humanoid à comparer
	 * @return Humanoid le plus proche
	 */
	template<typename T>
	T* findClosestHumanoid(const Humanoid& closeTo) const;

	/**
	 * Méthode permettant d'ajouter un Humanoid à la liste des Humanoids en jeu
	 * @param humanoid
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
	 * Méthode permettant de gérer ce qu'il se passe lorsqu'un Human meurt
	 */
	void humanDied();

	/**
	 * Méthode permettant de gérer ce qu'il se passe lorsqu'un Vampire meurt
	 */
	void vampireDied();

	/**
	 * Méthode permettant de gérer ce qu'il se passe lorsqu'un Human est transformé en Vampire
	 */
	void vampireBorn();

	/**
	 * Méthode permettant de récupérer le largeur du Field
	 * @return la largeur de la grille
	 */
	unsigned getWidth() const;

	/**
	 * Méthode permettant de récupérer la hauteur du Field
	 * @return la hauteur de la grille
	 */
	unsigned getHeight() const;

	/**
	 * Méthode permettant de récupérer l'itérateur constant du début de la liste des Humanoids
	 * @return un itérateur constant sur le premier acteur de la grille
	 */
	std::list<Humanoid*>::const_iterator begin() const;

	/**
	 * Méthode permettant de récupérer l'itérateur constant de la fin de la liste des Humanoids
	 * @return un itérateur constant après le dernier acteur de la grille
	 */
	std::list<Humanoid*>::const_iterator end() const;

	/**
	 * Méthode permettant de savoir si le jeu est terminé
	 * @return
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
