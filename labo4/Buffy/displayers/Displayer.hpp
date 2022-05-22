//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_DISPLAYER_HPP
#define BUFFY_DISPLAYER_HPP

class Field;

class Displayer {
public:
	void clear() const;

	virtual void display(const Field& field) const;

	virtual void displayStats() const;

	static void displayPrompt(int turn, char quit, char stats, char next);

private:
	static void displayHorizontalBorder(const Field& field) ;

	static constexpr char
		CORNER = '+',
		HORIZONTAL_BORDER = '-',
		VERTICAL_BORDER = '|',
		EMPTY = ' ';
};

#endif // BUFFY_DISPLAYER_HPP
