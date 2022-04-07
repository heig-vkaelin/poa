#ifndef SQUADRON_SQUADRON_HPP
#define SQUADRON_SQUADRON_HPP

#include "ships/Ship.hpp"

/**
 * Classe représentant une escadrille de divers vaisseaux pouvant être mise à jour
 *
 * @author Lazar Pavicevic
 * @author Valentin Kaelin
 */
class Squadron {
	friend std::ostream& operator<<(std::ostream& lhs, const Squadron& rhs);

	friend Squadron operator+(const Squadron& squadron, Ship& ship);

	friend Squadron operator-(const Squadron& squadron, Ship& ship);

public:
	/**
	 * Créée une escadrille avec un nom
	 * @param name : nom de l'escadrille
	 */
	explicit Squadron(const std::string& name);

	/**
	 * Détruit l'escadrille
	 */
	~Squadron();

	/**
	 * Créée une escadrille en copiant l'autre.
	 * La nouvelle escadrille contiendra les mêmes vaisseaux.
	 *
	 * @param squad : l'escadrille à copier
	 */
	Squadron(const Squadron& squad);

	/**
	 * Ajoute un vaisseau à l'escadrille
	 * @param ship : vaisseau à ajouter
	 * @return l'escadrille modifiée
	 */
	Squadron& addShip(Ship& ship);

	/**
	 * Ajoute un vaisseau dans une copie de l'escadrille
	 * @param ship : vaisseau à ajouter
	 * @return la nouvelle escadrille
	 */
	Squadron addShipCopy(Ship& ship) const;

	/**
	 * Supprime un vaisseau de l'escadrille
	 * @param ship : vaisseau à supprimer
	 * @return l'escadrille modifiée
	 */
	Squadron& removeShip(Ship& ship);

	/**
	 * Supprime un vaisseau dans une copie de l'escadrille
	 * @param ship : vaisseau à supprimer
	 * @return la nouvelle escadrille
	 */
	Squadron removeShipCopy(Ship& ship) const;

	Squadron& operator+=(Ship& ship);

	Squadron& operator-=(Ship& ship);

	/**
	 * Accès indexé à un vaisseau
	 * @param index du vaisseau à retourner
	 * @return le vaisseau cherché
	 */
	const Ship& get(std::size_t index) const;

	/**
	 * Accès indexé à un vaisseau dans une escadrille constante
	 * @param index du vaisseau à retourner
	 * @return le vaisseau cherché
	 */
	Ship& get(std::size_t index);

	const Ship& operator[](std::size_t index) const;

	Ship& operator[](std::size_t index);

	/**
	 * Modifie le nom de l'escadrille
	 * @param name : nouveau nom
	 */
	void setName(const std::string& name);

	/**
	 * Modifie le leader de l'escadrille.
	 * Le vaisseau est également ajouté à l'escadrille s'il n'en faisait pas partie.
	 * @param ship : vaisseau du nouveau leader
	 */
	void setLeader(Ship& ship);

	/**
	 * Supprime le leader actuel de l'escadrille.
	 * Le leader reste membre de l'escadrille.
	 */
	void removeLeader();

	/**
	 * Calcule la consommation totale de l'escadrille pour le voyage souhaité
	 * @param distance : distance du voyage en [millions de km]
	 * @param speed : vitesse des vaisseaux lors du voyage en [MGLT]
	 * @return le nombre de [tonnes] consommées
	 */
	double computeConsumption(double distance, double speed);

private:
	void init(const std::string& name);

	bool contains(Ship& ship);

	Ship& getByIndex(std::size_t index) const;

	struct Member;

	std::string name;
	std::size_t size;
	Ship* leader;
	Member* head;
};

#endif // SQUADRON_SQUADRON_HPP
