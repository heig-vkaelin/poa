//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_FIELD_HPP
#define BUFFY_FIELD_HPP

#include "actors/Humanoid.hpp"
#include "list"

class Field {
public:
	int nextTurn();

private:
	int turn;
	std::list<Humanoid*> humanoids;
};

#endif // BUFFY_FIELD_HPP
