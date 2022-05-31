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

	void display(ActorType actor) const override;

	void displayBuffy() const override;

	void displayHuman() const override;

	void displayVampire() const override;

private:
	static std::string getColor(ActorType actor);

	static void resetColor();

	static const std::string
		BUFFY_COLOR,
		HUMAN_COLOR,
		VAMPIRE_COLOR;
};

#endif // BUFFY_UNIXDISPLAYER_HPP
