//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_DISPLAYER_HPP
#define BUFFY_DISPLAYER_HPP

#include <string>
#include <vector>
#include "../actors/ActorType.hpp"
#include "../actors/Humanoid.hpp"

class Field;

class Displayer {
public:
	Displayer(unsigned width, unsigned height);

	virtual void display(const Field& field);

	virtual void display(const Humanoid* humanoid) const;

	virtual void displayStats(unsigned wins, unsigned total) const;

	static void displayPrompt(int turn, char quit, char stats, char next);

	virtual void clear() const;

private:
	static void displayHorizontalBorder(const Field& field);

	static constexpr char
		CORNER = '+',
		HORIZONTAL_BORDER = '-',
		VERTICAL_BORDER = '|',
		EMPTY = ' ';

	std::vector<std::vector<const Humanoid*>> content;
};

#endif // BUFFY_DISPLAYER_HPP
