#ifndef SQUADRON_SHUTTLE_HPP
#define SQUADRON_SHUTTLE_HPP

#include "CargoShip.hpp"

/**
 * Classe représentant un vaisseau de type navette impériale
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Shuttle : public CargoShip {
public:
	/**
	 * Crée une nouvelle shuttle
	 * @param cargo : cargaison actuelle en [tonnes]
	 */
	explicit Shuttle(double cargo);

private:
	static CargoShipSpecs specs;
};

#endif // SQUADRON_SHUTTLE_HPP
