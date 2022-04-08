#ifndef SQUADRON_STARDREADNOUGHT_HPP
#define SQUADRON_STARDREADNOUGHT_HPP

#include "CargoShip.hpp"

/**
 * Classe représentant un vaisseau de type Star Destroyer
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class StarDreadnought : public CargoShip {
public:
	/**
	 * Crée un nouveau Star Destroyer
	 * @param cargo : cargaison actuelle en [tonnes]
	 */
	explicit StarDreadnought(double cargo);

private:
	static CargoShipSpecs specs;
};


#endif // SQUADRON_STARDREADNOUGHT_HPP
