//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_FIELD_HPP
#define BUFFY_FIELD_HPP

#include "actors/Humanoid.hpp"
#include "EndStatus.hpp"
#include <cstdlib>
#include "list"

class Controller;

class Field {
public:
	Field(unsigned width, unsigned height,
			unsigned nbHumans, unsigned nbVampires);

	~Field();

	int nextTurn();

	template<typename T>
	T* findClosestHumanoid(const Humanoid& closeTo) const;

	/**
	 * @return la largeur de la grille
	 */
	unsigned getWidth() const;

	/**
	 * @return la hauteur de la grille
	 */
	unsigned getHeight() const;

	/**
	 * @return un itérateur constant sur le premier acteur de la grille
	 */
	std::list<Humanoid*>::const_iterator begin() const;

	/**
	 * @return un itérateur constant après le dernier acteur de la grille
	 */
	std::list<Humanoid*>::const_iterator end() const;

	EndStatus isFinished() const;

private:
	unsigned width, height;
	int turn;
	std::list<Humanoid*> humanoids;
};

#endif // BUFFY_FIELD_HPP
