//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_FIELD_HPP
#define BUFFY_FIELD_HPP

#include "actors/Humanoid.hpp"
#include <cstdlib>
#include "list"

class Field {
public:
	Field(unsigned width, unsigned height);

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

private:
	unsigned width, height;
	int turn;
	std::list<Humanoid*> humanoids;
};

#endif // BUFFY_FIELD_HPP
