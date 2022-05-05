#ifndef RIVIERE_BOAT_HPP
#define RIVIERE_BOAT_HPP

#include <string>
#include "Container.hpp"
#include "Bank.hpp"

/**
 * Conteneur représentant un bateau avec un capacité fixe
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Boat : public Container {
public:
	/**
	 * Crée un bateau avec un nom et une capacité
	 * @param name : nom du bateau
	 * @param capacity : capacité du bateau
	 */
	explicit Boat(const std::string& name, std::size_t capacity);

	std::ostream& toStream(std::ostream& os) const override;

	/**
	 * @return un pointeur sur la rive actuelle du bateau
	 */
	const Bank* getBank() const;

	/**
	 * Modifie la rive actuelle du bateau
	 * @param bank : un pointeur sur la nouveau rive
	 */
	void setBank(const Bank* bank);

	/**
	 * @return true si le bateau a un pilote, false sinon
	 */
	bool hasDriver();

private:
	const Bank* bank;
	std::size_t capacity;
};

#endif // RIVIERE_BOAT_HPP
