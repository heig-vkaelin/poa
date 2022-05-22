//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_DISPLAYER_HPP
#define BUFFY_DISPLAYER_HPP

#include "../actors/ActorType.hpp"

class Field;

class Displayer {
public:
	virtual void display(const Field& field) const;

	virtual void displayStats(unsigned wins, unsigned total) const;

	static void displayPrompt(int turn, char quit, char stats, char next);

	void clear() const;

private:
	static void displayHorizontalBorder(const Field& field);

	static char getActorSymbol(ActorType type);

	static constexpr char
		CORNER = '+',
		HORIZONTAL_BORDER = '-',
		VERTICAL_BORDER = '|',
		EMPTY = ' ';
};

#endif // BUFFY_DISPLAYER_HPP
