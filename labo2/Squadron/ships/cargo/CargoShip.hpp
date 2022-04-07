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
	 * @throws runtime_error si la nouvelle cargaison est invalide
	 */
	void setCargo(double newCargo);

	/**
	 * @return la cargaison actuelle en [tonnes]
	 */
	double getCargo() const;

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
	 * @param maxCargo : cargaison maximale du cargo
	 */
	explicit CargoShip(unsigned id, double cargo, double maxCargo);

private:
	void init(double cargo, double maxCargo);

	double cargo; // en [tonnes]
	double maxCargo; // en [tonnes]
};

#endif // SQUADRON_CARGOSHIP_HPP
