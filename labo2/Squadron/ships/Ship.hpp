#ifndef SHIP_HPP
#define SHIP_HPP

#include <ostream>
#include <string>

class Ship;

/**
 * Affiche les caractéristiques du vaisseau sur le stream souhaité
 * @param os  : stream sur lequel afficher le vaisseau
 * @param ship : le vaisseau à afficher
 * @return le stream avec les infos du vaisseau en plus
 */
std::ostream& operator<<(std::ostream& os, const Ship& ship);

class Ship {
public:
	virtual ~Ship();

	/**
	 * Modifie le surnom du vaisseau
	 * @param nick : nouveau surnom
	 */
	void setNickname(const std::string& nick);

	/**
	 * @return la vitesse maximale du vaisseau, en [MGLT]
	 */
	virtual unsigned getMaxSpeed() const = 0;

	/**
	 * @return le nom du modèle du vaisseau
	 */
	virtual std::string getModelName() const = 0;

	/**
	 * @return le poids du vaisseau, en [tonnes]
	 */
	virtual double getWeight() const = 0;

	/**
	 * Affiche les caractéristiques du vaisseau sur le stream souhaité
	 * @param os : stream sur lequel afficher le vaisseau
	 * @return le stream avec les infos du vaisseau en plus
	 */
	virtual std::ostream& toStream(std::ostream& os) const;

protected:
	explicit Ship(unsigned id);

private:
	std::string nickname;
	unsigned id;
};

#endif /* SHIP_HPP */
