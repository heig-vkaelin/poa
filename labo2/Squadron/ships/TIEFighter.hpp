#ifndef SQUADRON_TIEFIGHTER_HPP
#define SQUADRON_TIEFIGHTER_HPP

#include "Ship.hpp"
#include "ShipSpecs.hpp"

/**
 * Classe représentant un vaisseau de type Chasseur TIE
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class TIEFighter : public Ship {
public:
	TIEFighter();

private:
	static ShipSpecs specs;
};


#endif // SQUADRON_TIEFIGHTER_HPP
