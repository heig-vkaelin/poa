//
// Created by Valentin Kaelin on 17.03.22.
//

#ifndef SQUADRON_SHUTTLE_HPP
#define SQUADRON_SHUTTLE_HPP

#include "CargoShip.hpp"

class Shuttle : public CargoShip {
public:
	explicit Shuttle(double cargo);
};


#endif //SQUADRON_SHUTTLE_HPP
