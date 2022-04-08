#ifndef SQUADRON_TIEINTERCEPTOR_HPP
#define SQUADRON_TIEINTERCEPTOR_HPP

#include "Ship.hpp"

/**
 * Classe représentant un vaisseau de type Intercepteur TIE
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class TIEInterceptor : public Ship {
public:
	TIEInterceptor();

private:
	static ShipSpecs specs;
};


#endif // SQUADRON_TIEINTERCEPTOR_HPP
