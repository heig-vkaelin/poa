//
// Created by Valentin Kaelin on 19.05.22.
//

#ifndef BUFFY_UNIXDISPLAYER_HPP
#define BUFFY_UNIXDISPLAYER_HPP

#include <string>
#include "Displayer.hpp"

class UnixDisplayer : public Displayer {
public:
	void displayBuffy() const override;

	void displayHuman() const override;

	void displayVampire() const override;

private:
	static void resetColor();

	static const std::string
		BUFFY_COLOR,
		HUMAN_COLOR,
		VAMPIRE_COLOR;
};

#endif // BUFFY_UNIXDISPLAYER_HPP
