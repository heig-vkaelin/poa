#ifndef SQUADRON_CARGOSHIP_HPP
#define SQUADRON_CARGOSHIP_HPP

#include "../Ship.hpp"
#include "CargoShipSpecs.hpp"

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
	 * @throws runtime_error si la nouvelle cargaison est invalide
	 */
	void setCargo(double newCargo);

	/**
	 * @return la cargaison actuelle en [tonnes]
	 */
	double getCargo() const;

	/**
	 * @return le poids du vaisseau (cargaison comprise)
	 */
	double getWeight() const override;

	/**
	 * Affiche les caractéristiques du cargo sur le stream souhaité
	 * @param os : stream sur lequel afficher le cargo
	 * @return le stream avec les infos du cargo en plus
	 */
	std::ostream& toStream(std::ostream& os) const override;

protected:
	/**
	 * Crée un vaisseau cargo
	 * @param id : id du cargo
	 * @param cargo : cargaison actuelle du cargo
	 */
	explicit CargoShip(CargoShipSpecs* specs, double cargo);

private:
	double cargo; // en [tonnes]
	CargoShipSpecs* specs;
};

#endif // SQUADRON_CARGOSHIP_HPP
