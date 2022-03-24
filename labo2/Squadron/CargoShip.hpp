//
// Created by Valentin Kaelin on 17.03.22.
//

#ifndef SQUADRON_CARGOSHIP_HPP
#define SQUADRON_CARGOSHIP_HPP

#include "Ship.hpp"

class CargoShip : public Ship {
public:
	void setCargo(double newCargo);

	virtual std::ostream& toStream(std::ostream& os) const;

	virtual double getWeight() const;

protected:
	CargoShip(unsigned maxSpeed, double weight, double cargo);

private:
	double cargo; // in tons
	double maxCargo; // in tons TODO: en static ??
};


#endif // SQUADRON_CARGOSHIP_HPP
