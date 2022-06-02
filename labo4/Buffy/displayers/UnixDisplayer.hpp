//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_UNIXDISPLAYER_HPP
#define BUFFY_UNIXDISPLAYER_HPP

#include <string>
#include "Displayer.hpp"

class UnixDisplayer : public Displayer {
public:
	UnixDisplayer(unsigned width, unsigned height);

	void display(const Humanoid* humanoid) const override;

private:
	static std::string getColor(Color color);

	static void resetColor();
};

#endif // BUFFY_UNIXDISPLAYER_HPP
