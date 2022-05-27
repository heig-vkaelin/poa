//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_WINDOWSDISPLAYER_HPP
#define BUFFY_WINDOWSDISPLAYER_HPP

#ifdef __WIN32

#include "Displayer.hpp"
#include <windows.h>

class WindowsDisplayer : public Displayer {
public:
	void displayBuffy() const override;

	void displayHuman() const override;

	void displayVampire() const override;

	void clear() const override;

private:
	static WORD getColor();

	static void changeColor(WORD color);

	static const WORD
		BUFFY_COLOR = 0x0E,
		HUMAN_COLOR = 0x0D,
		VAMPIRE_COLOR = 0x01;
};

#endif // __WIN32

#endif // BUFFY_WINDOWSDISPLAYER_HPP
