//
// Created by Valentin Kaelin on 17.03.22.
//

#ifndef SQUADRON_CARGOSHIP_HPP
#define SQUADRON_CARGOSHIP_HPP

#include "../Ship.hpp"

class CargoShip : public Ship {
public:
	void setCargo(double newCargo);

	double getCargo() const;

	virtual double getMaxCargo() const = 0;

	virtual std::ostream& toStream(std::ostream& os) const;

protected:
	explicit CargoShip(unsigned id, double cargo);

private:
	double cargo; // in tons
};


#endif // SQUADRON_CARGOSHIP_HPP
