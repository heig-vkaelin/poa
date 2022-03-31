#ifndef SQUADRON_CARGOSHIP_HPP
#define SQUADRON_CARGOSHIP_HPP

#include "../Ship.hpp"

/**
 * Classe représentant un vaisseau avec une cargaison
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class CargoShip : public Ship {
public:
	/**
	 * Modifie la cargaison actuelle
	 * @param newCargo : la nouvelle cargaison
	 */
	void setCargo(double newCargo);

	/**
	 * @return la cargaison actuelle en [tonnes]
	 */
	double getCargo() const;

	/**
	 * @return la cargaison maximale du vaisseau, en [tonnes]
	 */
	virtual double getMaxCargo() const = 0;

	std::ostream& toStream(std::ostream& os) const override;

protected:
	explicit CargoShip(unsigned id, double cargo);

private:
	double cargo; // en [tonnes]
};


#endif // SQUADRON_CARGOSHIP_HPP
