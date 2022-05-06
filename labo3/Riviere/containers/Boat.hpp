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

	bool addPerson(const Person& person) override;

	/**
	 * Vérifie si le bâteau est à quai de la rive souhaitée
	 * @param bank : la rive à vérifier
	 * @return true si le bâteau se trouve bien sur la rive, false sinon
	 */
	bool isDockedTo(const Bank& bank) const;

	/**
	 * Modifie la rive actuelle du bateau
	 * @param bank : un pointeur sur la nouveau rive
	 */
	void setBank(const Bank& bank);

	/**
	 * @return true si le bateau a un pilote, false sinon
	 */
	bool hasDriver();

private:
	const Bank* bank;
	std::size_t capacity;
};

#endif // RIVIERE_BOAT_HPP
