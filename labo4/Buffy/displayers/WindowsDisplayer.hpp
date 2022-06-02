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
	WindowsDisplayer(unsigned width, unsigned height);

	void display(const Humanoid* humanoid) const override;

	void clear() const override;

private:
	static WORD getCurrentColor();

	static WORD getColor(Color color);

	static void changeColor(WORD color);
};

#endif // __WIN32

#endif // BUFFY_WINDOWSDISPLAYER_HPP
